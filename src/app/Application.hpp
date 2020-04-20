//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_APPLICATION_HPP
#define DOCKER_COMPOSE_MULTISTAGE_APPLICATION_HPP

#include "Config.hpp"
#include "docker/Compose.hpp"

class Application {
public:
    explicit Application(const Config &config);
    void start();

private:
    const Config &config;
    Docker::Compose compose;
};


#endif //DOCKER_COMPOSE_MULTISTAGE_APPLICATION_HPP
