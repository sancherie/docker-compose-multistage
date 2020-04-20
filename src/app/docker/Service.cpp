//
// Created by clementsanchez on 4/19/20.
//

#include <iostream>
#include "Service.hpp"

Docker::Service::Service(String name, Docker::Image image, Docker::BuildContext buildContext) :
        name(std::move(name)),
        image(std::move(image)),
        buildContext(std::move(buildContext))
{
}

void Docker::Service::pull(const String &tag) const
{
    this->image.pull(tag);
}

void Docker::Service::build(const String &stage) const
{
    this->buildContext.build(stage, this->image.getFullPath(stage), this->image.getFullPath(stage));
}

void Docker::Service::push(const String &tag) const
{
    this->image.push(tag);
}

void Docker::Service::process(const ActionSet &actions) const
{
    std::cout << "Processing service " << this->name << std::endl;

    if (this->buildContext.hasMainStage()) {
        std::cout << "Processing the [main stage]" << std::endl;
        this->processStage(actions, "");
    }

    for (const String &stage : this->buildContext.getStages()) {
        std::cout << "Processing stage [" << stage << "]" << std::endl;
        this->processStage(actions, stage);
    }
}

void Docker::Service::processStage(const ActionSet &actions, const String &stage) const
{
    if (actions.needToPull()) {
        this->pull(stage);
    }

    if (actions.needToBuild()) {
        this->build(stage);
    }

    if (actions.needToPush()) {
        this->push(stage);
    }
}
