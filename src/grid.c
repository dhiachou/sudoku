/*
 * grid.c
 *
 *  Created on: Feb 22, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#include "interface.h"
#include <time.h>
#include <math.h>

/**
 *	Creates an Grid with the l lines and c columns
 *	@param size : a vector containing the number of lines and columns in a square
 *
 *	returns the newly created grid
 */
Grid create(Size size){
	Grid A;
	int i=0, j=0;

	/*Creating an empty grid with global dimensions : size.l² * size.c²*/
	A.size.l = sqr(size.l);
	A.size.c = sqr(size.c);


	A.Grid = (Field**)malloc(sizeof (Field*)*A.size.l);
	for (i =0 ; i< A.size.l;i++){
		A.Grid[i] = (Field*)malloc(sizeof(Field)*A.size.c);
	}

	/*Initializing each field*/
	for (i =0; i<A.size.l;i++){
		for (j=0; j<A.size.c; j++){
			/*Allocating the value*/
			A.Grid[i][j].val = (int*)malloc(sizeof(int));
			*(A.Grid[i][j].val) = 0;

			/*Affecting the coordinates of the field*/
			A.Grid[i][j].line = i;
			A.Grid[i][j].column = j;

			/*Affecting the number of the square where the field is*/
			A.Grid[i][j].square.x = (short)i/size.l;
			A.Grid[i][j].square.y = (short)j/size.c;

			/*making the field editable (default value ) */
			A.Grid[i][j].editable = True ;
		}
	}

	return A;
}
 /**
 *  Displays the Arena
 **/

void display_grid(Grid a){
	int i,j=0;
	/*printf ("Entered display_grid");*/
	printf("\t");
	for (i = 0 ; i<a.size.c;i++){
        printf ("%d \t",i+1);
        if ((i+1) % (int)sqrt(a.size.c) ==0 ) printf("| \t");
    }
    printf("\n");
    for (i = 0 ; i<a.size.l;i++)
        printf ("====\t");
    printf("\n");

	for (i=0;i<a.size.l;i++){
        printf("%d||\t",i+1);

		for (j=0;j<a.size.c;j++){
			printf("%d\t",*(a.Grid[i][j].val))	;
            if ((j+1) % (int)sqrt(a.size.c) ==0 ) printf("|| \t");
		}

		printf("\n\t");
        if ((i+1) % (int)sqrt(a.size.l) ==0 )
            for (j=0; j<a.size.c ; j++ ){
                printf("=====\t");
                if ((j+1) % (int)sqrt(a.size.c) ==0 ) printf("===\t");
            }
        printf("\n");

	}
}

 /**
 *   Tests whether the whole Arena is correct
 **/

 Boolean verify_arena(Grid g){
    int  j=0,i=0;

    for(i=0;i<g.size.l;i++){
        for(j=0;j<g.size.c;j++){
             if ( verify(g.Grid[i][j],g)==False) return False;
         }

    }

    return True;
}

/**
*   Tests whether the given  field verifies the conditions (columns, rows, square)
**/

Boolean verify(Field k, Grid A ){
    int i=0, j=0;
    //verying columns
    for (i=0 ; i< A.size.c ; i++){
        if (*A.Grid[k.line][i].val == *k.val && i != k.column) {
            return False ;
        }
    }
    //verifying lines
    for (i=0 ; i< A.size.l ; i++){
        if (*A.Grid[i][k.column].val == *k.val && i != k.line) {
            return False ;
        }
    }
    //verifying squares
    for (i = k.square.x * sqrt(A.size.l) ; i< (k.square.x+1)* sqrt(A.size.l); i++){
        for (j=k.square.y * sqrt(A.size.c) ; j< (k.square.y+1)* sqrt(A.size.c); j++){
            if ( (*A.Grid[i][j].val== *k.val) && (i != k.line) && ( j != k.column))
                return False;
        }
    }


    return True;

}
/**
 * Initialises the randomize seed
 */
void init_randomizer(){
    srand(time(NULL));
}

/**
 * Returns a random number between 0 and n
 */
int randomize(int n){
    return rand()% n ;
}

/**
 * Loads a random ready to play Arena from File
 **/
void fill_grid(Grid*A,int n,char * file){
    int c,cl,column=0,row=0;
    FILE* fichier=NULL;
    fichier = fopen(file,"r");

    row=0;

    /*going to the correct line */
    while (n >1)
    {
        c=fgetc(fichier);
        if (c=='\n')
            n--;
    }

    do {
        cl=(fgetc(fichier));

        if ('.'==cl) {

            *(A->Grid[row][column].val)=0;
            A->Grid[row][column].editable = True;
        }
        else if (cl<='9' && cl > '0'){

            *(A->Grid[row][column].val)=cl-'0';
            A->Grid[row][column].editable = False ;
        }

        column++;
        if (column==A->size.c)
        {
            printf ("\n");
            column=0;
            row++;
        }

    }while (cl!='\n' && row!=A->size.l);
    printf ("\n");
}

/**
 *  Deletes the grid and liberate the allocated memory
 **/
void delete_grid(Grid * grid){
    int i=0, j=0;
	/*Liberating each field*/
	for (i =0; i<grid->size.l;i++){
		for (j=0; j<grid->size.c; j++){
			/*Allocating the value*/
			free(grid->Grid[i][j].val);
        }
    }

    //freeing the grid elements
	for (i =0 ; i< grid->size.l;i++){
		free(grid->Grid[i]);
    }
    free(grid->Grid);
}

