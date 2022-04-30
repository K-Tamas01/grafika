#ifndef METEOR_H
#define METEOR_H

#define N_METEOR 50;

#include "utils.h"

typedef struct Meteors{
    vec3 position;
    vec3 rotation;
    vec3 rotation_speed;
    float angle;
    float speed;
    int direction;
}Meteors;

void init_meteors();

void update_rotation();

#endif