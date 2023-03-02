pipeline {
    agent none
    stages {
        agent {
            label 'cppcheck'
        }
        stage('Static analyze') {
            steps {
                sh script: 'make check', label: 'Analize with Cppcheck'
            }
            post {
                always {
                    publishCppcheck pattern: 'build/artifacts/cppcheck.xml'
                }
            }
        }
        stage('Unit tests') {
            steps {
                sh  script: 'ceedling clobber gcov:all utils:gcov',  label: 'Run unit tests with ceedling'
            }
            post {
                always {
                    xunit tools: [Custom(customXSL: 'test/support/unity.xsl', pattern: 'build/artifacts/gcov/report.xml', skipNoTestFiles: false, stopProcessingIfError: true)]
                    publishCoverage adapters: [cobertura('build/artifacts/gcov/GcovCoverageCobertura.xml')]
                }
            }
        }
        matrix {
            axes {
                axis {
                    name 'BOARD'
                    values 'EDU-CIAA-NXP'
                }
            }
            agent {
                label 'arm'
            }
            environment {
                USB_LOCATION = DutLocation(env.BOARD)
                ATE_LOCATION = AteLocation(env.BOARD)
                DUT_OCD_CFG = OpenOCD(env.BOARD)
                ATE_OCD_CFG = OpenOCD(env.BOARD)
            }
            stages {
                stage('Build') {
                    steps {
                        sh script: 'make clean && make all',  label: 'Build target binary'
                        archiveArtifacts(artifacts: 'build/bin/pase*.elf, build/bin/pase*.map', onlyIfSuccessful: true)
                    }
                }
                stage('System tests') {
                    steps {
                        sh script: 'make download', label: 'Write binary to target'
                        sh script: 'openocd -c "adapter usb location ${env.USB_LOCATION}" -f ${env.DUT_OCD_CFG} -c "init" -c "reset run" -c "shutdown"', label: "Reset DUT device"
                        sh script: 'openocd -c "adapter usb location ${env.ATE_LOCATION}" -f ${env.ATE_OCD_CFG} -c "init" -c "reset run" -c "shutdown"', label: "Reset ATE device"
                        sh script: 'pytest', label: 'Run system tests with PyTest'
                    }
                    post {
                        always {
                            xunit tools: [JUnit(pattern: 'build/artifacts/results.xml', skipNoTestFiles: false, stopProcessingIfError: true)]
                        }
                    }
                }
            }
        }
    }
}

def DutLocation(board) {
    if ("EDU-CIAA-NXP".equals(board)) {
        return "1-1.3";
    }
}

def AteLocation(board) {
    if ("EDU-CIAA-NXP".equals(board)) {
        return "1-1.4";
    }
}

def OpenOCD(board) {
    if ("EDU-CIAA-NXP".equals(board)) {
        return "muju/external/base/mcu/lpc4337-m4/openocd/openocd.cfg";
    }
}
