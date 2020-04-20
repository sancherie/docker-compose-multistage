//
// Created by clementsanchez on 4/19/20.
//

#include "ConfigBuilder.hpp"

ConfigBuilder::ConfigBuilder(int32_t ac, char **av)
{
    this->args = Vector<String>();

    for (int i = 0; i < ac; ++i) {
        this->args.push_back(av[i]);
    }
}

Config ConfigBuilder::build()
{
    this->buildArgumentParser();

    try {
        this->parser.parse_args(this->args);
    } catch (const std::runtime_error &err) {
        this->parser.help();
        exit(1);
    }

    return Config(this->parser.get<Vector<String>>("--files"), this->buildActions());
}


void ConfigBuilder::buildArgumentParser()
{
    this->parser = argparse::ArgumentParser("docker-compose-multistage");

    this->parser.add_argument("-f", "--files")
            .default_value(Vector<String>({}));

    this->parser.add_argument("-p", "--pull")
            .default_value(false)
            .implicit_value(true);

    this->parser.add_argument("-b", "--build")
            .default_value(false)
            .implicit_value(true);

    this->parser.add_argument("-e", "--push")
            .default_value(false)
            .implicit_value(true);
}

ActionSet ConfigBuilder::buildActions()
{
    return ActionSet(
            this->parser.get<bool>("--pull"),
            this->parser.get<bool>("--build"),
            this->parser.get<bool>("--push")
    );
}
