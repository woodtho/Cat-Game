#include "Cat.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

void Cat::frameUpdate()
{
	frame++;
	frameN = frame % 30;
}

void Cat::movement(bool right, bool left, bool down, bool up)
{
	if (right) {
		facesLeft = false;
		x += 3;
	}
	if (left) {
		facesLeft = true;
		x -= 3;
	}
	if (down) {
		y += 3;
	}
	if (up) {
		y -= 3;
	}
}

void Cat::update(bool right, bool left, bool down, bool up)
{

	movement(right, left, down, up);
	const int rightSide = x + width;
	if (x < 0) {
		x = 0;
	}
	else if (rightSide >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - width;
	}

	const int bottom = y + height;
	if (y < 0) {
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight) {
		y = (Graphics::ScreenHeight - 1) - height;
	}
	
	frameUpdate();
}


