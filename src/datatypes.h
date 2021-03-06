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
	False,
	True
} Boolean;

/*If Field.val == 0 then the field is empty*/
typedef struct Field {
	int* val;
	Coordinates square;
	int line;
	int column;
	Boolean editable;
} Field;

typedef struct Size {
	int l;
	int c;
} Size;


typedef struct Grid {
	Field** Grid;
	Size size;
}Grid ;



#endif /* DATATYPES_H_ */
