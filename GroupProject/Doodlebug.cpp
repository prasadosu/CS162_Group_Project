#include "Doodlebug.h"

Doodlebug::Doodlebug(int row, int col) : Critter(row, col)
{
}

Doodlebug::~Doodlebug()
{
}

void Doodlebug::Move(Critter*** &board)
{
}

void Doodlebug::Breed(Critter*** &board)
{
}

void Doodlebug::Starve()
{
}

Critter::Type Doodlebug::GetType()
{
	return Critter::Type::Doodlebug;
}
