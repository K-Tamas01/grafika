#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <time.h>
#include "meteor.h"
#include "spaceship.h"

#define Angels 90

float  h_space = 0, r_side_l = 0;				

void init_scene(Scene* scene)
{
    init_spaceship(scene);
    init_meteors(scene);

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

void init_spaceship(Scene* scene){

    load_model(&(scene->objects[0]), "assets/models/spaceship.obj");
    scene->texture_id[0] = load_texture("assets/textures/spaceship.jpg");

    scene->spaceship.position.x = 0;
    scene->spaceship.position.y = 0;
    scene->spaceship.position.z = 1.25;
    scene->spaceship.rotate = 0.00;
    scene->spaceship.speed = 0.35;
}

void init_meteors(Scene* scene){
    int coord;
    srand(time(0));

    load_model(&(scene->objects[1]), "assets/models/meteor.obj");
    scene->texture_id[1] = load_texture("assets/textures/meteor.jpg");

    for(int i = 0;i<10;i++){
        coord = (rand() % 90) + 20;
        scene->meteors[i].position.x = coord;
        coord = (rand() % 70) + 20;
        scene->meteors[i].position.y = coord;
        coord = (rand() % 90) + 20;
        scene->meteors[i].position.z = coord;
        scene->meteors[i].angle = 0.00;
    }
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

void update_scene(Scene* scene,float ang,float spaceship_height,float side_rl)
{   
    if((scene->spaceship.rotate + ang) <= -45)
	scene->spaceship.rotate = -45;
    if(((scene->spaceship.rotate + ang) >= 45))
	scene->spaceship.rotate = 45;    

    if(((scene->spaceship.rotate + ang) >= -45) && ((scene->spaceship.rotate + ang) <= 45))
	scene->spaceship.rotate += ang;
   

    if((h_space - spaceship_height) < 10) h_space = h_space + spaceship_height;
    if((h_space + spaceship_height) > 10) h_space = h_space - spaceship_height;

    if((r_side_l - side_rl) < 10) r_side_l = r_side_l + side_rl;
    if((r_side_l + side_rl) > 10) r_side_l = r_side_l - side_rl;

    for(int i = 0;i<10;i++)
        if((scene->meteors[i].angle + 0.05) < 360.00) scene->meteors[i].angle += 0.05;
        else scene->meteors[i].angle = 0.00;

    scene->spaceship.position.x = r_side_l;
    scene->spaceship.position.y = h_space;
    scene->spaceship.position.z += scene->spaceship.speed;

    scene->spaceship.rotate += ang;

    for(int i = 0;i<10;i++){
	scene->meteors[i].position.y -= 1;
	scene->meteors[i].position.z -= 1;
    }
}
void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    glPushMatrix();
       glRotatef(Angels+scene->spaceship.rotate,1.0f,0.0f,0.0f);
       glRotatef(Angels,0.0f,1.0f,0.0f);
       glTranslatef(scene->spaceship.position.x,scene->spaceship.position.y,scene->spaceship.position.z);
       glBindTexture(GL_TEXTURE_2D, scene->texture_id[0]);
       draw_model(&(scene->objects[0]));
    glPopMatrix();   
    for(int i = 0; i < 10;i++){    
        glPushMatrix(); 
            glBindTexture(GL_TEXTURE_2D, scene->texture_id[1]);
            glRotatef(scene->meteors[i].angle,1.0f,1.0f,0.0f);
            glTranslatef(scene->meteors[i].position.x,scene->meteors[i].position.y,scene->meteors[i].position.z);
            draw_model(&(scene->objects[1]));
        glPopMatrix();
    }
}