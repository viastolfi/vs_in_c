#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "raylib.h"
#include "hitbox.h"
#include "sprite2D.h"

typedef struct rigid_body_engine rigid_body_engine;

typedef void (*rigid_body_function) (rigid_body* self);

typedef struct
{
    Vector2 pos; 
    hitbox_engine* hitbox;
    sprite2D_engine* sprite;

    rigid_body_function rigid_body_draw;
} rigid_body_engine;

inline static rigid_body_engine init_rigidBody(Vector2 pos)
{
    rigid_body_engine rb = {0};
    rb.pos = pos;
    rb.hitbox = NULL;
    rb.sprite = NULL;
}

#define rigidBody_attach_sprite2D(rb, sp) (rb)->sprite = sp;

#endif // RIGIDBODY_H
