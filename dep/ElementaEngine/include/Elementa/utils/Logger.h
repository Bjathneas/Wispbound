//
// Created by benajah on 4/7/24.
//

#ifndef WISPBOUND_LOGGER_H
#define WISPBOUND_LOGGER_H

#include <filesystem>

#define __FILENAME__ std::filesystem::path( __FILE__ ).filename().c_str()

#define INFO( message ) Elementa::log( "INFO" , __FILENAME__, __LINE__, message )
#define WARN( message ) Elementa::log( "WARN" , __FILENAME__, __LINE__, message )
#define CRITICAL( message ) Elementa::log( "CRITICAL" , __FILENAME__, __LINE__, message )

#ifdef ELEMENTA_DEBUG_MODE
#define DEBUG( message ) Elementa::log( "DEBUG" , __FILENAME__, __LINE__, message )
#else
#define DEBUG( message )
#endif

#include <string>
#include <fstream>

namespace  Elementa {
    extern std::fstream log_file;

    void log(const char* level, const char* file, int line, const std::string& message);

    std::string getCurrentTimeString();
}

#endif //WISPBOUND_LOGGER_H
