//
// Created by benajah on 4/14/24.
//
#include "Elementa/graphics/Color.h"
#include "Elementa/utils/Logger.h"

namespace Elementa {
    Color colorFromRGB(int r, int g, int b, int a) {
        if (!(r >= 0 && r <= 255) || !(g >= 0 && g <= 255) || !(b >= 0 && b <= 255) || !(a >= 0 && a <= 255)) {
            CRITICAL("INVALID RGB COLOR: RGB(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) +
                     "," + std::to_string(a) + ")");
            exit(EXIT_FAILURE);
        }
        return Color(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
    }
}