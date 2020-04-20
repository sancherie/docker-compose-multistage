//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_COMPOSE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_COMPOSE_HPP

#include "../../types.hpp"
#include "Service.hpp"

namespace Docker {
    class Compose {
    public:
        explicit Compose(Vector<Service> services);
        void process(const ActionSet &actions);
    private:
        Vector<Service> services;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_COMPOSE_HPP
