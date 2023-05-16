#include "bits/stdc++.h"
using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define FO(i,a,n) for(int i=a; i<n; i++)
#define deb(x) cout << #x << " " << x << "\n";
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
#define pel cout << "\n";
#define accuracy setprecision(20)
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define mii map<int, int>
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll mod1 = 998244353;
const long double Pi = acos(-1);
const long double euler= 2.7182818284590452353602;

bool isPrime(ll n) 
{ 
if (n <= 1)  return false; 
if (n <= 3)  return true; 
if (n%2 == 0 || n%3 == 0) return false; 
for (int i=5; i*i<=n; i=i+6) 
if (n%i == 0 || n%(i+2) == 0) 
return false; 
return true; 
} 
void psi(int T) 
{
    int n; cin>>n;
    vi b,v; int x;
    mii m,ch;
    fo(i, 2*n)
    {
        cin>>x;
        b.pb(x);
        if(m[x]==0) v.pb(x);
        m[x]++;
    }
    sort(all(v));
    int k=0; ch[v[0]]++;
    for (int i = 1; i < v.size(); i++)
    {
           int mm = ceil((i+1)/2.0);
           ch[v[mm-1]]++;
    }
     k = v.size()-1; ch[v[k]]++;

    for (int i = k-1; i >= 0; i--)
    {
        int mm;
         mm = i+ceil((k-i+1)/2.0);
       
        ch[v[mm-1]]++;
    }
    
    for (auto i = m.begin(),j=ch.begin(); i != m.end(); i++,j++)
    {
        if(*i!=*j)
        {
            cout << "-1\n";
            return;
        }
        /* code */
    }

    fo(i,v.size())
    {
        cout << v[i] << ' ';
    }

    pel;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

int T=1;    
cin >> T;
while (T--)
{
psi(T);
}
return 0;
}