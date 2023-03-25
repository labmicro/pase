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
                        values 'edu-ciaa-nxp', 'blue-pill'
                    }
                }
                agent {
                    label 'arm'
                }
                environment {
                    def config = Configuracion(env.NODE_NAME, env.BOARD)
                    PROJECT_NAME = "${env.BOARD}"
                    USB_LOCATION = "${config['dut']['usb']}"
                    ATE_LOCATION = "${config['ate']['usb']}"
                    DUT_OCD_CFG = "${config['dut']['openocd']}"
                    ATE_OCD_CFG = "${config['ate']['openocd']}"
                    TEST_CFG = "${config['dut']['yaml']}"
                    VERBOSE = 'y'
                }
                stages {
                    stage('Compilation') {
                        steps {
                            sh script: 'make clean all', label: 'Build target binary'
                            sh script: 'rm build/bin/project.elf', label: 'Remove debug binary'
                            archiveArtifacts(artifacts: 'build/bin/*.elf, build/bin/*.map', onlyIfSuccessful: true)
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

def Configuracion(node, board) {
    def config = readYaml file: "test/config/jenkins.yaml"
    config = config.find { it.node == node.replaceAll(" ", "-")}
    config = config.boards.find { it.name == board }
    return config
}
