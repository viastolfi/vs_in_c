#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "raylib.h"
#include "../engine/hitbox.h"

typedef struct
{
    Vector2 pos; 
    hitbox_engine hitbox;
    Texture2D texture;
    Rectangle frameRec;
} rigid_body;

#endif // RIGIDBODY_H
