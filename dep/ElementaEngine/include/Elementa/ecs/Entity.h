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
        std::unordered_map<const char *, std::shared_ptr<Component>> components;
    };

    template<typename Comp>
    bool entityContainsComponent(unsigned int uid) {

    }

    template<typename Comp>
    bool entityContainsComponent(std::shared_ptr<Entity> entity) {

    }

    void addComponentToEntity(unsigned int uid, Component component);

    void addComponentToEntity(std::shared_ptr<Entity> entity, Component component);
}
#endif //WISPBOUND_ENTITY_H
