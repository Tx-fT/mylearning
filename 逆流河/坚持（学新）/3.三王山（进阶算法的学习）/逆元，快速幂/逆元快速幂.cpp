#include <iostream>
#include <cstring>
#define mod 1000000007
using namespace std;

int n, s;
int mx = 0;
int b[500005];
long long ans = 0;

long long pow_mod(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
long long inv(long long x) {
    return pow_mod(x, mod - 2);
}
long long solve(int cnt) {
    long long sum = 1;
    for (int i = 1; i <= mx; i++) {
        if (b[i] <= 0) continue;
        for (int j = 1; j <= b[i]; j++, cnt--) {
            sum = sum * cnt % mod;
            sum = sum * inv(j) % mod;
        }
        if (cnt == 0) break;
    }
    return sum;
}

int main() {
    memset(b, 0, sizeof(b));
    cin >> n;
    s = n - 2;

    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t > mx) mx = t;
        b[t]++;
    }

    for (int i = 1; i * i <= s; i++) {
        if (s % i != 0) continue;
        int j = s / i;
        if (b[i] && b[j]) {
            int ch = (i == j) ? 1 : 2;
            b[i]--;
            if (i != j) b[j]--;
            ans = (ans + ch * solve(s)) % mod;
            b[i]++;
            if (i != j) b[j]++;
        }
    }
    cout << ans << endl;
    return 0;
}
