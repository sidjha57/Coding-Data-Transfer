//template

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define endl                     "\n"
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(int i=(a);i>=(b);i--)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}


// // longest path of subtree i that starts at i
// int depth[200001];
// int ans[200001];
// vector<int> adj[200001];

// void eval_depth(int cur, int par) {
//     int cur_depth = 0;
//     for (auto child : adj[cur]) {
//         if (child != par) {
//             eval_depth(child,cur);
//             cur_depth = max(cur_depth, 1+ depth[child]);
//         }
//     }
//     depth[cur] = cur_depth;
// }

// void dfs (int cur, int par, int par_ans) {
    
//     vector<int> prefixMax,suffixMax;

//     //get depths of child nodes
//     for (auto child : adj[cur]) {
//         if (child != par) {
//             prefixMax.pb(depth[child]);
//             suffixMax.pb(depth[child]);
//         }
//     }

//     // build prefix and suffix max

//     loop (i,1,prefixMax.size()-1) 
//         prefixMax[i] = max (prefixMax[i], prefixMax[i-1]);
    
//     looprev (i,suffixMax.size()-2,0)
//         suffixMax[i] = max (suffixMax[i], suffixMax[i+1]);

//     // eval answer for each child

//     int c_no = 0;

//     for (auto child : adj[cur]) {
//         if (child != par) {
//             int op_1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
//             int op_2 = (c_no == suffixMax.size() -1) ? INT_MAX : suffixMax[c_no + 1];
//             int partial_ans = 1 + max (par_ans, max(op_1,op_2));
            
//             dfs (child, cur, partial_ans);
//             c_no ++;
//         }
//     }

//     // eval answer for current node

//     ans[cur] =  1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
// }

// void solve() {
//     ll n; cin >> n;
//     loop (i,1,n-1) {
//         ll u,v; cin >> u >> v;
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }
//     eval_depth (1,0);
//     dfs(1,0,-1);
//     loop (i,1,n) cout << ans[i] << " ";
// }
int solve(vector<int>& nums) {
    int freq[13]={},sum=0,maxi=-1;
    freq[0] = nums.size();
    for (int i=1;i<nums.size();i++) {
        string s = to_string(nums[i]);
        maxi = max((int)s.size(),maxi);
        if (s.size()>1)
        freq[s.size()]++;
        sum += nums[i];
    }
    cout << maxi << " ";
    freq[2*maxi-1]++;
    for (int i=0;i<13;i++) cout << freq[i] << " ";
    int value=0,power=1;
    for (int i=0;i<13;i++) {
         value += power*freq[i];
         power *= 10;
    }
    // cout << value <<" ";
    return value*sum;
}



#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ll t, i, j, c, ans, k, n, sum;
    
    // cin>>t;
    
    // for(j=1; j<=t; j++)
    // {
    //     cin>>n>>c;
    //     ans=n;
    //     ll l[n], r[n];
        
    //     vector<pair<ll, ll>> p, p1;
    //     vector<pair<ll, ll>> q;
        
    //     for(i=0; i<n; i++)
    //     {
    //         cin>>l[i]>>r[i];
    //     }
        
    //     sort(l, l+n);
    //     sort(r, r+n);
        
    //     for(i=0; i<n;)
    //     {
    //         k=i;
    //         while(l[i]==l[k] && i<n)
    //         {
    //             i++;
    //         }
    //         p.push_back({l[k]+1, i-k});
    //     }
        
    //     for(i=0; i<n;)
    //     {
    //         k=i;
    //         while(r[i]==r[k] && i<n)
    //         {
    //             i++;
    //         }
    //         p.push_back({r[k], k-i});
    //     }
        
    //     sort(p.begin(), p.end());
        
    //     n=p.size();
        
    //     for(i=0; i<n;)
    //     {
    //         k=i;
    //         sum=0;
    //         while(p[i].first==p[k].first && i<n)
    //         {
    //             sum=sum+p[i].second;
    //             i++;
    //         }
    //         p1.push_back({p[k].first, sum});
            
    //     }
        
    //     n=p1.size();
        
        
    //     for(i=1; i<n; i++)
    //     {
    //         p1[i].second+=p1[i-1].second;
    //     }
        
        
    //     for(i=0; i<n-1; i++)
    //     {
    //         if(p1[i].second>0)
    //         {
    //             q.push_back({p1[i].second, p1[i+1].first-p1[i].first});
    //         }
    //     }
        
    //     sort(q.begin(), q.end());
    //     reverse(q.begin(), q.end());
        
    //     n=q.size();
        
    //     for(i=0; i<n; i++)
    //     {
    //         if(c==0)
    //         break;
            
    //         if(q[i].second>c)
    //         {
    //             ans=ans+q[i].first*c;
    //             c=0;
    //         }else{
    //             ans=ans+q[i].second*q[i].first;
    //             c=c-q[i].second;
    //         }
    //     }
        
    //     cout<<"Case #"<<j<<": "<<ans<<"\n";
        
        
        
        
    // }
}