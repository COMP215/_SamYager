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


int num_words = 90000;	//number of words to be generated
string GenRandomWord(int);	//generates a random string take input of how long the string will be
void WriteFile();		  //opens a file and writes num_words number of randomly generated words to that file

int main() {
  WriteFile();
}

 string GenRandomWord(int len) {
  /* 
  Precondition: Take an input of an int called len. Assumes len is a valid integer.
  Postcondition: Generates a random string called word of length len. All letters 
    in word are lowercase letters between a and z.
  */
  string word;  //holds word being generated and is returned by the function
  word = "";
  char random_char; //holds temporary character to be added to word
  for (int i = 0; i < len; ++i) {
    int randomChar = rand()%(26);
    random_char = 'a' + randomChar;
    word = word + random_char;
  }
  return word;
 }

void WriteFile() {
  /*
  Precondition: Takes no input. Assumes GenRandomWord works correctly to generate 
    a random word of length len.
  Postcondition: Writes num_words number of words to a newly opened filed "text.txt"
  */
  ofstream myfile; 
  myfile.open ("text.txt");
  srand((unsigned)time(0));
  for (int j=0; j<num_words; ++j) {
    myfile << GenRandomWord(10) << "\n";
  }
  myfile.close();
}

