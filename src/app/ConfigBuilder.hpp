//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_ARGUMENT_PARSER_HPP
#define DOCKER_COMPOSE_MULTISTAGE_ARGUMENT_PARSER_HPP


#include "Config.hpp"
#include "../argparse.hpp"

class ConfigBuilder {
public:
    ConfigBuilder(int32_t ac, char **av);

    Config build();
private:
    void buildArgumentParser();
    ActionSet buildActions();

    Vector<String> args;
    argparse::ArgumentParser parser;
};


#endif //DOCKER_COMPOSE_MULTISTAGE_ARGUMENT_PARSER_HPP
