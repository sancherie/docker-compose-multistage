//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_DOCKER_CLI_HPP
#define DOCKER_COMPOSE_MULTISTAGE_DOCKER_CLI_HPP

#include "../../types.hpp"
#include <vector>
#include <map>

namespace Docker {
    class Client {
    public:
        void pull(const String &image);
        void build(const String &context,
                  const String &dockerfile,
                  const String &stage,
                  const String &tag,
                  const String &cache_from);
        void push(const String &image);
    private:
        void docker(const Vector<String> &, const Map<String, String> &);
        void command(const String &command);
        void startProcess(const String &command);
        void terminateProcess();

        FILE *process;
    };
}


#endif //DOCKER_COMPOSE_MULTISTAGE_DOCKER_CLI_HPP
