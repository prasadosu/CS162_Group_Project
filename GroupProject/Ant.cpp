#include "Ant.h"

Ant::Ant(int row, int col, int rowSize, int colSize) : Critter(row, col, rowSize, colSize)
{
}

Ant::~Ant()
{
}

void Ant::Move(Critter*** &board)
{
}

void Ant::Breed(Critter*** &board)
{
}

Critter::Type Ant::GetType()
{
	return Critter::Type::Ant;
}
