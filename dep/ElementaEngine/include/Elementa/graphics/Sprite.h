//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_SPRITE_H
#define WISPBOUND_SPRITE_H
#define STB_IMAGE_IMPLEMENTATION

#include <memory>
#include "stb_image.h"

namespace Elementa {
    struct SpriteFile {
        int width, height, nrChannels;
        unsigned char *data;

        ~SpriteFile();
    };

    std::shared_ptr<SpriteFile> loadSpriteFile(const char *path);

    struct Sprite {
        std::shared_ptr<SpriteFile> sprite_file;
        int w, h, x, y;
    };

    Sprite createTexture(std::shared_ptr<SpriteFile> sprite_file, int w, int h, int x = 0, int y = 0);
}
#endif //WISPBOUND_SPRITE_H
