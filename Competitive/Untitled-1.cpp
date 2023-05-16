//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
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
#define loop(x,start,end)        for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
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

bool check (int x, int n, vector<vector<int>>& range, string s, vector<int>& arr) {
    vector<vector<int>> freq (26, vector<int>(n+1,0));
    for (int i=0; i<=x;i++) {
        s[arr[i]-1] = '0';
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int idx = (s[i] - 'a');
        freq[idx][i+1]++;
    }
   for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            freq[i][j] += freq[i][j-1];
        }
   }
    bool flag = 1;
    for (int c = 0; c < 26; c++) {
        for (auto r : range) {
            if ((freq[c][r[1]] - freq[c][r[0]-1]) > 1)  {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }
    return flag;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()<=1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++) {
        if(output.back()[1] >= intervals[i][0]) output.back()[1] = max(output.back()[1] , intervals[i][1]);
        else output.push_back(intervals[i]); 
    }
    return output;
}

void solve() {
   
   int n,q;
   cin >> n >> q;
   string s ;
   cin >> s;
   vector<int> arr (n);
   loop (i,0,n) cin >> arr[i];
   vector<vector<int>> ranges (q, vector<int>(2));
   loop (i,0,q) cin >> ranges[i][0] >> ranges[i][1];
   ranges = merge(ranges);


   vector<vector<int>> freq (26, vector<int>(n+1,0));

   for (int i = 0; i < n; i++) {
    int idx = (s[i] - 'a');
    freq[idx][i+1]++;
   }
   for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            freq[i][j] += freq[i][j-1];
        }
   }
    bool flag = 1;
    for (int c = 0; c < 26; c++) {
        for (auto r : ranges) {
            if ((freq[c][r[1]] - freq[c][r[0]-1]) > 1)  {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) {
        cout << "0 \n";
        return;
    }
    
    int l = 0, r = n-1, ans = n;
    while (r >= l) {
        int mid = (r+l)/2;
        if (check(mid,n,ranges,s,arr)) {
            r = mid -1;
            ans = mid + 1;
        } else {
            l = mid +1;
        }
    }
    cout << ans << "\n";
}

int main(int argc, char const *argv[]){
    _fast

    ll t; cin >> t;
    while(t--){
     solve();
    }
  return 0;
}