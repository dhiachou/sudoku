#ifdef USING_SDL
#include "interface.h"
#include <string.h>
#define EASY 0
#define MEDIUM 1
#define HARD 2

#define EASY_LINE_NUM 50
#define MEDIUM_LINE_NUM 95
#define HARD_LINE_NUM 11

int levels_menu(SDL_Surface* screen)
{
    SDL_Surface *bg_img, *btn, *btn_clicked, *btn_hard, *btn_easy, *btn_medium, *txt_title,\
                *txt_easy, *txt_medium, *txt_hard, *txt_choose;
    SDL_Rect position, position_btn_easy, position_btn_medium, position_btn_hard, position_txt_title,\
             position_txt_easy, position_txt_medium, position_txt_hard, position_txt_choose;
    SDL_Event event;
    TTF_Font *font  = NULL, *font2 = NULL;
    TTF_Font *font1 = NULL;
    SDL_Color color_black = {0 , 0 , 0 };
    SDL_Color color_white = {255,255,255};

    unsigned short repeat = 1, choice = 0;

    /** Loading images **/
    if (! (bg_img      = IMG_Load("ressources/img/background.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (! (btn         = IMG_Load("ressources/img/btn.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (!(btn_clicked = IMG_Load("ressources/img/btn_clicked.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /**Loading fonts **/
    if (!(font  = TTF_OpenFont ("ressources/fonts/SakiScript.otf"    , 150))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (!(font1 = TTF_OpenFont ("ressources/fonts/Eyes Believer.ttf" , 30 ))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (!(font2 = TTF_OpenFont ("ressources/fonts/Eyes Believer.ttf" , 20 ))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /**initializing texts**/
    txt_title   = TTF_RenderText_Blended(font , "Sudoku"      , color_black);
    txt_choose  = TTF_RenderText_Blended(font2, "Please choose level :", color_black);
    txt_easy    = TTF_RenderText_Blended(font1, "easy"        , color_white);
    txt_medium  = TTF_RenderText_Blended(font1, "medium"      , color_white);
    txt_hard    = TTF_RenderText_Blended(font1, "hard"        , color_white);

    /**Setting everything positions **/
    position.x = 0;
    position.y = 0;

    position_txt_choose.x = 50;
    position_txt_choose.y = 210;

    position_btn_easy.x=200;
    position_btn_easy.y=240;

    position_btn_medium.x=200;
    position_btn_medium.y=340;

    position_btn_hard.x=200;
    position_btn_hard.y=440;

    position_txt_title.x = 250;
    position_txt_title.y = 60;

    position_txt_easy.x=350;
    position_txt_easy.y=260;

    position_txt_medium.x=350;
    position_txt_medium.y=360;

    position_txt_hard.x=380;
    position_txt_hard.y=460;


    /** Displaying the menu **/
    btn_hard = btn_easy = btn_medium = btn;
    /*** Program's main loop **/
    while (repeat) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                repeat = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT )
                {
                    if( in_surface(event.button.x , event.button.y , btn_easy , position_btn_easy))
                        btn_easy = btn_clicked;
                    if( in_surface(event.button.x , event.button.y , btn_medium , position_btn_medium))
                        btn_medium = btn_clicked;
                    if( in_surface(event.button.x , event.button.y , btn_hard , position_btn_hard))
                        btn_hard = btn_clicked;
                }
                break;
            case SDL_MOUSEBUTTONUP :
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                    if(in_surface(event.button.x , event.button.y , btn_easy , position_btn_easy)){
                        repeat = 0 ;
                        choice = 1;
                    }
                    else if(in_surface(event.button.x , event.button.y , btn_medium , position_btn_medium)){
                        repeat = 0 ;
                        choice = 2;
                    }
                    else if(in_surface(event.button.x , event.button.y , btn_hard , position_btn_hard)){
                        repeat = 0 ;
                        choice = 3;
                    }
                    btn_hard = btn_medium = btn_easy = btn;
                }

                break;

        }

        SDL_BlitSurface(bg_img      , NULL, screen, &position             );
        SDL_BlitSurface(btn_easy    , NULL, screen, &position_btn_easy    );
        SDL_BlitSurface(btn_medium  , NULL, screen, &position_btn_medium  );
        SDL_BlitSurface(btn_hard    , NULL, screen, &position_btn_hard    );
        SDL_BlitSurface(txt_title   , NULL, screen, &position_txt_title   );
        SDL_BlitSurface(txt_choose  , NULL, screen, &position_txt_choose  );
        SDL_BlitSurface(txt_easy    , NULL, screen, &position_txt_easy    );
        SDL_BlitSurface(txt_medium  , NULL, screen, &position_txt_medium  );
        SDL_BlitSurface(txt_hard    , NULL, screen, &position_txt_hard    );

        SDL_Flip(screen);
    }

    SDL_FreeSurface(bg_img);
    SDL_FreeSurface(btn);
    SDL_FreeSurface(btn_clicked);



    return choice;
}

Grid main_menu(SDL_Surface * screen)
{
    int diff=0,n=0;
    SDL_Surface *bg_img, *btn, *btn_clicked, *btn_exit, *btn_newGame, *btn_loadGame, *txt_title,\
                *txt_newGame, *txt_loadGame, *txt_exit ;
    SDL_Rect position, position_btn_newGame, position_btn_loadGame, position_btn_exit, position_txt_title,\
             position_txt_newGame, position_txt_loadGame, position_txt_exit ;
    SDL_Event event;
    TTF_Font *font  = NULL;
    TTF_Font *font1 = NULL;
    SDL_Color color_black = {0 , 0 , 0 };
    SDL_Color color_white = {255,255,255};

    unsigned short repeat = 1, choice;


    /** Creating an empty new grid **/
    Grid grid ;
    Size size;
    size.c=3;
    size.l=3;
    grid= create(size);

    /** Loading images **/
    if (! (bg_img      = IMG_Load("ressources/img/background.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (! (btn         = IMG_Load("ressources/img/btn.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (!(btn_clicked = IMG_Load("ressources/img/btn_clicked.png"))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /**Loading fonts **/
    if (!(font  = TTF_OpenFont ("ressources/fonts/SakiScript.otf"    , 150))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }
    if (!(font1 = TTF_OpenFont ("ressources/fonts/Eyes Believer.ttf" , 30 ))){
        fprintf (stderr, "%s",SDL_GetError());
        exit (EXIT_FAILURE);
    }

    /**initializing texts**/
    txt_title   = TTF_RenderText_Blended(font , "Sudoku"      , color_black);
    txt_newGame = TTF_RenderText_Blended(font1, "NEW GAME"    , color_white);
    txt_loadGame= TTF_RenderText_Blended(font1, "LOAD GAME"   , color_white);
    txt_exit    = TTF_RenderText_Blended(font1, "EXIT"        , color_white);

    /**Setting everything positions **/
    position.x = 0;
    position.y = 0;

    position_btn_newGame.x=200;
    position_btn_newGame.y=230;

    position_btn_loadGame.x=200;
    position_btn_loadGame.y=330;

    position_btn_exit.x=200;
    position_btn_exit.y=430;

    position_txt_title.x = 250;
    position_txt_title.y = 50;

    position_txt_newGame.x=350;
    position_txt_newGame.y=250;

    position_txt_loadGame.x=350;
    position_txt_loadGame.y=350;

    position_txt_exit.x=380;
    position_txt_exit.y=450;


    /** Displaying the menu **/
    btn_exit = btn_newGame = btn_loadGame = btn;
    /*** Program's main loop **/
    while (repeat) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                repeat = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT )
                {
                    if( in_surface(event.button.x , event.button.y , btn_newGame , position_btn_newGame))
                        btn_newGame = btn_clicked;
                    if( in_surface(event.button.x , event.button.y , btn_loadGame , position_btn_loadGame))
                        btn_loadGame = btn_clicked;
                    if( in_surface(event.button.x , event.button.y , btn_exit , position_btn_exit))
                        btn_exit = btn_clicked;
                }
                break;
            case SDL_MOUSEBUTTONUP :
                if ( event.button.button == SDL_BUTTON_LEFT )
                {
                    if(in_surface(event.button.x , event.button.y , btn_exit , position_btn_exit)){
                        repeat = 0 ;
                        choice = 0;
                    }
                    else if(in_surface(event.button.x , event.button.y , btn_newGame , position_btn_newGame)){
                        repeat = 0 ;
                        choice = 1;
                    }
                    else if(in_surface(event.button.x , event.button.y , btn_loadGame , position_btn_loadGame)){
                        repeat = 0 ;
                        choice = 2;
                    }
                    btn_exit = btn_loadGame = btn_newGame = btn;
                }

                break;

        }

        SDL_BlitSurface(bg_img      , NULL, screen, &position                );
        SDL_BlitSurface(btn_newGame , NULL, screen, &position_btn_newGame    );
        SDL_BlitSurface(btn_loadGame, NULL, screen, &position_btn_loadGame   );
        SDL_BlitSurface(btn_exit    , NULL, screen, &position_btn_exit       );
        SDL_BlitSurface(txt_title   , NULL, screen, &position_txt_title      );
        SDL_BlitSurface(txt_newGame , NULL, screen, &position_txt_newGame    );
        SDL_BlitSurface(txt_loadGame, NULL, screen, &position_txt_loadGame   );
        SDL_BlitSurface(txt_exit    , NULL, screen, &position_txt_exit       );

        SDL_Flip(screen);
    }

    switch(choice)
    {
        case 0: /// Exit
            exit(EXIT_SUCCESS);
            break;
        case 1: /// new game
            diff=levels_menu(screen);
            switch(diff)
            {
                case EASY :
                    n=randomize(EASY_LINE_NUM);
                    fill_grid(&grid,n,"ressources/easy");
                    break;
                case MEDIUM :
                    n=randomize(MEDIUM_LINE_NUM);
                    fill_grid(&grid,n,"ressources/hard");
                    break;
                case HARD :
                    n=randomize(HARD_LINE_NUM);
                    fill_grid(&grid,n,"ressources/hardest");
                    break ;
                default:
                    fprintf(stderr," Something went wrong \n");
                    delete_grid(&grid);
                    exit(EXIT_FAILURE);
                break;
            }

            break;
        case 2: /// load game
            if (load(&grid) == False ) {
                fprintf(stderr, "Something went wrong!\n\tcouldn't load grid");
                delete_grid(&grid);
                exit(EXIT_FAILURE);
            }
            break;
    }


    SDL_FreeSurface(bg_img);
    SDL_FreeSurface(btn);
    SDL_FreeSurface(btn_clicked);

    return grid;
}
void game (Grid * grid , SDL_Surface * screen){ //TODO : make it with sdl

    unsigned short choice = 0;
    Coordinates coord;
    int number=0;
    char *notice = NULL;

    notice = malloc(sizeof(char));
    notice [0] = '\0';

    //In the game
    while (1) {
        clear();

        //Displaying last notice :
        if (strlen(notice) > 0 ){
            printf(" [ ! ] %s ", notice);
            notice[0] = '\0';
        }
        //showing the grid
        printf("The grid : \n");
        display_grid(*grid);

        menu:
        //Asking for next action
        printf ("[?] What to do ? : \n");
        printf (" 1 - Enter a number\n");
        printf (" 2 - Edit a number\n");  ///need to update the data structure to know which numbers are editable and which are not
        printf (" 3 - Save progress\n");
        printf (" 0 - Quit\n");

        scanf("%d",&choice);

        //Testing upon the choice
        switch (choice ){
            case 0 :        /// Quit
                delete_grid(grid);              // Free allocated memory
                free(notice);
                exit(EXIT_SUCCESS);             //exit
                break;
            case 1 :        /// Enter a number
                coord_input:
                printf("Enter coordinates seperated by a space (line column) : ");
                scanf ("%d %d", &coord.x , &coord.y );

                //Shall test the input (input data between 0 and max allowed values (right coordinates)
                if (coord.x <=0 || coord.x> grid->size.c+1 || coord.y <=0 || coord.y>grid->size.l+1){
                    printf("Wrong coordinates!\n");
                    goto coord_input;
                }

                number_input:
                printf("Enter the number to put in (%d,%d) : " ,coord.x, coord.y);
                scanf("%d", &number);

                //checking whether the number is correct
                if (number <0 || number > grid->size.c)
                    goto number_input;
                //putting the number in the right place if it is a zero (AND EDITABLE! TODO )
                if (0 == *(grid->Grid[coord.x-1][coord.y-1].val))
                    *(grid->Grid[coord.x-1][coord.y-1].val) = number;
                else{
                    notice = realloc(notice , strlen("field is not empty, or is not editable\n")*sizeof(char));
                    strcpy(notice,"field is not empty, or is not editable\n");
                }
                break;
            case 2 :        /// Edit a number

                coord_input2:
                printf("Enter coordinates seperated by a space (line column) : ");
                scanf ("%d %d", &coord.x , &coord.y );

                //Shall test the input (input data between 0 and max allowed values (right coordinates)
                if (coord.x <=0 || coord.x> grid->size.c+1 || coord.y <=0 || coord.y>grid->size.l+1)
                    goto coord_input2;

                number_input2:
                printf("Enter the number to put in (%d,%d) : " ,coord.x, coord.y);
                scanf("%d", &number);

                //checking whether the number is correct
                if (number <0 || number > grid->size.c)
                    goto number_input2;
                //putting the number in the right place if it is ( EDITABLE! TODO )
                if (True)
                    *(grid->Grid[coord.x-1][coord.y-1].val) = number;
                else{
                    notice = realloc(notice , strlen("field is not editable\n")*sizeof(char));
                    strcpy(notice,"field is not editable\n");
                }
                break;
            case 3 :        /// Save progress
                    save(*grid);
                    notice = realloc(notice , strlen("PROGRESS SAVED! \n")*sizeof(char));
                    strcpy(notice,"PROGRESS SAVED! \n");
                break;
            default :       /// Wrong choice
                printf("Wrong choice!\n");
                goto menu;
                break;

        }
    }
}

#endif
