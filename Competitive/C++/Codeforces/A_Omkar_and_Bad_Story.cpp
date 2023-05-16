//template
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>

using namespace std;

#define ull unsigned long long
#define ld long double
#define pb push_back
#define pu pop_up
#define ff first
#define ss second
#define mp make_pair
#define vv vector
#define endl '\n'
#define f(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define SET(a) memset( a, -1, sizeof a )
#define CLR(a) memset( a,  0, sizeof a )
#define Pi 3.141592653589793
#define mod 1000000007
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);
#define N 1e7

/// TypeDef Start
typedef  long long int       ll;
typedef  map<string,int>     msi;
typedef  map<int,int>	    mii;
typedef  map<ll, ll>         mll;
typedef  map<char,int>       mci;
typedef  map<int,string>     mis;
typedef  pair<int,int>       pii;
typedef  pair<string,int>    psi;
typedef  pair<string,string> pss;
typedef  vector<int> 	    vi;
typedef  vector<string>      vs;
typedef  vector<char>	    vc;
typedef  vector<bool>        vb;
typedef  vector<ll>          vl;
typedef  vector< pii >       vii;


void solve() {
    ll n,a; 
    cin >> n;
    vector<int> arr; 
    loop (i,0,n-1) {
        cin >> a;
        arr.emplace_back(a);
        }
    ll k = n-1;
    bool flag = false;
    loop (i,0,k) {
        loop (j,0,k) {
            if (find (arr.begin(), arr.end(), abs (arr[i]-arr[j])) == arr.end()) {
                arr.emplace_back (abs (arr[i]-arr[j])); k++;
            }
            if (k > 300) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) 
        cout << "NO\n";
     
    else {
        cout << "YES\n" << arr.size() << "\n";
        for (auto x : arr) 
            cout << x << " ";
        cout << "\n";
    }
}

int main(int argc, char const *argv[]){
    _cin
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}