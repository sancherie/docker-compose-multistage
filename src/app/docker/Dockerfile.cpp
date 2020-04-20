//
// Created by clementsanchez on 4/19/20.
//

#include "Dockerfile.hpp"
#include "Docker.hpp"

Dockerfile::Dockerfile(String path, bool &mainStage, Vector<String> stages):
        path(std::move(path)),
        mainStage(mainStage),
        stages(std::move(stages))
{
}

void Dockerfile::build(const String &context, const String &stage, const String &tag, const String &cache_from)  const
{
    Docker::Client().build(context, this->getPath(), stage, tag, cache_from);
}

const String &Dockerfile::getPath()  const
{
    return this->path;
}

bool Dockerfile::hasMainStage()  const
{
    return this->mainStage;
}

const Vector<String> &Dockerfile::getStages() const
{
    return this->stages;
}