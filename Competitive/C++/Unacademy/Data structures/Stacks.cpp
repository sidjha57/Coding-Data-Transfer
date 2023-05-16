/* Stacks implementation and basic problems */

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




// valid parenthesis

// void valid_parenthesis (string s) {

// }

/*Given an array find the next greater element of all indices if no element is greater than the ith element print N*/
vi NgE (vi arr) {
    vector<pii> left_right; vi nge(arr.size());
    stack<pii> stk;stk.emplace(make_pair(arr[0],0));
    loop (i,0,arr.size()-1) left_right.pb(mp(arr[i],i));
    loop (i,1,arr.size()-1) {
        if (stk.top().ff < left_right[i].ff) 
            while (!stk.empty() && stk.top().ff < left_right[i].ff) {
                nge[stk.top().ss] = left_right[i].ss;
                stk.pop();
            }
        stk.emplace(left_right[i]);
    }
    ll last_index = stk.top().ss+1;
    while (!stk.empty()) {
        nge[stk.top().ss] = last_index;
        stk.pop();
    }
    return nge;
}

/*Given an array find the previous greater element of all indices if no element is greater than the ith element then its -1*/
vi PgE (vi arr) {
    vector<pii> right_left; vi pge(arr.size());
    stack<pii> stk; stk.emplace(arr[arr.size()-1],arr.size()-1);
    looprev (i,arr.size()-1,0) right_left.pb(mp(arr[i],i));
    loop (i,1,arr.size()-1) {
        if (stk.top().ff < right_left[i].ff) 
            while (!stk.empty() && stk.top().ff < right_left[i].ff) {
                pge[stk.top().ss] = right_left[i].ss;
                stk.pop();
            }
        stk.emplace(right_left[i]);
    }
    ll first_index = -1;
    while (!stk.empty()) {
        pge[stk.top().ss] = first_index;
        stk.pop();
    }
    return pge;
}



/*Given an array find the sum of max of all subarrays */ 
ll find_max (vi arr) {
    vi pge,nge;
    ll ans = 0;
    pge = PgE(arr),nge = NgE(arr);
    loop (i,0,arr.size()-1) ans += arr[i]*(nge[i] - i) * (i - pge[i]);
    return ans;
}

/*Given histograms lengths find the maximum area such that they are of unit length wide */

// calculate a[i] * (nse[i]-pse[i]-1) element into width between next smaller element encounterd and previous smaller element



int main(int argc, char const *argv[]){
    //valid_parenthesis ("");
    vi arr {1,5,2,3},ans;
    ans = PgE (arr);
    loop (i,0,ans.size()-1) cout << ans[i] << " ";
    cout << "\n";
    ans = NgE (arr);
    loop (i,0,ans.size()-1) cout << ans[i] << " ";
    cout << "\n";
    cout << find_max(arr);
  return 0;
}



