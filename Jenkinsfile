pipeline {
  agent {
    label 'arm'
  }
  stages {
    stage('Unit test') {
      steps {
        sh 'ceedling clobber gcov:all utils:gcov'
      }
      post {
        always {
          xunit tools: [Custom(customXSL: 'test/support/unity.xsl', pattern: 'build/artifacts/gcov/report.xml', skipNoTestFiles: false, stopProcessingIfError: true)]
          publishCoverage adapters: [cobertura('build/artifacts/gcov/GcovCoverageCobertura.xml')]
        }
      }
    }

    stage('System test') {
      steps {
        sh 'pytest'
      }
      post {
        always {
          xunit tools: [JUnit(pattern: 'build/artifacts/results.xml', skipNoTestFiles: false, stopProcessingIfError: true)]
        }
      }
    }

    stage('Build') {
      steps {
        sh 'make clean && make all'
        archiveArtifacts(artifacts: 'build/bin/pase.elf, build/bin/pase.map', onlyIfSuccessful: true)
      }
    }

  }
}
