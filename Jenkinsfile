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
          publishCoverage adapters: [coberturaAdapter('build/artifacts/gcov/GcovCoverageResults.xml')]
        }
      }
    }

    stage('System test') {
      steps {
        sh 'pytest'
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
