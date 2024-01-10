#include <time.h>
#include "jeu.h"
#include "ennemie.h"


#ifndef BOMBERMAN_CLION_MAP_H
#define BOMBERMAN_CLION_MAP_H

typedef char Map[MAP_HAUTEUR][MAP_LONGUEUR];
void initialiserMap(Map map);
void faireVivreMap(Map map, Ennemies ennemies, player *player, Bombe *bombe);
void afficherMap(Map map, Ennemies ennemies, player *player);

#endif //BOMBERMAN_CLION_MAP_H
