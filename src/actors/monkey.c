#include "monkey.h"

void update_monkey_hitbox(monkey_actor* m)
{
    m->rb.hitbox.rect.x = m->rb.pos.x;
    m->rb.hitbox.rect.y = m->rb.pos.y;
    m->rb.hitbox.rect.width = m->rb.frameRec.width;
    m->rb.hitbox.rect.height = m->rb.frameRec.height;
}

void update_monkey(monkey_actor* m)
{
    if(IsKeyDown(KEY_UP)) 
    {
        m->rb.pos.y -= MONKEY_SPEED; 
        if(m->rb.pos.y < 0) m->rb.pos.y = 0;
        if(m->currentAnimation != WALK_UP)
        {
            m->currentFrame = 0;
            m->rb.texture = m->textures[1];
            m->currentAnimation = WALK_UP;
        }
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        m->rb.pos.y += MONKEY_SPEED;
        if(m->rb.pos.y + m->textures[1].height/4 > HEIGHT) m->rb.pos.y = HEIGHT;
        if(m->currentAnimation != WALK_DOWN)
        {
            m->currentFrame = 0;
            m->rb.texture = m->textures[1];
            m->currentAnimation = WALK_DOWN;
        }
    }
    else if(IsKeyDown(KEY_LEFT))
    {
        m->rb.pos.x -= MONKEY_SPEED;
        if(m->rb.pos.x < 0) m->rb.pos.x = 0;
        if(m->currentAnimation != WALK_LEFT)
        {
            m->currentFrame = 0;
            m->rb.texture = m->textures[1];
            m->currentAnimation = WALK_LEFT;
        }
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        m->rb.pos.x += MONKEY_SPEED;
        if(m->rb.pos.x + m->textures[1].width / 4 > WIDTH) m->rb.pos.y = WIDTH;
        if(m->currentAnimation != WALK_RIGHT)
        {
            m->currentFrame = 0;
            m->rb.texture = m->textures[1];
            m->currentAnimation = WALK_RIGHT;
        }
    }
    else if(m->currentAnimation != IDLE)
    {
        m->currentFrame = 0;
        m->currentAnimation = IDLE; 
        m->rb.texture = m->textures[0];
    }

    update_monkey_hitbox(m);
}

void load_texture_monkey(monkey_actor* m)
{
    m->textures[0] = LoadTexture("./assets/monkey/Idle.png");
    m->textures[1] = LoadTexture("./assets/monkey/Walk.png");
    m->rb.texture = m->textures[0];
    m->currentFrame = 0;
    m->currentAnimation = IDLE;
    m->rb.hitbox = (hitbox_engine) {0};

    m->rb.hitbox.rect = (Rectangle) {0};
    m->rb.hitbox.id = 0;
    m->rb.hitbox.is_trigger = true;
    m->rb.hitbox.was_colliding_last_frame = false;
    m->rb.hitbox.on_enter = on_hitbox_entered_monkey;
    m->rb.hitbox.on_stay = NULL;
    m->rb.hitbox.on_exit = NULL;
}

void on_hitbox_entered_monkey(hitbox_engine* self, hitbox_engine* other)
{
    TraceLog(LOG_INFO, "HITBOX ENTERED");
}

void update_monkey_animation(monkey_actor* m)
{
    m->currentFrame++;
    if(m->currentFrame >= 4) m->currentFrame = 0;

    if(m->currentAnimation == IDLE)
    {
        m->rb.frameRec.width = m->textures[0].width/4;
        m->rb.frameRec.height = m->textures[0].height;
        m->rb.frameRec.y = (float)m->textures[0].height;
        m->rb.frameRec.x = (float)m->textures[0].width/4*(float)m->currentFrame;
    }
    else
    {
        m->rb.frameRec.width = m->textures[1].width/4;
        m->rb.frameRec.height = m->textures[1].height/4;
        m->rb.frameRec.y = (float)m->textures[1].height/4*m->currentFrame;
        m->rb.frameRec.x = (float)m->textures[1].width/4*m->currentAnimation;
    }
}
