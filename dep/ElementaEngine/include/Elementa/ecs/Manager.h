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

    void addSystemToManager(System sys, Manager manager);

    unsigned int createEntity(Manager manager);

    void destroyEntity(Manager manager, unsigned int uid);

    void destroyEntity(Manager manager, std::shared_ptr<Entity>);

    void addComponentToEntity(Manager manager, int uid, Component component);

    void addComponentToEntity(Manager manager, std::shared_ptr<Entity> entity, Component component);

    template<typename Comp/*int - > typeid(type).hash_code()*/>
    std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent(Manager manager) {

    }
}

#endif //WISPBOUND_MANAGER_H
