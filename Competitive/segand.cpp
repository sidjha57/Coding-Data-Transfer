#include <bits/stdc++.h>

using namespace std;

struct segtree {
 
    vector<int> seg;
    int size;
 
    void init(int n) {
        size = 1;
        while (n > size) size *= 2;
        seg.assign(2*size , 134217727);
    }
 
    void build (vector<int>& a,int x, int lx, int rx) {
        if ((rx-lx) == 1) {
            if (lx < a.size()) {
                seg[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build (a, 2 * x + 1, lx, m);
        build (a, 2 * x + 2, m, rx);
        seg[x] = (seg[2* x + 1] & seg[2* x + 2]);
    }
    
    void build (vector<int>& a) {
        build(a,0,0,size);
    }
    
    // l to r-1 
    int sum (int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 134217727;
        if (lx >= l && rx <= r) return seg[x];
        
        int m = (lx+rx)/2;
        int s1 = sum (l, r, 2 * x + 1, lx, m);
        int s2 = sum (l, r, 2 * x + 2, m, rx);
        return (s1&s2);
    }
 
    int sum (int l ,int r) {
        return sum (l, r, 0, 0, size);
    }
};

vector<int> solve (vector<int> A, vector<vector<int>> B) {
    int n = A.size();
    segtree seg;
    seg.init(n);
    seg.build(A);
    vector<int> ans(B.size());
    for (int i=0; i<B.size(); i++) {
        int l = B[i][0], r = B[i][1], l1 = B[i][2], r1 = B[i][3];
        int x1 = seg.sum(l-1,r), x2 = seg.sum(l1-1, r1);
        ans[i] = x1 ^ x2;
    }
    return ans;
}

int main () {
    
    

    vector<int> A {8, 6, 5, 9, 7, 7, 9, 3, 8};
    vector<vector<int>> B {
        {3,5,5,5}
    };

    vector<int> ans = solve(A,B);

    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    
}