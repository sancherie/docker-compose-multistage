//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_BUILD_CONTEXT_BUILDER_HPP
#define DOCKER_COMPOSE_MULTISTAGE_BUILD_CONTEXT_BUILDER_HPP


#include <yaml-cpp/yaml.h>
#include "../../../types.hpp"
#include "../BuildContext.hpp"

namespace Docker::Builder {
    class BuildContextBuilder {
    public:
        explicit BuildContextBuilder(const YAML::Node &node);

        BuildContext build();
    private:
        String parseContext();
        Dockerfile parseDockerfile();

        const YAML::Node &node;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_BUILD_CONTEXT_BUILDER_HPP
