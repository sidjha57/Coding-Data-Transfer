#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define nl "\n"
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);

 
using namespace std;
 
const ll N = 2e6+5;
const ll INF = 1e9+5;
const ll mod = 1e9+7;
 
ll fac[N],invfac[N];
 

 
ll binpow(ll x,ll y){
    ll res=1;
    for(;y>0;y>>=1,x=((x%mod * x%mod)%mod))
        if(y&1)
            res=(res%mod * x%mod)%mod;
    return res;
}
 
ll inv(ll x){
    return binpow(x,mod-2);
}
 
void factorial(){
    fac[0]=1;
    for(ll i=1;i<N;i++)
        fac[i]=(fac[i-1]%mod * i)%mod;
    // invfac[N-1]=inv(fac[N-1]);
    // for(ll i=N-2;i>=0;i--)
    //     invfac[i]=(invfac[i+1]%mod * (i+1))%mod;
}
  
ll nCr(ll n,ll r){
    ll ans = fac[n];
    ans = (ans%mod * inv(fac[n-r])%mod) % mod;
    ans = (ans%mod * inv(fac[r])%mod) % mod;
    return ans;
}
 
ll starsAndBars(ll n,ll m){
    return nCr(n+m-1,m-1);
}

void solve(){
    ll n,m;
    cin >> n >> m;
  	ll ans = 0, x=0;
    
  	for(ll i=1;i<=n;i++){
      ll temp=1,tmp1,tmp2;
      tmp1 = (nCr(m, i)%mod * fac[i]%mod)%mod;
      tmp2 = (nCr(n, i)%mod * temp%mod)%mod;
      temp = (tmp1%mod * tmp2%mod) %mod;
      temp = pow(-1,i+1)*temp;
      tmp1 = (nCr(m-i, n-i)%mod * fac[n-i]%mod)%mod;
      tmp2 = (nCr(m-i, n-i)%mod * fac[n-i]%mod)%mod;
      temp = (temp%mod *tmp1%mod * tmp2%mod) %mod;
      x = (x + temp + mod)%mod;
    }
    ans = (ans + x + mod)%mod;
    cout << ans%mod << nl;
    
}
 
signed main(){
    // #ifndef LOCAL
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
        
    fastio()
    factorial();
    ll tt=1;
    while(tt--)
        solve();
}