/*---------------------------------------------
  Program 3: TypingTutor
  Course: CS 141, FAll 2021: Tuesday 3pm Lab
  System: Windows 10 Using Atom Text Editor
  Author: Cortland Roberts


  Essay:
  Going into Program3, I see can that my solution and professor Reed solution
  has some similar and different solutions to each task. Starting with libraries.
  I have 2 libraries called sstream and string. I have taken MCS 360(data structures)
  so I am familiar with getline function since that was how I was taught to read in strings
  when I had to seperate them with a white space. With regards to displaying
  the main program or the menus. I see that my code is a little better. It is more organized
  since all instructions are in a function. While both are displayed the same. My program just has
  It is a little more organized. For the functions that read in the file and convert them to a vector. For the full dictionary. Ours is the same.
  However, for misspelled and Correctly Spelled words, Our methods are different. I decided to separate both misspelled and Correctly Spelled words
  by using the getline line function which would read in the file and separate the two different words at the space in between them. With Prof.Reed code.
  They decided to use a while loop that adds the new words to their perspective vector. I personally think my function is a little better because it is
  easy to understand, while Prof.Reed is shorter. After the display options and reading in the file, professor Reed decided to create a function to
  calculate the score and display it. I had a hard time understanding the score system and did not provide code for this portion of the project.
  Looking at the function for the score system I have a better understanding of how it is done but still do not know how I can a function that differs from
  the professor. So when the user chooses choice two, in my code. I have the user enter the words and display whether or not the words are inputted Correctly.
  However, I do not have a function that tells the user their score. Also, my choice two does not have a timer function. I was not able to fully understand the
  timer portion of the funcion.
    For Choice 3, Our functions are different. In my function I only use one function to display the start and end of the user choice. Not to mention
    I use a for loop to print the indices from the user start and end input, then print out the between. I did this for all variations. In Prof.Reed, only has one function that inputs one vector that prints out the
    indices of the user start and end. However, I think my function is a little bit better to read and understand.
    For choice 4. I decided to use the professor code since I could not figure out why my own binarySearch function was getting a infinite loop.
    For Choice 5 and 6, I did not copy the professor's code. Our code is the same. I adjusted my code based on the errors I got from zybooks.
  --------------------------------------------
*/
#include <iostream>
#include <ctime> //Timer functions
#include <fstream> //file input and output
#include <vector> //allows for vectors
#include <cassert> // for the assert statement
#include <cctype> // for toUpper. function
#include <sstream> //using getline() function
#include <string>  // .compare

using namespace std;
//displays menu option for users
void displayoptions(){
  cout << "Select a menu option: " << endl;
  cout << " 1. Spell commonly misspelled words (timed)" << endl;
  cout << " 2. Type random words from full dictionary (timed)" << endl;
  cout << " 3. Display some words from one of the lists" << endl;
  cout << " 4. Use binary search to lookup a word in full dictionary" << endl;
  cout << " 5. Set word length to use with full dictionary" << endl;
  cout << " 6. Exit the program" << endl;
} // end of function displayoptions()
//reads in words from files and creates a vector called dictionary of all its words
void getdictionarywords(vector <string>  & dictionary){ //use to put the strings from the file into the vectors
  ifstream read; //read in the word from the file
  read.open( "dictionary.txt");
  assert( read.fail() == false); // Ensure the file worked
  // Clear vector in case it already had some words in it

  dictionary.clear();
  // Keep repeating while input from the file yields a word

  string word;      // Store a single input word
  while(read >> word){  // While there is another word to be read
    // Add this new word to the end of the vector, growing it in the process

    dictionary.push_back(word);
  }
  read.close(); //cose this file
} //end of function getdictionarywords()

//reads in words from files and creates two vectors called mispelledWords and Correctlyspelled of all its words

void getmispelledwords(vector <string> &mispelledWords, vector <string> &Correctlyspelled){ //use to put the strings from the file into two different vectors
  ifstream read2; //read words into file
  read2.open("misspelledWords.txt");
  assert( read2.fail() == false); // Ensure the file worked

  mispelledWords.clear();

  string word2;
  while(getline(read2, word2)){
    stringstream s(word2); //creates a string using the sstream library.
    string mispell, proper;
    getline(s, mispell, ' '); //reads in the file until the whitespace and stores it into another string
    getline(s, proper, ' '); //reads in the file until the whitespace and stores it into another string
    mispelledWords.push_back(mispell); //add that string into the vector
    Correctlyspelled.push_back(proper);
  } // end of while

} // end of getmispelledwords() function.




//provide the user with a way to Correctly type words from the dictionary vector.
void choice_2(vector <string> &dictionary, int length){
  string typeIn;
  string storeWords;
  vector <string> wordofN; //words with length of input number or length of 5.
  vector <string> words;

  for(unsigned int i =0; i < dictionary.size(); i++){ //looping through the vector and adds each word to a new vector with words that has the lenght of 5
    if(dictionary.at(i).length() == 5){
      wordofN.push_back(dictionary.at(i));
    }
  }
  cout << "Using full dictionary" << endl;
  for(int i = 0; i < 5; i++){  // we only want 5 words to be into our vector.
    int index = rand() % wordofN.size(); // randomly generaes numbers from the vector.
    string word = wordofN.at(index);
    cout << word << " ";
    words.push_back(word); //This will store the random words into a new vector.
  }
  cout << endl;


  cout << "Type those words within goal of 15 seconds:" << endl;

  int count = 0;
  vector <string> user_input;


  while(count <5){
    string input;
    cin >>  input;
    user_input.push_back(input); //stores the words from the user into a vector
    count++;
  }
  // we are adding words from the user_input into this vector where we will later compare to see if it is correct or not
  vector <int> misspelled;
  for(int i=0;i<5;i++){
    if(user_input.at(i) != words.at(i)){
      misspelled.push_back(i);
    }
  }
// here we are comparing the words. if they are not equal we will display the correct word.
  if(misspelled.size() !=0 ){
    for(unsigned int i=0;i<misspelled.size();i++){
      int index = misspelled.at(i);
      cout << user_input.at(index) << " should be: " << words.at(index) << endl;
    }
  }
  else{
    cout << "No mispelled words!" << endl;
  }

}





void choice_3(vector <string>  & dictionary, vector <string> &mispelledWords, vector <string> &Correctlyspelled){ //takes in all vectors from both dictionary and misspelledWords file.
  char first_pick;
  int start, end; // tells us the start and end indices of user choice
  int start2, end2;
  int start3, end3;
  int count = 0; //used to cout the numer of words we are printing between the start and end.
  cout << "Displaying word list entries." << endl;
  cout << "Which words do you want to display?" << endl;
  cout << "   A. Dictionary of all words" << endl;
  cout << "   B. Wrongly spelled common misspelled words" << endl;
  cout << "   C. Correctly spelled common misspelled words" << endl;
  cout << "Your choice --> ";
  cin >> first_pick;

  first_pick = toupper(first_pick); //upper case the user input.

  switch(first_pick){
    case 'A':
      cout << "Enter the start and end indices between 0 and 263532: ";
      cin >> start >> end;
      for(int i = start; i < end+1; i++){  // start from the user input upto the user end input. then print out each word in between.
        count++;
        cout << count + start - 1 << ". "<< dictionary.at(i) << " " << endl;
      }
    break;
    case 'B':
    cout << "Enter the start and end indices between 0 and 113: ";
    cin >> start2 >> end2;
    for(int i = start2; i < end2+1; i++){
      count++;
      cout << count + start2 - 1 << ". " << mispelledWords.at(i) << " " << endl;
    }
    break;
    case 'C':
    cout << "Enter the start and end indices between 0 and 113: ";
    cin >> start3 >> end3;
    for(int i = start3; i < end3+1; i++){
      count++;
      cout << count + start3 - 1 << ". "<< Correctlyspelled.at(i) << " " << endl;
    }
    break;
   default: cout << "Invalid switch - case option chosen. Exiting..."; // sainity check. FUnny enough this was my orginal code then I saw the professor use this.
            exit( -1);
            break;
}
  }





void choice_5(vector <string> & dictionary){ //takes in the dictionary std::vector<int> v;
  int wordLength; // user input a number and we cout it.
  cout << "Enter new wordLength: ";
  cin >> wordLength;
}



long binarySearch( string searchWord,            // Word we are searching for
                   vector< string> dictionary)   // Dictionary of words as a vector
{
    long low, mid, high;    // array indices for binary search
    int searchResult = -1;  // Stores index of word if search succeeded, else -1
    int guessNumber = 1;    // Used to display the number of guesses

    // Binary search for word
    low = 0;
    high = dictionary.size() - 1;
    while( low <= high)  {
        mid = (low + high) / 2;
        // searchResult negative value means word is to the left, positive value means
        // word is to the right, value of 0 means word was found
        cout << "     " << guessNumber++ << ". Comparing to: " << dictionary[ mid] << endl;
        searchResult = searchWord.compare( dictionary[ mid]);
        if ( searchResult == 0)  {
            // Word IS in dictionary, so return the index where the word was found
            return mid;
        }
        else if (searchResult < 0)  {
            high = mid - 1; // word should be located prior to mid location
        }
        else  {
            low = mid + 1; // word should be located after mid location
        }
    } //end while( low...

    // Word was not found
    return -1;
}//end binarySearch()

// Binary search of a word in large dictionary was chosen

void choice_4(vector <string> &dictionary){
  string choiceWord;
  cout << "Enter the word to lookup: ";
  cin >> choiceWord;
  if(binarySearch(choiceWord,dictionary) != -1){
    cout << choiceWord << "was found.";
  } else{
    cout << choiceWord << "was NOT found.";
  }
  cout << endl;
}
// exits the program
void choice_6(){
  cout << "Exiting program" << endl;
  cout << "Best score was 0" << endl;
}


int main() {
  vector <string> dictionary; //vector for dictionary file
  vector <string> mispelledWords; //half of words that are mispelleds from the mispelled file.
  vector <string> Correctlyspelled; //half of words that are Correctly spelled from the mispelled file.
  int option2Length = 5;
  string word;
  getdictionarywords( dictionary);
  getmispelledwords(mispelledWords, Correctlyspelled);
  srand(1);
  cout << "There are " << dictionary.size() << " words in the full dictionary.";
  cout << "There are " << mispelledWords.size() << " commonly misspelled words.";
  while(true){
    displayoptions();
      int choice;
      cout << "Your choice --> ";
      cin >> choice;
      cout << endl;

      if(choice == 1){
        continue;
      }

      if(choice == 2){
        choice_2(dictionary,option2Length);
        option2Length++;
        continue;
      }

      if(choice == 3){
        choice_3(dictionary, mispelledWords, Correctlyspelled);
        continue;
      }

      if(choice == 4){
        choice_4(dictionary);
        continue;
      }

      if(choice == 5){
        choice_5(dictionary);
        continue;
      }

      if(choice == 6){
        choice_6();
        break;
      }


    } // wnd of while(loop)


   return 0;
}
