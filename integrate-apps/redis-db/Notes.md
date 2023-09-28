# Docker commands to run redis and expose ports

## Command to load the image and run it
```dockerfile
docker run --name redis-cpp-learn -p 6379:6379 redis
``````

## Command to start redis
1. Command to start an interactive session with redis
```dockerfile
docker exec -it redis-cpp-learn redis-cli
``````
## Command to list containers
1. Command to list all containers
```dockerfile
docker ps --all
``````

## To run redis-conn.cpp
```bash
.\bin\integrateAppsRedisDB1.exe localhost 6379 redispw
``````