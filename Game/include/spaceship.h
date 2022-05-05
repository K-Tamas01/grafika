#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "utils.h"
#include "scene.h"

#include "stdbool.h"

typedef struct Ship
{
    vec3 position;
    float rotate;
    float speed;
    bool bumb;
} Ship;

#endif