#include <iostream>

using namespace std; 

int solve (char a) {
     if (a >= '0' && a <= '9') return 0;
     if (a >= 'A' && a <= 'Z') return 1;
     if (a >= 'a' && a <= 'z') return 2;
     else return 3;
}

int main() {
    char a;
    cin >> a;
    cout << solve(a);
    return 0;
}