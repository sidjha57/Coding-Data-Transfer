#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll n,s; cin >> n >> s;
    vector<int> w(n),c(n);
    for (int i=0; i<n; i++) cin >> w[i];
    for (int i=0; i<n; i++) cin >> c[i];


    ll l=0,r=0,ans=0,curWeight=0,curCost=0;
    while(r < n) {
        if (curWeight <= s) {
            curWeight += w[r];
            curCost += c[r];
            r++;
        } 
        if (curWeight > s) {
            curWeight -= w[l];
            curCost -= c[l];
            l++;
        }
        if (curWeight <= s) {
            ans = max(ans,curCost);
        }
    }

    cout << ans;
}