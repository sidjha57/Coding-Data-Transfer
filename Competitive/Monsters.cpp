//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
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

/*
    Pacman has to reach the boundary before the monsters catch him, find if there is a path for pacman to reach the boundary 
    even if the monsters know the path. Print the path and also the time required to reach the boundary such that in one second 
    pacman and the monsters can move one cell up,down,left,right.

    A is the start, M is the Monster, . means floor and '#' means wall.
*/
ll n,m; 
vector<vi> dis;
vector<pii> a,monster, moves = {{-1,0}, {1,0}, {0,1}, {0,-1}};
map<pii,pii> parent;
pii start_a, end_a;

bool check (ll x, ll y, ll timer) {
    if (x < 0 || y < 0 || x >= n || y >= m || dis[x][y] <= timer) return false;
    return true;
}

bool reachable (ll x, ll y, ll timer) {
    if (!check (x, y, timer)) return false;
    if (x == 0 || y == 0 || x == n-1 || y == m-1) return true;
    return false;
}

void monster_dis () {
    queue <pair<pii,ll>> q;

    for (auto m : monster) 
        q.push({m,0});

    while (!q.empty()) {
        ll x = q.front().ff.ff, y = q.front().ff.ss, timer = q.front().ss;
        timer++, q.pop();

        for (auto mv : moves) {
            ll xx = x+mv.ff, yy = y+mv.ss;
            if (check(xx, yy, timer)) 
                dis[xx][yy] = timer, q.push({{xx, yy},timer});
        }
    }
}

bool a_escape() {
    queue<pair<pii,ll>> q;
    q.push({start_a,0});
    parent[start_a] = {-1,-1};

    while (!q.empty()) {
        ll x = q.front().ff.ff, y = q.front().ff.ss, timer = q.front().ss;
        timer++, q.pop();

        for (auto mv : moves) {
            ll xx = x+mv.ff, yy = y+mv.ss;
            if (reachable(xx,yy,timer)) {
                parent[{xx,yy}] = {x,y}, end_a = {xx,yy};
                return true;
            }

            if (check(xx, yy, timer)) 
                parent[{xx,yy}] = {x,y}, dis[xx][yy] = timer, q.push({{xx,yy} ,timer});
        }
    }

    return false;
}

void display_path () {
    pii tmp = end_a, tmp1 = parent[end_a], end = {-1,-1};
    string ans;

    while (tmp1 != end) {
        if ((tmp.ss - tmp1.ss) == 1  && (tmp.ff - tmp1.ff) == 0) ans.pb('R');
        if ((tmp.ss - tmp1.ss) == -1 && (tmp.ff - tmp1.ff) == 0) ans.pb('L');
        if ((tmp.ss - tmp1.ss) == 0  && (tmp.ff - tmp1.ff) == 1) ans.pb('D');
        if ((tmp.ss - tmp1.ss) == 0  && (tmp.ff - tmp1.ff) == -1) ans.pb('U');
        tmp = parent[tmp], tmp1 = parent[tmp];
    }
    reverse(all(ans));
    cout << ans.size() << "\n" << ans;
}

void solve() {
    char c;
    cin >> n >> m;
    dis = vector<vi> (n,vi(m,inf));
    
    loop (i,0,n-1) 
        loop (j,0,m-1) {
            cin >> c;
            if (c == 'A') start_a = {i,j},dis[i][j] = 0;
            if (c == 'M') monster.pb({i,j}),dis[i][j] = 0;
            if (c == '#') dis[i][j] = 0;
        }

    if (start_a.ff == 0 || start_a.ss == 0 || start_a.ff == n-1 || start_a.ss == m-1) {
        cout << "YES\n0";
        return;
    }
    
    monster_dis();

    if (!a_escape()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    display_path();
    
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t=1;
    while(t--){
     solve();
    }
  return 0;
}