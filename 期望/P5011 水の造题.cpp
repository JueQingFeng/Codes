#include <bits/stdc++.h>

typedef long long ll;
const ll mod = 19451001;

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

ll answer, inv;

int main() {
    scanf("%lld%lld", &N, &K);
    for (int i = 1; i <= K; ++ i)
        scanf("%lld", &a[i]);
    inv = QuickPower(K, mod - 2);
    
}