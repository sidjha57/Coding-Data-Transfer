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

struct Node {
    int data;
    Node* next;
} ;

Node* circular_linked_list(Node *p, int A[], int n)
{
    p = new Node();

    p->data = A[0];
    p->next = NULL;
    Node *last = NULL;
    last = new Node();
    last = p;


    Node *temp = NULL;
    for(int i = 1; i < n; i++)
    {
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    last->next = p;

    return p;
}

void Display_circular_linked_list(Node*p)
{
    Node* first = p;
    cout<<p->data<<" ";
    p = p->next;
    while(p != first)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    
}

// Displaying circular linked list using recursion

void dis_cir_rec(Node *p, Node *head)
{
    static int flag = 0;

    if((p != head) || flag == 0)
    {
        flag = 1;
        cout<<p->data<<" ";
        dis_cir_rec(p->next, head);
    }
    flag = 0;
}

// Inserting a node in circular linked list

Node* insert_in_circular_list(Node*p, int x, int pos)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next =NULL;

    int counter = 1;
    Node* head = p;
    if(pos == 0)
    {
        p = p->next;
        while(p->next != head)
        {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
        head = temp;

        return head;
    }

    else 
    {
        while(counter < pos)
        {
            p = p->next;
            counter++ ;

        }

        temp->next = p->next;
        p->next = temp;
        
    }

    return head;

}

// Deleting element from linked list

Node* delete_from_circular_linked_list(Node*p, int ind)
{
    Node* front = p;
    Node* back = NULL;

    int counter = 0;

    if(ind == 0)
    {
        back = front;
        front = front->next;
        while(front != p)
        {
            back = front;
            front = front->next;
        }

        back->next = front->next;
        delete(front);

        return back;
    }

    else
    {
        while(counter < ind)
        {
            back = front;
            front = front->next;
            counter ++;
            
        }

        back->next = front->next;

        delete(front);

        return p;

        
    }

}

int main () {
    int a[2] = {1,2};
    Node *p;
    p = circular_linked_list (p,a,2);
    p = delete_from_circular_linked_list (p,0);
    Display_circular_linked_list (p);
}