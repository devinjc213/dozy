#ifndef TILESHEET_H
#define TILESHEET_H

#include <SDL2/SDL.h>

typedef enum {
    ABANDONED_MINES,
    CELLAR_DOORS,
    CELLAR,
    DARK_CASTLE_ANIMATED,
    DARK_CASTLE,
    DARK_CASTLE_PURPLE_ANIMATED,
    DARK_CASTLE_PURPLE,
    EXTRAS,
    FOREST_FALL,
    FOREST_SPRING,
    FOREST_SUMMER,
    FOREST_WINTER,
    FORTRESS,
    FORTRESS_WINTER,
    FROZEN_CAVES,
    GRASSLANDS_FALL,
    GRASSLANDS_SPRING,
    GRASSLANDS_SUMMER,
    GRASSLANDS_WINTER,
    GROUNDS,
    HOUSES,
    HOUSES_WINTER,
    INTERIOR,
    MAGMA_DUNGEON,
    MAGMA_DUNGEON_WARM,
    MOUNTAINS_2,
    MOUNTAINS_2_WINTER,
    MOUNTAINS,
    MOUNTAINS_WINTER,
    VILLAGE,
    VILLAGE_WINTER
} tilesheet_t;

SDL_Texture* load_tilesheet(SDL_Renderer* renderer, tilesheet_t filename);

void free_tilesheet(SDL_Texture* tilesheet);

#endif
