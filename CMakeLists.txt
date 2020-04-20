cmake_minimum_required(VERSION 3.15)
project(docker_compose_multistage)

set(CMAKE_CXX_STANDARD 17)

add_executable(docker_compose_multistage
        src/main.cpp
        src/types.hpp
        src/argparse.hpp
        src/app/Application.cpp
        src/app/Application.hpp
        src/app/docker/Docker.cpp
        src/app/docker/Docker.hpp
        src/app/docker/Dockerfile.cpp
        src/app/docker/Dockerfile.hpp
        src/app/docker/BuildContext.cpp
        src/app/docker/BuildContext.hpp
        src/app/docker/builder/ComposeBuilder.cpp
        src/app/docker/builder/ComposeBuilder.hpp
        src/app/docker/Compose.cpp
        src/app/docker/Compose.hpp
        src/app/docker/Service.cpp
        src/app/docker/Service.hpp
        src/app/docker/Image.cpp
        src/app/docker/Image.hpp
        src/app/docker/builder/DockerfileBuilder.cpp
        src/app/docker/builder/DockerfileBuilder.hpp
        src/app/docker/builder/BuildContextBuilder.cpp
        src/app/docker/builder/BuildContextBuilder.hpp
        src/app/docker/builder/ServiceBuilder.cpp
        src/app/docker/builder/ServiceBuilder.hpp
        src/app/ConfigBuilder.cpp
        src/app/ConfigBuilder.hpp
        src/app/Config.cpp
        src/app/Config.hpp
        src/app/ActionSet.cpp
        src/app/ActionSet.hpp
        )

target_link_libraries(docker_compose_multistage yaml-cpp)