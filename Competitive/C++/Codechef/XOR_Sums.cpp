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

vector <ll> bitPosition ={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,
1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,214483648};
long long nCr(ll n, ll r)
{
	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	long long p = 1, k = 1;
	// choosing the smaller value
    if (n == 0 || r == 0) return 1;
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			long long m = __gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else
		p = 1;
    return p;
}

 int main(){
	_cin// for fast I/O
	
	 ll n,q,r,N,i,count,j,ans,sum,max=0,bit=0;
     vl bit_count_1 (30,0), bit_count_0(30,0);
	 cin>>N;
     vl a(N);
	 f(i,N)  {
         cin >> a[i];
         if (a[i]  > max) max = a[i];
     }
     cin >> q;
     vl M(q);   
    for (i=0;i<q;i++) cin >> M[i];
     
    for (i=0;i<N;i++) {
        for (j=0;j<30;j++) {
            bit = a[i] & bitPosition[j];
            if (bit == 1)
            bit_count_1[j]++;
            else if (bit == 0)
            bit_count_0[j]++;
        }
    }
    int k = lower_bound (bitPosition.begin(), bitPosition.end(),max) - bitPosition.begin();
     n = q;
     while (q--) {
         ans =0,sum=0,j=0;
          for (i=0;i<k;i++) {
               
               ans += nCr(bit_count_1[i],M[n-q]-1)*nCr(bit_count_0[i],M[n-q]-2)*bitPosition[i];
          }
          cout << ans << endl;
     }
     
   return 0;
 }