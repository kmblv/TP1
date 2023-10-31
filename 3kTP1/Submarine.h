#pragma once
#include "Ship.h"
class Submarine :public Ship {
private:
	double Length, Width;
	int TimeUnderWater, MaxUnderWaterSpeed;
	string Weapon;
public:

	Submarine();
	Submarine(int crew, double Length, double Width, int TimeUnderWater, int MaxUnderWaterSpeed, string Weapon);
	Submarine(Submarine& temp);
	~Submarine();
	virtual string getPrintData() override;
	virtual string getData() override;
	//virtual string Print() override;
};
///////////////////////
Submarine::Submarine(int crew, double Length, double Width, int TimeUnderWater, int MaxUnderWaterSpeed, string Weapon) {
	cout << "\tSubmarine has been added" << endl;
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



Submarine::Submarine(Submarine& temp) {
	cout << "Submarine has been added" << endl;
	crew = temp.crew;
	Length = temp.Length;
	Width = temp.Width;
	TimeUnderWater = temp.TimeUnderWater;
	MaxUnderWaterSpeed = temp.MaxUnderWaterSpeed;
	Weapon = temp.Weapon;
}

Submarine::~Submarine() {
	cout << "\tSubmarine has been deleted" << endl;
}

string Submarine::getPrintData() {
	return "Submarine\nCrew " + to_string(crew) + "\n" +
		"Length = " + to_string(Length) + "\n" +
		"Width = " + to_string(Width) + "\n" +
		"TimeUnderWater = " + to_string(TimeUnderWater) + "\n" +
		"MaxUnderWaterSpeed = " + to_string(MaxUnderWaterSpeed) + "\n" +
		"Weapon: " + Weapon + "\n";
}

string Submarine::getData() {
	return "Submarine\n" + to_string(crew) + "\n" +
		to_string(Length) + "\n" +
		to_string(Width) + "\n" +
		to_string(TimeUnderWater) + "\n" +
		to_string(MaxUnderWaterSpeed) + "\n" +
		Weapon + "\n";
}
