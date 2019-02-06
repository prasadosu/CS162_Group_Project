#pragma once
#include "Critter.h"

class Ant :
	public Critter
{
public:
	Ant(int row, int col);
	~Ant();

	void Move(Critter*** &board);
	void Breed(Critter*** &board);
	Type GetType();
};

