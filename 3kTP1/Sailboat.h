#pragma once
#include "Ship.h"

class Sailboat : public Ship {
private:
	string type, name;
	int hull_length, speed;
	bool is_peaceful;
public:
	Sailboat();
	Sailboat(string type, string name, bool is_peaceful, int hull_length, int speed, int crew);
	Sailboat(Sailboat& temp);
	~Sailboat();
	virtual string getData() override;
};

/////////////////////

Sailboat::Sailboat(string type, string name, bool is_peaceful, int hull_length, int speed, int crew) {
	cout << "Sailboat has been added" << endl;
	this->type = type;
	this->name = name;
	this->is_peaceful = is_peaceful;
	this->hull_length = hull_length;
	this->speed = speed;
	this->crew = crew;
}
Sailboat::Sailboat() {
	cout << "\tSailboat has been added" << endl;
	this->type = "based";
	this->name = "Titanic";
	this->is_peaceful = true;
	this->hull_length = 800;
	this->speed = 60;
	this->crew = 3000;
}




Sailboat::Sailboat(Sailboat& temp) {
	cout << "Sailboat has been added" << endl;
	type = temp.type;
	name = temp.name;
	is_peaceful = temp.is_peaceful;
	hull_length = temp.hull_length;
	speed = temp.speed;
	crew = temp.crew;
}



Sailboat::~Sailboat() {
	cout << "\tSailboat has been deleted" << endl;
}


string Sailboat::getData() {
	return "Type: " + type + "\n" + "Name: " + name + "\n"
		+ "Is it peaceful?(1/0)) " + to_string(is_peaceful) + "\n"
		+ "Hull material: " + to_string(hull_length) + "\n"
		+ "Speed = " + to_string(speed) + "\n"
		+ "Crew: " + to_string(crew) + "\n";
}