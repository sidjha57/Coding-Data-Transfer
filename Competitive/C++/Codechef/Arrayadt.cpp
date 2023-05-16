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

 class Arrayadt {
 
 private:
     ll total_size;
     ll used_size;
     ll *ptr;
 public:
     Arrayadt (ll tsize, ll usize);
      ~Arrayadt ();
     void set_val (ll usize) ;
     ll get_val (ll position);
     void insert_val (ll value,ll index);
     ll delete_val (ll position);
     ll search_val (ll number);

 };
 
 Arrayadt::Arrayadt (ll tsize,ll usize) {
     used_size = usize;
     total_size = tsize;
     ptr =  new ll (tsize);
 }
 
 Arrayadt ::~Arrayadt () {
      delete  ptr;
 }

 void Arrayadt::set_val(ll usize) {
            used_size= usize;
             f (i,used_size) {
                 cout << "Enter element " << i + 1 << "\t ";
                 //printf ("enter element");
                 cin >> ptr[i];
             }
 }
  
 ll Arrayadt::get_val(ll position) {
     return ptr[position-1];
 }

 void Arrayadt::insert_val(ll value,ll index) {
       if (index > total_size) cout << "-1";
       else if (index < used_size) {
            for (int i = 0; i < index; i++) {
                    ptr[used_size - i] = ptr[used_size - i - 1]; 
            } 
            ptr[index-1] = value;
            used_size ++;
              f(i,used_size) cout << ptr[i] << " ";
              cout << "\n";
       }
       else cout << "-1";
      //return -1;
 }

ll Arrayadt::delete_val(ll index) {
     if (index > used_size) return -1; 
     else {
          for (ll i = index-1; i < used_size -1; i++) {
              ptr[i] = ptr [i + 1];
          }
          used_size -= 1;
          cout << used_size;
           f(i,used_size) cout << ptr[i] << " ";
     }
     return 0;
}

ll Arrayadt::search_val(ll value) {
     f (i,used_size) {
         if (value == ptr[i]) return i+1;
         
     }
      return -1;
}

 int main(){
    //_cin// for fast I/O
    Arrayadt A(20,5),B(5,2);
    A.set_val(5);
    B.set_val(2);
    cout << B.get_val(1)<<"\n";
    cout << A.get_val(2)<<"\n";
    A.insert_val(34,3);
    cout << A.delete_val(2)<< "\n";
    cout << A.search_val(3)<<"\n"; 
     
   return 0;
 }