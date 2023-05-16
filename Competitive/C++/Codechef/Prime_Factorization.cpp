#include <bits/stdc++.h> //oncludes most of the libraries

using namespace std;

int main () {
    int n;
    n = 1e9;
    //cin >> n;
    int factors[int(sqrt(n))],power[int(sqrt(n))];
    memset (power,0,sizeof(power)); // initializing all elements to 0 works like a loop
    int j = 0;
    for (int i = 2; i*i <=n; i++) {
         if (n%i == 0) {
             factors[j] = i;
             while (n%i == 0) { //run the loop until n is not divisible by i
                power[j] ++; // will increment the power corresponding to i
                n /= i;
             }
             j++;
         }
    }
    if (n > 2) {
        factors[j] = n,power[j] =1;
        j++;
    }
    for (int i =0;i<j;i++) {
        cout << factors[i] << "^" << power[i] ;
        if (i != j-1) cout << "*"; // done this only because i do not want to print * after the last element
    }
}