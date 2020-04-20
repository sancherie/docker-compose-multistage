//
// Created by clementsanchez on 4/19/20.
//

#include "Image.hpp"
#include "Docker.hpp"

Docker::Image::Image(String path) :
        path(std::move(path))
{
}

void Docker::Image::pull(const String &tag) const
{
    Client().pull(this->getFullPath(tag));
}

void Docker::Image::push(const String &tag) const
{
    Client().push(this->getFullPath(tag));
}


String Docker::Image::getFullPath(const String &tag) const
{
    if (tag.empty()) {
        return this->path;
    } else {
        return this->path + ':' +  tag;
    }
}
