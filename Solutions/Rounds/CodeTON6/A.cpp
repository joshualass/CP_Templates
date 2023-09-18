#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if(k > n || k - 1 > x || (k == 0 && x == 0)) {
        cout << "-1\n";
        return;
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            sum += i;
        } else {
            // sum += x - 1;
            if(x > k) {
                sum += x;
            } else {
                sum += k -1;
            }
        }
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casi; cin >> casi;
    while(casi-->0) solve();

    return 0;
}