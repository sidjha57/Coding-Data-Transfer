#include <iostream>

using namespace std;

long long int solve (long long int x, long long y) {
    if (y == 0 || x == 0) return 0;
     return x/y;
}

int main () {
    long long int M,K;
    cin >> M >> K;
    cout << solve(M,K);
    return 0;
}