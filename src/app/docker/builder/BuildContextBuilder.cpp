//
// Created by clementsanchez on 4/19/20.
//

#include <iostream>
#include "BuildContextBuilder.hpp"
#include "DockerfileBuilder.hpp"

Docker::Builder::BuildContextBuilder::BuildContextBuilder(const YAML::Node &node) :
        node(node)
{
}

Docker::BuildContext Docker::Builder::BuildContextBuilder::build()
{
    return BuildContext(this->parseContext(), this->parseDockerfile());
}

String Docker::Builder::BuildContextBuilder::parseContext()
{
    return this->node["context"].as<String>();
}

Dockerfile Docker::Builder::BuildContextBuilder::parseDockerfile()
{
    return DockerfileBuilder(this->node["dockerfile"].as<String>()).build();
}
