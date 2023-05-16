#include <bits/stdc++.h>
using namespace std;

bitset<100> column, left_d,right_d;

/*The time to check isitsafe was taking O(n) we did that in O(1) for col just the col num would work
for the left diagonal the difference of the row and column is same for the right diagonal the sum is same*/
int ans = 0;
void NQueen (int n, int cur_row) {
    if (cur_row == n) {ans++; return;} 

    for (int col=0;col<n;col++) {
        if (!column[col] and !left_d[cur_row-col + n-1] and !right_d[col+cur_row]) {
            column[col] = left_d[cur_row-col + n-1] = right_d[col+cur_row] = 1;
            NQueen (n,cur_row+1);
            column[col] = left_d[cur_row-col + n-1] = right_d[col+cur_row] = 0;
        }
    }
}

int main () {
    int n; cin >> n;
    NQueen(n,0);
    cout << ans << "\n";
}