#include "gamelogic.h"

int gl_playerIndex(){
    int ret=0;
    for(ret=0;ob_levelTest[ret].type[0] != '\0' && ob_levelTest[ret].type[0] != '@';ret++);
    if(ob_levelTest[ret].type[0] == '\0'){printf("Error in gl_playerIndex(): Player not found\n");exit(1);}
    return ret;
}

void gl_init(){
    mh_init();
    cl_init();
    s.scene = salloc(sizeof(obj) * k_nMaxObj);
    s.pli = gl_playerIndex();

    int i;
    for(i=0; ob_levelTest[i].type[0] != '\0';i++){s.scene[i] = ob_levelTest[i];}
    s.scene[i].type[0] = '\0';

    s.x = ob_levelTest[s.pli].x;
    s.y = ob_levelTest[s.pli].y;
    s.flip = false;
}


void gl_update(){
    s.pli = gl_playerIndex();
    s.x = ob_levelTest[s.pli].x;
    s.y = ob_levelTest[s.pli].y;
    cl_update();
    mh_update();
    ai_update();
}

void gl_deinit(){
    free(s.scene);
}
