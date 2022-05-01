#ifndef METEOR_H
#define METEOR_H

#define N_METEOR 10;

#include "utils.h"
#include "scene.h"

typedef struct Meteors{
    vec3 position;
    vec3 rotation;
    vec3 rotation_speed;
    float angle;
    float speed;
    int direction;
}Meteors;

#endif