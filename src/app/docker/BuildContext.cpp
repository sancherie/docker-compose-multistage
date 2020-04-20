//
// Created by clementsanchez on 4/19/20.
//

#include "BuildContext.hpp"
#include "Docker.hpp"

Docker::BuildContext::BuildContext(String context, Dockerfile dockerfile) :
        context(std::move(context)),
        dockerfile(std::move(dockerfile))
{
}

void Docker::BuildContext::build(const String &stage, const String &tag, const String &cache_from) const
{
    this->dockerfile.build(this->context, stage, tag, cache_from);
}

bool Docker::BuildContext::hasMainStage() const
{
    return this->dockerfile.hasMainStage();
}

const Vector<String> &Docker::BuildContext::getStages() const
{
    return this->dockerfile.getStages();
}