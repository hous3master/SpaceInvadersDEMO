#pragma once
#include "Entity.h"
class Spaceship : public Entity
{
private:
	int lifes;
public:
	Spaceship();
	Spaceship(int px, int py, int pw, int ph);
	~Spaceship();

	void new_lifes(int new_data);
	int return_lifes();
};

