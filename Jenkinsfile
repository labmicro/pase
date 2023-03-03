pipeline {
    agent none
    stages {
        stage('test') {
            agent {
                label 'cppcheck'
            }
            steps {
                echo "${Configuracion(env.NODE_NAME, env.BOARD)}"
            }
        }
    }
}

def Configuracion(node, board) {
    def config = readYaml file: "test/config/jenkins.yaml"
    return config
}
