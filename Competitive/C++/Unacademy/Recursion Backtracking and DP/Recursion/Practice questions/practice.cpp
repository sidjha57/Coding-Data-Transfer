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

void permutations(string s, string osf, int i,int n) {
    if (i == n) {
        cout << "\"" << osf << "\"\n";
        return;
    }
    permutations(s,osf,i+1,n);
    permutations(s,osf + s[i],i+1,n);
    
}
void printBinary (string osf,int i , int n) {
    if (i==n) {
        cout << "\"" << osf << "\"\n";
        return;
    }
     printBinary (osf + "0",i+1,n);

    if (osf[i-1] == '\0' || osf[i-1] == '0') 
        printBinary (osf + "1",i+1,n);
}

void balancedParanthesis (string osf,int i,int j, int n) {
    if (i == 0 && j == 0) {
        balancedParanthesis (osf + "(",i+1,j,n);
    }
    if (i== n && j == n) {
        cout << "\"" << osf << "\"\n";
        return;
    }  
    if (i < n) {
        balancedParanthesis(osf + ")",i,j+1,n);
        balancedParanthesis(osf + "(",i+1,j,n);
    }  
    if (i > j ) {
        balancedParanthesis(osf + "(",i+1,j,n);
    }  
}

map<char,string> comb;
vector<string> ans;
void combinations (string &digits, string osf, int n , int i) {
    if (i == n) {
        ans.emplace_back(osf);
        return;
    }
    for (auto x : comb[digits[i]]) {
        combinations (digits,osf+x,n,i+1);
    }
}
vector<string> letterCombinations(string digits) {
        
    if (digits.size() == 0) return ans;
    comb['2'] = "abc";
    comb['3'] = "def";
    comb['4'] = "ghi";
    comb['5'] = "jkl";
    comb['6'] = "mno";
    comb['7'] = "pqrs";
    comb['8'] = "tuv";
    comb['9'] = "wxyz";
    combinations(digits,"",digits.size(),0);
    return ans;
}

// print numbers in lexicographical order upto n
    vector<int> result;
    void print_lexico (int num,int n) {
    if (num == n) {
        result.emplace_back(num);
        return;
    }
    if (num > n) return;
    if (num != 0) result.emplace_back(num);
    for (int i = (num == 0) ? 1 : 0; i <= 9; i++) {
        print_lexico(num*10+i,n);
    }
    
    }

int main(int argc, char const *argv[]){
    _fast
    // balancedParanthesis("",0,0,3);
    // letterCombinations("23");
    print_lexico(1,13);
  return 0;
}