#include <bits/stdc++.h>

typedef long long ll;
const ll mod = 19491001;

ll N, K;
ll a[1100000];

ll QuickPower(ll ttt, ll k) {
    ll result = 1, base = ttt;
    while (k) {
        if (k & 1)
            result = (result * base) % mod;
        base = base * base % mod;
        k >>= 1;
    }
    return result;
}

char ch[1100000];
ll answer, inv;

int main() {
    scanf("%s%lld", ch + 1, &K);
    int len = strlen(ch + 1);
    for (int i = 1; i <= len; ++ i) {
        N = (N * 10 % mod + ch[i] - '0') % mod;
    }
    inv = QuickPower(K, mod - 2);
    for (int i = 1; i <= K; ++ i) {
        scanf("%lld", &a[i]);
        answer = (answer + a[i] * inv % mod) % mod;
    }
    a[0] = a[K];
    for (int i = 1; i <= K; ++ i) {
        answer = (answer + a[i] * (N - 1) % mod * inv % mod) % mod;
        answer = (answer + (N - 1) * inv % mod * inv % mod * ((a[i] + a[i - 1]) % mod) % mod) % mod;
    }
    printf("%lld\n", answer);
    return 0;
}