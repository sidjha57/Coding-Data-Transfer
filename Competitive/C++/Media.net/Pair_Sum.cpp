#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    map<int,int> mp;
    for (int i=0; i<arr.size(); i++) {
        mp[arr[i]]++;
    }
    int pair_nums = 0;
    for (auto x : mp) {
        if (x.first == (s-x.first) && x.second > 1) {
            pair_nums += 2*x.second;
        }
        else if (mp.find(s-x.first) != mp.end()) {
            pair_nums += x.second * mp[(s-x.first)];
        }
    }
    vector<vector<int>> v(pair_nums/2, vector<int> (2));
    int i = 0;
    for (auto x: mp) {
        if (i == pair_nums/2) break;
        if (mp.find(s-x.first) != mp.end()) {
            int n = (x.first == (s-x.first) && x.second > 1) ? x.second : x.second*mp[(s-x.first)];
            for (int j=0; j<n; j++, i++) {
                v[i][0] = x.first, v[i][1] = s-x.first;
            }
        }
    }
    return v;
}

int main () {
    int n,s; cin >> n >> s;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> ans = pairSum(a,s);

    for (int i=0; i<ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
}