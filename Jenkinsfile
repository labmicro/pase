pipeline {
    agent none
    stages {
        stage('Static analyze') {
            agent {
                label 'cppcheck'
            }
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
            agent {
                label 'ceedling'
            }
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
        stage('Build') {
            matrix {
                axes {
                    axis {
                        name 'BOARD'
                        values 'edu-ciaa-nxp'
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
                    VERBOSE = 'y'
                }
                stages {
                    stage('Compilation') {
                        steps {
                            sh script: 'make all',  label: 'Build target binary'
                            archiveArtifacts(artifacts: 'build/bin/pase*.elf, build/bin/pase*.map', onlyIfSuccessful: true)
                        }
                    }
                    stage('System tests') {
                        steps {
                            sh script: 'make download', label: 'Write binary to target'
                            sh script: 'openocd -c "adapter usb location $USB_LOCATION" -f $DUT_OCD_CFG -c "init" -c "reset run" -c "shutdown"', label: "Reset DUT device"
                            sh script: 'openocd -c "adapter usb location $ATE_LOCATION" -f $ATE_OCD_CFG -c "init" -c "reset run" -c "shutdown"', label: "Reset ATE device"
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
}

def DutLocation(board) {
    if ("edu-ciaa-nxp".equals(board)) {
        return "1-1.3";
    }
}

def AteLocation(board) {
    if ("edu-ciaa-nxp".equals(board)) {
        return "1-1.4";
    }
}

def OpenOCD(board) {
    if ("edu-ciaa-nxp".equals(board)) {
        return "muju/external/base/mcu/lpc4337-m4/openocd/openocd.cfg";
    }
}
