#include "food.h"

void init_food_item(food_item* i, Vector2 pos)
{  
    i->rb = (rigid_body) {0};
    
    i->rb.pos = pos;
    i->rb.texture = LoadTexture("./assets/items/foods/Beaf.png");
    i->rb.frameRec = (Rectangle) {i->rb.pos.x, i->rb.pos.y, i->rb.texture.width, i->rb.texture.height};
    i->rb.hitbox = (hitbox_engine) {0};
    i->rb.hitbox.rect = i->rb.frameRec;
    i->rb.hitbox.id = 4;

    i->is_magneted = false;
}

void update_food_item(food_item* f, monkey_actor* m)
{
    Vector2 direction = Vector2Subtract(m->rb.pos, f->rb.pos);
    if(!f->is_magneted)
    {
        float distance = Vector2Length(direction);

        if(distance < 100.0f)
            f->is_magneted = true;
    }
    else
    {
        direction = Vector2Scale(Vector2Normalize(direction), MAGNET_SPEED * GetFrameTime());
        f->rb.pos = Vector2Add(f->rb.pos, direction); 
    }
}
