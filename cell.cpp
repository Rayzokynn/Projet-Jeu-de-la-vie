#include "cell.h"

Cell::Cell() : alive(false) {}              // Par défaut, une cellule est morte
Cell::Cell(bool state) : alive(state) {}    // Initialiser avec un état donné

bool Cell::isAlive() const {
    return alive;
}

void Cell::setAlive(bool state) {
    alive = state;
}

void Cell::toggle() {
    alive = !alive;                         // Inverser l'état
}


