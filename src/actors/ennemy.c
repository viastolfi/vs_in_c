#include "ennemy.h"

void load_texture_ennemy(ennemy_actor* e)
{
    e->rb.texture = LoadTexture("./assets/monkey/Idle.png");
    e->rb.frameRec = (Rectangle) {0.0f, 0.0f, (float)e->rb.texture.width/4, (float)e->rb.texture.height};
    e->rb.pos = (Vector2) {100.0f, 100.0f};
    e->rb.hitbox = (hitbox_engine) {0};

    e->rb.hitbox.rect = (Rectangle) {e->rb.pos.x, e->rb.pos.y, (float)e->rb.texture.width/4, (float)e->rb.texture.height};
    e->rb.hitbox.id = 1;

    e->hurtbox = (hitbox_engine) {0};
    e->hurtbox.rect = e->rb.hitbox.rect;
    e->hurtbox.id = 4;
    e->hurtbox.is_trigger = true;
    e->hurtbox.was_colliding_last_frame = false;
    e->hurtbox.on_enter = get_it_by_projectile;
    e->hurtbox.on_stay = unused_handler;
    e->hurtbox.on_exit = unused_handler;
}

void unused_handler(hitbox_engine* self, hitbox_engine *other) {}

void get_it_by_projectile(hitbox_engine *self, hitbox_engine *other)
{
    TraceLog(LOG_INFO, "ENNEMY HITBOX ENTERED");
}
