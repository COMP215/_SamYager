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

struct MyNode {
  string word_tracker_;  //keeps track of all the words used 
  MyNode *next_;  //a pointer used to point each struct of the linked list to the next
};

MyNode *newitem;
MyNode *currrent;
MyNode *head;
int num_words = 90000; //number of words in text file to be sorted

void ReadText(string&);  //reads the file and makes an array of all the words used
void Insert(string);    //insert into list in sorted order
void DisplayList();     //displayes words in alphabetical order


int main() {
  string fileName;
  fileName = "text.txt";

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();	//starts clock to measure duration

  ReadText(fileName);
  DisplayList();

  end = chrono::system_clock::now();	//ends clock to measure duration

  chrono::duration<double> elapsed_seconds = end-start;
  cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
}

void ReadText(string& file) {
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
    currrent = NULL;
    inFP >> word;

    /*creates the first struct of the linked list*/
    newitem = new MyNode;
    newitem -> word_tracker_ = word;
    newitem -> next_ = NULL;
    head = newitem;
    currrent = head;
    inFP >> word;

    counter = num_words;
    while (counter > 1) { 
      Insert(word);
      currrent = NULL;
      counter = counter-1;
      currrent = head;
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
  MyNode *prev;   //pointer to previous node
  MyNode *newitem;  //pointer to newly created item
  MyNode *curr;    //pointer for traversing
  bool found;     //if position in list is found

  newitem = new MyNode;
  newitem -> word_tracker_ = newword;

  curr = head;
  prev = NULL;
  found = false;
  //find correct spot in list
  while (curr && !found) {
    if (newitem -> word_tracker_ < curr -> word_tracker_)
      found = true;
    else {
      prev = curr;
      curr = curr -> next_;
    }
  }

  if (prev) {   //insert new item at end or in middle
    newitem -> next_ = curr;
    prev -> next_ = newitem;
  }
  else {      //insert at front of list
    newitem -> next_ = head;
    head = newitem;
  }
}


void DisplayList() {
  /*
  Precondition: Before the function begins, the linked list is assumed to be a 
    list of words and the number of occurrrence of each word. If there are no 
    words in the linked list, head will point to null and a message will print 
    to say the file is empty.
  Postcondition: Prints out an organized list of the words in the linked list.  
    Listing the words with multiple occurrrence first then the words with 
    only one occurrrence last, in a separate list.
  */
  ofstream myfile;
  myfile.open("sortedtext.txt");

  if (head != NULL) {
    currrent = head;

    while (currrent != NULL) {
      myfile << currrent -> word_tracker_ << "\n";
      currrent = currrent -> next_;
    }
  }
  else {
    cout << "You're file has no words!" << endl;
    exit(1);
  }
}
