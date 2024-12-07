#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>

#ifndef CONTROL_H
#define CONTROL_H

class Console {
private:
    std::string filename;
    std::string destinationDir;

public:
    Console();

    std::string get_sf();

    std::string get_df();

    void createDirectory();

};

#endif

