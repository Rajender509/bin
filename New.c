docker build -t javadockerapp https://github.com/deepak574/javadockertest.git
docker run javadockerapp
docker tag [IMAGE ID] [Docker Hub username]/[repository name]:[tag]
docker push [Docker Hub username]/[repository name]:[tag]
docker pull gujjuladeepak/javadockerapp:latest
docker run gujjuladeepak/javadockerapp:latest
import java.util.Scanner;

public class Fact {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();

        int factorial = 1;
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        System.out.println("The factorial is: " + factorial);
    }
}
pipeline {
    agent any

    stages {
        stage('Checkout Code') {
            steps {
                git branch: 'main', url: 'https://github.com/deepak574/project.git'
            }
        }
        stage('Build') {
            steps {
                
                bat 'javac Sample.java'
            }
        }
        stage('Test') {
            steps {
               
                bat 'java Sample'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                // Add your deployment commands here (like copying files to a server)
            }
        }
    }
}
