@REM docker run --name=mycodes -it -v F:\Coding\GithubRepositories\Mycodes:/realtyxxx realtyxxx/csapp_env /bin/zsh  
docker container start mycodes && ^
docker container exec -it mycodes /bin/zsh 
@REM docker container kill mycodes