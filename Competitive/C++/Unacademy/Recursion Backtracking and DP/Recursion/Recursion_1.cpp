#include <bits/stdc++.h>

using namespace std;

// factorial 
int fact (int n) {
    // base case 
    if (n <= 1) return 1;
    // recursive assumption
    int subproblem = fact(n-1);
    // self work
    return n*subproblem;
}

// Nth fibonacci
int fibo (int n) {
    // base case
    if (n == 0 || n == 1) return 1;
    // recursive assumption
    int subproblem1 = fibo(n-1);
    int subproblem2 = fibo(n-2);
    // self work
    return subproblem1 + subproblem2;
}

// print first n natural numbers in increasing order
void increasing_order (int n) {
    // base case
    if (n == 0) return;
    // recursive assumption
    increasing_order(n-1);
    // self work
    cout << n << " ";
}

// print first n natural numbers in descending order
void desending_order(int n) {
    // base case
    if (n == 0) return;
    // self work
    cout << n << " ";
    // recursive assumption
    desending_order(n-1);
}

// print first desending order then increasing order
void dec_inc_order (int n) {
    // base case
    if (n == 1) {
        cout << "1 ";
        return;
    } 
    // self work
    cout << n << " ";
    // recursive assumption
    dec_inc_order(n-1);
    // self work
    cout << n << " ";
}

// given value of n find the number of binary strings which do not have consecutive ones
int num_bin_str (int n) {
    // base case
    if (n == 1) return 2;
    if (n == 2) return 3;
    // recursive assumption
    int subproblem1 = num_bin_str(n-1); // when n-1 th character is 1
    int subproblem2 = num_bin_str(n-2); // when n-1 th character is 0
    // self work
    return subproblem1 + subproblem2;
}
int main () {
    cout << num_bin_str(3); 
}