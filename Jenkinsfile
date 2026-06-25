pipeline {
    agent any
	environment {
        PATH = "C:/D/Programs/msys64/ucrt64/bin;${env.PATH}"
    }
	triggers {
        //githubPush()  // 显式声明 GitHub 触发，git仓库 push后，自动trig Jenkins， 需要github仓库设置设置webhook
		//pollSCM('H/5 * * * *')  // 每5分钟轮询一次
    }
    stages {
        stage('Build') { 
            steps {
                sh 'pwd'
				sh 'rm -rf ./build'
				sh 'mkdir -p build' 
				
                sh 'cd $(pwd)/build/'
                sh 'cd $(pwd)/build/'
				sh 'pwd'
				//这一步进不去build目录，pipeline 每一行的指令是独立的
				
				sh 'cd $(pwd)/build/ && cmake .. -G "Unix Makefiles" -DCMAKE_C_COMPILER=C:/D/Programs/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/D/Programs/msys64/ucrt64/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug'
				//sh 'cmake -Bbuild -G "Unix Makefiles" -DCMAKE_C_COMPILER=C:/D/Programs/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/D/Programs/msys64/ucrt64/bin/g++.exe -DCMAKE_BUILD_TYPE=Debug'
				sh 'cd $(pwd)/build/ && make'
            }
        }
        stage('Test') { 
            steps {
				sh 'cd $(pwd)/build/ && ./main.exe'
			}
		}			
    }
}