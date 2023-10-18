#pragma once
#include "Ship.h"
class Submarine :public Ship {
private:
	double Length, Width;
	int TimeUnderWater, MaxUnderWaterSpeed;
	string Weapon;
public:
	Submarine(int crew, double Length, double Width, int TimeUnderWater, int MaxUnderWaterSpeed, string Weapon);
	Submarine();
	~Submarine();
	virtual string getData() override;
	//virtual string Print() override;
};