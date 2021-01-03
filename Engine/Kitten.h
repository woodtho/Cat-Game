#pragma once

class Kitten 
{
public:
	void Update();
	int x;
	int y;
	bool InMouth = false;
	bool InBed = false;
	int frame;
	int frameN;
	int vx;
	int vy;
	bool facesLeft = true;
	int mainR = 189;
	int mainG = 189;
	int mainB = 189;
	int accentR = 97;
	int accentG = 97;
	int accentB = 97;
	static constexpr int width = 26;
	static constexpr int height = 20;
};