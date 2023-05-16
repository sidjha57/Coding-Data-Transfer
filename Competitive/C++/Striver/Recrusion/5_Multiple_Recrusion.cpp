#include<bits/stdc++.h>

using namespace std;

// 1 1 2 3 5 
int fib(int n) {
    if (n < 3) return 1;
    return fib(n-1) + fib(n-2);
}
int main() {
    cout << fib(6);
}