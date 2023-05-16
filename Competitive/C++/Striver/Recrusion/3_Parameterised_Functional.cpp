#include <bits/stdc++.h>

using namespace std;

void sum_parameter(int i, int sum) {
    if (i < 1) {
        cout << sum;
        return;
    }
    sum_parameter(i-1, sum+i); // f(3,0) => f(2,0+3) => f(1,3+2) => f(0,5+1)
}

int sum_functional(int i) {
    if (i < 1) return 0;
    return i + sum_functional(i-1);
}

int main() {
    // sum_parameter(5,0);
    cout << sum_functional(5);
}