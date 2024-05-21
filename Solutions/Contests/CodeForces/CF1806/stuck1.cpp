#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;

const int maxn = 100000;
const int sqrtn = sqrt(maxn);

ll w[maxn + 1];
ll parents[maxn + 1];
int nodedepth[maxn + 1];
int ids[maxn + 1];
vector<ll> c[maxn + 1];
vector<int> atdepth[maxn + 1];
vector<vector<ll>> precalc[maxn + 1];

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T> v) {
    for(auto x : v) os << x << " ";
    return os;
}

void assign_depths(int i, int d) {
    // cout << "i : " << i << " d : " << d << endl;
    // nodedepth[i] = d;
    // atdepth[d].push_back(i);
    // cout << "c[i] : " << c[i] << endl;
    // for(int child : c[i]) {
    //     assign_depths(child,d+1);
    // }
    queue<pair<int,int>> q;
    q.push({i,d});
    while(q.size()) {
        pair<int,int> p = q.front();
        q.pop();
        nodedepth[p.first] = p.second;
        atdepth[p.second].push_back(p.first);
        for(int child : c[p.first]) {
            q.push({child,p.second + 1});
        }
    }
}

ll query(int a, int b) {
    stack<pair<int,int>> s2;
    ll res = 0;
    // for(int i = 0; i < 5000000; i++) {
    //     i++;
    //     i--;
    //     i <<= 1;
    //     i >>= 1;
    // }

    while(a != 1) {
        if(a % 1000 == 1) {
            cout << "a : " << a << " b : " << b << endl;
        }
        a = parents[a], b = parents[b];
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i <= maxn; i++) {
        precalc[i].clear();
        w[i] = -1;
        parents[i] = -1;
        c[i].clear();
        atdepth[i].clear();
        nodedepth[i] = -1;
        ids[i] = -1;
    }
    
    // int n, q; cin >> n >> q;
    int n = 100000, q = 1;
    for(int i = 1; i <= n; i++) {
        // cin >> w[i];
        w[i] = i;
    }

    for(int i = 2; i <= n; i++) {
        // int num; cin >> num;
        int num = i - 1;
        c[num].push_back(i);
        parents[i] = num;
    }

    assign_depths(1,0);

    for(int i = 0; i < q; i++) {
        // int a, b; cin >> a >> b;
        int a = 100000, b = 100000;
        cout << query(a,b) << '\n';
    }

    cout << "ENDED" << endl;

    return 0;
}