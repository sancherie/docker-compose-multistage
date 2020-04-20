//
// Created by clementsanchez on 4/19/20.
//

#include "ActionSet.hpp"

ActionSet::ActionSet(bool pull, bool build, bool push):
        pull(pull),
        build(build),
        push(push)
{
}

bool ActionSet::needToPull() const
{
    return this->pull;
}

bool ActionSet::needToBuild() const
{
    return this->build;
}

bool ActionSet::needToPush() const
{
    return this->push;
}
