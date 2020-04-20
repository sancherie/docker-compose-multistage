//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_SERVICE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_SERVICE_HPP


#include "Image.hpp"
#include "BuildContext.hpp"
#include "../../types.hpp"
#include "../ActionSet.hpp"

namespace Docker {
    class Service {
    public:
        explicit Service(String name, Image image, BuildContext buildContext);
        void process(const ActionSet &actions) const;
    private:
        void processStage(const ActionSet &actions, const String &stage) const;
        void pull(const String &tag) const;
        void build(const String &stage) const;
        void push(const String &tag) const;

        String name;
        Image image;
        BuildContext buildContext;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_SERVICE_HPP
