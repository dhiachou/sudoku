//============================================================================
// Name        : SUDOKU.cpp
// Author      : Dhaw - Salmouch - Dandoun - Nini
// Version     :
// Copyright   : All rights reserved to II1G
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


int main() {
	Vector size;
	Arena a ;

	printf("Enter size :");
	scanf("%d",&size.c);
	scanf("%d",&size.l);


	a = create(size);

	display_arena(a);


	return 0;
}
