#include "FriendlyBullet.h"
FriendlyBullet::FriendlyBullet() {}
FriendlyBullet::FriendlyBullet(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 6, 0, 0) {
	dx = 0;
	dy = -30;
}
FriendlyBullet::~FriendlyBullet() {}
void FriendlyBullet::Move(Graphics^ g) {
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) {
		dy = 0;
		flag = true;
	}
	y += dy;
}
void FriendlyBullet::Draw_Bullet(Graphics^ g) {
	Pen^ p = gcnew Pen(Color::White);
	p->Width = 5;
	SolidBrush^ b = gcnew SolidBrush(Color::LightGreen);

	g->DrawEllipse(p, x, y, w, h);
	g->FillEllipse(b, x, y, w, h);
}