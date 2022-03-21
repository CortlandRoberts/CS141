#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // access to tolower() or toupper() function
#include <vector>     // For vectors
#include <string>     // String operations
#include <cstring>    // For C string function strcpy
#include <algorithm>  // use of vector algorithms
#include <cmath>      // For trig functions used in finding distance between points
#include <iomanip>    // For setting precision of floating point number display
#include <unordered_set> //https://www.geeksforgeeks.org/print-all-distinct-strings-from-a-given-array/
using namespace std;

struct billBoard{
  string date;
  string rank;
  string song;
  string artist;
  string lastWeek;
  string peakRank;
  string weeksOnBoard;

};
//function to read in all CSV files
void readCSV(vector<billBoard> &boardOne, int& count){
  int csvChoice; //choice for which csv file we are going to use
  int cnt;
  //lets clear the vector first
  boardOne.clear();

  string inputLine, dateTempString, rankTempString, songTempString,
  artistTempString, lastWeekTempString, peakWeekTempString,
  weeksOnBoardTempString;

  char fileName[ 81];
  int csvSheetSelection;

  ifstream read;


  cout << "Select file option: " << endl;
  cout << "   1. To analyze charts top 50: 1960 - 1980 data file " << endl;
  cout << "   2. To analyze charts top 50: 1981 - 2000 data file " << endl;
  cout << "   3. To analyze charts top 50: 2001 - 2020 data file " << endl;
  cout << "your choice -> ";
  cin >> csvChoice;

  switch(csvChoice){
    case 1:
      strcpy(fileName, "charts_top50_1960_1980.csv");
      break;
    case 2:
      strcpy(fileName, "charts_top50_1981_2000.csv");
      break;
    case 3:
      strcpy(fileName, "charts_top50_2001_2020.csv");
      break;
    default: cout << "Invalid value. Exiting Program";
      exit(-1);
      break;
  } // end of switch

  read.open(fileName);
  assert(read.fail() == false);


  billBoard temp;

  getline(read, inputLine);

  while(getline(read, inputLine)){
    temp.date = inputLine.substr(0, inputLine.find(','));
//      cout << temp.date << endl;

    rankTempString = inputLine.substr(inputLine.find(',') + 1);
    temp.rank = rankTempString.substr(0, rankTempString.find(','));
  //  cout << rankTempString << endl;
     //cout << temp.rank << endl;

    songTempString = rankTempString.substr(rankTempString.find(',')+1);
    temp.song = songTempString.substr(0, songTempString.find(','));
   //cout << temp.song << endl;

    artistTempString = songTempString.substr(songTempString.find(',') + 1);
    temp.artist = artistTempString.substr(0, artistTempString.find(','));
    //cout << artistTempString << endl;
    //cout << temp.artist << endl;
    lastWeekTempString = artistTempString.substr(artistTempString.find(',') + 1);
    temp.lastWeek = lastWeekTempString.substr(0, lastWeekTempString.find(','));
    //cout << lastWeekTempString << endl;
    //cout << temp.lastWeek << endl;
    peakWeekTempString = lastWeekTempString.substr(lastWeekTempString.find(',')+ 1);
    temp.peakRank = peakWeekTempString.substr(0, lastWeekTempString.find(','));
  //  cout << temp.peakRank << endl;
    weeksOnBoardTempString = peakWeekTempString.substr(peakWeekTempString.find(',') + 1);
    temp.weeksOnBoard = weeksOnBoardTempString.substr(0, weeksOnBoardTempString.find(' '));
  //  cout << temp.weeksOnBoard << endl;
    boardOne.push_back(temp);
    cnt++;
  }
  count += cnt;
read.close();

} // end of readCSV

void menuOne(vector<billBoard> boardOne, int number){
  int songs = 0; //used for counting the songs
  vector<string> songName; //vector for storing only songs from the billBoard struct
  unordered_set<string> DistString;  //used to store distinct strings
  //first we are gonig to add only songs from the billboard to the song vector
  for(int i = 0; i < boardOne.size(); i++){
    songName.push_back(boardOne.at(i).song);
  }
  //looping though the songs vector
  for(int k = 0; k < songName.size(); k++){
    // If current string not
        // present into the set
    if(!DistString.count(songName[k])){
      // Insert current string
          // into the set
      DistString.insert(songName[k]);
    }
  }
    songs = DistString.size();
  cout << "Total number of rows: " << number << endl;
 cout << "Number of unique songs represented in the dataset: " << songs << endl;
 //cout << boardOne.at(0).rank << endl;
} // end of menuOne
//function for option 2
void menuTwo(vector<billBoard> boardOne){
  char option;
  string songs;
  int ranks;
  vector<string> date;
  vector<string> tmp;
  string names;
 // push only dates into the date vector


 for(int i = 0; i < boardOne.size(); i++){
       if(stoi(boardOne.at(i).peakRank) == 1){
          tmp.push_back(boardOne.at(i).song);
         }
     }

//   cout << "Enter D to select a decade or Y to select a year." << endl;
//   cin >> option;
//   option = toupper(option);
// while(true){
//   if(option != 'D' || 'Y'){
//     cout << "Invalid entry. Try again."  << endl;
//     continue;
//   }
// /*
//   if(option == 'D'){
//     int decade; //users decade
//     int storeDecade; //store users decade and change the last index
//     cout << "Enter the decade you would like to choose, as a multiple of 10 (e.g. 2010).";
//     cin >> decade;
//     storeDecade = decade;
//     storeDecade[3] = 0;
//     for(int i = boardOne.at(storeDecade); i <storeDecade + 10; i++){
//   //  int year = boardOne.at(i).data[substr(6, 9]
//
//     }
//   }
//   */
//
//   if(option == 'Y'){
//     int choiceY;
//     cout << "Enter the year you would like to choose (e.g. 2001). ";
//     cin >> choiceY;
//     int cntr;
//     vector<string> SongName;
//     vector<int> peakRank;
//     vector<string> ArtistName;
//
//     // for(int SongN = 0; SongN <boardOne.size(); SongN++){
//     //   SongName.push_back(boardOne.at(SongN).song);
//     // }
//     //
//     // for(int Peak = 0; Peak <boardOne.size(); Peak++){
//     //   peakRank.push_back(boardOne.at(Peak).song);
//     // }
//     //
//     //
//     // for(int Artist = 0; Artist <boardOne.size(); Artist++){
//     //   ArtistName.push_back(boardOne.at(Artist).song);
//      }
//
//
//
// } // end of while loop

} // end of menuTwo


/*
void menuFive(vector<billBoard> boardOne){
  string name;
  cout << "Enter search text to retrieve first 10 records of #1 songs that match by artist name: ";
  cin >> name;

  for(int i = 0; i <boardOne.size; i++){
    if(boardOne.at(i).artist != name){
      cout << "No matching artist wer found" << endl;
    } else{
      cout << "Retrieval of first 10 #1 records found based upon search by artist name: " << endl;
      for(int j = 0; j < 10; j++){
        int cnt = 0;
        cout  << cnt++ << ")  " << "Song: " << boardOne.at(i).song << endl;
        cout << " Artist" << boardOne.at(i).artist << endl;
        cout << "Week of" << ""
      }
    }
  }
}
*/
int main(){
  int count = 0;
  int choice; //for the options in the menu
  vector<billBoard> boardOne;
  vector<billBoard> anotherBoard;

  cout << "Program 4: BillBoard Analysis" << endl;
  cout << "CS 141, Spring 2022, UIC" << endl;
  cout << endl;

  cout << "This program will analyze weekly Billboard data spanning from 1960 - 2020." << endl;
  readCSV(boardOne, count);
  while(true){
    cout << endl
         << "Select a menu option: \n "
         <<"   1. Display overall information about the data\n"
         <<"   2. Display the Billboard info of the song with the most #1 occurrences for a given decade or year\n"
         <<"   3. Display the Billboard info for the most long-lasting song on the charts for a given decade or yea\n"
         <<"   4. Display the Billboard info for the song with the greatest weekly climb on the charts given a decade or year\n"
         <<"   5. Artist Search - Return the Billboard info for records that matches user input for artist search\n"
         <<"   6. Exit\n"
         <<" Your choice --> ";
  cin >> choice;
  //checks to make sure we are only selecting the menu options above
      if(choice < 1 || choice > 6){
        cout << "Invalid value.  Please re-enter a value from the menu options below." << endl;
        continue;
      }
//choice 6 to exit the program
      if(choice == 6){
        break;
      }
//choice 1 to display the information about the data
      if(choice == 1){
          menuOne(boardOne, count);
          continue;
      }

      if(choice == 2){
        menuTwo(boardOne);
      }

  } // end of while loop


  return 0;
}
