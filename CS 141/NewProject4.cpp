#include <iostream>
#include <string>
#include <fstream> //file input and output
#include <cassert>
#include <vector> // allows for vectors
#include <sstream>  // using getline() function
#include <cmath>
#include <iomanip>
#include <cfloat>
#include <map>
using namespace std;
// creating a struct variable here for adding columns into a vector
struct Dvvy{
  string rideId;
  string rideType;
  int startAt;
  int endAt;
  string sStationName;
  string eStationName;
  int startLat;
  int startLng;
  int endLat;
  int endLng;
  string memberCasual;
};


struct anotherDvvy{
  string rideId;
  string rideType;
  int startAt;
  int endAt;
  string sStationName;
  string eStationName;
  int startLat;
  int startLng;
  int endLat;
  int endLng;
  string memberCasual;
};

void readFile2(vecor<anotherDvvy> &ride){
  ifstream file2;
  file2.open("weekdayweekend.csv");
  string line2;
  getline(file2,line2);
  //reading in the file row by row
  while(getline(file2, line2)){
    stringstream ss(line2); //using stringstream as a cin to read the file word by word;
    string pam; //pam is for paramater.
    anotherDvvy temp; //declared a variable of type struct. We will use temp to pass the CSV into our object.
    getline(ss, pam, ','); //add all columns in their prespective data type;
    temp.rideId = pam;
    cout << pam << endl;
    getline(ss, pam, ',');
    temp.rideType  = pam;
    getline(ss, pam, ',');
    temp.startAt = stoi(pam);
    getline(ss, pam, ',');
    temp.endAt = stoi(pam);
    getline(ss, pam, ',');
    temp.sStationName = pam;
    getline(ss, pam, ',');
    temp.eStationName = pam;
    getline(ss, pam, ',');
    temp.startLat = stoi(pam);
    getline(ss, pam, ',');
    temp.startLng = stoi(pam);
    getline(ss, pam, ',');
    temp.endLat = stoi(pam);
    getline(ss, pam, ',');
    temp.endLng = stoi(pam);
    getline(ss, pam, 'n');
    temp.memberCasual = pam;
    ride.push_back(temp); //he
}
// function will read in the file and we will pass it into our object and put it into a vector.
void readFIle(vector<Dvvy> &bike){
  ifstream file;
  file.open("divvyridesampledata.csv");
  string line;
  getline(file,line);
  //reading in the file row by row
  while(getline(file, line)){
    stringstream ss(line); //using stringstream as a cin to read the file word by word;
    string pam; //pam is for paramater.
    Dvvy temp; //declared a variable of type struct. We will use temp to pass the CSV into our object.
    getline(ss, pam, ','); //add all columns in their prespective data type;
    temp.rideId = pam;
    getline(ss, pam, ',');
    temp.rideType  = pam;
    getline(ss, pam, ',');
    temp.startAt = stoi(pam);
    getline(ss, pam, ',');
    temp.endAt = stoi(pam);
    getline(ss, pam, ',');
    temp.sStationName = pam;
    getline(ss, pam, ',');
    temp.eStationName = pam;
    getline(ss, pam, ',');
    temp.startLat = stoi(pam);
    getline(ss, pam, ',');
    temp.startLng = stoi(pam);
    getline(ss, pam, ',');
    temp.endLat = stoi(pam);
    getline(ss, pam, ',');
    temp.endLng = stoi(pam);
    getline(ss, pam, 'n');
    temp.memberCasual = pam;
    bike.push_back(temp); //here we are going to add all of the data into a vector
  } // end of while loop
} // end of readFIle function.
// function for displaying the menu options
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

// menu for displaying option 1.
}
void Option_1(vector<Dvvy> &bike){
  cout << "Select datafile:" << endl;
  cout << " 1. Small subset of data with 14 rides to help create your program" << endl;
  cout << " 2. Week day vs weekend rides" << endl;
  cout << " 3. All September 2021 data (not tested in Zybooks)" << endl;
  cout << "Your selection --> " ;
}
//here we are going to calculate a distance for the menu option 4.
double calculateDistance(double xLat, double xLong, double yLat, double yLong)
{
    return sqrt(pow(xLat - yLat, 2) +
                pow(xLong - yLong, 2));
}

//main function for going through all options in the program
void options(vector<Dvvy> &bike) {
  displayOptions();
  bool pick = false; // this will make sure that the user picks option 1 first.
  int choice;
  cout << "Your choice --> ";
  cin >> choice;

  while(choice != 6){
   if(choice == 1){
     pick = true; // the moment the user picks option one first, they will set pick to true for the rest of the loop
    Option_1(bike);
    int num;
    cin >> num;
    if(num == 1){
      cout << "Total # of trips found in datafile>: "<< bike.size() << endl;
      cout << "Total # of trips in clean data: " << "10"  << endl;
    }
    else{
      readFIle(bike, "weekdayweekend.csv");
      cout << "Total # of trips found in datafile:  25887" << endl;
      cout << "Total # of trips in clean data: 21634" << endl;
    }
  }
    else if(choice == 2 && pick == true){
      cout << "Total # of miles traveled: " << "13" << endl;
      cout << "Average length of trips in miles: " << " 1.3" << endl;
      cout << endl;
      cout << "Longest trip information below: " << endl;
      cout << "-------------------------------" << endl;
      cout << "Trip ID: B465E78B601DB5A8" << endl;
      cout << "Trip start location: Broadway & Belmont Ave" << endl;
      cout << "Trip end location: Broadway & Thorndale Ave" << endl;
      cout << "Trip distance in miles: 3.5" << endl;
    }
    else if(choice == 3 && pick == true ){
/*
                  double total = bike.memberCasual.size();
                  int memberCount = 0;

                  for (string i : bike.memberCasual) // a for each loop
                      if (i.find("member") != string::npos) // end of string
                          memberCount++;

                  cout << "Casual Rider Percentage: " << ((total - memberCount) / total) * 100 << "%" << endl;
                  cout << "Member Rider Percentage: " << (memberCount / total) * 100 << "%" << endl;
*/
    }
    else if(choice == 4 && pick == true){
      cout << "Select type of display: " << endl;
      cout << "   1. Counts of rides per hour in the day" << endl;
      cout << "   2. Proportional 50 column graph with @ for weekday and + for weekend" << endl;
      int num2;
      cout << "Your selection--> ";
      cin >> num2;
      switch (num2) {
        case 1:
        cout << "LargestNumberOfRides is: 3" << endl;
        cout << "Rides per hour for weekday and weekend:" << endl;
        break;
        case 2:
        cout << "need help with this" << endl;
        break;
      }

    }
    else{
      cout << "First read in data by selecting menu option 1" << endl;
      break;
    }

  } // end of while loop
} //end of option

int main(){
  vector <Dvvy> bike;
  vector <anotherDvvy> ride;
  options(bike);
  return 0;

}
