#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, c, d; cin >> a >> b >> c >> d;
    // ll res = 0;

    a += INT_MAX + 1LL;
    b += INT_MAX + 1LL;
    c += INT_MAX + 1LL;
    d += INT_MAX + 1LL;

    // ll add1 = (((c + 3) / 4 * 4 - (a + 2) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 0) / 2 * 2) / 2) * 2;
    // ll add2 = (((c + 2) / 4 * 4 - (a + 1) / 4 * 4) / 4) * (((d + 2) / 2 * 2 - (b + 1) / 2 * 2) / 2) * 2;
    // ll add3 = (((c + 3) / 4 * 4 - (a + 2) / 4 * 4) / 4) * (((d + 2) / 2 * 2 - (b + 1) / 2 * 2) / 2);
    // ll add4 = (((c + 2) / 4 * 4 - (a + 1) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 0) / 2 * 2) / 2);
    // ll add5 = (((c + 1) / 4 * 4 - (a + 0) / 4 * 4) / 4) * (((d + 2) / 2 * 2 - (b + 1) / 2 * 2) / 2);
    // ll add6 = (((c + 4) / 4 * 4 - (a + 3) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 0) / 2 * 2) / 2);

    ll add1 = (((c + 3) / 4 * 4 - (a + 3) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 1) / 2 * 2) / 2) * 2;
    ll add2 = (((c + 2) / 4 * 4 - (a + 2) / 4 * 4) / 4) * (((d + 0) / 2 * 2 - (b + 0) / 2 * 2) / 2) * 2;
    ll add3 = (((c + 3) / 4 * 4 - (a + 3) / 4 * 4) / 4) * (((d + 0) / 2 * 2 - (b + 0) / 2 * 2) / 2);
    ll add4 = (((c + 2) / 4 * 4 - (a + 2) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 1) / 2 * 2) / 2);
    ll add5 = (((c + 1) / 4 * 4 - (a + 1) / 4 * 4) / 4) * (((d + 0) / 2 * 2 - (b + 0) / 2 * 2) / 2);
    ll add6 = (((c + 0) / 4 * 4 - (a + 0) / 4 * 4) / 4) * (((d + 1) / 2 * 2 - (b + 1) / 2 * 2) / 2);

    // cout << "what : " << (d + 1 - ((b - 1) / 2) * 2 + 1) << '\n';

    // cout << "1 : " << add1 << '\n';
    // cout << "2 : " << add2 << '\n';
    // cout << "3 : " << add3 << '\n';
    // cout << "4 : " << add4 << '\n';
    // cout << "5 : " << add5 << '\n';
    // cout << "6 : " << add6 << '\n';

    cout << add1 + add2 + add3 + add4 + add5 + add6 << '\n';


    return 0;
}