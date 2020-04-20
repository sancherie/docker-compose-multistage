//
// Created by clementsanchez on 4/19/20.
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include "Docker.hpp"

void Docker::Client::pull(const String &image)
{
    return this->docker({"pull", "-q", image}, {});
}

void Docker::Client::build(
        const String &context,
        const String &dockerfile,
        const String &stage,
        const String &tag,
        const String &cache_from)
{
    Map<String, String> options = {
            {"-f",           context + "/" + dockerfile},
            {"-t",           tag},
            {"--cache-from", cache_from},
    };

    if (!stage.empty()) {
        options["--target"] = stage;
    }

    return this->docker({"build", context}, options);
}

void Docker::Client::push(const String &image)
{
    return this->docker({"push", image}, {});
}

void Docker::Client::docker(const Vector<String> &arguments, const Map<String, String> &options)
{
    std::ostringstream stream;

    stream << "docker";

    std::for_each(arguments.begin(), arguments.end(), [&stream](const String &argument) {
        stream << " " << argument;
    });

    std::for_each(options.begin(), options.end(), [&stream](const Pair<String, String> &pair) {
        stream << " " << pair.first << " " << pair.second;
    });

    this->command(stream.str());
}

void Docker::Client::command(const String &command)
{
    this->startProcess(command);
    this->terminateProcess();
}

void Docker::Client::startProcess(const String &command)
{
    std::cout << "> " << command << std::endl;

    this->process = popen(command.c_str(), "w");

    if (this->process == nullptr) {
        throw std::exception();
    }
}

void Docker::Client::terminateProcess()
{
    if (pclose(this->process) == -1) {
        throw std::exception();
    }
}