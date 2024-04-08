//
// Created by benajah on 4/7/24.
//

#include <cstdio>

#include "Elementa/utils/Logger.h"

namespace Elementa {

    std::fstream log_file;

    void log(const char* level, const char* file, int line, const std::string& message) {
        //check if log_file is opened, if not open it
        if(!log_file.is_open()) {
            if(!std::filesystem::exists("logs"))
                std::filesystem::create_directories("logs");

            //Check that current logs are at the limit of 5
            if(std::filesystem::exists("logs/latest.log")) {
                //open latest log and get the date of the first log and rename log to that
                std::ifstream latest_log("logs/latest.log", std::ios_base::in);
                std::string new_log;
                std::getline(latest_log, new_log);
                latest_log.close();
                new_log = "logs/" + new_log.substr(0, 24) + ".log";
                rename(std::filesystem::path("logs/latest.log"), new_log);
            }

            log_file.open("logs/latest.log", std::ios_base::out);
        }
        std::string log_str = getCurrentTimeString() + "[" +
                file + ":" + std::to_string(line) + "] " + level +
                ": " + message + "\n";
        printf("%s", log_str.c_str());

        log_file << log_str;
    }

    std::string getCurrentTimeString() {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string time_string = std::ctime(&time);
        time_string.replace(time_string.end() - 1, time_string.end(), "");
        return time_string;
    }
}