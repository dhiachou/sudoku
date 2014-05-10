#include "interface.h"
#include<string.h>
#define EASY 0
#define MEDIUM 1
#define HARD 2


#define EASY_LINE_NUM 50
#define MEDIUM_LINE_NUM 95
#define HARD_LINE_NUM 11

int levels_menu()
{
    int choice=0;
    do {
        printf("which level \n");
        printf("1-easy \n");
        printf("2-medium \n");
        printf("3-hard\n");
        scanf("%d",&choice);
    }while (choice <1 || choice >3);
    return choice;
}

Grid main_menu()
{
    int choice=0, diff=0,n=0;
    char notice [200]="\0";
    Grid grid ;
    Vector size;

    size.c=3;
    size.l=3;

    menu :
    clear();
    if (strlen(notice) > 0   )
    {
            printf("%s", notice);
            notice[0] = '\O';
    }
    printf("hello good mornin \n");
    printf("what would you like to do today ? \n");
    printf("1- new game \n");
    printf("2- load game \n");
    printf("0- Quit \n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0: /// Exit
            exit(EXIT_SUCCESS);
            break;
        case 1: /// new game
            diff=levels_menu();
            switch(diff)
            {
                case EASY :
                    n=randomize(EASY_LINE_NUM);
                    grid= create(size);
                    fill_grid(&grid,n,"ressources/easy");
                    break;
                case MEDIUM :
                    n=randomize(MEDIUM_LINE_NUM);
                     grid= create(size);
                    fill_grid(&grid,n,"ressources/hard");
                    break;
                case HARD :
                    n=randomize(HARD_LINE_NUM);
                     grid= create(size);
                    fill_grid(&grid,n,"ressources/hardest");
                    break ;
                default:
                    fprintf(stderr," sth went wrong \n");
                    exit(EXIT_FAILURE);
                break;
            }

            break;
        case 2: /// load game
            break;
        default:
            strcpy(notice, "wrong input \n");
            goto menu;
            break;
    }
    return grid;
}
void game (Grid * grid){

    unsigned short choice = 0;
    Coordinates coord;
    int number=0;
    char notice [200] = "\0";

    //In the game
    while (1) {
        clear();

        //Displaying last notice :
        if (strlen(notice) > 2 ){
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
                delete_grid(grid);              // Free allocated memory  TODO !
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
                else
                    strcpy(notice,"field is not empty, or is not editable\n");
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
                else
                    strcpy(notice,"field is not editable\n");
                break;
            case 3 :        /// Save progress
                    save(*grid);
                    strcpy(notice,"PROGRESS SAVED! \n");
                break;
            default :       /// Wrong choice
                printf("Wrong choice!\n");
                goto menu;
                break;

        }
    }
}
