
#ifdef USING_SDL
//============================================================================
// Name        : SDLmain.cpp
// Author      : Dhaw - Salmouch - Dandoun - Nini
// Version     :
// Copyright   : All rights reserved to II1G
// Description : The sudoku project
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

#ifdef WIN32
#define ICON_PATH "ressources/img/icon32.bmp"
#elif defined __unix__
#define ICON_PATH "ressources/img/icon100.bmp"
#else
//eror
#endif // win32 favicon should be 32x32px

int main() {
	Grid grid ;
    SDL_Surface *screen;

    /**Initializing SDL and its components**/
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO)==-1)
    {
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /** Opening window**/
    SDL_WM_SetIcon(SDL_LoadBMP(ICON_PATH), NULL);
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);  ///Load the window
    SDL_WM_SetCaption("Sudoku" , NULL);

    /**Launching game**/
    grid = main_menu(screen);   //opening main_menu
    game(&grid,screen);         //opening the game window

    /** Shutting down **/
    SDL_Quit();


	return EXIT_SUCCESS;
}
#endif
