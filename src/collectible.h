#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "engine/sprite2D.h"
#include "engine/rigidBody.h"

typedef struct
{
    rigid_body_engine rb;
} collectible;

inline static collectible init_collectible(rigid_body_engine rb, const char* sprite_path)
{
    collectible c = {0}; 
    sprite2D_engine sp = load_sprite(sprite_path);
    rigidBody_attach_sprite2D(&rb, &sp);
    c.rb = rb;
    return c;
}

#endif // COLLECTIBLE_H
