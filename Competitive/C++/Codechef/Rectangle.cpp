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



 int main(){
    _cin// for fast I/O
    
     ll t,n,m,j1,j2,i1,i2,j,i;
     cin>>t;
     while(t--){
      cin >> n >> m;
      char grid[n][m];
      bool fj = true,fi = true;
      for (i=0;i<n;i++) { 
          for (j=0;j<m;j++) {
          cin >> grid[i][j];
          if (fj && grid[i][j] == '1') {
              j1 = j;
              fj = false;
            }
            if (j != 0 &&grid[i][j-1] == '1' && grid[i][j] == '1')
             j2 = j;
          
          }
          if (fi && grid[i][j] == '1') {
          i1 = i;
          fi = false;
         }
        if (i != 0 && grid[i-1][j] == '1' && grid[i][j] == '1')
         i2 = i;
        
      }
      bool f = false;
      for (i = i1; i <i2;i++) {
          if (grid[i][j1] == '0' || grid[i][j2] == '0')
            {
                cout << "NO\n";
                f = true;
                break;
            }
      }
      if (!f) {
       for (j = j1; j <j2;j++) {
          if (grid[i1][j] == '0' || grid[i2][j] == '0')
            {
                cout << "NO\n";
                f=true;
                break;
            }
         }
      }
      if (f) cout << "YES\n";
     }
   return 0;
 }