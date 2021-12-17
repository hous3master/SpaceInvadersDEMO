#pragma once
#include "Entity.h"
class FriendlyBullet : public Entity
{
public:
	FriendlyBullet();
	FriendlyBullet(int px, int py, int pw, int ph);
	~FriendlyBullet();
	void Move(Graphics^ g);
	void Draw_Bullet(Graphics^ g);
};



