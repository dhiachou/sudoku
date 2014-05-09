#include "interface.h"

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
                printf("Enter coordinates seperated by a space (line,column) : ");
                scanf ("%d %d", &coord.x , &coord.y );

                //Shall test the input (input data between 0 and max allowed values (right coordinates)
                if (coord.x <=0 || coord.x> grid->size.c+1 || coord.y <=0 || coord.y>grid->size.l+1)
                    goto coord_input;

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
                printf("Enter coordinates seperated by a space (line,column) : ");
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
                    save(grid);
                    strcpy(notice,"PROGRESS SAVED! \n");
                break;
            default :       /// Wrong choice
                printf("Wrong choice!\n");
                goto menu;
                break;

        }
    }
}
