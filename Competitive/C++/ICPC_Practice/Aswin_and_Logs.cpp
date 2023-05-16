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

map <string , int> price_match {{"SMALL",1}, {"MEDIUM",2}, {"LARGE",3}, {"XLARGE",5}}; 

bool checkbefore(ll y1,ll m1,ll d1,ll y2,ll m2,ll d2) {
    if(y1==y2 && m1==m2) return d1<=d2;
    else if(y1==y2) return m1<m2;
    else return y1<y2;
}
bool checkafter(ll y1,ll m1,ll d1,ll y2,ll m2,ll d2) {
    if(y1==y2 && m1==m2) return d1>=d2;
    else if(y1==y2) return m1>m2;
    else return y1>y2;
}
bool span(string date, string start, string end) {
    ll dateyear=stoi(date.substr(0,4));
    ll datemonth=stoi(date.substr(5,2));
    ll dateday=stoi(date.substr(8,2));
    ll startyear=stoi(start.substr(0,4));
    ll startmonth=stoi(start.substr(5,2));
    ll startday=stoi(start.substr(8,2));
    ll endyear=stoi(end.substr(0,4));
    ll endmonth=stoi(end.substr(5,2));
    ll endday=stoi(end.substr(8,2));
    return (checkbefore(dateyear,datemonth,dateday,endyear,endmonth,endday)&&checkafter(dateyear,datemonth,dateday,startyear,startmonth,startday));
}
int main() {
    ll n; cin>>n;
    assert (n >= 1 && n <= 200000);
    string start,end,text,date,flavor;
    ll h,vmid;
    map <ll,ll> id_cost;
    cin>>start>>end;
    for(int i=0;i<n;i++) {
        cin>>text>>date>>h>>vmid>>flavor;
        assert (vmid >= 1 && vmid <= 1000000000);
        assert (h >= 0 && h <= 23);
        if (span(date,start,end)) 
            id_cost[vmid] += price_match[flavor];  
    }
     for ( auto x: id_cost) cout << x.first << " " << x.second << "\n";
    return 0;
}