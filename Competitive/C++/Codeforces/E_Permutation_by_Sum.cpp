#include <bits/stdc++.h>

using namespace std;


int main () {
    int t,n,l,r,s;
    cin >> t;
    while (t--) {
      cin >> n >> l >> r >> s;
      int k = r-l,arr[n];
      int dp[k+1][s+1];
      set<int> s; 
      dp[0][0] = 0;
      for (int i=0; i<n; i++) arr[i] = i+1;
       for (int size=1;size<=k;size++) {
           for (int sum=0;sum<=size;sum++) {
                 if (sum == 0) 
                 if (size== 0)
           }
       }
    }

    
}