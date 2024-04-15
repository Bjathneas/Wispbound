//
// Created by benajah on 4/14/24.
//
#include "Elementa/utils/File.h"
#include "Elementa/utils/Logger.h"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace Elementa {
    std::string fileToString(const char *path) {
        if (!std::filesystem::exists(path)) {
            CRITICAL("File[" + std::string(path) + "] Does Not Exist");
            exit(EXIT_FAILURE);
        }

        std::fstream file(path, std::ios_base::in);

        std::stringstream file_stream;
        file_stream << file.rdbuf();

        return file_stream.str();
    }
}