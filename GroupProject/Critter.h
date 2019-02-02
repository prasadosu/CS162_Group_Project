#pragma once

class Critter
{
private:
	bool moved;
public:
	enum Type{Ant, Doodlebug};
	Critter() { moved = false; }

	bool hasMoved() { return moved; }
	void setMoved(bool moved) { this->moved = moved; }

	virtual void Move() = 0;
	virtual void Breed() = 0;
	virtual Type GetType() = 0;
	virtual void Starve() { return; }
	virtual ~Critter() {}
};

