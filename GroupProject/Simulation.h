/******************************************************************************
** Program name: Simulation.hpp
** Author: Group8 : 
** Assignment: Group Project  -  CS162-400-W19
** Date: 2/2/19
** Description: 2D Predator-Prey simulation program
**	Ants(prey) and Doodlebugs(predators) move, breed and starve in a 2D grid
******************************************************************************/

#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Ant.h"
#include "Doodlebug.h"

// Globals
#define DEFAULT_ROWS 20
#define DEFAULT_COLS 20
#define DEFAULT_ANTS 100
#define DEFAULT_BUGS 5

class Simulation
{
private:
	int rows;			// Number of rows in grid
	int cols;			// Number of columns in grid
	int startingAnts;	// Initial ants on board
	int startingBugs;	// Initial bugs on board

	Critter*** board;
	void makeMoves(Critter::Type type);
	void doBreedAndStarve();

	void resetMoved();

	void printBoard();

public:
	Simulation();
	Simulation(int rows, int cols, int startingAnts, int startingBugs);
	~Simulation();

	void Run();
};

