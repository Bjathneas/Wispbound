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

    void update();

    void render(); //is its own system

    // TODO: LOOP THROUGH ENTITIES IN SCENE AND CHECK IF THEY HAVE SPECIFIED COMPONENT

}

#endif //WISPBOUND_ENGINE_H
