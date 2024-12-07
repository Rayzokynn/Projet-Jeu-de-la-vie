#include "grille.h"
#include "graphique.h"
#include <iostream>
#include <fstream>
#include <filesystem>

Grille::Grille() : height(0), width(0) {}

Grille::Grille(int height, int width) : height(height), width(width) {}

void Grille::initializeGrille(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier '" << filename << "'" << std::endl;
        return;
    }

    file >> height >> width;
    std::cout << "Dimensions lues du fichier : " << height << "x" << width << std::endl;

    if (height <= 0 || width <= 0) {                                                                            // Vérifier que les dimensions sont valides
        std::cerr << "Dimensions invalides lues depuis le fichier : " << height << "x" << width << std::endl;
        return;
    }

    grid.resize(height, std::vector<Cell>(width));

    
    for (int i = 0; i < height; ++i) {                                                                          // Remplir la grille avec les états des cellules
        for (int j = 0; j < width; ++j) {  
            int state;
            if (!(file >> state)) {                                                                             // Vérifier que la lecture a bien fonctionné
                std::cerr << "Erreur de lecture des états des cellules à la position (" << i << ", " << j << ")" << std::endl;
                return;                                                                                         // Arrêter si la lecture échoue
            }

            grid[i][j].setAlive(state == 1);                                                                    // Si l'état est 1, la cellule est vivante, sinon elle est morte
        }
    }

    file.close();
}


int Grille::compter_voisins(int x, int y) {
    int count = 0;

    
    for (int dx = -1; dx <= 1; ++dx) {                                                                          // Parcourir les 8 voisins autour de la cellule (x, y)
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;                                                                   // Ignorer la cellule centrale

            int nx = x + dx;
            int ny = y + dy;

            
            if (nx >= 0 && nx < height && ny >= 0 && ny < width) {                                              // Vérifier que l'indice est valide avant d'accéder à la grille
                if (grid[nx][ny].isAlive()) count++;
            }
        }
    }

    return count;
}

void Grille::generateGenerations(int generations, const std::string& destinationDir) {
    for (int i = 0; i < generations; ++i) {
        sauvegarder_generation(i, destinationDir);
        passer_a_generation_suivante();
    }
}

void Grille::passer_a_generation_suivante() {
    std::vector<std::vector<Cell>> newGrid = grid;                                                              // Copie de la grille actuelle

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            int voisins = compter_voisins(x, y);
            bool vivante = grid[x][y].isAlive();

            if (vivante) {
                newGrid[x][y].setAlive(voisins == 2 || voisins == 3);                                           // Une cellule vivante reste vivante si elle a 2 ou 3 voisins vivants
            } else {
                newGrid[x][y].setAlive(voisins == 3);                                                           // Une cellule morte devient vivante si elle a exactement 3 voisins vivants
            }
        }
    }

    grid = newGrid;                                                                                             // Mise à jour de la grille avec la nouvelle génération
}


void Grille::sauvegarder_generation(int generation, const std::string& destinationDir) {
    std::string filename = destinationDir + "/generation_" + std::to_string(generation) + ".txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible de sauvegarder la génération dans '" << filename << "'" << std::endl;
        return;
    }

    for (const auto& row : grid) {
        for (const Cell& cell : row) {
            file << (cell.isAlive() ? 1 : 0) << " ";
        }
        file << std::endl;
    }

    file.close();
    std::cout << "Generation " << generation << " sauvegardée dans : " << filename << std::endl;
}

void Grille::modeConsole(const std::string& filename, const std::string& destinationDir, int generations) {
    std::filesystem::create_directory(destinationDir);
    initializeGrille(filename);
    generateGenerations(generations, destinationDir);
}

void Grille::modeGraphique(const std::string& filename, int delay) {
    initializeGrille(filename);
    Graphique graphique(*this, delay);
    graphique.runSimulation();
}

void Grille::TestUnitaire(const std::string& filename, const std::string& destinationDir, int generations) {
    std::filesystem::create_directory(destinationDir);
    initializeGrille(filename);
    generateGenerations(generations, destinationDir);
}

void Grille::ajouterBlinker(int x, int y) {
    if (isValidIndex(x, y) && isValidIndex(x, y - 1) && isValidIndex(x, y + 1)) {
        grid[x][y - 1].setAlive(true);
        grid[x][y].setAlive(true);
        grid[x][y + 1].setAlive(true);
    }
}

void Grille::ajouterGlider(int x, int y) {
    if (isValidIndex(x, y) && isValidIndex(x + 1, y + 1) && isValidIndex(x + 2, y + 2)) {
        grid[x][y + 1].setAlive(true);
        grid[x + 1][y + 2].setAlive(true);
        grid[x + 2][y].setAlive(true);
        grid[x + 2][y + 1].setAlive(true);
        grid[x + 2][y + 2].setAlive(true);
    }
}

void Grille::ajouterStructureStable(int x, int y) {
    if (isValidIndex(x, y) && isValidIndex(x + 1, y) && isValidIndex(x, y + 1) && isValidIndex(x + 1, y + 1)) {
        grid[x][y].setAlive(true);
        grid[x + 1][y].setAlive(true);
        grid[x][y + 1].setAlive(true);
        grid[x + 1][y + 1].setAlive(true);
    }
}


bool Grille::isValidIndex(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int Grille::getwidth(){ 
    return width; }
int Grille::getheight(){ 
    return height; }

Cell& Grille::getCell(int x, int y) {
    if (!isValidIndex(x, y)) {
        std::cerr << "Erreur : Indices hors limites (" << x << ", " << y << ")" << std::endl;
        throw std::out_of_range("Indices hors limites");
    }
    return grid[y][x];
}

