#pragma once

#include "Ship.h"

class Speedboat : public Ship {
private:
	string purpose, hull_material, driving_characteristics;
	int speed;
public:
	Speedboat(string purpose,
		string hull_material,
		string driving_characteristics,
		int speed,
		int crew);
	Speedboat();
	~Speedboat();
	virtual string getData() override;

};