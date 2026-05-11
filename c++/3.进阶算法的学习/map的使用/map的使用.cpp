#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
signed main() {
    long long n, m, k;
    cin >> n >> m >> k;
    unordered_map<long long, long long> cnt; // key为冰山体积，value为该体积的冰山数量
    for (long long i = 0; i < n; ++i) {
        long long v;
        cin >> v;
        cnt[v]++;
    }
    while (m--) {
        long long x, y;
        cin >> x >> y;
        unordered_map<long long, long long> newcnt; // 存储处理后的冰山状态
        for (auto& [u, v] : cnt) {//map遍历可用元组或auto& i然后i.first/i.second:c11
        	long long t = u + x;
            if (t <= 0) {
                continue; 
            }
            if (t <= k) {
                newcnt[t] += v; 
            } 
            else {
                newcnt[k] += v;
                newcnt[k] %= MOD;
                newcnt[1] += (v * ((t - k) % MOD)) % MOD;
            }
        }
        if (y > 0) {
            newcnt[y]++;
        }
        cnt = newcnt;
        long long sum = 0;
        for (auto& [u, v] : newcnt) {
            sum = (sum + (u % MOD) * (v % MOD) % MOD) % MOD; 
        }
        cout << sum << '\n';
    }
    return 0;
}
