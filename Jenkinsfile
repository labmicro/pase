pipeline {
    agent none
    stages {
        stage('Format check') {
            agent {
                label 'precommit'
            }
            steps {
                sh 'pre-commit run --all-files --show-diff-on-failure'
            }
        }
        stage('Static analyze') {
            agent {
                label 'cppcheck'
            }
            steps {
                sh 'make check'
            }
            post {
                always {
                    publishCppcheck pattern: 'build/artifacts/cppcheck.xml'
                }
            }
        }
        stage('Unit test') {
            agent {
                label 'ceedling'
            }
            steps {
                sh 'ceedling gcov:all utils:gcov'
            }
            post {
                always {
                    xunit tools: [Custom(customXSL: 'test/support/unity.xsl', pattern: 'build/artifacts/gcov/report.xml', skipNoTestFiles: false, stopProcessingIfError: true)]
                    publishCoverage adapters: [cobertura('build/artifacts/gcov/GcovCoverageCobertura.xml')]
                }
            }
        }
    }
}
