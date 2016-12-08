/*
Sam Yager
The Game of Life
Rules: 
If the cell is dead:

    Birth: if exactly three of its neighbours are alive, the cell will become alive at the next step.

If the cell is already alive:

    Survival: if the cell has two or three live neighbours, the cell remains alive.

Otherwise, the cell will die:

    Death by loneliness: if the cell has only zero or one live neighbours, the cell will become dead at the next step.
    Death by overcrowding: if the cell alive and has more than three live neighbours, the cell also dies.

example: https://fiftyexamples.readthedocs.io/en/latest/life.html
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "gameoflife.hpp"

void LifeBoard::CreateBoard() {
	//creates a board using a pseudo-random generator, where 1 is alive and 0 is dead
	srand(time(0));
	for (int i=0; i < arraysize; i++) {
		for (int j=0; j < arraysize; j++) {
			lifeboard[i][j] = rand()%2;
		}
	}
}

void LifeBoard::PrintBoard() {
	//prints board as an n x n square
	for (int i=0; i < arraysize; i++) {
		for (int j=0; j < arraysize; j++) {
			cout << lifeboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void LifeBoard::OneStep() {
	//completes one step of the game of life
	for (int i=0; i < arraysize; i++) {
		for (int j=0; j < arraysize; j++) {
			if (lifeboard[i][j] == 0) {
				SwitchDead(i,j);
			}
			else if (lifeboard[i][j] == 1) {
				SwitchLiving(i,j);
			}
		}
	}
	for (int i=0; i < arraysize; i++) {
		for (int j=0; j < arraysize; j++) {
			lifeboard[i][j] = stepboard[i][j];
		}
	}
}

int LifeBoard::CountLiving (int x, int y) {
	int numalive = 0;	//number of living neighbors

	bool top = true;
	bool bottom = true;
	bool left = true;
	bool right = true;

	if (y == 0)	{
		top = false;
	}
	if (y == (arraysize-1)) {
		bottom = false;
	}
	if (x == 0) {
		right = false;
	}
	if (x == (arraysize-1)) {
		left = false;
	}

	if (top == true && bottom == true && right == true && left == true) {	//not an edge
		for (int i = (x-1) ; i < (x+2); i++) {
			for (int j = (y-1); j < (y+2); j++) {
				if (i == x & j == y) {}	//don't count the cell itself
				else {
					if (lifeboard[i][j] == 1)
						numalive = numalive + 1;
				}
			}
		}
	}

	if (top == false && right == true && left == true) {	//top but not a corner, y = 0
		if (lifeboard[x-1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y+1] == 1) {
			numalive = numalive + 1;
		}
	}
	if (top == false && right == false) {		//top right corner, y=0, x=0
		if (lifeboard[x][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y+1] == 1) {
			numalive = numalive + 1;
		}
	}
	if (top == false && left == false) {		//top left corner, y=0, x=max
		if (lifeboard[x-1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y+1] == 1) {
			numalive = numalive + 1;
		}
	}
	if (left == false && top == true && bottom == true) {	//left not top or bottom, x=max
		if (lifeboard[x-1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y+1] == 1) {
			numalive = numalive + 1;
		}
	}
	if (right == false && top == true && bottom == true) {	//right not top or bottom, x=0
		if (lifeboard[x][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y+1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y+1] == 1) {
			numalive = numalive + 1;
		}
	}
	if (bottom == false && right == true && left == true) {	//bottom but not a corner, y=max
		if (lifeboard[x-1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y] == 1) {
			numalive = numalive + 1;
		}	
	}
	if (bottom == false && right == false) {		//bottom right corner, y=max, x=0
		if (lifeboard[x][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x+1][y] == 1) {
			numalive = numalive + 1;
		}
	}
	if (bottom == false && left == false) {	//bottom left corner, y=max, x=max
		if (lifeboard[x-1][y-1] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x-1][y] == 1) {
			numalive = numalive + 1;
		}
		if (lifeboard[x][y-1] == 1) {
			numalive = numalive + 1;
		}
	}
	return numalive;
}

void LifeBoard::SwitchDead(int x, int y) {
	//given the location (x,y) of a dead cell, see if it is reborn
	
	//Birth: if exactly three of its neighbours are alive, the cell will become alive at the next step.

	int living = CountLiving(x,y);

	if (living == 3) {
		stepboard[x][y] = 1;
	}
	else {
		stepboard[x][y] = 0;
	}
}

void LifeBoard::SwitchLiving(int x, int y) {
	//given the location of a living cell, see if it dies

    //Survival: if the cell has two or three live neighbours, the cell remains alive
    //Death by loneliness: if the cell has only zero or one live neighbours, the cell will become dead at the next step.
    //Death by overcrowding: if the cell alive and has more than three live neighbours, the cell also dies.

	int living = CountLiving(x,y);

	if (living == 2 || living == 3) {
		stepboard[x][y] = 1;
	}
	else {
		stepboard[x][y] = 0;
	}
}

void LifeBoard::RunLifeBoard(int numsteps) {
	//runs the game of life given a number of steps
	CreateBoard();
	cout << "Initial board: " << endl;
	PrintBoard();

	for (int i=0; i<numsteps; i++) {
		cout << "Step: " << (i+1) << endl;
		OneStep();
		PrintBoard();
	}
}