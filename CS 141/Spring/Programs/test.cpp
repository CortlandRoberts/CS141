/**------------------------------------------

    Program 3:  Wordle Reload
    Course: CS 141, Spring 2022.
    System: Windows using Atom
    Author: Cortland Roberts

 ---------------------------------------------*/
 #include <iostream>
 #include <ctime> //Timer functions
 #include <fstream> //file input and output
 #include <vector> //allows for vectors
 #include <cassert> // for the assert statement
 #include <cctype> // for toUpper. function
 #include <sstream> //using getline() function
 #include <string>  // .compare

using namespace std;
//displays the messqage of the game;
void displayWelcomeMessage(){
  cout << "Program 3: Wordle Reload" << endl;
  cout << "CS 141, Spring 2022, UIC" << endl;

  cout << "The objective of this game is to guess the randomly selected" << endl;
  cout << "word within a given number of attempts. You can select either" << endl;
  cout << "a three or five word board.";
  cout << endl;

  cout << "At the conclusion of the game, stats will be displayed." << endl;
  cout << "Indicators will be given if characters of the user entered" << endl;
  cout << "word are reflected in the guessed word." << endl;

  cout << "  - If the character is in the correct position, the character will display as an uppercase value." << endl;

  cout << "  - If the character is within the random word, the character will display as a lowercase value." << endl;

  cout << "  - If you enter a character that is not in the word, an asterisk " << "'*'" << " will display." << endl;
  cout << endl;

  cout << endl;
}

//generate 3 letter board
void generateThreeBoard(char board[3]){
  for(int i = 0; i < 3; i++){
      cout << "[ " << board[i] << " ]" << " ";
  } // end of outer loop

  cout << endl;
}// end of generate file


void insertBoard(char board[3]){
  string word;
  cout << endl;
  cout << "Please enter word --> ";
  cin >> word;
  for(int i = 0; i < word.size();  i++){
      board[i] = word.at(i);
  }
 //inserting the word into the board

}



void getWordleWords(vector <string> &WordleWords, vector <string> &threeLetters, vector <string> &fiveLetters){
  // Read in dictionary into dictionary vector
   ifstream read2;                      // Declare an input stream for reading
   read2.open( "wordlewords.txt");       // Open dictionary file
   assert( read2.fail() == false );     // Ensure file open worked

   // If you had previously used vector dictionary, then you might want to clear it
   // before continuing to use it, though that is not the case here.
   read2.clear();

   // Keep repeating while input from the file yields a word
   string wodWord;                         // Store a single input word
   while( read2 >> wodWord) {           // While there is another word to be read
       // Add this new word to the end of the vector, growing it in the process
          if (wodWord.size() == 3) {
            threeLetters.push_back(wodWord);
          }
          if (wodWord.size() == 5) {
            fiveLetters.push_back(wodWord);
          }

   }

   // Close the dictionary file
   read2.close();



}


//binary search function to get the words
int binarySearchString(string searchWord, vector< string> WordleWords){
   int mid;
   int low;
   int high;

   low = 0;
   high = WordleWords.size() - 1;

   while (high >= low) {
      mid = (high + low) / 2;
      int searchResult = searchWord.compare(WordleWords[mid]);
      if (searchResult == 0) {
         return mid;
      }
      else if (searchResult < 0) {
         high = mid - 1;
      }
      else {
         low = mid + 1;
      }
   }
   return -1; // not found
}

//generating a function for option one.
int valCheck(char board[3],vector <string> threeLetters, string randomWord){
  string word2; // to collect the words from the board
  cout << endl;

  //going to read the char's from the board and put them into a string
  for(int b = 0; b < 3; b++){
      word2 += board[b];
  }
//passing the word into a binary search function that will return the word index if it word is in there or not.
int result = binarySearchString(word2, threeLetters);

    return result;
} // end of choiceTwo Function


void playGame(char board[3],vector <string> threeLetters, string randomWord){
  int attempsFour = 4;
  string word2;
  while(true){
    insertBoard(board);
    attempsFour--;
    if(valCheck(board,threeLetters, randomWord) == -1){ //going to have to add parameters in the function for valCheck
      cout << "Not a playable word, please select another word." << endl;
      continue;
    }else{
      for(int i = 0; i < 3; i++){
        if(word2[i] == randomWord[i]){
          word2.at(i) = toupper(word2.at(i));
        }else{
            board[i] = word2.at(i);
            }
      }
    }
      // checks to see if the board is correct


  } // end of while loop



} // end of pleayGame




int main(){
  srand(1);
  displayWelcomeMessage();
  //vector <string> dictionary;
  string threeLetterWord;
  string randomWord;
  char board[3] = { ' ', ' ', ' '};
  vector <string> WordleWords;
  vector <string> threeLetters;
  vector <string> fiveLetters;
  //cout << "passed vec call";
  getWordleWords(WordleWords,threeLetters,fiveLetters);
  randomWord = threeLetters[rand() % threeLetters.size()];

  int option; //for user to pick an option;
    cout << endl;
    cout << "Select a menu option:" << endl;
    cout << "  1. To play Wordle Reload 3 letter play" << endl;
    cout << "  2. To play Wordle Reload 5 letter play" << endl;
    cout << "  3. Exit the program" << endl;
    cout << "Your choice --> ";
    cin >> option;
        if(option == 1){
          cout << "To get started, enter your first 3 letter word." << endl;
          cout <<"You have 4 attempts to guess the random word." << endl;
          cout << "The timer will start after your first word entry. " << endl;
          cout << "Try to guess the word within 20 seconds." << endl;
        }
    while(true){
 // if the user picks option two
      if(option == 1){
      playGame(board);
        generateThreeBoard(board);
      } // end of option == 1

      if(option == 2){
        break;
      }

      if(option == 3){
        break;
      }

    } // end of while loop

  return 0;
}
