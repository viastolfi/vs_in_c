#ifndef TYPES_H
#define TYPES_H

#define DA_LIB_IMPLEMENTATION
#include "data_structures/da.h"
#include "items/projectile.h"

typedef struct
{
    projectile_item** items;
    size_t count;
    size_t capacity;
} projectiles;

#endif // TYPES_H
