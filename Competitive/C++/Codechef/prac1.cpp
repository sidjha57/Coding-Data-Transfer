#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

 

int main() {
    map <char,int> m;
    int n[0];
    int count[0]=(0);
    cin >> n[0];
    char s[n[0]];
    for (int i=0;i<n[0];i++) {
        cin >> s[i];
        m[s[i]]++;
    }
   map<char, int>::iterator it;

for (it = m.begin(); it != m.end(); it++)
{
    if (it->second >= 2) {
        count[0]++;
    }
    if (count[0] >=2)
    {
        cout << it->first <<"\n";
        break;
    }
}
    return 0;
}
