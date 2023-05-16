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
#define SET(a) memset( a, -1, sizeof (a) )
#define CLR(a) memset( a,  0, sizeof (a) )
#define Pi 3.141592653589793
#define mod 1000000007
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);

/// TypeDef Start
typedef  long long int       ll;
typedef  map<string,int>     msi;
typedef  map<int,int>	     mii;
typedef  map<ll, ll>         mll;
typedef  map<char,int>       mci;
typedef  map<int,string>     mis;
typedef  pair<int,int>       pii;
typedef  pair<string,int>    psi;
typedef  pair<string,string> pss;
typedef  vector<int> 	     vi;
typedef  vector<string>      vs;
typedef  vector<char>	     vc;
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

 int t[16][81];
 int knapsack (int wt[],int val[],int w,int n) {
    if (w == 0 || n == 0) return 0;

    //if (t[n][w] != -1) return t[n][w];

    if ( w >= wt[n-1]) return  amax <int> (val[n-1] + knapsack(wt,val,w - wt[n-1],n-1), knapsack(wt,val,w,n-1)); 
    
    else return  knapsack (wt, val, w, n-1);
 } 

 int main(){
    _cin// for fast I/O
    int wt[30] = {20,30,1,4,4,8,10,11,5,2,3,1,140,130,12,10,20,5000,10,60,180,74,50,20,84,90,100,110,30,80};
    int val[30] = {10,20,5,30,80,20,30,50,4,4,8,10,10,60,180,74,50,20,84,90,100,110,11,5,2,3,1,140,130,12};
    int w = 80;
    SET(t);
    cout << knapsack(wt,val,w,5); 
   //cout << "hello";
   return 0;
 }