#include "Ant.h"

Ant::Ant(int row, int col) : Critter(row, col)
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
