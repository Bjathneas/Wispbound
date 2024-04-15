//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_ENTITY_H
#define WISPBOUND_ENTITY_H

#include <memory>
#include <unordered_map>

#include "Elementa/ecs/Component.h"
// TODO : EVERYTHING HERE
namespace Elementa {
    struct Entity {
        unsigned int uid;
        std::unordered_map<int/*typeid(type).hash_code()*/, std::shared_ptr<Component>> components;
    };

    template<typename Comp>
    bool entityContainsComponent(unsigned int uid) {

    }

    template<typename Comp>
    bool entityContainsComponent(std::shared_ptr<Entity> entity) {

    }
}
#endif //WISPBOUND_ENTITY_H
