#include "console.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>

Console::Console() {
    std::cout << "Veuillez entrer le chemin du fichier source : ";
    std::getline(std::cin, filename);

    std::cout << "Veuillez entrer le nom du dossier de destination : ";
    std::getline(std::cin, destinationDir);
}

std::string Console::get_sf(){
    return filename;
}

std::string Console::get_df(){
    return destinationDir;
}

void Console::createDirectory() {
    try {
        if (std::filesystem::create_directory(destinationDir)) {
            std::cout << "Dossier cree : " << destinationDir << std::endl;
        } else {
            std::cout << "Le dossier existe deja." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors de la creation du dossier : " << e.what() << std::endl;
    }
}



