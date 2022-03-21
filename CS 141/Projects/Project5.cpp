#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;
// function for reading file
void readFIle(vector<string> &Word){
  ifstream read;
  read.open("dictionary-3to5-letters.txt");
  assert( read.fail() == false);

  Word.clear();
  string line;
  while(read >> line){
    Word.push_back(line);

  }
  read.close();
} // end of readfile function





// function for options
void Pick_options(vector<string> &Word){
  char Choice;
  bool pick = false;
  int num;
  cout << "Enter Q to quit or B to begin: ";
  cin >> Choice;
  Choice = toupper(Choice);
  if(Choice == 'B'){
    cout << "Choose your board size (must be a number greater than or equal to 4): ";
    cin >> num;
    if(num < 4){
      cout << "The board size must be at least 4. Retry." << endl;
    }
    else{
      while(num >= 4){
        char letter;
        cout << "Enter one of the following: " << endl
  << "R to rotate a row or column," << endl
  << "C to view what the completed board should look like, " << endl
  << "B to reset the board back to the beginning, " << endl
  << "G to generate a new board with new random words, " << endl
  << "S to have the computer automatically solve a board that you enter (5 points extra credit), " << endl
  << "Q to quit." << endl;
cout << "Your choice: ";
cin >> letter;
letter = toupper(letter);


        /*
  SOME BIG FUNCTION HERE FOR DISPLAYING THE BOARD;
        */
      } // end of while
    } // end of else option
  } // end of if(Choose == 'B') option
    else if(Choice == 'Q'){
      cout << "Thank you for playing!" << endl;
      cout << "Exiting Program;";
    }
}


int main(){
  vector<string>  Word;
  vector<string> Random_Word;
  readFIle(Word);
  cout <<  "You will be presented with a board that is filled" << endl <<
           "with scrambled words. Rotate the rows and columns" << endl <<
           "to get the words displayed in the right order."    << endl;

    cout << endl;
    cout << Word.size() << " words have been read in from the dictionary." << endl;
    Pick_options(Word);

  return 0;
}
