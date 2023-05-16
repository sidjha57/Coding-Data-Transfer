#include <bits/stdc++.h>
#define ll long long
using namespace std;

class heap {
    private:
    ll size,root;
    vector<ll> a;

    public:

    heap() {
        size=0,root=1;
        a.resize(1);    
    }

    void push (ll val) {
        ll node = ++size;
        a.push_back(val);
        while (node != root) {
            if (a[node] < a[parent(node)]) break;
            swap(a[node],a[parent(node)]);
            node = parent(node);
        }
    } 
    
    void remove (ll val) {
        for (ll i=1; i<=size; i++) {
            if (a[i] == val) {
                swap (a[i],a[size--]);
                heapify(a[i]);
                break;
            }
        }
    }
    ll top () {
         if(isEmpty()){
            cout<<"Empty Heap :(\n";
            return -1;
        }
        return a[root];
    } 

    void pop () {
         if(isEmpty()){
            cout<<"Empty Heap :(\n";
            return;
        }
        swap(a[root],a[size--]);
        heapify(root);
        
    }

    void heapify (ll node) {
        ll largest = node;
        if (left_child(node) <=size && a[largest] < a[left_child(node)]) largest = left_child(node);
        if (right_child(node) <= size && a[largest] < a[right_child(node)]) largest = right_child(node);

        if (largest != node) {
            swap (a[largest],a[node]);
            heapify(largest);
        }
        return;
    }
    
    bool isEmpty () {
        if (size == 0) return true;
        return false;
    }
    
    ll getsize () {
        return size;
    }

    ll parent (ll node) {
        return node/2;
    }

    ll left_child (ll node) {
         return node*2;
    }

    ll right_child (ll node) {
        return node*2+1;
    }

    void print () {
        for (ll i = 1; i <= size; i++) 
            cout << a[i] << " ";
        cout<<"\n";
    }

};

int main () {
    heap hp;
    hp.push(10); 
    hp.push(5);
    hp.push(7);
    hp.push(0);
    hp.push(-3);
    hp.push(2);
    hp.print();
    cout << hp.top() << "\n";
    hp.remove(7);
    cout << hp.getsize() << "\n";
    hp.print();
}