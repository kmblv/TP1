#pragma once
#include "Ship.h"

class Sailboat : public Ship {
private:
	string type, name;
	int hull_length, speed;
	bool is_peaceful;
public:
	Sailboat(string type, string name, bool is_peaceful, int hull_length, int speed, int crew);
	Sailboat();
	~Sailboat();
	virtual string getData() override;
};