#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	ll a = 0, b = 1;
	for(int i = 0; i < 50; i++) {
		cout << a << " ";
		ll c = a + b;
		a = b;
		b = c;
	}

    return 0;
}