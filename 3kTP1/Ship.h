#pragma once

#include<iostream>
#include<string>
#include"Keeper.h"
using namespace std;


class Ship {

protected:
	int crew;

public:
	Ship();
	Ship(int crew);
	virtual ~Ship();
	virtual string getData() = 0;
	//virtual string Print() = 0;
};