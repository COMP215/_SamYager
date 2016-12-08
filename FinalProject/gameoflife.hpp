#ifndef gameoflife_hpp
#define gameoflife_hpp

using namespace std;

class LifeBoard {
private:
	int arraysize;
	int lifeboard[6][6];
	int stepboard[6][6];	//used for each step to create a new lifeboard
public:
	LifeBoard() {arraysize = 6;};
	void CreateBoard();					//creates a randomized board
	void PrintBoard();					//prints the game board
	void OneStep();						//completes one step of the game of life
	int CountLiving(int, int);			//counts and returns a cell's the number of living neighbors
	void SwitchDead(int, int);		//checks if a dead cell is reborn
	void SwitchLiving(int, int);		//checks if a living cell dies
	void RunLifeBoard(int);
};

#endif