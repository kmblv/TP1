#include "Sailboat.h"

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
	cout << "Sailboat has been added" << endl;
	this->type = "based";
	this->name = "Titanic";
	this->is_peaceful = true;
	this->hull_length = 800;
	this->speed = 60;
	this->crew = 3000;
}


Sailboat::~Sailboat() {
	cout << "Sailboat has been deleted" << endl;
}


string Sailboat::getData() {
	return type + "\n" + name + "\n"
		+ to_string(is_peaceful) + "\n"
		+ to_string(hull_length) + "\n"
		+ to_string(speed) + "\n"
		+ to_string(crew) + "\n";
}