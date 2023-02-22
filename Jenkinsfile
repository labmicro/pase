pipeline {
  agent {
    label 'arm'
  }
  stages {
    stage('Unit test') {
      steps {
        sh 'ceedling clobber && ceedling gcov:all && ceedling utils:gcov'
        archiveArtifacts(artifacts: 'build/artifacts/gcov/*', onlyIfSuccessful: true)
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
