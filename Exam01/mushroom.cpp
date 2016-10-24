/* 
Sam Yager
Exam 01
Mushroom Problem: mushroom.cpp
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int satchelsize = 10;		//the size of the satchel

class Node {
public:
	Node *pointer;
	string common_name;
	string scientific_name;
	int quantity;
	int totalvalue;
	int priceperoz;
	int quantitytaken;
	int valuetaken;
	Node() {pointer = NULL; quantity = totalvalue = priceperoz = quantitytaken = valuetaken = 0;};
};

class MushroomCollector {
	Node *head_;
	Node *tail_;
public:
	int moneymade;			//totalvalue of all mushrooms taken
	MushroomCollector() {moneymade = 0; head_ = tail_ = NULL;};
	void ReadFile(string);	//reads an input file that has been passed to it
	void PricePerOz();		//finds the price per oz of each mushroom found
	void WhatToTake();		//Finds what mushroom combination will yield the largest reward
	void PrintTaken();		//Prints what mushrooms you took and the total value
};

void MushroomCollector::ReadFile(string filename) {
/* 
Reads file into the linked list assuming file is a list of mushrooms 
set up with each line listing the mushroom type as follows:
common_name, scientific_name, quantity, totalvalue
*/
	Node *addtolist;

	char character;
	int number;
	ifstream inFP;
	inFP.open(filename.c_str());
	if (inFP.good()) {
		inFP >> character;
		while (inFP.eof() != true) {
			if (head_ == NULL) {
					head_ = new Node();
					addtolist = head_;
					tail_ = head_;
					addtolist -> common_name = character;
				} else {
					addtolist = new Node();
					tail_ -> pointer = addtolist;
					tail_ = addtolist;
					addtolist -> common_name = addtolist -> common_name + character;
				}
			inFP >> character;
			while (character != ',') {
				addtolist -> common_name = addtolist -> common_name + character;
				inFP >> character;
			}
			inFP >> character;
			while (character != ',') {
				addtolist -> scientific_name = addtolist -> scientific_name + character;
				inFP >> character;
			}
			inFP >> character;
			while (character != ',') {
				addtolist -> quantity = addtolist -> quantity + character;
				inFP >> character;
			}
			inFP >> character;
			while (character != ',') {
				addtolist -> totalvalue = addtolist -> totalvalue + character;
				inFP >> character;
			}
			inFP >> character;
		}
	}
}

void MushroomCollector::PricePerOz() {
/* finds the price per oz of each mushroom */
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		iterate -> priceperoz = iterate -> totalvalue / iterate -> quantity;
	}
}

void MushroomCollector::WhatToTake() {
/* finds the mushrooms with the largest price per oz to take */
	PricePerOz();

	Node *lookthrough;
	Node *beforelookthrough;
	Node *taker;
	Node *deleter;
	lookthrough = head_;

	while (satchelsize != 0)	{
		int maxpriceperoz = 0;
		while (lookthrough != NULL) {
			//find max price per oz
			if (lookthrough -> priceperoz > maxpriceperoz) {
				taker = lookthrough;
				deleter = beforelookthrough;
				cout << "newbie" << endl;
			}
			beforelookthrough = lookthrough;
			lookthrough = lookthrough -> pointer;
		}
		if (taker -> quantity < satchelsize) {
			taker -> quantitytaken = taker -> quantity;
			taker -> valuetaken = taker -> totalvalue;
			satchelsize = satchelsize - taker -> quantity;
		} else if (taker -> quantity >= satchelsize) {
			taker -> quantitytaken = satchelsize;
			taker -> valuetaken = taker -> priceperoz * satchelsize;

			satchelsize = 0;
		}
		moneymade = moneymade + taker -> valuetaken;
		lookthrough = head_;
	}
	cout << "here" << endl;
	satchelsize = satchelsize - 1;
}

void MushroomCollector::PrintTaken() {
	Node *iterate;
	iterate = head_;
	while (iterate != NULL) {
		cout << iterate -> quantitytaken;
		cout << " ounces of " << iterate -> common_name;
		cout << "(" << iterate -> scientific_name << ") mushrooms\n";
		iterate = iterate -> pointer;
	}
	cout << "-------------------------------------" << endl;

	cout << "Total Value: $" << moneymade << endl;
}


int main() {
	MushroomCollector satchel;

	satchel.ReadFile("mushrooms_1.csv");
	satchel.WhatToTake();
	satchel.PrintTaken();

	return 0;
}