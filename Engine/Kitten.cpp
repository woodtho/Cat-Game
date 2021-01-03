#include "Kitten.h"
#include "Graphics.h"


void Kitten::Update()
{
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0) {
		x = 0;
		vx = -vx; 
	}
	else if (right >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	} 

	const int bottom = y + height;
	if (y < 0) {
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight) {
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}

	if (vx <= 0) {
		facesLeft = true;
	}
	else {
		facesLeft = false;
	}

	if (InBed == true) {
		frame++;
		frameN = frame % 120;
		if (frameN > 59) {
			facesLeft = false;
		}
		else {
			facesLeft = true;
		}
	}
	

}
