//
// Created by clementsanchez on 4/19/20.
//

#include "Config.hpp"

Config::Config(Vector<String> files, const ActionSet &actions):
        files(std::move(files)),
        actions(actions)
{
}

const Vector<String> &Config::getFiles() const
{
    return this->files;
}

const ActionSet &Config::getActions() const
{
    return this->actions;
}
