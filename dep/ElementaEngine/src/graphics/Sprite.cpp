//
// Created by benajah on 4/14/24.
//

#include <utility>

#include "Elementa/graphics/Sprite.h"

namespace Elementa {
    SpriteFile::~SpriteFile() {
        if (data)
            stbi_image_free(data);
    }

    std::shared_ptr<SpriteFile> loadSpriteFile(const char *path) {
        int w, h, nrChannels;

        unsigned char *data = stbi_load(path, &w, &h, &nrChannels, 0);

        return std::make_shared<SpriteFile>(w, h, nrChannels, data);
    }

    Sprite createTexture(std::shared_ptr<SpriteFile> sprite_file, int w, int h, int x, int y) {
        return Sprite{std::move(sprite_file), w, h, x, y};
    }
}
