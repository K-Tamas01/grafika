#ifndef METEOR_H
#define METEOR_H

#define N_METEOR 10;

#include "utils.h"
#include "scene.h"

#include <stdbool.h>

typedef struct Meteors{
    vec3 position;
    float angle;
    bool is_plus;
}Meteors;

#endif