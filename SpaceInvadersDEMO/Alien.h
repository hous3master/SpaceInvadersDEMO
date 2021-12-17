#pragma once
#include "Entity.h"
class Alien: public Entity
{
public:
	Alien();
	Alien(int px, int py, int pw, int ph);
	~Alien();

	void Move(Graphics^ g);
};

