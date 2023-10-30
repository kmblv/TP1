#pragma once

#include<iostream>
#include<string>
#include"Keeper.h"
#include <chrono>
#include<thread>
using namespace std;


class Ship {

protected:
	int crew;

public:
	Ship();
	Ship(int crew);
	virtual ~Ship();
	virtual std::string getData() = 0;
};

Ship::Ship() : crew(0) {
	cout << "\tShip has been added" << endl;
}
Ship::~Ship() {
	cout << "\tShip has been deleted" << endl;
}
Ship::Ship(int crew) : crew(crew) {
	cout << "Ship has been added1" << endl;
}