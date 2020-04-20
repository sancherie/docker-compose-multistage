//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_SERVICE_BUILDER_HPP
#define DOCKER_COMPOSE_MULTISTAGE_SERVICE_BUILDER_HPP


#include <yaml-cpp/node/node.h>
#include "../Service.hpp"

namespace Docker::Builder {
    class ServiceBuilder {
    public:
        explicit ServiceBuilder(String name, const YAML::Node &node);

        Service build();
    private:
        Image parseImage();
        BuildContext parseBuildContext();

        String name;
        const YAML::Node &node;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_SERVICE_BUILDER_HPP
