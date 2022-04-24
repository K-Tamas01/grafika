#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

#define SIZE 10

typedef struct Scene
{
    Model objects[SIZE];
    Material material;
    GLuint texture_id;
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
void update_scene(Scene* scene ,float ang);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

#endif /* SCENE_H */
