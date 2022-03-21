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

  cout << "At the conlusion of the game, stats will be displayed." << endl;
  cout << "Indicators will be given if characters of the user entered" << endl;
  cout << "word are reflected in the guessed word." << endl;

  cout << "  - If the character is in the correct position, the character will display as an uppercase value." << endl;

  cout << "  - If the character is within the random word, the character will display as a lowercase value." << endl;

  cout << "  - If you enter a character that is not in the word, an asterisk " << "'*'" << " will display." << endl;
  cout << endl;

  cout << endl;
}

//generate 3 letter board
void generateThreeBoard(char board[3], string &printLine){
  for(int i = 0; i < 3; i++){
      printLine+= "[ ";
      printLine+= board[i];
      printLine+=" ]";
      printLine+=" ";
  } // end of outer loop
  printLine+= "\n";
  cout<<printLine;

}// end of generate file


//generate 5 letter board
void generateFiveBoard(char bigBoard[5], string &printLine){
  for(int i = 0; i < 5; i++){
    printLine+= "[ ";
    printLine+= bigBoard[i];
    printLine+=" ]";
    printLine+=" ";
  } // end of outer loop
  printLine+= "\n";
  cout<<printLine;

}


//function for splitting the words from the txt into different vectors.
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



// Search function that will either return the index if the word is in the dictionary or return -1 if the word is in the the txt file
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

// checks the index of the current word and compare it to the chat of user input;
int checkIndex(string currentWord, char userWord){
  for(int i = 0; i <3; i++){
    if(currentWord[i] == userWord)
      return i;
  }
  return -1;
}


//game for option 1(three letter board)
void playThree(char board[3],vector <string> &threeLetters, string randomWord, int &currentStreak, int &timeThree, int &guesses){
  string word; //user input word
  int streakCount = 0;
  int attemptsThree = 0;
  int elapsedSeconds = 0;     // Will store number of elapsed seconds
  string printLine = "";
  cout << "To get started, enter your first 3 letter word." << endl;
  cout <<"You have 4 attempts to guess the random word." << endl;
  cout << "The timer will start after your first word entry. " << endl;
  cout << "Try to guess the word within 20 seconds." << endl;
  time_t startTime = time( NULL);
  while(attemptsThree < 4){
  cout << endl;
  cout << "Please enter word --> ";
  cin >> word;
//lowercase all letters in the user word
  for(int i = 0; i <word.size(); i++){
    word[i] = tolower(word.at(i));
  }

  cout << endl;
  cout << endl;
//pass the word into the binarySearch function

  int result = binarySearchString(word, threeLetters);

    //making sure the user word is equal to 3
    if(word.length() != 3){
      cout << "Invalid word entry - please enter a word that is 3 characters long." << endl;
      continue;
    }

    cout << endl;
 //if the word is not into the dictionary
    if(result == -1){
    cout << "Not a playable word, please select another word." << endl;
    continue;
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
      board[i] = '*';
      for(int j = 0; j < 3; j++){
         //int wordIndex = checkIndex(randomWord, word[i]);
         if(word[i] == randomWord[j] && i==j){
           //insert the words into the board
              board[i] = toupper(word.at(i));
              break;
           }
          else if(word[i] == randomWord[j] && i != j){
            board[i] = tolower(word.at(i));

          }

       }



    } // end of for loop
    //check to make sure the board is all correct
    generateThreeBoard(board,printLine);

    attemptsThree++;
    //winning conditions

    if((word == randomWord) && (attemptsThree <= 4)){ //try board == random work next'
      //generateThreeBoard(board);
      elapsedSeconds = difftime( time( NULL), startTime);
      cout << endl;
      cout << "Nice Work!  You guessed the correct word" << endl;
      cout << " - You completed the board in: "<< elapsedSeconds << " seconds." << endl;
      cout << " - It took you " << attemptsThree << "/4 attempts." << endl;
      cout << endl;
      timeThree += elapsedSeconds;
      guesses++;
      streakCount = 1;
      break;
    }
    elapsedSeconds = difftime( time( NULL), startTime);
    if(elapsedSeconds > 20){
      cout << "Your time has expired.  Try again." << endl;
      cout << " - You are " << elapsedSeconds << " seconds over the 20 second time limit." << endl;
      streakCount = 0;
      break;
    }

    if(attemptsThree == 4) {
    cout << "Maximum amount of attempts have been reached. Try again." << endl;
    streakCount = 0;
    break;
    }

  } // end of while loop
    currentStreak = streakCount;
} // end of function


//game for option 2(five letter board)
void playFive(char bigBoard[5],vector <string> &fiveLetters, string randomFive, int &currentStreak, int &timeFive, int &guesses){
  string word; //user input word
  int streakCount = 0;
  int attemptsFive = 0;
  int elapsedSeconds = 0;
  string printLine = "";     // Will store number of elapsed seconds
  cout << "To get started, enter your first 5 letter word." << endl;
  cout <<"You have 6 attempts to guess the random word." << endl;
  cout << "The timer will start after your first word entry. " << endl;
  cout << "Try to guess the word within 40 seconds." << endl;
  time_t startTime = time( NULL);
  while(attemptsFive < 6){
  cout << "Please enter word --> ";
  cin >> word;

  for(int i = 0; i <word.size(); i++){
    word[i] = tolower(word.at(i));
  }
  cout << endl;
  cout << endl;

  int result = binarySearchString(word, fiveLetters);


    if(word.length() != 5){
      cout << "Invalid word entry - please enter a word that is 5 characters long." << endl;
      continue;
    }

    if(result == -1){
    cout << " Not a playable word, please select another word. " << endl;
    continue;
    }

    for(int i = 0; i < 5; i++){
       bigBoard[i] = '*';
       for(int j = 0; j < 5; j++){
         //int wordIndex = checkIndex(randomFive, word[i]);
         if(word[i] == randomFive[j] && i == j){
           //insert the words into the board
           bigBoard[i] = toupper(word.at(i));
           break;
       }
       else if(word[i] == randomFive[j] && i != j){
           bigBoard[i] = tolower(word.at(i));

       }

      }

    } // end of for loop

    //check to make sure the board is all correct
    generateFiveBoard(bigBoard, printLine);
    attemptsFive++;


    if((word == randomFive) && (attemptsFive <= 5)){ //try board == random work next'
      elapsedSeconds = difftime( time( NULL), startTime);
      cout << "Nice Work!  You guessed the correct word" << endl;
      cout << " - You completed the board in: "<< elapsedSeconds << " seconds." << endl;
      cout << " - It took you " << attemptsFive << "/6 attempts." << endl;
      cout << endl;
      timeFive += elapsedSeconds;
      guesses++;
      streakCount = 1;
      break;
    }

    elapsedSeconds = difftime( time( NULL), startTime);
    if(elapsedSeconds > 40){
      cout << "Your time has expired.  Try again." << endl;
      cout << " - You are " << elapsedSeconds << " seconds over the 20 second time limit." << endl;
      streakCount = 0;
      break;
    }

    if(attemptsFive >= 6) {
    cout << "Maximum amount of attempts have been reached. Try again." << endl;
    streakCount = 0;
    break;
    }


  } // end of while loop

  currentStreak = streakCount;

}// end of function;

//------------------This part is from the solution, everything else is my own doing ------------------------
//  Determine longest win streak
void assignLongestWinStreak(int &currentStreak, int &addToStreakCount, int &longestStreakHolder) {

    if (currentStreak == 0) { // if user did not successfully complete 3 or 5 letter word currentStreak flag variable equals 0
        addToStreakCount = 0; // reset streak count for next game play attempt
    }

    if (currentStreak == 1) {  // if user successfully completed 3 or 5 letter word currentStreak flag variable equals 1
        addToStreakCount++;    //increment current streak
        if (addToStreakCount > longestStreakHolder) {  //check to see if current streak count should replace longest streak
            longestStreakHolder = addToStreakCount;
        }
    }
} //end assignLongestWinStreak()





int main(){
  srand(1);
  int option; //menuInput option
  int addToStreakCount = 0; //Solution CODE
  int currentStreak = 0; //SOLUTION CODE
  int longestStreakHolder = 0; //SOLUTION CODE
  int guesses = 0; // number of gussess
  int timeFive = 0; // number of time for five word
  int timeThree = 0; //number of time for three word
  int totalTime = timeFive + timeThree; //avg time of word completion;
  string randomWord; //for a random word from the three letter txt
  string randomFive; // for a random word form the three letter txtin
  char board[3] = { ' ', ' ', ' '};
  char bigBoard[5] = { ' ', ' ', ' ', ' ', ' '};
  vector <string> WordleWords;
  vector <string> threeLetters;
  vector <string> fiveLetters;
  displayWelcomeMessage();
  getWordleWords(WordleWords,threeLetters,fiveLetters);
  while(true){
  cout << "Select a menu option:" << endl;
  cout << "  1. To play Wordle Reload 3 letter play" << endl;
  cout << "  2. To play Wordle Reload 5 letter play" << endl;
  cout << "  3. Exit the program" << endl;
  cout << "Your choice --> ";
  cin >> option;
  cout << endl;
    if(option == 1){

      randomWord = threeLetters[rand() % threeLetters.size()];

      playThree(board,threeLetters,randomWord, currentStreak, timeThree,guesses);
      assignLongestWinStreak(currentStreak,addToStreakCount, longestStreakHolder);

    }

    if(option == 2){
      randomFive = fiveLetters[rand() % fiveLetters.size()];
      playFive(bigBoard,fiveLetters,randomFive, currentStreak, timeFive,guesses);
      assignLongestWinStreak(currentStreak,addToStreakCount, longestStreakHolder);

    }

    if(option == 3){

      cout << "Overall Stats: "  << endl;
      cout << " - You guessed: "  << guesses<< endl;
      cout << " - Your longest streak is: " << longestStreakHolder<< endl;
      cout << " - Average word completion time: " << timeThree<< endl;
      cout << "Exiting program" << endl;
      break;
      if(guesses == 0){
        cout << "  - Average word completion time: N/A" << endl;
      }else{
        cout << "  - Average word completion time: " << (timeThree / guesses) << endl;
      }

    }
}
  return 0;
}
