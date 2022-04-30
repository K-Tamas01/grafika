#include "meteors.h"
#include "scene.h"
#include <obj/load.h>
#include <obj/draw.h>

int 
float m_rotate = 0.00;

void init_meteors(){

    for(int i = 0;i<1;i++){
        load_model(&(scene->objects[1]), "assets/models/meteor.obj");
        scene->texture_id[1] = load_texture("assets/textures/meteor.jpg");
        scene->meteors[i].position.x = 10;
        scene->meteors[i].position.y = 10;
        scene->meteors[i].position.z = 10;
        glBindTexture(GL_TEXTURE_2D, scene->texture_id[1]);
    }
}

void update_rotation(){
    if((m_rotate + 0.05) == 360)
        m_rotate = 0.00;
    else    
        m_rotate = m_rotate + 0.05;

    scene->meteors[i].rotate

}