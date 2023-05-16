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
    
     ll t,n,a,b,c,m,k,i,j,l1,r1,l2,r2;
     cin>>t;
     while(t--){
      cin >> n>> m>> k;
      ll matrix[n+1][m+1],count=0;
        
      for (i=0;i<n+1;i++)
          for(j=0;j<m+1;j++) { 
              if (j==0 || i == 0) {
                matrix[i][j] =0;
                continue;
              }
              cin >> matrix[i][j];
              if (matrix[i][j] >= k) count++;
          }
      
     
      for(int l=1;l<n+1;l++) 
          for (int k=0;k<m+1;k++) 
            matrix[l][k] += matrix[l-1][k];

      for(int k=1;k<m+1;k++) 
          for (int l=0;l<n+1;l++) 
            matrix[l][k] += matrix[l][k-1];
        
       ll minimum = min(n,m),sum=0,sub_size=2;
       while (sub_size <= minimum) {
         for (i=sub_size;i<n+1;i++) {
           sum = 0;
           for (j =sub_size; j <m+1;j++) {
             sum = matrix[i][j] - matrix[i-sub_size][j]- matrix[i][j-sub_size] + matrix[i-sub_size][j-sub_size];
             if (sum >= (sub_size*sub_size*k)) {
               count += m-j+1;
               break;
             }

           }
         }
         sub_size++;
       }
         
       cout << count <<"\n";
     }
   return 0;
 }