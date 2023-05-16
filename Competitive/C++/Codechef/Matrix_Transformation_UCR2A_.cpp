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
    int n[1];
    char a[1];
    
    cin >> n[0] >> a[0];
    int num[n[0]][n[0]];
    f (i,n[0])  {
        f (j,n[0]) 
        cin >> num[i][j];
        
    }
    if (a[0]=='N') {
       f (i,n[0])  {
        f (j,n[0]) 
        cout << num[i][j]<<" ";
        
       }
    }
 
    if (a[0] == 'V') {
       f (i,n[0])  {
        for (int j=n[0]-1; j>=0; j--) {
        cout << num[i][j]<<" ";
        }
      }
    }
 
    if (a[0] == 'B') {
       for (int i=n[0]-1; i>=0; i--) { 
        for (int j=n[0]-1; j>=0; j--) {
        cout << num[i][j]<<" ";
        }
      }
    }
    
    if (a[0] == 'H') {
       for (int i=n[0]-1; i>=0; i--) {  
       f (j,n[0]){
        cout << num[i][j] << " ";
        }
      }
    }
    
   return 0;
 }