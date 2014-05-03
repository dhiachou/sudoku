/*
 * arena.c
 *
 *  Created on: Feb 22, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#include "interface.h"
#include <time.h>
#include <math.h>

/**
 *	Creates an Arena with the l lines and c columns
 *	@param size : a vector containing the number of lines and columns in a square
 *
 *	returns the newly created arena
 */
Arena create(Vector size){
	Arena A;
	int i=0, j=0;

	/*Creating an empty arena with global dimensions : size.l² * size.c²*/
	A.size.l = sqr(size.l);
	A.size.c = sqr(size.c);


	A.Arena = (Field**)malloc(sizeof (Field*)*A.size.l);
	for (i =0 ; i< A.size.l;i++){
		A.Arena[i] = (Field*)malloc(sizeof(Field)*A.size.c);
	}

	/*Initializing each field*/
	for (i =0; i<A.size.l;i++){
		for (j=0; j<A.size.c; j++){
			/*Allocating the value*/
			A.Arena[i][j].val = (int*)malloc(sizeof(int));
			*(A.Arena[i][j].val) = 0;

			/*Affecting the coordinates of the field*/
			A.Arena[i][j].line = i;
			A.Arena[i][j].column = j;

			/*Affecting the number of the square where the field is*/
			A.Arena[i][j].square.x = (short)i/size.l;
			A.Arena[i][j].square.y = (short)j/size.c;
		}
	}

	return A;
}

void display_arena(Arena a){
	int i,j=0;
	/*printf ("Entered display_arena");*/
	for (i=0;i<a.size.l;i++){
		for (j=0;j<a.size.c;j++){
			printf("===")	;
		}
		printf("\n");
		for (j=0;j<a.size.c;j++){
			printf("|%d|",*(a.Arena[i][j].val))	;
		}

		printf("\n");

	}
}


Boolean verifier(Field k, Arena A ){
    int i=0, j=0;
    /*verying columns*/
    for (i=0 ; i< A.size.c ; i++){
        if (A.Arena[k.line][i].val == k.val && i != k.column) {
            return False ;
        }
    }
    //verifying lines
    for (i=0 ; i< A.size.l ; i++){
        if (A.Arena[i][k.column].val == k.val && i != k.line) {
            return False ;
        }
    }
    //verifying squares
    for (i = k.square.x * sqrt(A.size.l) ; i< (k.square.x+1)* sqrt(A.size.l); i++){
        for (j=k.square.y * sqrt(A.size.c) ; j< (k.square.y+1)* sqrt(A.size.c); j++){
            if ( (A.Arena[i][j].val== k.val) && (i != k.line) && ( j != k.column))
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
void fill_arena(Arena*A,int numero)
 {

     int c,cl,column=0,row=0;

    FILE* fichier=NULL;
    fichier = fopen("ressources/easy","r");

    row=0;
    /*boucle pour mettre le curseur dans la bonne position */
    while (numero >1)
    {
        c=fgetc(fichier);
        if (c=='\n')
            numero--;
    }

    do {
        cl=(fgetc(fichier));

        if ('.'==cl) {

            *(A->Arena[row][column].val)=0;
        }
        else if (cl<='9' && cl > '0'){

            *(A->Arena[row][column].val)=cl-'0';
        }


        printf ("%d",*(A->Arena[row][column].val));

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

