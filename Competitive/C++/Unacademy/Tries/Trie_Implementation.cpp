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

class node {
public:
  char data;
  bool isTerminal;
  ump <char,node*> children;

  node (char ch) {
    this->data = ch;
    this->isTerminal = false;
  }
};

class Trie {
  public:
  node *root;

  Trie () {
    root = new node ('\0'); // root node is null
  }

  void insert (string &str) {
    node *temp = this->root;
    loop (i,0, str.size()-1) {
      char ch = str[i];
      // if the character has the same child then iterate further or create a new node
      if (temp->children.count(ch)) { 
        temp = temp->children[ch];
      } else {
        node *n = new node (ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->isTerminal = true; // for last character save it as terminal of the word
    return;
  }

  bool search (string &str) {
    node *temp = this->root;
    loop (i,0, str.size()-1) {
      char ch = str[i];
      // if the character is present iterate upto the last if in between it does not have child same as string then the word is not present
      if (temp->children.count(ch)) 
        temp = temp->children[ch];
      else 
        return false; 
    }
    return temp->isTerminal == true; // to check whether the word is completely present or its a substring
  }

  void HelperDFS (node *root, string& str, string osf) {
    if (root == NULL) return; // if it has no children 
    if (root->isTerminal) // whenever encountered a string print it
      cout << str+osf << "\n"; // print should be done during upward filling of stack
    
    for (auto ch: root->children) // visits all its children
      HelperDFS (ch.ss, str, osf + ch.ff);
    
  }

  // prints all the string of same prefix 
  void printPrefix (string& str) {
    node *temp = this->root;
    loop (i,0, str.size()-1) {
      char ch = str[i];
      if (temp->children.count(ch)) 
        temp = temp->children[ch];
      else {
        cout << "Query string is not present as prefix\n";
        return;
      }
    }
    // reaches the string end if it is present as prefix and now prints all strings with that prefix
      HelperDFS(temp, str, "");
  }
};
int main(int argc, char const *argv[]){
    _fast
        std::string str;
    int t;
    std::cin>>t;
    Trie tr;
    while(t--) {
        std::cin>>str;
        tr.insert(str);
    }
    int q;
    std::cin>>q;
    while(q--) {
        std::cin>>str;
        std::cout<<((tr.search(str) == true) ? "Yes" : "No")<<"\n";
    }
    int prefix;
    std::cin>>prefix;
    while(prefix--) {
        std::cin>>str;
        std::cout<<"prefixes are: \n";
        tr.printPrefix(str);
    }

  return 0;
}