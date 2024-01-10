#include <stdlib.h>
#include <stdio.h>
#include <synchapi.h>
#include <windows.h>
#include <time.h>
#include "bombe.h"

#include "jeu.h"
#include "map.h"
#include "player.h"

Bombe **b;
void initialiserMap(Map map){
    int x,y;
    srand(time(NULL));

    for(y=0; y < MAP_HAUTEUR; y++){
        for(x=0; x < MAP_LONGUEUR; x++) {

            if (x % 2 != 0 && y % 2 != 0) {
                map[x][y] = MAP_MUR_SOLIDE;
            }
            else if (rand() % NOMBRE_ENNEMIES == 0 && map[y][x] != MAP_MUR_SOLIDE & map[y][x] != MAP_MUR_CASSABLE) {
                map[x][y] = SKIN_ENNEMIE;
            }

            else if (rand() % MAP_DENSITE == 0 && map[y][x] != MAP_MUR_SOLIDE) {
                map[x][y] = MAP_MUR_CASSABLE;
            }
            else{
                map[x][y] = MAP_SOL;
            }
        }
        printf("\n");
    }
}

void afficherMap(Map map, Ennemies ennemies, player *player) {
    int x, y;
    system("CLS");
    printf("_________________");
    printf("\n");
    for(y=0; y < MAP_HAUTEUR; y++){

        for (int l =0; l<1; l++) {
            printf("|");
        }
        for(x=0; x < MAP_LONGUEUR; x++){
            if (playerPresent(player, x, y)) {
                printf("%c", MAP_PLAYER);
            } else {
                Ennemie *ennemie = ennemiePresent(ennemies, x, y);
                if (ennemie == NULL) {
                    printf("%c", map[y][x]);
                } else {
                    if ((*player).etat == MORT) {
                        printf("%c", MAP_MORT);
                    } else {
                        printf("%c", SKIN_ENNEMIE);
                    }
                }
            }
        }
        for (int l =0; l<1; l++) {
            printf("|");
        }
        printf("\n");
    }
    printf("|_______________|");
}

void faireVivreMap(Map map, Ennemies ennemies, player *player, Bombe *bombe) {
    int x,y;

    x = (*player).x;
    y = (*player).y;

    for(;;) {

        afficherMap(map, ennemies, player);
        deplacerEnnemies(ennemies, map);

        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            y--;
            if(map[x][y] == MAP_MUR_SOLIDE){
                y++;
                (*player).x = x;
                (*player).y = y;
            }

            else if(map[x][y] == MAP_MUR_CASSABLE){
                y++;
                (*player).x = x;
                (*player).y = y;

            }

            else if(map[y][x] == SKIN_ENNEMIE){
                exit(1);
            }
            else {
                (*player).x = x;
                (*player).y = y;
            }
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            x--;
            if(map[x][y] == MAP_MUR_SOLIDE){
                x++;
                (*player).x = x;
                (*player).y = y;

            }
            else if(map[x][y] == MAP_MUR_CASSABLE){
                x++;
                (*player).x = x;
                (*player).y = y;

            }
            else if(map[y][x] == SKIN_ENNEMIE){
                exit(1);
            }
            else{
                (*player).x = x;
                (*player).y = y;
            }

        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            y++;
            if (map[x][y] == MAP_MUR_SOLIDE) {
                    y--;
                    (*player).x = x;
                    (*player).y = y;
                }

            else if(map[x][y] == MAP_MUR_CASSABLE){
                y--;
                (*player).x = x;
                (*player).y = y;

            }
            else if(map[y][x] == SKIN_ENNEMIE) {
                exit(1);
            }
            else{
                (*player).x = x;
                (*player).y = y;
            }

        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            x++;
            if (map[x][y] == MAP_MUR_SOLIDE) {
                x--;
                (*player).x = x;
                (*player).y = y;

            }
            else if(map[x][y] == MAP_MUR_CASSABLE){
                x--;
                (*player).x = x;
                (*player).y = y;

            }
            else if(map[y][x] == SKIN_ENNEMIE) {
                exit(1);
            }

            else{
                (*player).x = x;
                (*player).y = y;
            }
            if (GetAsyncKeyState(VK_TAB) & 0x8000){
                initialiserBombe(x,y,map,bombe);
            }
        }

        if(map[y][x] == SKIN_ENNEMIE) {
            exit(1);
        }
        Sleep(150);
    }
}









