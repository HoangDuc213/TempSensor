pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git 'hhttps://github.com/HoangDuc213/TempSensor.git'
            }
        }

        stage('Install Ceedling') {
            steps {
                bat 'gem install ceedling'
            }
        }

        stage('Run Unit Tests') {
            steps {
                bat 'ceedling test:all'
            }
        }

        stage('Run Coverage') {
            steps {
                bat 'ceedling gcov:all'
            }
        }
    }

    post {
        always {
            archiveArtifacts artifacts: 'build/artifacts/**/*', fingerprint: true
        }

        success {
            echo 'Build SUCCESS'
        }

        failure {
            echo 'Build FAILED'
        }
    }
}