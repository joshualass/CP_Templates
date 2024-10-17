#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = LLONG_MAX;

ll binexp(ll base, ll power) {
    ll ans = 1;
    while(power != 0) {
        if(power & 1) {
            ans = ans*base%MOD;
        }
        base = base*base%MOD;
        power >>= 1;
    }
    return ans;
}

signed main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << gcd(1739, binexp(2,5*4*3*2*1) - 1) << '\n';

    return 0;
}