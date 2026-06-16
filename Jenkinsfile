pipeline {
    agent any
    stages {
        stage('Build') { 
            steps {
                sh 'pwd'
				sh 'mkdir -p build' 
                sh 'cd $(pwd)/build/'
				sh 'pwd'
				//这一步进不去build目录，不知道为啥				
				//sh 'cd $(pwd)/build/ && cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=C:/D/Programs/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/D/Programs/msys64/ucrt64/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug'
				sh 'cmake -Bbuild -G "Unix Makefiles" -DCMAKE_C_COMPILER=C:/D/Programs/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/D/Programs/msys64/ucrt64/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug'
				sh 'make'
            }
        }
    }
}