#ifndef EXTENSION1_H
#define EXTENSION1_H

#include <vector>
#include <string>
#include <fstream>
#include "cell.h"
#include "grille.h"

class Celluleobs: public Grille{
private:
    int nb;
    cell& obstacle;
public:
    Celluleobs(cell& obstacle, int nb);

    cell& createobstacle();

    void passer_a_generation_suivante();

    void generateGenerations(int generations, const std::string& destinationDir)

}