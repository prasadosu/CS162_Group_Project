#pragma once
#include "Critter.h"
#include "randNum.hpp"

enum direction {UP, DOWN, LEFT, RIGHT};

class Ant :
	public Critter
{
private:
	int posX;
	int posY;
	int stepNum;

public:
	Ant(int row, int col, int rowSize, int colSize);
	~Ant();

	// Getters
	int getPosX() { return this->posX; }
	int getPosY() { return this->posY; }
	int getMaxRows() { return this->rowSize; }
	int getMaxCols() { return this->colSize; }

	// Setters
	void setPosX(int x) { this->posX = x; }
	void setPosY(int y) { this->posY = y; }

	// Functions
	void Move(Critter*** &board);
	void Breed(Critter*** &board);
	Type GetType();
};