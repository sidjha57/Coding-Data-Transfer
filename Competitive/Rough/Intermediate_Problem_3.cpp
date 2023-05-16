#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n,i,j; cin >> n; 
    int ans[1000];
    if (n >=0 && n <= 9) cout << n;
    else {
        for (i = 9; i > 1; i--)
            while (n % i == 0) {
                n = n / i;
                ans[j] = i;
                j++;
            }
        if (n > 10)
            cout << "Not possible";
        for (i = j - 1; i >= 0; i--)
            cout << ans[i];
    }
    return 0;
}
