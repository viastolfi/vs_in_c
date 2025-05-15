#ifndef HITBOX_H
#define HITBOX_H

#include "raylib.h"

typedef struct hitbox_engine hitbox_engine;

typedef void (*hitbox_event_callback) (hitbox_engine* self, hitbox_engine* other);

struct hitbox_engine
{
    Rectangle rect;
    bool is_trigger;
    int id;

    bool was_colliding_last_frame;

    hitbox_event_callback on_enter;
    hitbox_event_callback on_stay;
    hitbox_event_callback on_exit;
};

inline static void update_hitbox(hitbox_engine* self, hitbox_engine* others[], int other_count) {
    for (int i = 0; i < other_count; i++) {
        hitbox_engine* other = others[i];

        if (self == other) continue; // skip self

        bool is_colliding = CheckCollisionRecs(self->rect, other->rect);

        if (is_colliding && !self->was_colliding_last_frame) {
            // Enter event
            if (self->on_enter) self->on_enter(self, other);
        }
        else if (is_colliding && self->was_colliding_last_frame) {
            // Stay event
            if (self->on_stay) self->on_stay(self, other);
        }
        else if (!is_colliding && self->was_colliding_last_frame) {
            // Exit event
            if (self->on_exit) self->on_exit(self, other);
        }

        self->was_colliding_last_frame = is_colliding;
    }
}


#endif // HITBOX_H
