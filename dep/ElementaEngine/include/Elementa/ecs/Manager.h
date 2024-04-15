//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_MANAGER_H
#define WISPBOUND_MANAGER_H

#include <vector>
#include <functional>
#include "Elementa/ecs/Entity.h"

namespace Elementa {
    //Creates, Removes, and Edits all Entities
    struct Manager {
        //Keep a map of entities by their uid to optimize entity lookup
        std::unordered_map<unsigned int, std::shared_ptr<Entity>> entities;
        //Keep a map of entites(by uid) by their component to optimize getEntitiesWithComponent
        std::unordered_map<int/*typeid(type).hash_code()*/, std::vector<unsigned int>> entities_by_component;
        unsigned int next_uid{0};
    };

    typedef std::function<void()> System;

    unsigned int createEntity(Manager &manager);

    //To allow moving an entity from another manager
    void addEntity(Manager &manager, const std::shared_ptr<Entity> &entity);

    //To allow removing an entity from the manager
    void removeEntity(Manager &manager, unsigned int entity_uid);

    void removeEntity(Manager &manager, std::shared_ptr<Entity> &entity);

    template<typename Comp/*int - > typeid(type).hash_code()*/>
    void addComponentToEntity(Manager &manager, int uid, std::shared_ptr<Comp> component) {
        if (manager.entities.contains(uid)) {
            int comp_id = typeid(Comp).hash_code();
            manager.entities[uid]->components[comp_id] = component;
            manager.entities_by_component[comp_id].push_back(component);
        }
    }

    template<typename Comp/*int - > typeid(type).hash_code()*/>
    void addComponentToEntity(Manager &manager, std::shared_ptr<Entity> &entity, std::shared_ptr<Comp> component) {
        addComponentToEntity(manager, entity->uid, component);
    }

    template<typename Comp/*int - > typeid(type).hash_code()*/>
    std::vector<unsigned int> getEntitiesWithComponent(Manager &manager) {
        return manager.entities_by_component[typeid(Comp).hash_code()];
    }

    std::shared_ptr<Entity> getEntityByUID(Manager &manger, unsigned int entity_uid);
}

#endif //WISPBOUND_MANAGER_H
