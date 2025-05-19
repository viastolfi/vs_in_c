#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../engine/rigidBody.h"
#include "raylib.h"

#define PROJECTILE_SPEED 5

typedef struct
{
    rigid_body rb;
} projectile_item;

void init_projectile(projectile_item* p, Vector2 pos, Texture2D texture);
void update_projectile(projectile_item* p);
Texture2D load_texture_projectile();

#endif // PROJECTILE_H
