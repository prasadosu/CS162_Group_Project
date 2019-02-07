/******************************************************************************
** Program name: Game.hpp
** Author: Group8 :
** Assignment: Group Project  -  CS162-400-W19
** Date: 2/2/19
** Description: 2D Predator-Prey simulation program
**	Ants(prey) and Doodlebugs(predators) move, breed and starve in a 2D grid
******************************************************************************/

#include "Simulation.h"
#include "iohelper.h"

// Default constructor
Simulation::Simulation() : 
	rows(DEFAULT_ROWS),		
	cols (DEFAULT_COLS), 
	startingAnts(DEFAULT_ANTS),
	startingBugs(DEFAULT_BUGS)
{
	board = new Critter**[rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new Critter*[cols];
	}
}

// Custom simulation constructor
Simulation::Simulation(int rows, int cols, int startingAnts, int startingBugs) :
	rows(rows),
	cols(cols),
	startingAnts(startingAnts),
	startingBugs(startingBugs)
{
	board = new Critter**[rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new Critter*[cols];
	}
}

Simulation::~Simulation()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			delete board[r][c];
		}
		delete[] board[r];
	}
	delete[] board;
}

// Main program loop
void Simulation::Run()
{
	printString("\nWelcome to the Predator-Prey Simulation Program by <NAMES>!\n");

	// Populate board with predefined board for now (REPLACE WITH RANDOM)
	/*vector< vector<int> > sampleBoard {
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };*/

	// Tim's added Board for debugging Ant movement
	vector< vector<int> > sampleBoard{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (sampleBoard[r][c] == 1)
			{
				board[r][c] = new Ant(r, c, rows, cols);
			}
			else if (sampleBoard[r][c] == 2)
			{
				board[r][c] = new Doodlebug(r, c, rows, cols);
			}
			else
			{
				board[r][c] = nullptr;
			}
		}
	}

	bool endSimulation = false;
	int currentTurn = 0, turns = 0;

	while (!endSimulation)
	{
		turns += getInt("How many turns do you want to simulate?:");

		while (currentTurn < turns)
		{
			// go thru board and do actions
			// doodlebugs moved first
			makeMoves(Critter::Type::Doodlebug);
			makeMoves(Critter::Type::Ant);
			resetMoved();		// reset moved bool for next turn
			doBreedAndStarve();	// do breed and starve actions for all critters
			printBoard();		// print board to console
			currentTurn++;
			printString("Turn: " + std::to_string(currentTurn));
		}

		char doMoreTurns[] = { 'y', 'n' };
		char more = getChar("\nSimulate more turns? (y/n):", doMoreTurns, 2);
		if (more == 'n')
		{
			endSimulation = true;
		}
	}
	printString("\nThanks for running our simulation!");
}

void Simulation::makeMoves(Critter::Type type)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			// Check spot is critter, the right type and hasn't moved already
			if (board[r][c] != nullptr &&
				board[r][c]->GetType() == type &&
				board[r][c]->hasMoved() == false)
			{
				board[r][c]->Move(board);	// Move should update moved bool
			}
		}
	}
}

void Simulation::doBreedAndStarve()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (board[r][c]) 
			{
				board[r][c]->Breed(board);
				if (board[r][c]->GetType() == Critter::Type::Doodlebug)
				{
					if (board[r][c]->Starve())
					{
						delete board[r][c];
						board[r][c] = nullptr;
					}//end if starve
				}//end if doodlebug
			}
		}
	}
}

void Simulation::resetMoved()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			if (board[r][c])
			{
				board[r][c]->setMoved(false);
			}
		}
	}
}

void Simulation::printBoard()
{
	printString();
	for (int c = 0; c < cols + 2; c++)
	{
		printString("=", false);
	}
	printString();

	for (int r = 0; r < rows; r++)
	{
		printString("|", false);

		for (int c = 0; c < cols; c++)
		{
			if (!board[r][c])
			{
				printString("-", false);
			}
			else if (board[r][c]->GetType() == Critter::Type::Ant)
			{
				printString("O", false);
			}
			else if (board[r][c]->GetType() == Critter::Type::Doodlebug)
			{
				printString("X", false);
			}
			else
			{
				printString("!", false);
			}
		}

		printString("|");
	}

	for (int c = 0; c < cols + 2; c++)
	{
		printString("=", false);
	}
	printString();
}

int main()
{
	Simulation* simulation = new Simulation();
	simulation->Run();
	delete simulation;
}