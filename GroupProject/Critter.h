#pragma once

class Critter
{
public:
	enum Type { Ant, Doodlebug };

private:
	bool moved;
	int row;
	int col;
	int rowSize;
	int colSize;

public:
	Critter(int row, int col, int rowSize, int colSize)
	{ 
		this->row = row;
		this->col = col;
		this->rowSize = rowSize;
		this->colSize = colSize;
		this->moved = false;
	}

	void setMoved(bool moved) { this->moved = moved; }
	bool hasMoved() { return moved; }
	virtual Type GetType() = 0;
	virtual void Move(Critter*** &board) = 0;
	virtual void Breed(Critter*** &board) = 0;
	virtual void Starve() { return; }
	virtual ~Critter() {}
};

