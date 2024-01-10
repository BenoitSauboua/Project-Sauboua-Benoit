#include "player.h"
#include "map.h"
#include "jeu.h"
#include <stdio.h>
#include <windows.h>

void initialiserPlayer(Map map , player *p){
    int x,y;
    (*p).x = 0;
    (*p).y = 0;
    (*p).etat = VIVANT;
}



player *playerPresent(player *player, int x, int y) {
    if (((*player).x != x) || ((*player).y != y)) {
        return NULL;
    } else {
        return player;
    }
}