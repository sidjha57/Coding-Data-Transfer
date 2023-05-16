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
#define mod                      998244353
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
const int MOD =  998244353;
const long long MOD2 = static_cast <long long> (MOD)*MOD;

struct Matrix {
  vector < vector <int> > mat;
  int n_rows,n_cols;

  Matrix() {}

  Matrix(int r, int c) {
      n_rows = r; n_cols = c;
      mat.resize(r,vector<int>(c));
  }

  Matrix (vector < vector<int> > values) : mat(values), n_rows(values.size()),
          n_cols(values[0].size()) {}

  static Matrix identity_matrix (int n) { 
     vector < vector <int> > values(n, vector <int> (n,0));
     for (int i=0; i<n; i++) values[i][i] = 1;
     return values;
  }

  Matrix operator* (const Matrix &other) const {
    int n = n_rows, m = n_cols;
    vector < vector <int> > result (n_rows, vector<int> (n_cols,0));
    for (int i=0; i<n; i++)
      for (int j=0; j<m; j++) {
        long long tmp = 0;
        for (int k=0; k < n_cols; k++) {
            tmp += mat[i][k] * 1ll * other.mat[k][j];
            while (tmp >= MOD2) tmp -= MOD2;
        }
        result[i][j] = tmp % MOD;
      }
    return move(Matrix(move(result)));
  } 

  Matrix operator+ (const Matrix& other) const {
      int n = n_rows, m = n_cols;
      vector<vector<int>> result (n, vector<int>(m,0));
      for (int i=0; i<n; i++) {
          long long tmp = 0;
          for (int j=0; j<m; j++) {
              tmp = mat[i][j] + other.mat[i][j];
              while (tmp >= MOD2) tmp -= MOD2;
              result[i][j] = tmp % MOD;
          }
      }
      return move(Matrix(move(result)));
  }

  inline bool is_square () const { return n_rows == n_cols;}
};

Matrix A;
bool characteristics (Matrix &a, Matrix &b,vi& c, ll n, ll m) {
   
    Matrix ans (n,1),I, powA;
    I = I.identity_matrix(n); 
    powA = I;
    loop (i,0,n-1) I.mat[i][i] = c[0];
    I = I*b;
    A = I;
    loop (i,0,m-1) {
         loop (k,0,n-1) {
             A.mat[k][0] = (A.mat[k][0] * c[i])%mod;  
         }
         ans = ans+A;
         powA = powA*a; // A = a^i
         A = powA*b;
    }

    loop (i,0,n-1) {
        if (ans.mat[i][0] == 1) return false;
    }
    return true;
}

void solve() {
    ll n,N,a; cin >> n;
    vi c(n); 
    loop (i,0,n-1) cin >> c[i];
    cin >> N;
    Matrix m(N,N),b(N,1);
     
    loop (i,0,N-1) {
        loop (j,0,N-1) {
            cin >> a;
            m.mat[i][j]= a;
        }
    }

    loop (i,0,10) {
        loop (j,0,N-1) {
            b.mat[j][0] = rand()%mod;
        }
        if (characteristics(m,b,c,N,n)) {
                cout << "NO\n";
                return;
        }
    }
    cout << "YES\n";
}

int main(int argc, char const *argv[]){
    _fast
    //fileIO();
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}