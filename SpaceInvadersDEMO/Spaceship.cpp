#include "Spaceship.h"
Spaceship::Spaceship() {}
Spaceship::Spaceship(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	lifes = 3;
	vertical_velocity = 0;
	horizontal_velocity = 25;
	new_orientation(direction::still);
}
Spaceship::~Spaceship() {}
void Spaceship::new_lifes(int new_data) { lifes = new_data; }
int Spaceship::return_lifes() { return lifes; }
