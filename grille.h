#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <string>
#include <fstream>
#include "cell.h"

class Grille {
private:
    std::vector<std::vector<Cell>> grid;                                        // Grille de cellules
    int height, width;                                                          // Dimensions de la grille
    int compter_voisins(int x, int y);

public:
    Grille();
    Grille(int height, int width);

    void initializeGrille(const std::string& filename);
    void generateGenerations(int generations, const std::string& destinationDir);
    void passer_a_generation_suivante();
    void sauvegarder_generation(int generation, const std::string& destinationDir);
    void modeConsole(const std::string& filename, const std::string& destinationDir, int generations);
    void modeGraphique(const std::string& filename, int delay);
    void TestUnitaire(const std::string& filename, const std::string& destinationDir, int generations);
    void ajouterBlinker(int x, int y);
    void ajouterGlider(int x, int y);
    void ajouterStructureStable(int x, int y);

    bool isValidIndex(int x, int y) const;
    int getwidth();
    int getheight();
    Cell& getCell(int x, int y);
};

#endif
