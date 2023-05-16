#include<bits/stdc++.h>
#define int         int64_t
#define ll          long long 
#define pb          push_back
#define endl        '\n'
#define pll         pair<int,int>
#define vll          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mi        map<int,int>
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
void solve(){
    int c;
    cin>>c;
    if(c==0){
        cout<<2<<endl<<"1 1"<<endl;
        return ;
    }
    vector<int> ans;
    int count=0;
    for(int i=59; i>=0;i--){
       
       if(  ((c>>i)&1)==1){
            if(count%2==0){
                count++;
                int val= (1LL*1<<(i+1)) -1;
                ans.pb(val);
            }
       }else{
          if(count%2!=0){
             count++;
            int val= (1LL*1<<(i+1)) -1;
                ans.pb(val);
          }
       }
    }
     // if(count==0){
     //    cout<<count<<endl;
     //    return;
     // }
    cout<<count<<endl;
    for( auto  x: ans){
      cout<<x<<" ";
    }
    cout<<endl;
}
signed main(){
    ios
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    int test=1;
    cin>>test;
    // int val=1;
    while(test--){
        solve();
        // val++;
    }    
    return 0;
}