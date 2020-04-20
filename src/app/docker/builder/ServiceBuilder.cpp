//
// Created by clementsanchez on 4/19/20.
//

#include "ServiceBuilder.hpp"
#include "BuildContextBuilder.hpp"

Docker::Builder::ServiceBuilder::ServiceBuilder(String name, const YAML::Node &node):
    name(std::move(name)),
    node(node)
{
}

Docker::Service Docker::Builder::ServiceBuilder::build()
{
    return Service(this->name, this->parseImage(), this->parseBuildContext());
}

Docker::Image Docker::Builder::ServiceBuilder::parseImage()
{
    return Image(this->node["image"].as<String>());
}

Docker::BuildContext Docker::Builder::ServiceBuilder::parseBuildContext()
{
    return BuildContextBuilder(this->node["build"].as<YAML::Node>()).build();
}
