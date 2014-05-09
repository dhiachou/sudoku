#include "interface.h"
#include <stdlib.h>
#include <stdio.h>


#ifdef LINUX
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif // LINUX


void clear(){
    system(CLEAR);
}
