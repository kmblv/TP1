#pragma once

#include "Ship.h"

class Speedboat : public Ship {
private:
	string purpose, hull_material, driving_characteristics;
	int speed;
public:
	Speedboat();
	Speedboat(string purpose, string hull_material, string driving_characteristics, int speed, int crew);
	Speedboat(Speedboat& temp);
	~Speedboat();
	virtual string getPrintData() override;
	virtual string getData() override;

};

Speedboat::Speedboat(string purpose, string hull_material, string driving_characteristics, int speed, int crew) {
	cout << "\tSpeedboat has been added" << endl;
	this->purpose = purpose;
	this->hull_material = hull_material;
	this->driving_characteristics = driving_characteristics;
	this->speed = speed;
	this->crew = crew;
}

Speedboat::Speedboat() {
	cout << "Speedboat has been added" << endl;
	this->purpose = "unknown";
	this->hull_material = "Steel";
	this->driving_characteristics = "-";
	this->speed = 40;
	this->crew = 4;
}


Speedboat::Speedboat(Speedboat& temp) {
	purpose = temp.purpose;
	hull_material = temp.hull_material;
	driving_characteristics = temp.driving_characteristics;
	speed = temp.speed;
	crew = temp.crew;
}


Speedboat::~Speedboat() {
	cout << "\tSpeedboat has been deleted" << endl;
}

string Speedboat::getPrintData() {
	return "Submarine\nCrew " + to_string(crew) + "\n" +
		"Purpose: " + purpose + "\n" +
		"Hull material: " + hull_material + "\n" +
		"Driving characteristics: " + driving_characteristics + "\n" +
		"Speed = " + to_string(speed) + "\n";
}

string Speedboat::getData() {
	return "Speedboat\n" + to_string(crew) + "\n" +
		purpose + "\n" +
		hull_material + "\n" +
		driving_characteristics + "\n" +
		to_string(speed) + "\n";
}