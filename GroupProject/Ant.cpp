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

	// Get random number for moving up, down, left, or right
	// UP = 0, DOWN, = 1, LEFT = 2, RIGHT = 3
	int randDir = getRandInt(0, 3);

	/*
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
	}*/

	// randDir = 3; TODO: For debug, delete this

	// Try and move ant with particular random direction
	if (randDir == UP) {
		if (row - 1 >= 0) {
			if (board[row - 1][col] == nullptr) {
				row -= 1;
			}
		}
	}
	else if (randDir == DOWN) {
		if (row + 1 <= rowSize - 1) {
			if (board[row + 1][col] == nullptr) {
				row += 1;
			}
		}

	}
	else if (randDir == LEFT) {
		if (col - 1 >= 0) {
			if (board[row][col - 1] == nullptr) {
				col -= 1;
			}
		}
	}
	else {
		if (col + 1 <= colSize - 1) {
			if (board[row][col + 1] == nullptr) {
				col += 1;
			}
		}
	}

	// Update new calculated position with ant
	board[row][col] = this;

	//cout << "New position: [" << row << "][" << col << "]" << endl; TODO: For debug, delete this

	// Finish move
	setMoved(true);
	this->age += 1;
}

bool Ant::Breed(Critter*** &board)
{
	return false;
}

Critter::Type Ant::GetType()
{
	return Critter::Type::Ant;
}
