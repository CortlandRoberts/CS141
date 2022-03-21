#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int steps;
    cout << "enter steps ";
    cin >> steps;


    for(int i = 1; i <= steps; i++){

      cout << setw(i - steps) << "/";
      cout << setw( (i * 2) + 4) << "\\";
      cout << endl;


      cout << setw(steps - i + 1) << "\\";
      cout << setw( (i * 2) + 2) << "/";
      cout << endl;

    }



  return 0;
}
