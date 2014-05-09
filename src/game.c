#include "interface.h"

void game (Grid * grid){

    unsigned short choice = 0;
    Coordinates coord;
    int number=0;

    //In the game
    while (1) {
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
                //delete_grid(grid);              // Free allocated memory  TODO !
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
                if (number <1 || number > grid->size.c)
                    goto number_input;
                //putting the number in the right place if it is a zero (AND EDITABLE! TODO )
                if (0 == *(grid->Grid[coord.x-1][coord.y-1].val))
                    *(grid->Grid[coord.x-1][coord.y-1].val) = number;
                else
                    printf("field is not empty, or is not editable\n");
                break;
            case 2 :        /// Edit a number
                break;
            case 3 :        /// Save progress
                break;
            default :       /// Wrong choice
                printf("Wrong choice!\n");
                goto menu;
                break;

        }
    }
}
