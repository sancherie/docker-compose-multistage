//
// Created by clementsanchez on 4/19/20.
//

#include "Compose.hpp"

Docker::Compose::Compose(Vector<Docker::Service> services):
    services(std::move(services))
{
}

void Docker::Compose::process(const ActionSet &actions)
{
    for (const Service &service: this->services) {
        service.process(actions);
    }
}
