#ifndef FOOD_H
#define FOOD_H

#define  MAGNET_SPEED 100

#include "raylib.h"
#include "raymath.h"
#include "../engine/rigidBody.h"
#include "../actors/monkey.h"

#include <math.h>
#include <stdbool.h>

typedef struct
{
    bool is_magneted;
    rigid_body rb;
} food_item;

void update_food_item(food_item* f, monkey_actor* m);
void init_food_item(food_item* i, Vector2 pos);

#endif // FOOD_H
