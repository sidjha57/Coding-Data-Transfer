#include <iostream>
using namespace std;

int main () {
    int t,k;
    cin >> t;
    while (t--) {
        cin >> k;
        k--;
        for (int i = 1; i <=8;i++) {
            for (int j =1;j<=8;j++) {
                if (i==1 && j==1) cout <<'O';
                else if (k) {
                    cout <<'.';
                    k--;
                }
                else cout <<'X';
            }
            cout << "\n";
        }
        cout << " \n" ;
    }
}