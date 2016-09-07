/* 
Sam Yager
Sort.cpp
Takes in a file of random words
Sorts alphabetically and stores in new file
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

struct myNode {
  string word_tracker;  //keeps track of all the words used 
  myNode *next;     
  //a pointer used to point each struct of the linked list to the next
};

myNode *newitem;
myNode *current;
myNode *head;
int num_words = 80000; //number of words in text file to be sorted

void readText(string&);  //reads the file and makes an array of all the words used
void Insert(string);    //insert into list in sorted order
void displaylist();     //displayes words in alphabetical order


int main() {
  string fileName;
  fileName = "text.txt";

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();	//starts clock to measure duration

  readText(fileName);
  displaylist();

  end = chrono::system_clock::now();	//ends clock to measure duration

  chrono::duration<double> elapsed_seconds = end-start;
  cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
}

void readText(string& file) {
  /*
  Precondition: The function takes a file name. 
  Postcondition: The function begins by checking if the file is valid. It then 
    creates a linked list of the words within the text file. 
  */
  string word;  //used to hold words from the file to put into the linked list
  int counter;  //counts words to print
  ifstream inFP;
  inFP.open(file.c_str());

  if (inFP.good()) {

    head = NULL;
    current = NULL;
    inFP >> word;

    /*creates the first struct of the linked list*/
    newitem = new myNode;
    newitem -> word_tracker = word;
    newitem -> next = NULL;
    head = newitem;
    current = head;
    inFP >> word;

    counter = num_words;
    while (counter > 1) { 
      Insert(word);
      current = NULL;
      counter = counter-1;
      current = head;
      inFP >> word;
    }

    inFP.close();
  }
  else {
    cout << endl << "Error: invalid file name." << endl << endl;
    exit(1);
  }
}

void Insert(string newword) {
  /*
  Precondition: Before function begins, it is passed a word to be added to the 
    linked list. 
  Postcondition: This function iterates through the linked list to find where
    the new word should be inserted to keep the list in alphabetical order. 
    It then inserts the word into its correct spot in the list.
  */
  myNode *prev;   //pointer to previous node
  myNode *newitem;  //pointer to newly created item
  myNode *cur;    //pointer for traversing
  bool found;     //if position in list is found

  newitem = new myNode;
  newitem -> word_tracker = newword;

  cur = head;
  prev = NULL;
  found = false;
  //find correct spot in list
  while (cur && !found) {
    if (newitem -> word_tracker < cur -> word_tracker)
      found = true;
    else {
      prev = cur;
      cur = cur -> next;
    }
  }

  if (prev) {   //insert new item at end or in middle
    newitem -> next = cur;
    prev -> next = newitem;
  }
  else {      //insert at front of list
    newitem -> next = head;
    head = newitem;
  }
}


void displaylist() {
  /*
  Precondition: Before the function begins, the linked list is assumed to be a 
    list of words and the number of occurrence of each word. If there are no 
    words in the linked list, head will point to null and a message will print 
    to say the file is empty.
  Postcondition: Prints out an organized list of the words in the linked list.  
    Listing the words with multiple occurrence first then the words with 
    only one occurrence last, in a separate list.
  */
  ofstream myfile;
  myfile.open("sortedtext.txt");

  if (head != NULL) {
    current = head;

    while (current != NULL) {
      myfile << current -> word_tracker << "\n";
      current = current -> next;
    }
  }
  else {
    cout << "You're file has no words!" << endl;
    exit(1);
  }
}