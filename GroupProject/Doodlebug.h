#pragma once
#include "Critter.h"

class Doodlebug :
	public Critter
{
public:
	Doodlebug();
	~Doodlebug();

	void Move();
	void Breed();
	void Starve();
	Type GetType();
};

