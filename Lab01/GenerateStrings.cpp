/* 
Sam Yager
GenerateStrings.cpp
Generate a list of random strings
A number of strings will be generated
Store the list of generated strings in a file*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

int num_words = 80000;	//number of words to be generated
string gen_random(int);	
//generates a random string take input of how long the string will be
void write_file();		
//opens a file and writes num_words number of randomly generated words to that file

int main() {
  write_file();
}

 string gen_random(int len) {
 /* Take an input of an int called len. Then generates a random string of length len.*/
  string word;
  char holder;
  for (int i = 0; i < len; ++i) {
    int randomChar = rand()%(26);
    holder = 'a' + randomChar;
    word = word + holder;
  }
  return word;
  word = "";
 }

void write_file() {
  ofstream myfile;
  myfile.open ("text.txt");
  srand((unsigned)time(0));
  for (int j=0; j<num_words; ++j) {
    myfile << gen_random(10) << "\n";
  }
  myfile.close();
}

