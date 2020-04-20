//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_BUILDER_HPP
#define DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_BUILDER_HPP

#include "../../../types.hpp"
#include "../Dockerfile.hpp"
#include "../Service.hpp"

namespace Docker::Builder {
    class DockerfileBuilder {
    public:
        explicit DockerfileBuilder(String path);

        Dockerfile build();
    private:
        void initializeBuilder();
        void parseFile();
        void parseLine(const String &line);
        void parseStageCommand(const String &command);

        String path;
        bool hasMainStage;
        Vector<String> stages;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_BUILDER_HPP
