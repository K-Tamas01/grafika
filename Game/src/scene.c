#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include "meteor.h"

#define Angels 90

float rotate = 0.00;

void init_scene(Scene* scene)
{
    load_model(&(scene->objects[0]), "assets/models/spaceship.obj");
    scene->texture_id[0] = load_texture("assets/textures/spaceship.jpg");

    glBindTexture(GL_TEXTURE_2D, scene->texture_id[0]);

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 0.8;
    scene->material.diffuse.green = 0.8;
    scene->material.diffuse.blue = 0.8;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 1.4;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene,float ang)
{   
    if((rotate + ang) >= 360.00)
        rotate = 0;
    else if((rotate - ang) <= -360.00)
        rotate = 0;
    else
        rotate = rotate + ang;
}
void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    glPushMatrix();
       glRotatef(Angels+rotate,1.0f,0.0f,0.0f);
       glRotatef(Angels,0.0f,1.0f,0.0f);
       glTranslatef(0,0,2.60);
       draw_model(&(scene->objects[0]));
    glPopMatrix();
    glPushMatrix();
        glTranslatef(scene->meteors[0].position.x,scene->meteors[0].position.y,scene->meteors[0].position.z);
        draw_model(&(scene->objects[1]));
    glPopMatrix();
}