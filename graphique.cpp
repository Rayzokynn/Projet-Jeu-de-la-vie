#include "graphique.h"
#include <SFML/Graphics.hpp>
#include <iostream>

const int cellSize = 10;                                                        // Taille de chaque cellule en pixels


Graphique::Graphique(Grille& g, int d) : grille(g), delay(d), isPaused(false) {
    if (cellSize <= 1) {
        std::cerr << "Erreur : La taille des cellules (cellSize) doit être > 1." << std::endl;
        return;
    }

    int width = grille.getwidth() * cellSize;
    int height = grille.getheight() * cellSize;

    if (width <= 0 || height <= 0) {
        std::cerr << "Dimensions de la fenêtre invalides : " << width << "x" << height << std::endl;
        return;
    }

    std::cout << "Dimensions de la fenêtre : " << width << "x" << height << std::endl;
    window.create(sf::VideoMode(width, height), "Jeu de la Vie");
}

void Graphique::renderGrid(sf::RenderWindow &window) {
    window.clear();                                                             // Effacer la fenêtre avant chaque rendu
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));    // Cellule

    for (int x = 0; x < grille.getwidth(); ++x) {
        for (int y = 0; y < grille.getheight(); ++y) {
            if (!grille.isValidIndex(x, y)) {
                std::cerr << "Erreur : Indices hors limites détectés dans renderGrid (" 
                          << x << ", " << y << ")" << std::endl;
                continue;
            }

            if (grille.getCell(x, y).isAlive()) {
                cell.setFillColor(sf::Color::White);                            // Cellule vivante en blanc
            } else {
                cell.setFillColor(sf::Color::Black);                            // Cellule morte en noir
            }
            cell.setPosition(x * cellSize, y * cellSize);
            window.draw(cell);                                                  // Dessiner la cellule
        }
    }

    window.display();                                                           // Afficher le rendu à l'écran
}

void Graphique::runSimulation() {
    sf::Clock clock;                                                            // Horloge pour gérer le temps entre les générations

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Fermer la fenêtre
            }

            // Pause / Reprise avec la touche Espace
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                isPaused = !isPaused;
            }

            // Placement de motifs avec les touches b/g/s
            if (event.type == sf::Event::KeyPressed) {
                int mouseX = sf::Mouse::getPosition(window).x / cellSize; // Convertir position souris en coordonnées grille
                int mouseY = sf::Mouse::getPosition(window).y / cellSize;

                if (grille.isValidIndex(mouseY, mouseX)) { // Vérifier que la position est valide
                    if (event.key.code == sf::Keyboard::B) {
                        grille.ajouterBlinker(mouseY, mouseX);
                    } else if (event.key.code == sf::Keyboard::G) {
                        grille.ajouterGlider(mouseY, mouseX);
                    } else if (event.key.code == sf::Keyboard::S) {
                        grille.ajouterStructureStable(mouseY, mouseX);
                    }
                }
            }
        }

        if (!isPaused && clock.getElapsedTime().asMilliseconds() >= delay) {
            grille.passer_a_generation_suivante(); // Passer à la génération suivante
            renderGrid(window); // Afficher la nouvelle grille
            clock.restart();
        } else if (isPaused) {
            renderGrid(window); // Mise à jour de l'affichage même en pause
        }
    }

}

