//
// Created by benajah on 4/11/24.
//

#ifndef WISPBOUND_COLOR_H
#define WISPBOUND_COLOR_H
namespace Elementa {
    struct Color {
        float r, g, b, a;
    };

    Color colorFromRGB(int r, int g, int b, int a = 255);

    Color colorFromHex(const char *hex);
}
#endif //WISPBOUND_COLOR_H
