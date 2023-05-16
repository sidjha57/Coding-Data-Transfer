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
    
     ll t,n,a,b,c,i,j;
     string s;
     cin>>t;
     while(t--){
     cin >> s;
     n = s.length();
     ll f = 1;
     for (i=0; i<n; i++) {
         if (s[i] != 'a' ) {
             f = 0; break;
         }
     }
     if (f) cout<< "NO\n";
     else {
    //  string s1;
    //  j = 0;
    //  ll index = -1;
    //  bool f = false;
    // //  ll k = (n%2 == 0)? n/2: (n/2 +1);
    // //  while (j != k) {
    // //      if (s[j] == s[n-1-j]) {
    // //          index = j;
    // //          break;
    // //      }
    // //      else {
    // //          if (s[j] == 'a') {
    // //              index = j;
    // //              f=true;
    // //          }
    // //          if (s[n-1-j] == 'a') {
    // //              index = n-1-j;
    // //              f=true;
    // //          }
    // //          else {
    // //              index = j;
    // //              f = true;
    // //          }
    // //      }
    // //      if(f) break;
    // //      j++;
    // //    }
    //    if (index == -1) cout<<"NO\n";
    //    else {
    //        cout <<"YES\n";
    //        for (i=0; i<n; i++) {
    //            if (i == index) s1.push_back('a');
    //            s1.push_back(s[i]);
    //        }

    //        cout <<s1<<"\n";
    //    }
      string s1,s1_rev;
      s1_rev = 'a' + s;
      s1 = 'a' + s;
      reverse(s1_rev.begin(),s1_rev.end());
      cout << "YES\n";
      if (s1 == s1_rev) cout<< s + 'a' <<"\n";
      else cout << s1<<"\n";
      }
     }
   return 0;
 }