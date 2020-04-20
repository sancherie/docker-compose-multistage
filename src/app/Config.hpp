//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_CONFIG_HPP
#define DOCKER_COMPOSE_MULTISTAGE_CONFIG_HPP

#include "../types.hpp"
#include "ActionSet.hpp"


class Config {
public:
    explicit Config(Vector<String> files, const ActionSet &actions);
    [[nodiscard]] const Vector<String> &getFiles() const;
    [[nodiscard]] const ActionSet &getActions() const;
private:
    const Vector<String> files;
    const ActionSet actions;
};


#endif //DOCKER_COMPOSE_MULTISTAGE_CONFIG_HPP
