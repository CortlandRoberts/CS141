#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>


using namespace std;
class Dvvy{
public:
  /*
  dvvy() {string ride_id; string ride_type; string start_at;
    string end_at; string startStation; string endStation;
    int startLat; int endLat; int startLng; int endLng;
    string memberCasual;}
*/

};
void displayOptions(){
  cout << "Analyze Divy bike ride information using September trip data.";
  cout << "First select option 1 to read and clean the data.";
  cout << endl;
  cout << "Select a menu option: " << endl;
  cout << " 1. Select datafile, display rides totals and clean data" << endl;
  cout << " 2. Display overall trip information" << endl;
  cout << " 3. Display percentage of members vs. casual riders" << endl;
  cout << " 4. Display weekday vs weekend usage" << endl;
  cout << " 5. Extra Credit: find closest station" << endl;
  cout << " 6. Exit" << endl;


}

void datafile(vector<string>  & weekday_weekend){
  ifstream read;
  read.open("weekdayweekend.csv");
  assert( read.fail() == false);

  weekday_weekend.clear();

  string word;
  while(read >> word){
    weekday_weekend.push_back(word);
  }
  read.close();
}

void datafile2(vector<string> &divy_sample){
  ifstream read2;
  read2.open("divvyridesampledata.csv");
  assert( read2.fail() == false);

  divy_sample.clear();

  string word2;
  while(read2 >> word2){
  divy_sample.push_back(word2);
  }
  read2.close();
}

void Option_1(){
  cout << "Select datafile:" << endl;
  cout << " 1. Small subset of data with 14 rides to help create your program" << endl;
  cout << " 2. Week day vs weekend rides" << endl;
  cout << " 3. All September 2021 data (not tested in Zybooks)" << endl;
  cout << "Your selection --> " ;
}


void Option_2(){

}


int main(){
vector<string> weekday_weekend;
vector<string> divy_sample;
datafile2(divy_sample);
    cout << divy_sample[0] << endl;

    /*
    while(true){
      displayOptions();
      int choice;
      cout << "Your choice --> ";
      cin >> choice;
      if(choice)
    }
    */
  return 0;
}
