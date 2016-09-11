/* 
Sam Yager
3Lists.cpp
Takes in a file of words
Sorts into 3 distinct lists
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;

struct MyNode {
  string word_tracker;  //keeps track of all the words used 
  MyNode *next;     
  //a pointer used to point each struct of the linked list to the next
};

MyNode *newitem;
MyNode *current;
MyNode *head;
int num_words = 80000; //number of words in text file

void ReadText(string&);  //reads the file and makes an array of all the words used
void Insert(string);    //insert into list in sorted order
void DisplayList();     //displayes words in alphabetical order


int main() {
  string fileName;
  fileName = "sortedtext.txt";

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();  //starts clock to measure duration

  ReadText(fileName);
  DisplayList();

  end = chrono::system_clock::now();  //ends clock to measure duation

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
    current = NULL;
    inFP >> word;

    /*creates the first struct of the linked list*/
    newitem = new MyNode;
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
  MyNode *prev;   //pointer to previous node
  MyNode *newitem;  //pointer to newly created item
  MyNode *cur;    //pointer for traversing
  bool found;     //if position in list is found

  newitem = new MyNode;
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


void DisplayList() {
  /*
  Precondition: Before the function begins, the linked list is assumed to be a 
    list of words and the number of occurrence of each word. If there are no 
    words in the linked list, head will point to null and a message will print 
    to say the file is empty.
  Postcondition: Prints out an organized list of the words in the linked list.  
    Listing the words with multiple occurrence first then the words with 
    only one occurrence last, in a separate list.
  */
  ofstream myfile1;
  ofstream myfile2;
  ofstream myfile3;
  myfile1.open("list1.txt");
  myfile2.open("list2.txt");
  myfile3.open("list3.txt");

  int tracker = 0;

  if (head != NULL) {
    current = head;

    while (current != NULL) {
      if (tracker == 0) {
        myfile1 << current -> word_tracker << "\n";
        current = current -> next;
      }
      if (tracker == 1) {
        myfile2 << current -> word_tracker << "\n";
        current = current -> next;
      }
      if (tracker == 2) {
        myfile3 << current -> word_tracker << "\n";
        current = current -> next;
      }
      tracker = (tracker + 1) % 3;
    }
  }
  else {
    cout << "You're file has no words!" << endl;
    exit(1);
  }
  myfile1.close();
  myfile2.close();
  myfile3.close();
}
