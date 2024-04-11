//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_MANAGER_H
#define WISPBOUND_MANAGER_H

#include <vector>
#include <functional>
#include "Elementa/ecs/Entity.h"

namespace Elementa {
    struct Manager {
        std::unordered_map<unsigned int, std::shared_ptr<Entity>> entities;
    };

    extern Manager world;
    //rethink scene, just develop ecs as world cords
    //extern Manager scene;//Stores entity if it exists in scene, or has no position

    typedef std::function<void()> System;

    extern std::vector<System> systems;

    void addSystem(System sys);

    extern unsigned int next_uid;

    unsigned int createEntity();

    template<typename Comp>
    std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent() {

    }
}

#endif //WISPBOUND_MANAGER_H
