//
// Created by benajah on 4/14/24.
//
#include "Elementa/graphics/Shader.h"
#include "Elementa/utils/File.h"
#include "Elementa/utils/Logger.h"

#include <filesystem>

namespace Elementa {

    Shader loadShaderFromString(const char *string, SHADER_TYPE type) {
        GLuint shader;

        switch (type) {
            case SHADER_TYPE::VERTEX:
                shader = glCreateShader(GL_VERTEX_SHADER);
                break;
            case SHADER_TYPE::FRAGMENT:
                shader = glCreateShader(GL_FRAGMENT_SHADER);
                break;
            case SHADER_TYPE::GEOMETRY:
                shader = glCreateShader(GL_GEOMETRY_SHADER);
                break;
        }

        glShaderSource(shader, 1, &string, nullptr);
        glCompileShader(shader);

        int success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success) {
            CRITICAL("Shader failed to compile: " + std::string(infoLog));
            exit(EXIT_FAILURE);
        } else
            return Shader{type, shader};
    }

    Shader loadShaderFromFile(const char *path) {
        SHADER_TYPE type;

        std::string extension = std::filesystem::path(path).extension();

        if (extension == ".vert") {
            type = SHADER_TYPE::VERTEX;
        } else if (extension == ".frag") {
            type = SHADER_TYPE::FRAGMENT;
        } else if (extension == ".geo") {
            type = SHADER_TYPE::GEOMETRY;
        } else {
            CRITICAL("File[" + std::string(path) + "] is not a Shader File");
        }

        return loadShaderFromString(fileToString(path).c_str(), type);
    }

    ShaderProgram createShaderProgram() {
        return ShaderProgram{glCreateProgram()};
    }

    void addShaderToProgram(Shader &shader, ShaderProgram &program) {
        glAttachShader(program.ID, shader.ID);
        glLinkProgram(shader.ID);
    }

    void useShaderProgram(ShaderProgram &program) {
        glUseProgram(program.ID);
    }

}