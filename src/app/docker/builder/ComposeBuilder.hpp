//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_DOCKER_BUILDER_COMPOSE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_DOCKER_BUILDER_COMPOSE_HPP

#include <algorithm>
#include <sstream>
#include <cstring>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/node/node.h>
#include "../../../types.hpp"
#include "../Service.hpp"
#include "../Compose.hpp"
#include "ServiceBuilder.hpp"

namespace Docker::Builder {
    class ComposeBuilder {
    public:
        explicit ComposeBuilder(Vector<String> files);
        Docker::Compose build();
    private:
        void parseComposeConfig();
        String getComposeCommand();
        Vector<Service> parseServices();
        bool isServiceBuildable(const YAML::Node &service) const;

        YAML::Node config;
        Vector<String> files;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_DOCKER_BUILDER_COMPOSE_HPP
