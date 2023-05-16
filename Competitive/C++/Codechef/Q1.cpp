#include <iostream>

using namespace std;

int main () {
   
   int t = 15;
   while (t--) {
   char letter;

   cin >> letter;

   if ((letter == 'c' || letter == 'C') || (letter == 'o' || letter == 'O') || (letter == 'u' || letter == 'U'))
        cout << "0";
   
   else if ((letter == 'b') || (letter == 'B') || (letter == 'd'|| letter == 'D') || (letter == 'g' || letter == 'G') || (letter == 'j'  || letter == 'J') 
   || (letter == 'p' || letter == 'P') || (letter == 'Q') || (letter == 'q') || (letter == 'r' || letter == 'R'))
        cout <<"-1";

    else 
        cout << "1";
  }
    return 0;
}