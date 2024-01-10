#include "jeu.h"
#include "bombe.h"

void initialiserBombe(int x , int y,Map map ,Bombe *bombe){
    (*bombe).x = x;
    (*bombe).y = y;
    map[y][x] = BOMB;
}

void boomBombe(Bombe *bombe,Map map){
    int x,y;
    x = (*bombe).x;
    y = (*bombe).y;
    map[y][x] = MAP_SOL;

}

Bombe *bombePresent(Bombe *bombe, int x, int y) {
    if (((*bombe).x != x) || ((*bombe).y != y)) {
        return NULL;
    } else {
        return bombe;
    }
}