#include<bits/stdc++.h>

using namespace std;

void name_print(int i, int n) {
    if (i > n) return;
    cout << "Siddharth ";
    return name_print(i+1,n-1);
}

void print_linearly (int i, int n) {
    if (i > n) return;
    cout << i << " ";
    return print_linearly(i+1,n);
}

void print_linearly_reverse (int i, int n) {
    if (i < 1) return;
    cout << i << " ";
    return print_linearly_reverse(i-1,n);
}

void print_linearly_backtrack (int i, int n) {
    if (i < 1) return;
    print_linearly_backtrack(i-1,n); // f(3,3) => f(2,3) => f(1,3)
    cout << i << " ";  // f(1,3) print i => f(2,3) print i => f(3,3) print i
} 

void print_linearly_backtrack_reverse (int i, int n) {
    if (i > n) return;
    print_linearly_backtrack_reverse(i+1,n); // f(1,3) => f(2,3) => f(3,3)
    cout << i << " "; // f(3,3) print i => f(2,3) print i => f(1,3) print i
}

int main () {
    // int n; cin >> n;
    // name_print(1,5);
    // print_linearly(1,5);
    // print_linearly_reverse(5,5);
    // print_linearly_backtrack(5,5);
    // print_linearly_backtrack_reverse(1,5);
}