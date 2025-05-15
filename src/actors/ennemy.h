#ifndef ENNEMY_H
#define ENNEMY_H

#include "raylib.h"
#include "../engine/rigidBody.h"

typedef struct
{
    rigid_body rb;
} ennemy_actor;

void load_texture_ennemy(ennemy_actor* e);

#endif // ENNEMY_H
