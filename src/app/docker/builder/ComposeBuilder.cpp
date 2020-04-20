//
// Created by clementsanchez on 4/19/20.
//

#include <iostream>
#include "ComposeBuilder.hpp"

Docker::Builder::ComposeBuilder::ComposeBuilder(Vector<String> files) :
        files(std::move(files))
{
}

Docker::Compose Docker::Builder::ComposeBuilder::build()
{
    this->parseComposeConfig();

    return Compose(this->parseServices());
}

void Docker::Builder::ComposeBuilder::parseComposeConfig()
{
    FILE *process = popen(this->getComposeCommand().c_str(), "r");
    std::ostringstream stream;
    char buffer[1024] = {0};

    while (fgets(buffer, 1024, process) != nullptr) {
        stream << buffer;
        memset(buffer, 0, 1024);
    }

    pclose(process);

    this->config = YAML::Load(stream.str());
}

String Docker::Builder::ComposeBuilder::getComposeCommand()
{
    std::ostringstream stream;

    stream << "docker-compose";
    std::for_each(this->files.begin(), this->files.end(), [&stream](const String &file) {
        stream << " -f " << file;
    });
    stream << " config";

    return stream.str();
}


Vector<Docker::Service> Docker::Builder::ComposeBuilder::parseServices()
{
    Vector<Service> services;
    const Map<String, YAML::Node> &servicesMap = this->config["services"].as<Map<String, YAML::Node>>();

    std::for_each(servicesMap.begin(), servicesMap.end(), [this, &services](const Pair<String, YAML::Node> &service) {
        if (this->isServiceBuildable(service.second)) {
            services.push_back(ServiceBuilder(service.first, service.second).build());
        }
    });

    return services;
}

bool Docker::Builder::ComposeBuilder::isServiceBuildable(const YAML::Node &service) const
{
    return service["image"].IsDefined() && service["build"].IsDefined();
}
