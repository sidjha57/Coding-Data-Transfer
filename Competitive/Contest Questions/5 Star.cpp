#include <iostream>

using namespace std;

int solve () {
    int X,Y;
    cin >> X >> Y;
    int moneyLeft = X - 5*Y;
    return moneyLeft/5;
}

int main () {
    cout << solve();
    return 0;
}