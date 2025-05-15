#include "ennemy.h"

void load_texture_ennemy(ennemy_actor* e)
{
    e->rb.texture = LoadTexture("./assets/monkey/Idle.png");
    e->rb.frameRec = (Rectangle) {0.0f, 0.0f, (float)e->rb.texture.width/4, (float)e->rb.texture.height};
    e->rb.pos = (Vector2) {100.0f, 100.0f};
    e->rb.hitbox = (hitbox_engine) {0};

    e->rb.hitbox.rect = (Rectangle) {e->rb.pos.x, e->rb.pos.y, (float)e->rb.texture.width/4, (float)e->rb.texture.height};
    e->rb.hitbox.id = 1;
}

