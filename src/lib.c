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
