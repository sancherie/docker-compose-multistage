//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_IMAGE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_IMAGE_HPP


#include "../../types.hpp"

namespace Docker {
    class Image {
    public:
        explicit Image(String path);
        void pull(const String &tag) const;
        void push(const String &tag) const;
        String getFullPath(const String &tag) const;
    private:
        String path;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_IMAGE_HPP
