#include <bits/stdc++.h>

using namespace std;

// void increase_count (vector<vector<int>>& freq, char ch, int& sum, string& s, int i, int k) {
//    freq[i][s[k] - ch] ++;
//    sum += (s[k] - ch) + 1;
// }

// void sort_it (int i,int start, int end, vector<vector<int>>& freq, string& ans) {
//   for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--)) {
//     if (freq[i][x] > 0) {
//       char ch = 'a' + x;
//       int cnt = freq[i][x];
//       while (cnt--) {
//         ans.push_back(ch);
//       }
//     }
//   }
// } 

int main() {
  
  string s,ans; cin >> s;
  int dash = 0;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == '-') dash++;
  }
  
  vector<pair<string,int>> words(dash+1);
  int k = 0, i=0;
  while (k < s.size()) {
    int &sum = words[i].second;
    string &temp = words[i].first;
    while (k < s.size() && s[k] != '-') {
        int id;
        if (s[k] > 'Z') 
            id = s[k] - 'a'; 
        else 
            id = s[k] - 'A';
        
        char ch = 'a' + id;
        sum += id + 1;
        temp.push_back(ch);
        k++;
    }
    k++,i++;
  }

  sort(words.begin(),words.end());

  for (int i=0; i<words.size(); i++) {
    int sum = words[i].second;
    string &temp = words[i].first;
    if (words[i].second&1) {
        sort(temp.begin(),temp.end(), greater<char> ());
    } else {
        sort(temp.begin(), temp.end());
    }
  }

  for (int i=0; i<words.size(); i++) {
    if (i != words.size()-1) cout << words[i].first << '-';
    else cout << words[i].first;
  }
//   vector<vector<int>> freq(dash+1, vector<int> (27, 0));
  
//   int k = 0, i=0;
//   while (k < s.size()) {
//     int sum = 0;
//     while (k < s.size() && s[k] != '-') {
      
//       if (s[k] > 'Z') 
//         increase_count(freq,'a', sum, s, i, k);
//       else 
//         increase_count(freq,'A', sum, s, i, k);
      
//       k++;
//     }
//     freq[i][26] = sum;
//     i++,k++;
//   }
  
//   map<string,int> strs;
  
//   for (int i=0; i<freq.size(); i++) {
//     string temp;
//     sort_it(i,0,26,freq,temp);
//     strs[temp] = i;
//   }

//   for (auto &word : strs) {
//     int idx = word.second;
//     if (freq[idx][26]&1) {
//         string temp;
//         sort_it(idx,26,0,freq,temp);
//         ans += temp;
//     } else {
//         ans += word.first;
//     }
//     ans.push_back('-');
//   }

//   ans.pop_back();
  
//   cout << ans;
  
}