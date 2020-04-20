AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = docker-compose-multistage
docker_compose_multistage_CPPFLAGS = -std=c++17
docker_compose_multistage_LDFLAGS = -lyaml-cpp
docker_compose_multistage_SOURCES = main.cpp \
        app/Application.cpp \
        app/docker/Docker.cpp \
        app/docker/Dockerfile.cpp \
        app/docker/BuildContext.cpp \
        app/docker/builder/ComposeBuilder.cpp \
        app/docker/Compose.cpp \
        app/docker/Service.cpp \
        app/docker/Image.cpp \
        app/docker/builder/DockerfileBuilder.cpp \
        app/docker/builder/BuildContextBuilder.cpp \
        app/docker/builder/ServiceBuilder.cpp \
        app/ConfigBuilder.cpp \
        app/Config.cpp \
        app/ActionSet.cpp
