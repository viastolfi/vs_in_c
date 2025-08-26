#include "raylib.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "actors/monkey.h"
//#include "actors/ennemy.h"
#include "constants.h"
#include "engine/hitbox.h"
//#include "items/projectile.h"
//#include "items/food.h"
//#include "types.h"
#include "collectible.h"

#define DA_LIB_IMPLEMENTATION
#include "./data_structures/da.h"

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "vsc");

    collectible c = init_collectible(init_rigidBody((Vector2) {20, 20}), "assets/items/foods/Beaf.png");

    //monkey_actor m = {0};
    //ennemy_actor e = {0};
    //food_item f = {0};

    //int frameCounter = 0, framePerSecond = 8;
    //projectiles projs = {0};

    /*
    // load monkey actor
    {
        m.currentAnimation = (animation_list) IDLE;
        m.rb.frameRec = (Rectangle) {0.0f, 0.0f, 0.0f, 0.0f};

        load_texture_monkey(&m);
    }

    // load ennemy actor
    {
        load_texture_ennemy(&e);
    }

    Vector2 food_pos = (Vector2) {500.0f, 500.0f};
    init_food_item(&f, (Vector2) food_pos);

    Texture2D proj_texture = load_texture_projectile();

    hitbox_engine* hitboxes[] = {&(m.rb.hitbox), &(e.rb.hitbox)};
    */
    SetTargetFPS(60);
   
    while (!WindowShouldClose())
    {
        // UPDATE
        {
            /*
            update_monkey(&m);
            update_food_item(&f, &m);
            for(size_t i = 0; i < projs.count; ++i)
            {
                update_projectile(&(projs.items[i]));
                if (projs.items[i]->rb.pos.x > WIDTH)
                {
                    da_remove(&projs, i);
                }
                
            }

            frameCounter++;
            if(frameCounter >= (60/framePerSecond))
            {
                frameCounter = 0;
                update_monkey_animation(&m);
                projectile_item* p = (projectile_item*) malloc(sizeof(projectile_item));
                init_projectile(p, m.rb.pos, proj_texture);
                da_append(&projs, p); 
            }

            update_hitbox(&(m.rb.hitbox), hitboxes, 2);
            projectiles hitters = {0};
            update_hitbox_with_da(&(e.hurtbox), &projs, &hitters);
            da_free(&hitters);
            */
        }
    
        // DRAW
        {
            BeginDrawing();
            
            ClearBackground(RAYWHITE);

            /*
            DrawTextureRec(e.rb.texture, e.rb.frameRec, e.rb.pos, WHITE);
            DrawRectangleLinesEx(e.rb.hitbox.rect, 1, BLUE);

            DrawTextureRec(m.rb.texture, m.rb.frameRec, m.rb.pos, WHITE);
            DrawRectangleLinesEx(m.rb.hitbox.rect, 1, LIME);

            DrawTextureRec(f.rb.texture, f.rb.frameRec, f.rb.pos, WHITE);

            da_foreach(projectile_item, it, &projs)
            {
                DrawTextureRec(it->rb.texture, it->rb.frameRec, it->rb.pos, WHITE);
                DrawRectangleLinesEx(it->rb.hitbox.rect, 1, LIME);
            }
            */

            EndDrawing();
        }
    }

    CloseWindow();

    return 0;
}
