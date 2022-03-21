/**------------------------------------------

    Program 1:  Matryoshka Dolls
        Prompt for the number of dolls and display
        ASCII Matryoshka dolls in decending order
        above each other.

    Course: CS 141, Spring 2022.
    System: Windows using Atom
    Author: Cortland Roberts

 ---------------------------------------------*/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.

using namespace std; // so that we don't need to preface every cin and cout with std::

int main()
{
    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Matryoshka Dolls            \n"
        << "Choose from among the following options:  \n"
        << "   1. Display original graphic  \n"
        << "   2. Display Matryoshka Dolls         \n"
        << "   3. Exit the program          \n"
        << "Your choice -> ";
    cin >> menuOption;

    // Handle menu option of 3 to exit
    if (menuOption == 3) {
        exit(0);
    }
    // Handle menu option of 1 to display custom ASCII graphics
    else if (menuOption == 1) {
       cout << endl;
  for (int i = 0; i < 42; i++) //Prints out 41 dashes for the beginning of the ASCII
    {
        cout << "-";
    }
    cout << endl;
    cout << "I am a Data Science Major" << endl;
    cout
         << "   _______       ______       _______________     ______ " << endl
         << "  |   _  \\       /   _ \\     |_____|  |______|   /  _   \\" << endl
         << "  |  /_\\  \\     /   /_\\ \\          |  |         /  /_\\   \\ " << endl
         << "  |   |    \\   /  ______ \\         |  |        /  ______  \\"<< endl
         << "  |_________\\ /           \\        |  |       /            \\"<< endl
         << endl;

    for (int i = 0; i < 42; i++) //Prints out 41 dashes for the end of the ASCII
    {
        cout << "-";
    }
    cout << endl;
    } //end if( menuOption == 1)  // menu option to display custom graphic

    else if (menuOption == 2) {
        // Prompt for and get the number of dolls.
         int dolls;
         cout << "Number of dolls -> ";
         cin >> dolls;



  // for loop for printing number of dolls AKA dollNum
  for(int dollNum = 1; dollNum <= dolls; dollNum++){
      cout << setw(dolls + 3) << "( )" << endl; // adding the head for the beginning of each doll.
      /*
        I want to make two loops; One for printing the arms or upper body, and one
        for printing the legs or lower body.
      */


        // this loop will be for printing the arms or upper body

        for(int dollArm = 0; dollArm < dollNum; dollArm++){

              cout << setw(dolls - dollArm ) << "/"; // formula for getting the spacing on the  arms("/ ")

              if(dollArm == 0){
                // printing the "-" or ":" in the for the chest
                if( (dollNum % 2) == 1){
                    cout << setw(dollArm + 2) << "-"; // we are saying if the user inputs a number and it is divisor is odd. print the "-".
                }
                else
                {
                  cout << setw(dollArm + 2) <<":";//otherwise if not odd, the user input must be even, so print ":".
                }

                cout << " \\" << endl;
              }
              else{
                 cout << setw( (dollArm * 2) + 4 ) << "\\"; // formula for getting the spacing on the opposite of the arm
                         cout << endl;
              }

        } // end of inner loop .. this prints / after each level is made


        /*
          In the loop below I am going to take what i did above and try to flip it.
        */

        // this loop will create the legs or the lower body of the doll.
      for(int dollLeg = dollNum; dollLeg > 0; dollLeg--){
          cout << setw(dolls - dollLeg + 2) << "\\"; // formula for getting the spacing on the "/"

          cout << setw( (dollLeg * 2)) << "/";
          cout << endl;
          } // end of loop for lower body or leg


    cout << setw(dolls + 2) << "-" << endl; //formula for getting the spacing
  } // end of outer loop .. loop is for number of dolls



    } //end if( menuOption == 2) // menu option to display dolls

    cout << "Exiting" << endl;
    return 0;
}
