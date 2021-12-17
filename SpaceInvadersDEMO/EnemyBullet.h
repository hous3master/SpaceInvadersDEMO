#pragma once
#include "Entity.h"
class EnemyBullet : public Entity
{
public:
	EnemyBullet();
	EnemyBullet(int px, int py, int pw, int ph);
	~EnemyBullet();
	void Move(Graphics^ g);
	void Draw_Bullet(Graphics^ g);
};

