#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "meteor.h"

#include <obj/model.h>

#define SIZE 2
#define T_SIZE 2
#define N_METEOR 10

typedef struct Scene
{
    Model objects[SIZE];
    Material material;
    Meteors meteors[N_METEOR];
    GLuint texture_id[T_SIZE];
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene ,float ang,float spaceship_height,float side_rl);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

void init_meteors(Scene* scene);

void update_rotation(Scene* scene);

#endif /* SCENE_H */
