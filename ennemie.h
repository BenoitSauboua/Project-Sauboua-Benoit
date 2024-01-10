#include "jeu.h"

#ifndef BOMBERMAN1_ENNEMIE_H

void initialiserEnnemies(Ennemies ennemies, Map map);
void initialiserEnnemie(Ennemie *ennemie, Map map);
Ennemie *ennemiePresent(Ennemies ennemies, int x, int y);
void deplacerEnnemie(Ennemie *ennemie, Map map);
void deplacerEnnemies(Ennemies ennemies, Map map);

#endif //BOMBERMAN1_ENNEMIE_H