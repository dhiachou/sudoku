#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


#ifdef __unix__
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif // linux


void clear(){
    system(CLEAR);
}

#ifdef USING_SDL
int in_surface(Uint16 x , Uint16 y , SDL_Surface* btn , SDL_Rect position)
{
    return (position.x < x &&\
                    x < (position.x + btn->w) && position.y < y && \
                    y < (position.y + btn->h));
}

Boolean time_elapsed(int init, int time){
    if (SDL_GetTicks()-init >= time){
        return True;
    } else {
    return False;
    }
}
#endif
