#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;

template<typename T>
struct Tree {
    static constexpr T base = 0;
    vector<vector<pair<int,T>>> v;
    int n, size, op;
    T comb(T a, T b) { //change this when doing maximum vs minimum etc.
        return a + b;
    }
    Tree(int n = 0, T def = base) {
        this->n = n; //max number of elements
        op = 0;
        size = 1;
        while(size < n) size *= 2;
        v.assign(size * 2, {{-1, 0}});
    }
    void update(int pos, T val) { //update 0 indexed, assignment
        assert(pos < n && pos >= 0);
        int curr = pos + size;
        v[curr].push_back({op,val});
        while(curr != 1) {
            v[curr / 2].push_back({op, comb(v[curr].back().second, v[curr ^ 1].back().second)});
            curr /= 2;
        }
        op++;
    }
    bool isLeaf(int idx) {
        return idx >= size;
    }
    T at(int idx) {
        assert(idx >= 0 && idx < n);
        return v[idx + size];
    }
    T query(int l, int r, int time) {//queries in range [l,r)
        return _query(1,0,size,l,r,time);
    }
    T _query(int idx, int currl, int currr, int &targetl, int &targetr, int &time) {
        if(currr <= targetl || currl >= targetr) return base;
        if(currl >= targetl && currr <= targetr) {
            int l = 0, r = v[idx].size() - 1;
            while(l != r) {
                int m = (l + r + 1) / 2;
                if(v[idx][m].first <= time) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            return v[idx][l].second;
        }
        
        int mid = (currl + currr) / 2;
        return comb(
            _query(idx * 2, currl, mid, targetl, targetr, time),
            _query(idx * 2 + 1, mid, currr, targetl, targetr, time)
        );
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    Tree<ll> tree(n);

    for(int i = 0; i < n; i++) {
        tree.update(v[i].second, v[i].first);
    }

    ll ans = 0;
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        ll l, r, x; cin >> l >> r >> x;
        l ^= ans;
        r ^= ans; 
        x ^= ans;

        int lo = -1, hi = n - 1;
        while(lo != hi) {
            int m = (lo + hi + 1) / 2;
            if(v[m].first <= x) {
                lo = m;
            } else {
                hi = m - 1;
            }
        }
        ans = tree.query(l-1,r,lo);
        cout << ans << '\n';
    }

    return 0;
}