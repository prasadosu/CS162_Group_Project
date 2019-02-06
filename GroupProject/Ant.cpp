#include "Ant.h"

#include <iostream>
using std::cout;
using std::endl;

Ant::Ant(int row, int col, int rowSize, int colSize) : Critter(row, col, rowSize, colSize)
{
	this->stepNum = 0;
}

Ant::~Ant()
{
}

void Ant::Move(Critter*** &board)
{
	// Set old position to nullptr (blank space)
	board[row][col] = nullptr;	

	if (row + 1 < getMaxRows()) {
		row += 1;
	}
	// Get random number for moving up, down, left, or right
	// UP = 0, DOWN, = 1, LEFT = 2, RIGHT = 3
	int randDir = getRandInt(0, 3);

	// Printing out for debugging. TODO: Remove this or comment out.
	switch (randDir) {
		case UP:
			cout << "Move UP" << endl;
			break;
		case DOWN:
			cout << "Move DOWN" << endl;
			break;
		case LEFT:
			cout << "Move LEFT" << endl;
			break;
		case RIGHT:
			cout << "Move RIGHT" << endl;
			break;
		default:
			break;
	}

	// Try and move ant with particular random direction
	if (randDir == UP) {

	}
	else if (randDir == DOWN) {

	}
	else if (randDir == LEFT) {

	}
	else {

	}

	// Update new calculated position with ant
	board[row][col] = this;

	// Finish move
	setMoved(true);
	this->age += 1;
}

void Ant::Breed(Critter*** &board)
{
	cout << "Ant age: " << getAge();
}

Critter::Type Ant::GetType()
{
	return Critter::Type::Ant;
}
