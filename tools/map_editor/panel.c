#include <SDL2/SDL.h>
#include "panel.h"
#include "../../defs.h"
#include "../../shared/sprite.h"
#include "../../shared/logger.h"

SpritePanel* init_panel(SpriteMap* sprite_map) {
    SpritePanel* panel = malloc(sizeof(SpritePanel));
    panel->rect = (SDL_Rect){ 0, 0, PANEL_WIDTH, SCREEN_HEIGHT };
    panel->sprite_count = 0;
    panel->selected_sprite = NULL;
    panel->sprites = malloc(sizeof(SpriteCoord) * sprite_map->count);

    GDEBUG("count: %d", sprite_map->count);

    int xOffset = 5;
    int yOffset = 5;

    for (int i = 0; i < sprite_map->count; i++) {
        if (panel->sprite_count >= PANEL_COLS * PANEL_ROWS) break;

        Sprite* sprite = &sprite_map->sprites[i];
        
        // Check if the sprite name ends with _f followed by a number
        char* last_underscore = strrchr(sprite->name, '_');
        if (last_underscore == NULL || *(last_underscore + 1) != 'f' || !isdigit(*(last_underscore + 2))) {
            panel->sprites[panel->sprite_count]->sprite = sprite;
            panel->sprites[panel->sprite_count]->x = xOffset;
            panel->sprites[panel->sprite_count]->y = yOffset;
            panel->sprite_count++;
            GINFO("Added sprite: %s at %d, %d, new count: %d", sprite->name, xOffset, yOffset, panel->sprite_count);

            xOffset += SPRITE_WIDTH + PANEL_PADDING;

            if (xOffset >= PANEL_WIDTH) {
                xOffset = 0;
                yOffset = yOffset + SPRITE_HEIGHT + PANEL_PADDING;
            }
        }

    }

    return panel;
}

Sprite* find_sprite_panel(SpriteCoord** coords, int x, int y) {
    GDEBUG("x, y: %d, %d", x, y);
    int buf = 6;
    //okay i really hate this
    for (int i = 0; i < MAX_SPRITES; i++) {
        GDEBUG("testing: %d, %d", coords[i]->x, coords[i]->y);
    }

    return NULL;
}

void render_panel(SDL_Renderer* renderer,
                  SDL_Texture* spritesheet,
                  SpritePanel* panel,
                  Sprite* selected_sprite) {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &panel->rect);

    for (int i = 0; i < panel->sprite_count; i++) {
        Sprite* sprite = panel->sprites[i]->sprite;
        int x = panel->sprites[i]->x;
        int y = panel->sprites[i]->y;

        SDL_Rect dest = { x, y, SPRITE_WIDTH, SPRITE_HEIGHT };

        SDL_RenderCopy(renderer, spritesheet, &sprite->rect, &dest);

        if (sprite == selected_sprite) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &dest);
        }
    }
}