#include "Alien.h"
Alien::Alien() {}
Alien::Alien(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	dx = 10;
	dy = 0;
}
Alien::~Alien() {}
void Alien::Move(Graphics^ g) {
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) {
		dx *= -1;
		y += 40;
	}
	x += dx;
}
