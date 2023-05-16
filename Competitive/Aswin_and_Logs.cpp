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
#define eb                       emplace_back
#define em                       emplace
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
#define loop(i,a,b)              for(ll i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(ll i=(a);i>=(b);i--)
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

void fileIO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
string start,ending;

bool before (ll syear, ll smonth, ll sday, ll year, ll month, ll day) {
    if (syear == year && smonth == month ) {
        return sday <= day;
    } else if (syear == year) {
        return smonth < month;
    } else {
        return syear < year;
    }
}

bool after (ll eyear, ll emonth, ll eday, ll year, ll month, ll day) {
    if (eyear == year && emonth == month ) {
        return eday >= day;
    } else if (eyear == year) {
        return emonth > month;
    } else {
        return eyear > year;
    }
}

bool check (string date) {
    ll year = stoi(date.substr(0,4)),month = stoi(date.substr(5,2)),day = stoi(date.substr(8,2));
    ll syear = stoi(start.substr(0,4)),smonth = stoi(start.substr(5,2)),sday = stoi(start.substr(8,2));
    ll eyear = stoi(ending.substr(0,4)),emonth = stoi(ending.substr(5,2)),eday = stoi(ending.substr(8,2));

    return before(syear,smonth,sday,year,month,day) && after(eyear,emonth,eday,year,month,day);
}

void solve() {
    ll n; cin >> n;
    map <ll,ll> costing;
    map<string,ll> flavours;
    flavours.emplace ("SMALL",1),flavours.emplace ("MEDIUM",2),flavours.emplace ("LARGE",3),flavours.emplace ("XLARGE",5);
    cin >> start >> ending;
    loop (i,0,n-1) {
        string bil,date,hr,vm_id,flavour; cin >> bil >> date >> hr >> vm_id >> flavour;
        if (check(date)) {
            costing[stoi(vm_id)] += flavours[flavour];
        }
    }

    for (auto logs : costing) {
        cout << logs.ff << " " << logs.ss << "\n";
    }

}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}