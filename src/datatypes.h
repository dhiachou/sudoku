/*
 * datatypes.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Dhia - Salma - Nidhal - Ouijdane
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef struct Coordinates {
	short x;
	short y;
} Coordinates ;

typedef enum Boolean
{
	Faux,
	Vrai
} Boolean;

//If Field.val == 0 then the field is empty
typedef struct Field {
	int* val;
	Coordinates square;
	int line;
	int column;
} Field;

typedef struct Vector {
	int l;
	int c;
} Vector;


typedef struct Arena {
	Field** Arena;
	Vector size;
}Arena ;



#endif /* DATATYPES_H_ */
