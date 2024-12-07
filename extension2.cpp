#include "grille.h"
#include "graphique.h"
#include <iostream>
#include <fstream>
#include <filesystem>

//Celluleobs::Celluleobs():{}
Celluleobs::Celluleobs(cell& obstacle, int nb): obstacle(obstacle), nb(nb){
        std::cout<<"Combien de cellules obstacles voulez-vous creer?"<<endl;
        std::cin>>nb;
}

Cell& Celluleobs::createobstacle(){
    std::cout<<"Veuillez choisir l'emplacement de ces cellules"<<endl;
    for (i=0; i<nb; i++){
        std::cin>>x;
        std::cin>>y;
        obstacle=grid[x][y];
        returreturn obstacle;n obstacle;
    }  
}

void Celluleobs::passer_a_generation_suivante() {
    std::vector<std::vector<Cell>> newGrid = grid;                                                              // Copie de la grille actuelle

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            int voisins = compter_voisins(x, y);
            bool vivante = grid[x][y].isAlive();

            if(obstacle){
                newGrid[x][y]=grid[x][y];
            }
            else if (vivante) {
                newGrid[x][y].setAlive(voisins == 2 || voisins == 3);                                           // Une cellule vivante reste vivante si elle a 2 ou 3 voisins vivants
            } else {
                newGrid[x][y].setAlive(voisins == 3);                                                           // Une cellule morte devient vivante si elle a exactement 3 voisins vivants
            } 
        }
    }

    grid = newGrid;                                                                                             // Mise à jour de la grille avec la nouvelle génération
}

void Celluleobs::sauvegarder_generation(int generation, const std::string& destinationDir) {
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

void Celluleobs::generateGenerations(int generations, const std::string& destinationDir) {
    for (int i = 0; i < generations; ++i) {
        sauvegarder_generation(i, destinationDir);
        passer_a_generation_suivante();
    }
}
