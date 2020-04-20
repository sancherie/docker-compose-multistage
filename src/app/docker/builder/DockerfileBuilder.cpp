//
// Created by clementsanchez on 4/19/20.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "DockerfileBuilder.hpp"

Docker::Builder::DockerfileBuilder::DockerfileBuilder(String path) :
        path(std::move(path)),
        hasMainStage(false),
        stages({})
{
}

Dockerfile Docker::Builder::DockerfileBuilder::build()
{
    this->initializeBuilder();
    this->parseFile();
    return Dockerfile(this->path, this->hasMainStage, this->stages);
}

void Docker::Builder::DockerfileBuilder::initializeBuilder()
{
    this->hasMainStage = false,
            this->stages = {};
}


void Docker::Builder::DockerfileBuilder::parseFile()
{
    std::ifstream file(this->path);
    String line;

    while (std::getline(file, line)) {
        this->parseLine(line);
    }

    file.close();
}

void Docker::Builder::DockerfileBuilder::parseLine(const String &line)
{
    if (line.find("FROM") == 0) {
        this->parseStageCommand(line);
    }
}

void Docker::Builder::DockerfileBuilder::parseStageCommand(const String &command)
{
    std::istringstream stream(command);
    Vector<String> args(std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>());

    if (args.size() == 2) {
        this->hasMainStage = true;
    } else if (args.size() == 4) {
        this->stages.push_back(args[3]);
    }
}
