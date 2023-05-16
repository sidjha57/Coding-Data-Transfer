#include <iostream>
#include <string>

using namespace std;

void swap_string (string& x, string& y) {
    string temp;
    temp = x;
    x = y;
    y = temp;
    return;
}
void swap_int (int& x, int& y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    return;
}

void arrange (int a[], string s[],int n) {

    //used bubble sort
         for (int i = 0; i<n-1; i++) {
             for (int j=0; j<n-i-1;j++) {
                  if (a[j] < a[j+1]) {
                      swap_int(a[j], a[j+1]);
                      swap_string(s[j], s[j+1]);
                  }
             }
         }

    // print

    for (int i = 0; i<n ;i++) 
    cout << a[i] << " " << s[i] << "\n";
    return;
}

int main () {
    int n=3;
    int a[n];
    string s[n];
    for (int i = 0; i<n; i++) {
        cin >> a[i] >>s[i];
    }
   arrange (a,s,n);
  return 0;
}