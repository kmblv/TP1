#include "Ship.h"

Ship::Ship(int crew) : crew(crew) {
	cout << "Ship has been added1" << endl;
}
Ship::Ship() : crew(0) {
	cout << "Ship has been added" << endl;
}
Ship::~Ship() {
	cout << "Ship has been deleted" << endl;
}
