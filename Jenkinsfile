pipeline {
    agent any
    stages {
        stage('Build') { 
            steps {
                sh 'mkdir build' 
                sh 'cd build' 
				sh 'pwd'
				sh 'cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=C:/D/Programs/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/D/Programs/msys64/ucrt64/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug'
				sh 'make'
            }
        }
    }
}