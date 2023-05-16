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
#define SET(a) memset( a, -1,    sizeof a )
#define CLR(a) memset( a,  0,    sizeof a )
#define Pi 3.141592653589793
#define mod 1000000007
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

/// TypeDef Start
typedef  long long int       ll;
typedef  map<string,int>     msi;
typedef  map<int,int>	       mii;
typedef  map<ll, ll>         mll;
typedef  map<char,int>       mci;
typedef  map<int,string>     mis;
typedef  pair<int,int>       pii;
typedef  pair<string,int>    psi;
typedef  pair<string,string> pss;
typedef  vector<int> 	       vi;
typedef  vector<string> 	   vs;
typedef  vector<char>	       vc;
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

 struct Time {
     int Lhr=0,Lmin=0,Rhr=0,Rmin=0;
 };
int convertIntoMinutes (string s) {
    int hr,min;
    min = 10 * (s[3] -'0') + (s[4] -'0');
    hr  = 10 * (s[0] - '0') + (s[1] - '0');
    if (hr == 12 && s[5] =='A')
    min = min+0;
    else if (hr == 12 && min == 0 && s[5] =='P')
    min = 12*60;
    else if (s[5] == 'P') {
        hr += 12;
        min += hr*60;
    }
    else {
        min += hr*60;
    }
    return min;
}

Time solveForTime (string s) {
    int hr1=0,min1=0,hr2=0,min2=0;
    Time t;
    min1 = 10 * (s[3] -'0') + (s[4] -'0');
    hr1  = 10 * (s[0] - '0') + (s[1] - '0');
    if (s[5] == 'P' && hr1 < 12) hr1 += 12;
    else if (s[5] == 'A' && hr1 == 12) hr1 = 0;

    t.Lhr = hr1;
    t.Lmin = min1;
    if (s.length() > 11) {
    min2 = 10 * (s[10] -'0') + (s[11] -'0');
    hr2  = 10 * (s[7] - '0') + (s[8] - '0');
    if (s[12] == 'P' && hr2 < 12) hr2 += 12;
    else if (s[12] == 'A' && hr2 == 12) hr2 = 0;
    t.Rhr = hr2;
    t.Rmin = min2;
    }
    return t;
}
bool solve (int hr1,int min1,int hr2, int min2) {
    if (hr1 > hr2) return 1;
    if (hr1 == hr2 && min1 >= min2) return 1;
    return 0;
}
 int main(){
    //  convertIntoMinutes ("12:01 AM");
    //  solveForTime ("11:59 AM 11:59 PM");
   // _cin// for fast I/O
    
     ll t,n,i,P,j;
     char s1[7];
     Time Pt,time;
     cin>>t;
     while(t--){
         f(i,7)
      cin >> s1[i]; 
      cin>>n;
      Pt = solveForTime(s1);
      char s[n][14];
      for (i = 0; i < n ; i++) {
          for (j=0; j <14; j++)
      cin >> s[i][j];
      }
      bool f1,f2;
      for (i =0; i < n ; i++) {
          time = solveForTime (s[i]);
          f1 = false,f2= false;
          
          if (time.Lhr < Pt.Lhr) f1 = true;
          else if (time.Lhr == Pt.Lhr && time.Lmin <= Pt.Lmin) f1 = true;

          if (time.Rhr > Pt.Lhr) f2 = true;
          else if ( time.Rhr == Pt.Lhr && time.Rmin >= Pt.Lmin) f2 = true;

          if (f1 && f2) cout <<"1";
          else cout << "0";
      }
      cout << "\n";

     }
   return 0;
 }