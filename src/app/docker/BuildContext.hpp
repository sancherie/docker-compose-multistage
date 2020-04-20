//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_BUILDABLE_DOCKERFILE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_BUILDABLE_DOCKERFILE_HPP


#include "../../types.hpp"
#include "Dockerfile.hpp"

namespace Docker {
    class BuildContext {
    public:
        explicit BuildContext(String context, Dockerfile dockerfile);
        void build(const String &stage, const String &tag, const String &cache_from) const;
        [[nodiscard]] bool hasMainStage() const;
        [[nodiscard]] const Vector<String> &getStages() const;
    private:
        String context;
        Dockerfile dockerfile;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_BUILDABLE_DOCKERFILE_HPP
