// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double ld;
// using namespace std;
// const ll MOD = 1e9 + 7;

// template <typename T, std::size_t N>
// std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
//     os << "[";
//     for (std::size_t i = 0; i < N; ++i) {
//         os << arr[i];
//         if (i < N - 1) {
//             os << ", ";
//         }
//     }
//     os << "]";
//     return os;
// }

// template<typename T>
// std::ostream& operator<<(std::ostream& os, const vector<T> v) {
//     for(auto x : v) os << x << " ";
//     return os;
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll n, M, k; cin >> n >> M >> k;

//     map<ll,int> cnts;
//     vector<ll> a(n);

//     for(int i = 0; i < n; i++) {
//         cin >> a[i];
//         cnts[a[i]]++;
//     }
//     vector<array<ll,2>> b(cnts.size()); // {value, cnt strictly above value}
//     ll c = 0;
//     int i = cnts.size() - 1;
//     ll cutoff = -1; // if a[i] has a value >= cutoff, then we consider the first m + 1 elements. 
//     for(auto it = cnts.rbegin(); it != cnts.rend(); it++, i--) {
//         b[i][0] = it->first;
//         b[i][1] = c;
//         c += it->second;
//         if(c >= 0) {
//             cutoff = max(cutoff, it->first);
//         }
//     }

//     c = 0;
//     for(auto it = cnts.begin(); it != cnts.end(); it++) {
//         c += it->second;
//         it->second = c;
//     }

//     ll totalv = accumulate(a.begin(), a.end(), 0LL);
//     ll left = k - totalv;

//     vector<ll> p(n + 1);
//     vector<ll> acopy = a;
//     sort(acopy.begin(), acopy.end());
//     for(int i = 1; i <= n; i++) {
//         p[i] = acopy[i-1] + p[i-1];
//     }

//     for(int i = 0; i < n; i++) {

//         ll l = 0, r = left + 1;
//         int plo = n - M - (a[i] >= cutoff ? 1 : 0);

//         while(l != r) {
//             ll m = (l + r) / 2;

            



//         }

//         if(l == left + 1) {
//             cout << "-1\n";
//         } else {
//             cout << l << '\n';
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    map<ll,int> cnts, cumcnts;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnts[a[i]]++;
    }

    ll cutoff = LLONG_MAX;
    ll cnt = 0;
    for(map<ll,int>::reverse_iterator it = cnts.rbegin(); it != cnts.rend(); it++) {
        cnt += it->second;
        it->second = cnt;
        if(cnt <= m) {
            cutoff = it->first;
        }
    }

    vector<ll> p(n + 1);
    vector<ll> s = a;
    sort(s.begin(), s.end());

    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + s[i-1];
    }

    cout << "cutoff : " << cutoff << '\n';

    ll votesrem = k - accumulate(a.begin(), a.end(), 0LL);

    for(int i = 0; i < 1; i++) {
        ll l = 0, r = votesrem + 1;
        while(l != r) {
            ll m = (l + r) / 2;
            ll newscore = a[i] + m;
            ll newleft = votesrem - m;
            ll greatercnt = 0;
            if(cumcnts.upper_bound(newscore) != cumcnts.end()) {
                greatercnt = cumcnts.upper_bound(newscore)->second;
            }
            ll neededplength = m - greatercnt;
            ll intl = -1, intr = -1;
            if(a[i] < cutoff) {
                intl = n - m;
                intr = intl + neededplength;
            } else {
                intl = n - m - 1;
                intr = intl + neededplength + 1;
            }
            intl = max(0LL, intl);
            ll needed = p[intr] - p[intl];
            if(a[i] >= cutoff) {
                needed -= a[i];
            }


            ll votesneeded = (m - greatercnt) - needed;
            cout << "m : " << m << " votesneeded : " << votesneeded << '\n';

            if(needed > votesneeded) {
                r = m;
            } else {
                l = m + 1;
            }

        }
        if(l == votesrem + 1) {
            cout << "-1";
        } else {
            cout << l;
        }
        cout << " ";
    }

    cout << '\n';

    return 0;
}