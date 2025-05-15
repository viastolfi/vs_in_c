#ifndef MONKEY_H
#define MONKEY_H

#include "raylib.h"
#include "../constants.h"
#include "rigidBody.h"
#include <stdio.h>

#define MONKEY_SPEED 2
#define ANIMATIONS_COUNT 2

typedef enum
{
    WALK_DOWN = 0,
    WALK_UP,
    WALK_LEFT,
    WALK_RIGHT,
    IDLE
} animation_list;

typedef struct
{
    rigid_body rb;
    animation_list currentAnimation;
    int currentFrame;
    Texture2D textures[ANIMATIONS_COUNT];
} monkey_actor;

void update_monkey_animation(monkey_actor* m);
void update_monkey(monkey_actor* m);
void load_texture_monkey(monkey_actor* m);
void on_hitbox_entered_monkey(hitbox_engine* self, hitbox_engine* other);

#endif // MONKEY_H
