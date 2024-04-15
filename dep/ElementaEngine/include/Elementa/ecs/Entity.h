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
        std::unordered_map<int/*typeid(type).hash_code()*/, std::shared_ptr<Component>> components;
    };

    template<typename Comp>
    bool entityContainsComponent(std::shared_ptr<Entity> &entity) {
        return entity->components.contains(typeid(Comp).hash_code());
    }

    template<typename Comp>
    std::shared_ptr<Comp> getEntityComponent(std::shared_ptr<Entity> &entity) {
        int comp_id = typeid(Comp).hash_code();
        if (entity->components.contains(comp_id))
            return std::static_pointer_cast<Comp>(entity->components[comp_id]);
        else
            return nullptr;
    }
}
#endif //WISPBOUND_ENTITY_H
