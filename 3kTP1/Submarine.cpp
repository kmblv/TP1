#include"Submarine.h"
Submarine::Submarine(int crew, double Length, double Width, int TimeUnderWater, int MaxUnderWaterSpeed, string Weapon) {
	cout << "Submarine has been added" << endl;
	this->crew = crew;
	this->Length = Length;
	this->Width = Width;
	this->TimeUnderWater = TimeUnderWater;
	this->MaxUnderWaterSpeed = MaxUnderWaterSpeed;
	this->Weapon = Weapon;
}
Submarine::Submarine() {
	cout << "Submarine has been added" << endl;
	this->crew = 100;
	this->Length = 300;
	this->Width = 4;
	this->TimeUnderWater = 108000;
	this->MaxUnderWaterSpeed = 80;
	this->Weapon = "cannon";
}
Submarine::~Submarine() {
	cout << "Submarine has been deleted" << endl;
}
string Submarine::getData() {
	return "Submarine\n" + to_string(crew) + "\n" +
		to_string(Length) + "\n" +
		to_string(Width) + "\n" +
		to_string(TimeUnderWater) + "\n" +
		to_string(MaxUnderWaterSpeed) + "\n" +
		Weapon + "\n";
}