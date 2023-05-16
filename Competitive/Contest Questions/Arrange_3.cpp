//Approach 3
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n=3;
    int score;
    string name;
    map <int,string, greater<int>> m; //greater<int> added so that it sorts in descending order default is ascending order
    for (int i=0;i<n;i++) {
        cin >> score >> name;
        m[score] = name; //m.insert({score,name})
    }
    for (auto& i:m) {
        cout << i.first <<" " << i.second << "\n";
    }
}
