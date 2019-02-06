#ifndef ANT_H
#define ANT_H


#include "Critter.h"

class Ant :
	public Critter
{
private:
	int posX;
	int posY;

public:
	Ant(int row, int col, int rowSize, int colSize);
	~Ant();

	// Getters
	int getPosX() { return this->posX; }
	int getPosY() { return this->posY; }

	// Setters
	void setPosX(int x) { this->posX = x; }
	void setPosY(int y) { this->posY = y; }


	void Move(Critter*** &board);
	void Breed(Critter*** &board);
	Type GetType();
};

#endif