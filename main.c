#include <stdio.h>
#include "map.h"
#include "ennemie.h"
#include "player.h"
#include "bombe.h"
#include "jeu.h"

int main() {
    Map map;
    Ennemies ennemies;
    player player;
    Bombe bombe;
    initialiserMap(map);
    initialiserPlayer(map, &player);
    initialiserEnnemies(ennemies, map);

    faireVivreMap(map,ennemies, &player, &bombe);
    scanf(" ");
    return 0;
}
