//
// Created by clementsanchez on 4/19/20.
//

#ifndef DOCKER_COMPOSE_MULTISTAGE_TYPES_HPP
#define DOCKER_COMPOSE_MULTISTAGE_TYPES_HPP

#include <vector>
#include <map>
#include <string>

typedef std::string String;

template<typename T>
using Vector = std::vector<T>;

template<typename T, typename U>
using Pair = std::pair<T, U>;

template<typename T, typename U>
using Map = std::map<T, U>;

template<typename T>
using Vector = std::vector<T>;

#endif //DOCKER_COMPOSE_MULTISTAGE_TYPES_HPP
