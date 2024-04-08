//
// Created by benajah on 4/7/24.
//

#ifndef WISPBOUND_ENGINE_H
#define WISPBOUND_ENGINE_H

#include "Elementa/utils/Logger.h"
#include "Elementa/core/Window.h"

namespace Elementa {

    void initEngine(const char *title, int width, int height);

    void startEngine();

    void update();

    void render();
}

#endif //WISPBOUND_ENGINE_H
