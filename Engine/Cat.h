#pragma once

class Cat
{
public:
	int x;
	int y;
	static constexpr int width = 104;
	static constexpr int height = 80;
	int frame = 0;
	int frameN = 0;
	bool facesLeft = true;
	bool hasKitten = false;
	void frameUpdate();
	void movement(bool right, bool left, bool down, bool up);
	void update(bool right, bool left, bool down, bool up);
};