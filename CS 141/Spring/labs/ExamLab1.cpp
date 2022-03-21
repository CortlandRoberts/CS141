#include <iostream>
#include <vector>
#include <string>

using namespace std;



int p1(int num1, int num2, int numdif){

  cout << "enter a number: ";
  cin >> numdif;
  cout << endl;
  cout << "enter a range of numbers: ";
  cin >> num1 >> num2;

  for(int i = num1; i <=num2; i++){
    if((i % numdif) == 0){
      cout << i << " ";
    }
  }

}
/*
void p2(){

  cout << "Enter a sequence of 6 numbers: ";
  cin >> s1 >> s2 >> s3 >>s4 >> s5 >> s6;
  seq.push_back(s1);
  seq.push_back(s2);
  seq.push_back(s3);
  seq.push_back(s4);
  seq.push_back(s5);
  seq.push_back(s6);
  cout << "Multiples in the sequence are: ";
  for(int i = 0; i <=seq.size(); i++){
    if((seq[i] % numdif) == 0){
        cout << seq[i] << " ";
    }
  }
}
*/

/*
void p3{
  cout << "Enter a sequence of 5 numbers: ";
  cin >> s1 >> s2 >> s3 >> s4 >> s5;
  p3.push_back(s1);
  p3.push_back(s2);
  p3.push_back(s3);
  p3.push_back(s4);
  p3.push_back(s5);

      if(s1 % 2 == 0 || s2 % 2 == 0 || s3 % 2 == 0 ||s4 % 2 == 0 || s5 % 2 == 0 ){
        even++;
      }
      else{
        odd++;
      }
  cout << "Number of even numbers: " << even << endl;
  cout << "Number of odd numbers: " << odd << endl;
}
*/

/*
void p4(){

    cout << "Enter a string: ";
    cin >> p4;
    cout << endl;
    cout << "Enter the first character: ";
    cin >> p1;
    cout << endl;
    cout << "Enter the second character: ";
    cin >> p2;
    for(int i = 0; i < p4.size(); i++){
      if(p4[i] == p1){
        p4[i] = p2;
      }
    }
    cout << "The new string is: " << p4;

}
*/

int main(){
  int num1, num2, numdif;
  int s1, s2, s3, s4, s5, s6;
  int even = 0;
  int odd = 0;
  int ha = 0;
  string p4;
  char p1, p2;
  vector<int> seq;
  vector<int> p3;
  //p1(num1, num2, numdif);

  //cout << "Enter a number: ";
  //cin >> numdif;
  //cout << endl;

  cout << "Enter a string: ";
  cin >> p4;
  cout << endl;
  cout << "Enter a character: ";
  cin >> p1;

  for(int i = 0; i <p4.size(); i++){
    if(p4[i] > p1){
      even++;
    }
    else if(p4[i] < p1 ){
      odd++;
    }
    else{
      ha++;
    }

  }

  cout << "Number of characters larger than " << p1 <<": " << even << endl;
  cout << "Number of characters smaller than "<< p1<<  ": " << odd << endl;


  return 0;
}
