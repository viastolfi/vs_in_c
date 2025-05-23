#include "projectile.h"

Texture2D load_texture_projectile()
{
    return LoadTexture("./assets/projectile/Arrow.png");
}

void init_projectile(projectile_item* p, Vector2 pos, Texture2D texture)
{
    p->rb = (rigid_body) {0};

    p->rb.pos = pos;
    p->rb.texture = texture;
    p->rb.frameRec = (Rectangle) {p->rb.pos.x, p->rb.pos.y, p->rb.texture.width, p->rb.texture.height};
    p->rb.hitbox = (hitbox_engine) {0};
    p->rb.hitbox.rect = p->rb.frameRec;
    p->rb.hitbox.id = 3;
}
   
void update_projectile(projectile_item* p) 
{
    p->rb.pos.x += PROJECTILE_SPEED; 
    p->rb.hitbox.rect = (Rectangle) {p->rb.pos.x, p->rb.pos.y, p->rb.texture.width, p->rb.texture.height};
}
