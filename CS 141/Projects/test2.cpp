#include <iostream>
#include <cstring>
using namespace std;

int start = 18;
int goal = 56;
int movesSize = 4;
int maze[] =/* + 0 1 2 3 4 5 6 7 8 9 */
/* 0 */ {1,1,1,1,1,1,1,1,1,1,
/*10 */ 1,1,1,1,1,1,0,1,0,1,
/*20 */ 1,1,1,1,0,0,0,0,0,1,
/*30 */ 1,1,1,1,0,1,0,1,0,1,
/*40 */ 1,1,1,1,0,0,0,0,1,1,
/*50 */ 1,1,1,1,1,1,0,1,1,1,
/*60 */ 1,1,1,1,1,1,1,1,1,1};
int moves[] = {10,1,-1,-10};
int cameFrom[70];
bool done = false;
void makeMove( int current)
{
cout << current << ", ";
if ( current == goal) {
done = true;
return; // found solution,
}
for (int i=0; i<movesSize; i++) {
int next = current + moves[i];
if( (maze[next] != 1) &&
(next != cameFrom[current]) &&
!done &&
cameFrom[next]==0
){
cameFrom[ next] = current;
makeMove( next);
}
}
}//end makeMove
int main()
{
  makeMove(1);
return 0; // Keep C++ happy
}
