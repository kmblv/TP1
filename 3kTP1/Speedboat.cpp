#include "Speedboat.h"
Speedboat::Speedboat(string purpose, string hull_material, string driving_characteristics, int speed, int crew) {
	cout << "Speedboat has been added" << endl;
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
Speedboat::~Speedboat() {
	cout << "Speedboat has been deleted" << endl;
}

string Speedboat::getData() {
	return purpose + "\n" +
		hull_material + "\n" +
		driving_characteristics + "\n" +
		to_string(speed) + "\n" +
		to_string(crew) + "\n";
}