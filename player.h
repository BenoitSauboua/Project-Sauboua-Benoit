#include "map.h"
#include "jeu.h"
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

void initialiserPlayer(Map,player *p);
player *playerPresent(player *player, int x, int y);
#endif 