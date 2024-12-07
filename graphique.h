#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "grille.h" 

class Graphique {
private:
    Grille& grille;                     // Constructeur
    sf::RenderWindow window;            // Fenêtre pour afficher le jeu
    int delay;                          // Délai entre chaque génération (en millisecondes)
    bool isPaused;
    
public:
    Graphique(Grille& g, int d);
    void renderGrid(sf::RenderWindow &window);
    void runSimulation();
};

#endif 


