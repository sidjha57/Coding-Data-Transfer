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

// bubble sort function

void bubble_sort (int a[],int n) {
    for (int i = 0; i < n; i++) 
    // Last i elements are already in place
        for (int j = 1; j <n; j++) 
            if (a[j-1] > a[j])
                swap(a[j],a[j-1]);
    
    for (int i = 0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
    
}

//insertion sort function

void insertion_sort (int a[],int n) {
    int i,j,key;
    for ( i = 1; i < n; i++) {
         key = a[i];
         j = i-1;
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
            while (j >= 0 && key < a[j]) {
                a[j+1] = a[j];
                j--;
            }
        a[j+1] = key;
    }
    for (int i = 0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
}

// selection sort function 

void selection_sort (int a[],int n) {
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n; i++) {
        // Find the minimum element in unsorted array
        int min_idx=i;
        for (int j = i+1; j < n; j++)
            if (a[min_idx] > a[j]) min_idx = j; 
        // Swap the found minimum element with the first element
        swap(a[i],a[min_idx]);
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

}


int main () {
    int a[] = {1,5,8,19,100,25,64,78,97};
    //bubble_sort(a,sizeof(a)/sizeof(a[0]));
    //insertion_sort(a,sizeof(a)/sizeof(a[0]));
    selection_sort(a,sizeof(a)/sizeof(a[0]));
}