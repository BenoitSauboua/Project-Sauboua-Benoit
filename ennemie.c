#include <stdlib.h>
#include "ennemie.h"
#include "jeu.h"

void initialiserEnnemies(Ennemies ennemies, Map map) {
    int i;
    for (i=0; i < NOMBRE_ENNEMIES; i++) {
        initialiserEnnemie(&ennemies[i], map);
    }
}

void initialiserEnnemie(Ennemie *ennemie, Map map) {
    int x, y;
    do {
        x = rand() % MAP_LONGUEUR;
        y = rand() % MAP_HAUTEUR;
    } while (map[y][x] != MAP_SOL);
    (*ennemie).x = x;
    (*ennemie).y = y;
    (*ennemie).etat = VIVANT;

}

Ennemie *ennemiePresent(Ennemies ennemies, int x, int y) {
    int i=0;
    while( ((ennemies[i].x != x) || (ennemies[i].y != y)) && (i < NOMBRE_ENNEMIES) ) {
        i++;
    }
    if (i >= NOMBRE_ENNEMIES) {
        return NULL;
    } else {
        return &ennemies[i];
    }
}

void deplacerEnnemie(Ennemie *ennemie, Map map) {
    int x,y;
    Direction direction;
    direction = rand()%4;
    x = (*ennemie).x;
    y = (*ennemie).y;
    switch (direction) {
        case HAUT :
            y--;
            break;
        case DROITE :
            x++;
            break;
        case BAS :
            y++;
            break;
        case GAUCHE :
            x--;
            break;
    }
    if (map[y][x] == MAP_SOL) {
        (*ennemie).x = x;
        (*ennemie).y = y;
    }
}

void deplacerEnnemies(Ennemies ennemies, Map map) {
    int i;
    for (i=0; i < NOMBRE_ENNEMIES; i++) {
        if (ennemies[i].etat == VIVANT) {
            deplacerEnnemie(&ennemies[i], map);
        }
    }
}