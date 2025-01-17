#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

template<class T>
constexpr T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

//Modular Division currently uses Little Fermat's Theorem, so won't work for nonprime p. 
template<int P>
struct Mint {
    int x;
    constexpr Mint(): x{} {}
    constexpr Mint(ll x): x{norm(x % getMod())} {}

    static int Mod;
    constexpr static int getMod() {
        if(P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if(x < 0) {
            x += getMod();
        }
        if(x >= getMod()) { //not sure why this is needed
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    constexpr Mint operator-() const {
        Mint res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr Mint inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr Mint &operator*=(Mint rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
        ll v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(Mint lhs, Mint rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) {
        return lhs.val() != rhs.val();
    }
};

constexpr int P = 1e9 + 7;
using Z = Mint<P>;

vector<Z> fact(1,1);
vector<Z> inv_fact(1,1);

Z choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    while(fact.size() < n + 1) {
        fact.push_back(fact.back() * fact.size());
        inv_fact.push_back(1 / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n-k];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    choose(10000,10000);
    ll n, k; cin >> n >> k;
    vector<vector<Z>> dp(k+1,vector<Z>(k * 2 + 1));
    dp[0][0] = 1;
    for(int c = 2; c <= k + 1; c++) {
        for(int i = k; i >= 0; i--) {
            for(int j = 0; j <= k * 2; j++) {
                Z fp = 1;
                for(int l = 1; i - (c - 1) * l >= 0 && j - c * l >= 0; l++) {
                    fp *= inv_fact[c] * fact[c-1];
                    dp[i][j] += dp[i - (c - 1) * l][j - c * l] * fp * fact[j] * inv_fact[j - c * l] * inv_fact[l];
                }
            }
        }
    }

    vector<Z> cm(k * 2 + 1);
    for(int i = 0; i <= k * 2; i++) {
        Z res = 1;
        for(int j = 0; j < i; j++) {
            res *= n - j;
            res /= j + 1;
        }
        cm[i] = res;
    }

    // cout << "print dp zzzZZZ\n";
    // for(int i = 0; i <= k; i++) {
    //     for(int j = 0; j <= k * 2; j++) {
    //         cout << dp[i][j] << " \n"[j == k * 2];
    //     }
    // }

    // cout << "cm zzzZZZ\n";
    // for(int i = 0; i <= k * 2; i++) {
    //     cout << cm[i] << " \n"[i == k * 2];
    // }

    for(int op = 1; op <= k; op++) {
        Z res = 0;
        for(int i = op; i >= 0; i -= 2) {
            for(int j = 0; j <= min(n, k * 2); j++) {
                res += dp[i][j] * cm[j];
            }
        }
        cout << res << " \n"[op == k];
    }

    return 0;
}