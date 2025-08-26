#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "raylib.h"

typedef struct
{
    const char* sprite_path;
    Texture2D texture;
} sprite2D_engine;

inline static sprite2D_engine load_sprite(const char* path)
{
    sprite2D_engine sp = {0};
    sp.sprite_path = path;
    sp.texture = LoadTexture(path);

    return sp;
}

#endif // SPRITE2D
