#ifndef ENNEMY_H
#define ENNEMY_H

#include "raylib.h"
#include "../engine/rigidBody.h"
#include "../engine/hitbox.h"

typedef struct
{
    rigid_body rb;
    hitbox_engine hurtbox;
} ennemy_actor;

void load_texture_ennemy(ennemy_actor* e);
void get_it_by_projectile(hitbox_engine *self, hitbox_engine *other);
void unused_handler(hitbox_engine* self, hitbox_engine *other);

#endif // ENNEMY_H
