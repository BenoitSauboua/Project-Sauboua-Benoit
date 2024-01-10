#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BOMBERMAN2_JEU_H
#define BOMBERMAN2_JEU_H

#define MAP_HAUTEUR 15
#define MAP_LONGUEUR 15
#define MAP_MUR_SOLIDE 'X'
#define MAP_SOL ' '
#define MAP_DENSITE 5
#define MAP_MUR_CASSABLE 'O'

#define NOMBRE_ENNEMIES 10
#define SKIN_ENNEMIE 1

#define BOMB 6

#define MAP_MORT 43

#define MAP_PLAYER 2

typedef enum Etat {VIVANT, MORT};

typedef struct player{
    int x, y;
    enum Etat etat;
} player;

typedef struct Ennemie{
    int x, y;
    enum Etat etat;
} Ennemie;

typedef struct Bombe{
    int x,y;
    enum Etat etat;
}Bombe;



typedef enum Direction {HAUT, DROITE, BAS, GAUCHE} Direction;


typedef Ennemie Ennemies[NOMBRE_ENNEMIES];
typedef Ennemie Ennemies[NOMBRE_ENNEMIES];

typedef char Map[MAP_HAUTEUR][MAP_LONGUEUR];


#endif //BOMBERMAN2_JEU_H

