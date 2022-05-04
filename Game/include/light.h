#ifndef LIGHT_H
#define LIGHT_H

#define LIGHT 4

#include "scene.h"

typedef struct Light{
    float ambient_light[LIGHT];
    float diffuse_light[LIGHT];
    float specular_light[LIGHT];
    float position[LIGHT];
}Light;

#endif