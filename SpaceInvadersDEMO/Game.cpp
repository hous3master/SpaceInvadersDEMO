#include "Game.h"
Game::Game() {
	objSpaceship = new Spaceship(250, 520, 1, 1);
	timer1 = time(0);
	end_flag = false;
	//Insertion of 5 rows of 10 aliens in each one
	int height = 0;
	int width = 100;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			arrEntity.push_back(new Alien(width, height, 1, 1));
			width += 40;
		}
		height += 40;
		width = 100;
	}
}
Game::~Game(){}
void Game::Draw_arrEntity(Graphics^ g, Bitmap^ bmpAlien) {
	for (int i = 0; i < arrEntity.size(); i++) {
		if (dynamic_cast<Alien*> (arrEntity.at(i))) {
			((Alien*)arrEntity.at(i))->Move(g);
			((Alien*)arrEntity.at(i))->Draw_from_image(g, bmpAlien);
		}
		if (dynamic_cast<FriendlyBullet*> (arrEntity.at(i))) {
			((FriendlyBullet*)arrEntity.at(i))->Move(g);
			((FriendlyBullet*)arrEntity.at(i))->Draw_Bullet(g);
			//Delete bullets out of map
			if (((FriendlyBullet*)arrEntity.at(i))->return_flag()) {
				arrEntity.erase(arrEntity.begin() + i);
				break;
			}		
		}
		if (dynamic_cast<EnemyBullet*> (arrEntity.at(i))) {
			((EnemyBullet*)arrEntity.at(i))->Move(g);
			((EnemyBullet*)arrEntity.at(i))->Draw_Bullet(g);
			//Delete bullets out of map
			if (((EnemyBullet*)arrEntity.at(i))->return_flag()) {
				arrEntity.erase(arrEntity.begin() + i);
				break;
			}
		}
	}
}
void Game::Draw_SpaceShip(Graphics^ g, Bitmap^ bmp) {
	objSpaceship->Draw_from_image(g, bmp);
	objSpaceship->Move(g);
}
int Game::TotalFriendlyBullets() {
	int total = 0;
	for (int i = 0; i < arrEntity.size(); i++) {
		if (dynamic_cast<FriendlyBullet*> (arrEntity.at(i))) {
			total++;
		}
	}
	return total;
}
int Game::TotalAliens() {
	int total = 0;
	for (int i = 0; i < arrEntity.size(); i++) {
		if (dynamic_cast<Alien*> (arrEntity.at(i))) {
			total++;
		}
	}
	return total;
}
void Game::EnemyShooting() {
	System::Random^ rnd = gcnew System::Random();
	//Every second a random alien shoots
	if (difftime(time(0), timer1) > 1) {
		timer1 = time(0);
		int ShootingAlienIDX, x, y;
		ShootingAlienIDX = rnd->Next(0, TotalAliens());
		while (!dynamic_cast<Alien*> (arrEntity.at(ShootingAlienIDX))) {
			ShootingAlienIDX++;
			if (ShootingAlienIDX >= arrEntity.size())
				ShootingAlienIDX == 0;
		}
		x = arrEntity.at(ShootingAlienIDX)->return_x();
		y = arrEntity.at(ShootingAlienIDX)->return_y();
		arrEntity.push_back(new EnemyBullet(x, y, 10 ,10));
	}
	delete rnd;
}
void Game::Colission() {
	for (int i = 0; i < arrEntity.size(); i++) {
		//CASE: Colission player-enemybullet DO: delete bullet and lifes dicrease
		if (dynamic_cast<EnemyBullet*> (arrEntity.at(i))) {
			if (arrEntity.at(i)->return_rectangle().IntersectsWith(objSpaceship->return_rectangle())) {
				objSpaceship->new_lifes(objSpaceship->return_lifes() - 1);
				arrEntity.erase(arrEntity.begin() + i);
				break;
			}
		}
		//CASE: Colission alien-friendlybullet DO: delete both objects
		if (dynamic_cast<Alien*> (arrEntity.at(i))) {
			for (int j = i; j < arrEntity.size(); j++) {
				if (dynamic_cast<FriendlyBullet*> (arrEntity.at(j))) {
					if (arrEntity.at(i)->return_rectangle().IntersectsWith(arrEntity.at(j)->return_rectangle())) {
						arrEntity.erase(arrEntity.begin() + j);
						arrEntity.erase(arrEntity.begin() + i);
						break;
					}
				}
			}
		}
		//CASE: Colission alien-spaceship DO: end game
		if (dynamic_cast<Alien*> (arrEntity.at(i))) {
			if (arrEntity.at(i)->return_rectangle().IntersectsWith(objSpaceship->return_rectangle()))
				end_flag = true;
		}
	}
}
bool Game::End_Game() {
	if (objSpaceship->return_lifes() <= 0 || TotalAliens() <= 0 || end_flag)
		return true;
	return false;
}
System::String^ Game::return_text_points() {
	System::String^ points_text;
	points_text = ((50 - TotalAliens()) * 100).ToString();
	return points_text;
}
System::String^ Game::return_text_lifes() {
	System::String^ lifes_text;
	lifes_text = objSpaceship->return_lifes().ToString();
	return lifes_text;
}
void Game::new_orientation(direction new_data) {
	objSpaceship->new_orientation(new_data);
}
void Game::shoot() {
	if (TotalFriendlyBullets() < 3)
		arrEntity.push_back(new FriendlyBullet(objSpaceship->return_x() + 25, objSpaceship->return_y() - 10, 10, 10));
}
