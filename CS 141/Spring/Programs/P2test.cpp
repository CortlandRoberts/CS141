/*--------------------------------------------
   Program 2: Knight Escape
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.

	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR
	two squares in a vertical direction, then one in a horizontal direction).

   Course: CS 141, Spring 2022
   System: Windows Using Atom Text editor
   Author: Cortland Roberts

 ---------------------------------------------*/

#include <iostream>		// for input and output
#include <cctype>		   // for toupper()
using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the 25 board positions.
// global variables for string pieces and for the user move inputs(from and to)
string p1, p2, p3, p4, p5, p6, p7, p8, p9,
p10, p11, p12, p13, p14, p15, p16, p17, p18,
p19, p20, p21, p22, p23, p24, p25;

int moveFrom, moveTo;

int moveNumber = 1;
// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658";		// White knight character
const string BlackKnight = "\u265E";		// Black knight character
const string BlankPosition = " ";			// Blank position character

//function for initalizing the board;
void initBoard(){
  p1=p2=p3=p4=p6=p7=p8=p9=
  p10=p11=p12=p13= p14= p15=p16= p17=p18=
  p19= p20=p22= p23= p24= p25 = BlackKnight;

  p5 = BlankPosition;
  p21 = WhiteKnight;
}
//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage()
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}//end displayWelcomeMessage()

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard()
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} //end displayBoard()

//function to check to see if the from position is valid or not
bool valSource(int valFrom){
  if((valFrom >= 1) &&(valFrom <=25) ){
    return true;
  }
  else{
    cout << "The source position should be a valid position on the board (1-25). Try again.";
    return false;
  }
} // end of valSource

//function to check to see if the TO position is valid or not
bool valDestination(int validTo){
  if((validTo >= 1) && (validTo <= 25) ){
    return true;
  }
  else{
    cout << "The destination position should be a valid position on the board (1-25). Try again.";
    return false;
  }

}

//checking to see if sourcePosition has a Knight or not;
bool sourcePosition(int valTo){
  if(valTo == 1){
    if(p1 == WhiteKnight || p1 == BlackKnight){
      return true;
      }
      else{
        return false;
      }
    } else if(valTo == 2){
        if(p2 == WhiteKnight || p2 == BlackKnight){
          return true;
        }
        else{
          return false;
        }

    } else if(valTo == 3){
      if(p3 == WhiteKnight || p3 == BlackKnight){
        return true;
      }
      else{
        return false;
      }

    } else if(valTo == 4){
        if(p4 == WhiteKnight || p4 == BlackKnight){
          return true;
        }
        else{
          return false;
        }

    } else if(valTo == 5){
        if(p5 == WhiteKnight || p5 == BlackKnight){
          return true;
        }
        else{
          return false;
        }

    } else if(valTo == 6){
        if(p6 == WhiteKnight || p6 == BlackKnight){
          return true;
        }
        else{
          return false;
        }

    } else if(valTo == 7){
        if(p7 == WhiteKnight || p7 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 8){
        if(p8 == WhiteKnight || p8 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 9){
        if(p9 == WhiteKnight || p9 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 10){
        if(p10 == WhiteKnight || p10 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 11){
        if(p11 == WhiteKnight || p11 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 12){
        if(p12 == WhiteKnight || p12 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 13){
        if(p13 == WhiteKnight || p13 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 14){
        if(p14 == WhiteKnight || p14 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 15){
        if(p15 == WhiteKnight || p15 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 16){
        if(p16 == WhiteKnight || p16 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 17){
        if(p17 == WhiteKnight || p17 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 18){
        if(p18 == WhiteKnight || p18 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 19){
        if(p19 == WhiteKnight || p19 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 20){
        if(p20 == WhiteKnight || p20 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 21){
        if(p21 == WhiteKnight || p21 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 22){
        if(p22 == WhiteKnight || p22 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 23){
        if(p23 == WhiteKnight || p23 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 24){
        if(p24 == WhiteKnight || p24 == BlackKnight){
         return true;
       }
       else{
         return false;
       }

    } else if(valTo == 25){
        if(p25 == WhiteKnight || p25 == BlackKnight){
         return true;
       }
       else{
         return false;
       }
    }
    else{
      return false;
    }
} // end of sourcePosition function

//checking to see if the destination is empty or not
bool destinationEmpty(int moveFrom){
  if(moveFrom == 1){
    if(p1 == BlankPosition){
      return true;
    } else{
      return false;
    }

  } else if(moveFrom == 2){
      if(p2 == BlankPosition){
        return true;
      } else{
        return false;
      }

  } else if(moveFrom == 3){
      if(p3 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 4){
      if(p4 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 5){
      if(p5 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 6){
      if(p6 == BlankPosition){
        return true;
      } else{
        return false;
      }

  } else if(moveFrom == 7){
      if(p7 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 8){
      if(p8 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 9){
      if(p9 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 10){
      if(p10 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 11){
      if(p11 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 12){
      if(p12 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 13){
      if(p13 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 14){
      if(p14 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 15){
      if(p15 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 16){
      if(p16 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 17){
      if(p17 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 18){
      if(p18 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 19){
      if(p19 == BlankPosition){
        return true;
      } else{
        return false;
      }

  } else if(moveFrom == 20){
      if(p20 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 21){
      if(p21 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 22){
      if(p22 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 23){
      if(p23 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 24){
      if(p24 == BlankPosition){
        return true;
      } else{
        return false;
      }
  } else if(moveFrom == 25){
      if(p25 == BlankPosition){
        return true;
      } else{
        return false;
      }

  }
  else{
    return false;
  }
} // end of destinationEmpty function

//checks to see if the move is valid;
bool validMove(int moveFrom, int moveTo){
    if(moveFrom == 1){
      if(moveTo == 8 || moveTo == 12){
        return true;
      }
      else{

        return false;
      }
    } else if(moveFrom == 2){
        if(moveTo == 9 || moveTo == 11 || moveTo == 13){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 3){
        if(moveTo == 6 || moveTo == 10 || moveTo == 12 || moveTo == 14){
          return true;
        }
        else{
          return false;
        }
    } else if(moveFrom == 4){
        if(moveTo == 7 || moveTo == 13 || moveTo == 15){
          return true;
        }
        else{
          return false;
        }
    } else if(moveFrom == 5){
        if(moveTo == 8 || moveTo == 14){
          return true;
        }
        else{
          return false;
        }
    } else if(moveFrom == 6){
        if(moveTo == 3 || moveTo == 13 || moveTo == 17){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 7){
        if(moveTo == 4 || moveTo == 14 || moveTo == 18 || moveTo == 16){
          return true;
        }
        else{
          return false;
        }
    } else if(moveFrom == 8){
        if(moveTo == 1 || moveTo == 5 || moveTo ==15 || moveTo == 11 || moveTo == 17 || moveTo == 19){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 9){
      if(moveTo == 2 || moveTo == 12 || moveTo == 18 || moveTo == 20){
        return true;
      }
      else{
        return false;
      }

    } else if(moveFrom == 10){
        if(moveTo == 3 || moveTo == 13 || moveTo == 19){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 11){
        if(moveTo == 2|| moveTo == 22 || moveTo == 8 || moveTo == 18){
          return true;
        }
        else {
          return false;
        }

    } else if(moveFrom == 12){
        if(moveTo == 1 || moveTo == 3 || moveTo == 21 || moveTo == 23 || moveTo == 9 || moveTo == 19){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 13){
        if(moveTo == 2 || moveTo == 4 || moveTo == 22 || moveTo == 24 || moveTo == 6 || moveTo == 16 || moveTo == 10 || moveTo == 20){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 14){
        if(moveTo == 3 || moveTo == 5 || moveTo == 23 || moveTo == 25 || moveTo == 7 || moveTo == 17){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 15){
        if(moveTo == 4 || moveTo == 24 || moveTo == 8 || moveTo == 18){
          return true;
        }
        else{
          return false;
        }

    }else if(moveFrom == 16){
        if(moveTo == 7 || moveTo == 23 || moveTo == 13){
          return true;
        }
        else {
          return false;
        }

    } else if(moveFrom == 17){
        if(moveTo == 6 || moveTo == 8 || moveTo == 14 || moveTo == 24){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 18){
        if(moveTo == 7 || moveTo == 9 || moveTo == 11 || moveTo == 21 || moveTo == 15 || moveTo == 25){
            return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 19){
        if(moveTo == 8 || moveTo == 10 || moveTo == 12 || moveTo == 22){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 20){
        if(moveTo == 13 || moveTo == 23 || moveTo == 9){
          return true;
        }
        else {
          return false;
        }

    } else if(moveFrom == 21){
        if(moveTo == 18 || moveTo == 12){
          return true;
        }
        else{
          return false;
        }

    } else if(moveFrom == 22){
        if(moveTo == 11 || moveTo == 13 || moveTo == 19){
          return true;
        }
        else {
          return false;
        }

    } else if(moveFrom == 23){
      if(moveTo == 16 || moveTo == 20 || moveTo == 12 || moveTo == 14){
        return true;
      }
      else{
        return false;
      }

    } else if(moveFrom == 24){
        if(moveTo == 13 || moveTo == 15 || moveTo == 17){
          return true;
        }
        else{
          return false;
        }

    }else if(moveFrom == 25){
      if(moveTo == 14 || moveTo == 18){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }
}

//swaps the pieces and makes the move
void makeMove(){
  string temp;
  if(moveFrom == 1){
    switch(moveTo){
      case 8:
        swap(p1, p8);
        break;
      case 12:
        swap(p1, p12);
        break;
    } // end of switch

  } else if(moveFrom == 2){
      switch(moveTo){
    case 9:
      swap(p2, p9);
      break;
    case 11:
      swap(p2, p11);
      break;
    case 13:
      swap(p2, p13);
      break;
    } // end of switch

  } else if(moveFrom == 3){
      switch(moveTo){
        case 6:
          swap(p3, p6);
          break;
        case 10:
          swap(p3, p10);
          break;
        case 12:
          swap(p3, p12);
          break;
        case 14:
          swap(p3, p14);
          break;
      }
  } else if(moveFrom == 4){
      switch(moveTo){
        case 7:
          swap(p4, p7);
          break;
        case 13:
          swap(p4, p13);
          break;
        case 15:
          swap(p4, p15);
          break;
      } // end of switch
  } else if(moveFrom == 5){
      switch(moveTo){
        case 8:
          swap(p5, p8);
          break;
        case 14:
          swap(p5, p14);
          break;
      } // end of switch
  } else if(moveFrom == 6){
      switch(moveTo){
        case 3:
          swap(p6, p3);
          break;
        case 13:
          swap(p6, p13);
          break;
        case 17:
          swap(p6, p17);
          break;
      } // end of swipe
  } else if(moveFrom == 7){
      switch(moveTo){
        case 4:
          swap(p7, p4);
          break;
        case 14:
          swap(p7, p14);
          break;
        case 18:
          swap(p7, p18);
          break;
        case 16:
          swap(p7, p16);
          break;
      } // end of switch
  } else if(moveFrom == 8){
      switch(moveTo){
        case 1:
          swap(p8, p1);
          break;
        case 5:
          swap(p8, p5);
          break;
        case 15:
          swap(p8, p15);
          break;
        case 11:
          swap(p8, p11);
          break;
        case 17:
          swap(p8, p17);
          break;
        case 19:
          swap(p8, p19);
          break;
      } // end of switch
  } else if(moveFrom == 9){
      switch(moveTo){
        case 2:
          swap(p9, p2);
          break;
        case 12:
          swap(p9, p12);
          break;
        case 18:
          swap(p9, p18);
          break;
        case 20:
          swap(p9, p20);
          break;
      } // end of switch
  } else if(moveFrom == 10){
      switch(moveTo){
        case 3:
          swap(p10, p3);
          break;
        case 13:
          swap(p10, p13);
          break;
        case 19:
          swap(p10, p19);
          break;
      } // end of match
  } else if(moveFrom == 11){
      switch(moveTo){
        case 2:
          swap(p11, p2);
          break;
        case 22:
          swap(p11, p22);
          break;
        case 8:
          swap(p11, p8);
          break;
        case 18:
          swap(p11, p18);
          break;
      } // end of switch
  } else if(moveFrom == 12){
    switch(moveTo){
      case 1:
        swap(p12, p1);
        break;
      case 3:
        swap(p12, p3);
        break;
      case 21:
        swap(p12, p21);
        break;
      case 23:
        swap(p12, p23);
        break;
      case 9:
        swap(p12, p9);
        break;
      case 19:
        swap(p12, p19);
        break;
    } // end of switch

  } else if(moveFrom == 13){
      switch(moveTo){
        case 2:
          swap(p13, p2);
          break;
          case 4:
            swap(p13, p4);
            break;
          case 22:
            swap(p13, p22);
            break;
          case 24:
            swap(p13, p24);
            break;
          case 6:
            swap(p13, p6);
            break;
          case 16:
            swap(p13, p16);
            break;
          case 10:
            swap(p13, p10);
            break;
          case 20:
            swap(p13, p20);
            break;
      } // end of switch
  } else if(moveFrom == 14){
      switch(moveTo){
        case 3:
          swap(p14, p3);
          break;
        case 5:
          swap(p14, p5);
          break;
        case 23:
          swap(p14, p23);
          break;
        case 25:
          swap(p14, p25);
          break;
        case 7:
          swap(p14, p7);
          break;
        case 17:
          swap(p14, p17);
          break;
      } // end of switch

  } else if(moveFrom == 15){
      switch(moveTo){
        case 4:
          swap(p15, p4);
          break;
        case 24:
          swap(p15, p24);
          break;
        case 8:
          swap(p15, p8);
          break;
        case 18:
          swap(p15, p18);
          break;
      }

  } else if(moveFrom == 16){
      switch(moveTo){
        case 7:
          swap(p16, p7);
          break;
        case 23:
          swap(p16, p23);
          break;
        case 13:
          swap(p16, p13);
          break;
      } // end of switch
  } else if(moveFrom == 17){
      switch(moveTo){
        case 6:
          swap(p17, p6);
          break;
        case 8:
          swap(p17, p8);
          break;
        case 14:
          swap(p17, p14);
          break;
        case 24:
          swap(p17, p24);
          break;
      } // end of switch
  } else if(moveFrom == 18){
    switch(moveTo){
      case 7:
        swap(p18, p7);
        break;
      case 9:
        swap(p18, p9);
        break;
      case 11:
        swap(p18, p11);
        break;
      case 21:
        swap(p18, p21);
        break;
      case 15:
        swap(p18, p15);
        break;
      case 25:
        swap(p18, p25);
        break;
      } // end of switch

  } else if(moveFrom == 19){
      switch(moveTo){
        case 8:
          swap(p19, p8);
          break;
        case 10:
          swap(p19, p10);
          break;
        case 12:
          swap(p19, p12);
          break;
        case 22:
          swap(p19, p22);
          break;
      } // end of switch
  } else if(moveFrom == 20){
      switch(moveTo){
        case 13:
          swap(p20, p13);
          break;
        case 23:
          swap(p20, p23);
          break;
        case 9:
          swap(p20, p9);
          break;
      } // end of switch
  } else if(moveFrom == 21){
      switch(moveTo){
        case 18:
          swap(p21, p18);
          break;
        case 12:
          swap(p21, p12);
          break;
      } // end of switch
  } else if(moveFrom == 22){
      switch(moveTo){
        case 11:
          swap(p22, p11);
          break;
        case 13:
          swap(p22, p13);
          break;
        case 19:
          swap(p22, p19);
          break;
      } // end of switch
  } else if(moveFrom == 23){
      switch(moveTo){
        case 16:
          swap(p23, p16);
          break;
        case 20:
          swap(p23, p20);
          break;
        case 12:
          swap(p23, p12);
          break;
        case 14:
          swap(p23, p14);
          break;
      } // end of switch
  } else if(moveFrom == 24){
      switch(moveTo){
        case 13:
          swap(p24, p13);
          break;
        case 15:
          swap(p24, p15);
          break;
        case 17:
          swap(p24, p17);
          break;
      } // end of switch
  } else if(moveFrom == 25){
      switch(moveTo){
        case 14:
          swap(p25, p14);
          break;
        case 18:
          swap(p25, p18);
          break;
      }
  }
}
// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {

   displayWelcomeMessage();
   initBoard();
	// Set board values to the default starting position
   int moveNumber = 1;
   int score = 500;
   char menuOption;
   displayBoard();
   cout << "Current score: " << score;
   cout << endl;
   // Loop that controls game play
   while(true) {
      cout << endl;
      cout << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
		cin >> menuOption;
	  menuOption = toupper(menuOption); // convert user input to uppercase
 //if user input is equal to x, exit out of the program
    if(menuOption == 'X'){
      cout << "Exiting..." << endl;
      break;
    }
//if user input is equal to r, I want to reset the board and its values
    if(menuOption == 'R'){
      cout << endl;
      cout << "    *** Restarting";
      cout << endl;
      initBoard();
      displayBoard();
      moveNumber = 1;
      score = 500;
      cout << "Current score: " << score;
      cout << endl;
      continue;
    }

		// If the user entered 'M' to move a knight,
		// ask for the position of the knight to be moved
	   if(menuOption == 'M'){
       //int moveFrom, moveTo;
       cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): ";
       cin >> moveFrom >> moveTo;
       cout << "You have chosen to move a knight from position " << moveFrom << " to position " << moveTo <<"." << endl;


       // Check that FROM position is valid, i.e. within 1-25

       if( !(valSource(moveFrom)) ){
         score = score - 10;
         cout << "Current score: " << score << endl;
        continue;
       }
       // Check that TO position is valid, i.e. within 1-25
       if( !(valDestination(moveTo)) ){
         score = score - 10;
         cout << "Current score: " << score << endl;
         continue;
       }
// Check that the source position has a knight
       if( !(sourcePosition(moveFrom)) ){
         cout << "The source position should have a knight. Try again." << endl;
         score = score - 10;
         cout << "Current score: " << score << endl;
         continue;
       }
	// Check that the destination position is empty
       if( !(destinationEmpty(moveTo)) ){
         cout << "The destination position should be empty. Try again.";
         cout << endl;
         score  = score - 10;
         cout << "Current score: " << score << endl;
         continue;
       }
      // Check that the move is valid - knights can only move in an L-shape
       if( !validMove(moveFrom, moveTo) ){
         cout << "Invalid move. Knights can only move in an L-shape. Try again.";
         cout << endl;
         score = score - 10;
         cout << "Current score: " << score << endl;
         cout << endl;
         continue;
       }

//this will make the move and update the board.
       makeMove();
       score = score - 5;
       displayBoard();
       cout << endl;
       cout << "Current score: " << score;

     } // end of option M

    moveNumber++;
   //-------------------------winning conditions-------------
//checking to see if the space is equal to the WhiteKnight
    if(p5 == WhiteKnight){
      cout << "Congratulations, you did it!" << endl;

      cout << "Thank you for playing!" << endl;
      exit(0);
    }
//checking to see if the score is less than 0;
    if(score <= 0){
      cout << "Current score: " << score << endl;
      cout << endl;
      cout << "You have run out of moves. Try to do better next time!" << endl;
      cout << "Thank you for playing!" << endl;
      exit(0);
    }

   } // end loop for game play




   cout << "Thank you for playing!" << endl;

	return 0;
}
