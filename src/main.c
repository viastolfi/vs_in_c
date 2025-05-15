#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "actors/monkey.h"
#include "actors/ennemy.h"
#include "constants.h"
#include "engine/hitbox.h"

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "vsc");

    monkey_actor m = {0};
    ennemy_actor e = {0};
    int fps = 0;
    char* text = malloc(30);
    int frameCounter = 0, framePerSecond = 8;

    // load monkey actor
    {
        m.rb.pos = (Vector2) {350.0f, 280.0f};
        m.currentFrame = 0;
        m.currentAnimation = (animation_list) IDLE;
        m.rb.frameRec = (Rectangle) {0.0f, 0.0f, 0.0f, 0.0f};

        load_texture_monkey(&m);
    }

    // load ennemy actor
    {
        load_texture_ennemy(&e);
    }

    hitbox_engine* hitboxes[] = {&(m.rb.hitbox), &(e.rb.hitbox)};
    SetTargetFPS(60);
   
    while (!WindowShouldClose())
    {
        // UPDATE
        {
            fps = GetFPS();
            sprintf(text, "%s%d", "FPS : ", fps);
            
            update_monkey(&m);
            frameCounter++;
            if(frameCounter >= (60/framePerSecond))
            {
                frameCounter = 0;
                update_monkey_animation(&m);
            }

            update_hitbox(&(m.rb.hitbox), hitboxes, 2);
        }
    
        // DRAW
        {
            BeginDrawing();
            
            ClearBackground(RAYWHITE);

            DrawTextureRec(e.rb.texture, e.rb.frameRec, e.rb.pos, WHITE);
            DrawRectangleLinesEx(e.rb.hitbox.rect, 1, BLUE);

            DrawTextureRec(m.rb.texture, m.rb.frameRec, m.rb.pos, WHITE);
            DrawRectangleLinesEx(m.rb.hitbox.rect, 1, LIME);


            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}
