@REM docker run --name=mycodes -it -v F:\Coding\GithubRepositories\Mycodes:/realtyxxx realtyxxx/csapp_env /bin/zsh  
@REM docker container start mycodes && ^
@REM docker container exec -it mycodes /bin/zsh 
@REM docker container kill mycodes
@REM 这种方式加载的文件夹太大了,进去后太慢了 还是得绑定方式

@REM docker run --rm -it -v F:\Coding\GithubRepositories\Mycodes:/realtyxxx realtyxxx/csapp_env /bin/zsh 

@REM 打开需要使用的目录然后运行一下

docker run -it --rm -v %~dp0:/realtyxxx realtyxxx/csapp_env /bin/zsh