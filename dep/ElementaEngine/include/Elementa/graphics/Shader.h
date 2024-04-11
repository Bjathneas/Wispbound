//
// Created by benajah on 4/8/24.
//

#ifndef WISPBOUND_SHADER_H
#define WISPBOUND_SHADER_H

#include <GL/glew.h>

namespace Elementa {
    enum SHADER_TYPE {
        VERTEX, FRAGMENT, GEOMETRY
    };

    struct Shader {
        SHADER_TYPE type;
        GLuint ID;
    };

    Shader loadShaderFromFile(const char *path);

    Shader loadShaderFromString(const char *string, SHADER_TYPE type);
    //TODO: create ShaderProgram
}

#endif //WISPBOUND_SHADER_H
