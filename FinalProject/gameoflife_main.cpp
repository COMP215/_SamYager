#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gameoflife.hpp"
using namespace std;

int main () {
	int stepnumber;
	LifeBoard life;

	cout << "How many steps would you like to take? (enter an integer) ";
	cin >> stepnumber;
	life.RunLifeBoard(stepnumber);

	return 0;
}