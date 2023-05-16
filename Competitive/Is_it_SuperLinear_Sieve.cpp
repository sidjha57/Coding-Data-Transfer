#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=1e6+7;
const int mod=1e9+7;
const double eps=1e-6;
const double pi=   3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;


bool sieve[N+1];

ll exponent(ll n,ll a)
{
   ll ans=0;
   while(n%a==0)
   {
      ans++;
      n=n/a;
   }
   return ans;
}

ll binpow(ll base,ll exp)
{
   ll ans=1ll;
   while(exp>0)
   {
      if(exp%2==1)
            ans=(ans*base);
      exp=exp/2;
      base=base*base;
   }
   return ans;
}

int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   memset( sieve , true , sizeof(sieve));
   for(int i=2;i*i<=N;i++)
   {
      if(sieve[i]==true)
      {
         for(int j=i*i;j<=N;j+=i)
            sieve[j]=false;
      }
   }

   vector<ll> primes;
   for(int i=2;i<=N;i++)
   {
      if(sieve[i]==true)
            primes.pb(i);
   }


   int t;
   cin >> t;
   while(t--)
   {
      ll a,b;
      cin >> a >> b;

      int siz=b-a+1;
      vector<ll> least(siz,100),divi(siz,1ll),made(siz,1ll);

      for(auto ele : primes)
      {
         ll start=(a+ele-1ll)/ele;
         start=start*ele;
         if(start>b)
               break;

         while(start<=b)
         {
            ll exp = exponent(start,ele);
            least[start-a] = min(least[start-a],exp+1);
            divi[start-a]  = divi[start-a]*(exp+1ll);
            made[start-a]  = made[start-a]*binpow(ele,exp);
            start+=ele*1ll;
         }
      }

      ll ans=0ll;
      for(ll i=0;i<siz;i++)
      {
         if(made[i]!=a+i)
            ans=ans+divi[i];
         else
            ans=ans+(divi[i]/least[i]);
      }

      cout << ans << "\n";

   }
      
}

/*
I can't wait to live in glory and eternal lasting life
*/