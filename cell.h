#ifndef CELL_H
#define CELL_H

class Cell {
private:
    bool alive;                                         // État de la cellule : true = vivante, false = morte

public:
    Cell();                                             // Par défaut, une cellule est morte
    explicit Cell(bool state);                          // Initialiser avec un état donné

    bool isAlive() const;                               // Vérifier si la cellule est vivante
    void setAlive(bool state);                          // Définir l'état de la cellule
    void toggle();                                      // Inverser l'état de la cellule
};

#endif
