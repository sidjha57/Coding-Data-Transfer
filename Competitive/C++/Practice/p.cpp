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
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define SET(a) memset( a, -1, sizeof a )
#define CLR(a) memset( a,  0, sizeof a )
#define Pi 3.141592653589793
#define mod 1000000007
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

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

/// Functions Start
template <class T> T amax( T a, T b ) {return ( a > b ? a : b );}
template <class T> T amin( T a, T b ) {return ( a < b ? a : b );}
template <class T> T gcd(T a,T b) {if(b == 0)return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b ) {return (a*b)/gcd(a,b);}
template <class T> T prime(T n) { if(n%2==0)return 0; else{T count=0; 
for(T i=3;i<sqrt(n)+1;i+=2)
{if(n%i==0)count++;if(count==1)break;}
if(count==1)return 0; else return 1;}} //at max 15812 times for 9 digit long number

ll fac (ll n) {
    ll sum = 0;
    for (ll i=1;i<=n/2;i++) {
        if (n%i==0) sum ++;
    }
    return sum;
}

ll solve(ll n, ll m)
{
    ll ans = 0;
    if(n >= m)
    {
        ans += ((n - m + 1) * (n - m)) / 2; // m < a < b
        ans += ((m - 1) * (n - m)) + fac(m); // a < m < b
        for (int b = 2; b <= m - 1; b++)
        {
            int x = b*(m/b), i = 1;
            while(i * i <= x)
            {
                if(x % i == 0)
                {
                    if(i < b) {
					   //cout <<  "{" <<i << "," << b <<"}\n";
                       ans ++;
					}
                    if(x / i != i)
                    {
                        if(x/i < b) {
						//cout <<  "{" <<x/i << "," << b <<"}\n";
                        ans++;
					  }
                    }
                }
                i++;
            }
        }
    }
    else
    {
        for (int b = 2; b <= n; b++)
        {
            int x = b*(m/b), i = 1;
          
            while(i * i <= x)
            {
                if(x % i == 0)
                {
                    if(i < b)
                        ans ++;
                    if(x / i != i)
                    {
                        if(x/i < b)
						  ans++;
                    }
                }
                i++;
            }
        }
    }
    return ans;
}

int main()
{
    ll t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}