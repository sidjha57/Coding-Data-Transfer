/*Merge sort and its applications */

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

/* Find the max among all elements */

int find_max (vi arr,int l,int r) {
    if (l == r) return arr[l];
    int mid = mid(l,r);
    int left_max = find_max(arr,l,mid);
    int right_max = find_max(arr,mid+1,r);
    return max(left_max,right_max);
}

/* merge sort algorithm */
vi arr {2,5,7,9,10,-4,17,-2,87,56,28,90};
void merge (int i,int n,int j, int m) {
    int c[m-i+1],l=i,k=0;
    while (i <= n && j <= m) {
        if (arr[i] < arr[j]) c[k++] = arr[i++];
        else {
            // to count number of inversions ans += n-i+1;
            c[k++] = arr[j++];
        } 
    }
    while (i <= n) c[k++] = arr[i++];
    while (j <= m) c[k++] = arr[j++]; 
    

    loop (j,0,k-1) arr[l++] = c[j];
}

void merge_sort (int l, int r) {
    /*recursion version*/
    // if (l == r) return;
    // int mid = mid(l,r);
    // merge_sort (l,mid); // divide
    // merge_sort (mid+1,r); // divide
    // merge(l,mid,mid+1,r); // combine

    /*iterative version*/
    int n = arr.size();
    for (int sz=2; sz < n; sz *= 2) 
        for (int i=0; i < n ; i+= sz) 
            merge (i,(i+sz/2-1),(i+sz/2),(i+sz-1));

     
}

int main(int argc, char const *argv[]){
    
//   vi arr {1,9,2,7,30,42,6,5,9};
//   cout << find_max(arr,0,arr.size()-1);
merge_sort (0,arr.size()-1);
loop (i,0,arr.size()-1) cout << arr[i] <<" ";
  return 0;
}