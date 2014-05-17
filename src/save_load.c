/*
 * save_load.c
 *
 *  Created on: Mar 25, 2014
 *      Author: dhia
 */

#include <stdlib.h>
#include <stdio.h>

#include "interface.h"
#include <math.h>


/** loads an already saved Arena from file **/

Boolean load(Grid* a){
	Boolean exit_status = True;
	int i=0, j=0;
	Size size ;
	FILE* fin  = NULL;

	fin = fopen("game","r"); /*Opening file*/

	/*getting game grid's dimension */
	fscanf(fin, "%d %d", &size.c,&size.l);

	/*creating the imported grids with the correct size */
	*a = create(size);

	if(NULL!=fin){	/*file opened correctly*/
		/*reading fields' properties*/
		for ( i=0 ; i<a->size.l ; i++){
			for ( j=0 ; j<a->size.c ; j++){
				fscanf(fin, "%d", a->Grid[i][j].val);
			}
		}

	}
	else {
		fprintf(stderr,"Can't open file in read mode");
		exit_status = False;
	}

	if(fclose(fin)!=0) exit_status = False;
	return exit_status;
}

 /** Saves game in progress into file  **/


Boolean save(Grid a){
	Boolean exit_status = True;
	FILE* fout = NULL;
	int i = 0, j = 0;
	fout = fopen("game","w"); /*Opening file for writing*/


	printf("File opened\n");

	if(NULL!=fout){

		fprintf(fout,"%d %d\n", (int)sqrt(a.size.c) , (int)sqrt(a.size.l));	/*saving grid's dimensions*/
		/*writing each fields property on a new line */
		for(i=0; i<a.size.l; i++){			/* each line of the actual grid */
			for (j=0 ;j<a.size.c; j++){ 	/*each field*/
				fprintf(fout, "%d ",*(a.Grid[i][j].val));/* saving the value */
			}
			fprintf(fout,"\n");
		}
	}
	else{
		fprintf(stderr,"Can't open file in write mode");
		exit_status=False;
	}

	if(fclose(fout)!=0)	exit_status = False ;
	return exit_status;
}
