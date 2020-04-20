//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_ACTIONSET_HPP
#define DOCKER_COMPOSE_MULTISTAGE_ACTIONSET_HPP


class ActionSet {
public:
    explicit ActionSet(bool pull, bool build, bool push);
    [[nodiscard]] bool needToPull() const;
    [[nodiscard]] bool needToBuild() const;
    [[nodiscard]] bool needToPush() const;
private:
    bool pull;
    bool build;
    bool push;
};


#endif //DOCKER_COMPOSE_MULTISTAGE_ACTIONSET_HPP
