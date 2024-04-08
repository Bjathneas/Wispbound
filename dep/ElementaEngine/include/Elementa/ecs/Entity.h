//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_ENTITY_H
#define WISPBOUND_ENTITY_H

#include <memory>
#include <unordered_map>

#include "Elementa/ecs/Component.h"

namespace Elementa {
    struct Entity {
        unsigned int uid;
        std::unordered_map<const char *, std::shared_ptr<Component>> components;
    };

    void addComponentToEntity(Component component);
}
#endif //WISPBOUND_ENTITY_H
