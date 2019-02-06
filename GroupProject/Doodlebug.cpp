#include "Doodlebug.h"

Doodlebug::Doodlebug(int row, int col, int rowSize, int colSize) : Critter(row, col, rowSize, colSize)
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
