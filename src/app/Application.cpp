//
// Created by clementsanchez on 4/19/20.
//

#include "Application.hpp"
#include "ConfigBuilder.hpp"
#include "docker/builder/ComposeBuilder.hpp"

Application::Application(const Config &config):
    config(config),
    compose(Docker::Builder::ComposeBuilder(config.getFiles()).build())
{
}

void Application::start()
{
    this->compose.process(this->config.getActions());
}

