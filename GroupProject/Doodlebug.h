#pragma once
#include "Critter.h"

class Doodlebug :
	public Critter
{
public:
	Doodlebug(int row, int col);
	~Doodlebug();

	void Move(Critter*** &board);
	void Breed(Critter*** &board);
	void Starve();
	Type GetType();
};

