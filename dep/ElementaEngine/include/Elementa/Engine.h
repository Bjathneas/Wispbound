//
// Created by benajah on 4/7/24.
//
// GOAL: KEEP IT SIMPLE, MORE FEATURES AS THEY ARE NEEDED
#ifndef WISPBOUND_ENGINE_H
#define WISPBOUND_ENGINE_H

#include "Elementa/utils/Logger.h"
#include "Elementa/core/Window.h"
#include "Elementa/ecs/Entity.h"

namespace Elementa {

    void initEngine(const char *title, int width, int height);

    void startEngine();

    extern std::vector<double> update_frame_times, render_frame_times, frame_times, frame_count;

    void update();

    void render(); //is its own system

    //Entity managment without the use of the manager specific functions
    void destroyEntity();

    unsigned int createEntity();

    void addComponentToEntity();

    std::shared_ptr<Entity> getEntityByUID(unsigned int uid);

    //INFO: SCENE SPECIFIC
    template<typename Comp/*int - > typeid(type).hash_code()*/>
    std::vector<std::shared_ptr<Entity>> getEntitiesWithComponent() {
        
    }

}

#endif //WISPBOUND_ENGINE_H
