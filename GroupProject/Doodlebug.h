#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Critter.h"

class Doodlebug :
	public Critter
{
public:
	Doodlebug(int row, int col, int rowSize, int colSize);
	~Doodlebug();

	void Move(Critter*** &board);
	void Breed(Critter*** &board);
	void Starve();
	Type GetType();
};

#endif