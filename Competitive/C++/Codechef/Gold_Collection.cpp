#include <iostream>

using namespace std;

int main () {
   int test,numOfIsland;
   cin >> test;
   while (test--) {
       cin >> numOfIsland;
       int a[numOfIsland+1];
       int prefix[numOfIsland+1];
       prefix[0] = 0;
       a[0] =0;
       for (int i=1;i<=numOfIsland;i++) {
           cin >> a[i];
           prefix[i] = prefix[i-1] + a[i];
       }
       
       int quires;
       cin >> quires;
       for (int i=0;i<quires;i++) {
           int leftIsland,rightIsland;
           cin >> leftIsland >> rightIsland;
           int sum = prefix[rightIsland] - prefix[leftIsland-1];
           cout << sum << endl;
       }
   }

}