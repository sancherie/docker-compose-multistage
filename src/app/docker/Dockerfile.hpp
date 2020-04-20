//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_HPP
#define DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_HPP


#include "../../types.hpp"

class Dockerfile {
public:
    explicit Dockerfile(String, bool &, Vector<String>);
    void build(const String &context, const String &stage, const String &tag, const String &cache_from)  const;
    [[nodiscard]] const String &getPath()  const;
    [[nodiscard]] bool hasMainStage()  const;
    [[nodiscard]] const Vector<String> &getStages() const;
private:
    String path;
    bool mainStage;
    Vector<String> stages;
};


#endif //DOCKER_COMPOSE_MULTISTAGE_DOCKERFILE_HPP
