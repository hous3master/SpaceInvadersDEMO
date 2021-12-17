#pragma once
#include "Alien.h"
#include "Spaceship.h"
#include "FriendlyBullet.h"
#include "EnemyBullet.h"
class Game
{
private:
	vector<Entity*> arrEntity;
	Spaceship* objSpaceship;
	time_t timer1;
	bool end_flag;
public:
	Game();
	~Game();
	void Draw_arrEntity(Graphics^ g, Bitmap^ bmpAlien);
	void Draw_SpaceShip(Graphics^ g, Bitmap^ bmp);
	
	int TotalFriendlyBullets();
	int TotalAliens();
	void EnemyShooting();
	void Colission();
	bool End_Game();
	System::String^ return_text_points();
	System::String^ return_text_lifes();
	void new_orientation(direction new_data);
	void shoot();
};

