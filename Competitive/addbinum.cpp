//template

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define endl                     "\n"
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(int i=(a);i>=(b);i--)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}

// string solve(string a, string b) {
//     string ans = "";
//     char carry = '0';
//     int i = 0,j=b.size()-1;
//     if (a.size() > b.size()) swap(a,b);
//     for (i=a.size()-1; i>= 0; i--,j--) {
//         if (a[i] == '1' && b[j] == '1' && carry == '1') ans += '1'; //111
//         else if (a[i] == '1' && b[j] == '1' && carry == '0') { // 110
//             ans += '0', carry = '1';
//         } else if ((a[i] == '1' || b[j] == '1') && carry == '1') ans += '0'; //101 011 
//         else if ((a[i] == '1' || b[j] == '1') && carry == '0') ans += '1'; // 100 010
//         else if (a[i] == '0' && b[j] == '0' && carry == '1') { // 001
//             ans += '1', carry = '0';
//         }
//         else if (a[i] == '0' && b[j] == '0' && carry == '0') ans += '0';
//     }
//     for (int k=j; j >= 0; j--) {
//         if (b[k] == '1' && carry == '1') ans += '0'; // 1 1
//         else if (carry == '1') {
//               ans += '1',carry = '0';
//         } else {
//             ans += b[k];
//         }
//     }
//     if (carry == '1') ans += '1';
//     reverse(ans.begin(),ans.end());
//     return ans;

//     // 111, 110, 001,000,101, 100, 011, 010
// }
// int solve(string s) {
//     // int ans = 1,mod=1000000007;
//     int ans = 1;
//     for (int i=1; i<s.size()-1;i++) {
//         if (s[i] == '0' && s[i-1] == '0') {
//             return 0;
//         }
//         if (s[i] == '*' && s[i-1] == '*') ans = (ans *(9*9 + 12))%mod;
//         else if (s[i] == '*' || s[i-1] == '*') {
//             if (s[i] == '1' || s[i] == '1') ans = (ans*18)%mod;
//             else if (s[i-1] == '2') ans = (ans*(15))%mod;
//             else ans = (ans*9)%mod;
//         }
//         else if (s[i] != '0' && s[i-1] != '0') ans = (ans*2)%mod;
//     }
//     return ans ;
// }


// vector<vector<int>> rotateMatrix(vector<vector<int> > &matrix){    	
// 	int row = matrix.size();
// 	int col = matrix[0].size();
	
//     vector<vector<int>> ans(col,vector<int> (row));
// 	for(int i = 0; i < row; i++)
// 		for(int j = 0; j < col; j++)
//             ans[j][col-i-1] = matrix[i][j];
	
// 	return ans;
// }

bool solve(vector<vector<int>>& matrix) {
    int n = matrix.size(),m=matrix[0].size();
    int i=0,j=0,z=0,val;
    while (z < (n+m-1)) {
        int l=i,k=j;
        val = matrix[l][k];
        while (l <n && k<m) {
            if (val != matrix[l][k]) return false;
            l++,k++;
        }
        if (j < m-1 && i == 0) {
            j++;
        } else {
            j=0,i++;
        }
        z++;
    }
    return true;
}

int main(int argc, char const *argv[]){
    _fast
    vector<vector<int>> matrix {{0,1,2},{3,0,1},{4,3,0},{5,4,3}};
     cout << solve(matrix);
  return 0;
}