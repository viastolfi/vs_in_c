#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../engine/rigidBody.h"
#include "raylib.h"

#define PROJECTILE_SPEED 5

typedef struct
{
    rigid_body rb;
} projectile_item;

void init_projectile(projectile_item* p, Vector2 pos);
void update_projectile(projectile_item* p);

#endif // PROJECTILE_H
