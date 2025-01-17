#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 998244353;

mt19937 rng;

bool isprime(ll num) {
    if(num <= 1) return 0;
    if(num == 2 || num == 3) return 1;
    if(num % 2 == 0 || num % 3 == 0) return 0;
    for(int i = 5; i <= sqrt(num); i++) {
        if(num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

ll gen_prime(ll l, ll r) { //generates a prime number [l,r]
    while(1) {
        ll num = (rng() % (r - l + 1)) + l;
        if(isprime(num)) return num;
    }
}

ll M1, M2, B1, B2;
struct stringhash {
    vector<ll> h1, h2;
    vector<ll> p1, p2;
    int n;

    stringhash(string s) {
        this->n = s.size();
        p1.push_back(1);
        for(int i = 0 ; i < n; i++) {
            p1.push_back(p1.back() * B1 % M1);
        }
        p2.push_back(1);
        for(int i = 0 ; i < n; i++) {
            p2.push_back(p2.back() * B2 % M2);
        }
        h1.push_back(0);
        for(int i = 0; i < n; i++) {
            h1.push_back((h1[i] * B1 + s[i]) % M1);
        }
        h2.push_back(0);
        for(int i = 0; i < n; i++) {
            h2.push_back((h2[i] * B2 + s[i]) % M2);
        }
    }

    ll get_hash(int l, int r) { //[l,r) because that's the cool, Andwerp way
        ll num1 = (h1[r] - h1[l] * p1[r-l] % M1 + M1) % M1;
        ll num2 = (h2[r] - h2[l] * p2[r-l] % M2 + M2) % M2;
        return num1 + num2 * M1;
    }

};

void buildsh() {
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    M1 = gen_prime(900000000,1000000000);
    B1 = gen_prime(9000,10000);
    M2 = gen_prime(900000000,1000000000);
    B2 = gen_prime(9000,10000);
}


void solve() {
    string s; cin >> s;
    int n = s.size();
    int start = -1;

    vector<int> nextnota(n+1,n);

    stringhash sh(s);

    for(int i = 0; i < n; i++) {
        if(s[i] != 'a') {
            start = i;
            break;
        }
    }
    if(start == -1) {
        cout << n - 1 << '\n';
        return;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'a') {
            nextnota[i] = nextnota[i+1];
        } else {
            nextnota[i] = i;
        }
    }


    ll res = 0;
    for(int size = 1; size + start <= n; size++) {
        ll key = sh.get_hash(start, start + size);
        ll minbetween = INT_MAX;
        ll minbefore = start;
        ll prev = -9999999;
        bool ok = 1;
        int cnt = 0;
        for(int j = start; j < n;) {
            if(j + size <= n && sh.get_hash(j,j+size) == key) {
                minbetween = min(minbetween, j - prev);
                j += size;
                prev = j;
                cnt++;
                j = nextnota[j];
            } else {
                ok = 0;
                break;
            }
        }
        ll minafter = n - prev;
        if(ok && s[start + size - 1] != 'a') {
            // cout << "size : " << size << " str : " << s.substr(start, size) << " before: " << minbefore << " between : " << minbetween << " after : " << minafter << " cnt : " << cnt << '\n';
            if(cnt == 1) {
                res += (minbefore + 1) * (minafter + 1);
            } else {
                for(ll p = 0; p <= minbefore; p++) {
                    res += max(0LL, min(minbetween - p, minafter) + 1);
                }
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    buildsh();

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}