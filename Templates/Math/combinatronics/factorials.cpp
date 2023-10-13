const int N = 1e6;
ll factorials[N+1];

//finds all factorials 0-N iteratively
void factorial(int n, ll MOD = 1e9 + 7) {
    factorials[0] = 1;
    for(int i = 1; i <= n; i++) {
        factorials[i] = factorials[i-1] * i % MOD;
    }
}