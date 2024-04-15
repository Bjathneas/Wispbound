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

    Shader loadShaderFromString(const char *string, SHADER_TYPE type);

    Shader loadShaderFromFile(const char *path);

    struct ShaderProgram {
        GLuint ID;
    };

    ShaderProgram createShaderProgram();

    void addShaderToProgram(Shader &shader, ShaderProgram &program);

    void useShaderProgram(ShaderProgram &program);
}

#endif //WISPBOUND_SHADER_H
