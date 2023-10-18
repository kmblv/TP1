#include "Ship.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Speedboat.h"
int main(int argc, char* argv[]) {

	Speedboat s1("unknown", "Steel", "-", 40, 4);
	string s = s1.getData();
	cout << s;

	return 0;
}