#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long modinv(long long x) {
    return modpow(x, MOD - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (n == 1) {
        cout << "0\n";
        return;
    }

    // 生成所有 n^2 个比值 (b_q, b_p) 即 b_q / b_p
    vector<pair<long long, long long>> ratios;
    ratios.reserve((size_t)n * n);
    for (int q = 0; q < n; q++)
        for (int p = 0; p < n; p++)
            ratios.emplace_back(b[q], b[p]);

    // 按分数大小排序: b_q1/b_p1 < b_q2/b_p2
    sort(ratios.begin(), ratios.end(), [](const auto& x, const auto& y) {
        return x.first * y.second < y.first * x.second;
    });

    // 生成所有查询 (a_i, a_j) for i<j
    struct Query {
        long long ai, aj;
        bool ai_gt_aj;
    };
    vector<Query> queries;
    queries.reserve((size_t)n * (n - 1) / 2);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            queries.push_back({a[i], a[j], a[i] > a[j]});

    // 按分数大小排序: a_i1/a_j1 < a_i2/a_j2
    sort(queries.begin(), queries.end(), [](const Query& x, const Query& y) {
        return x.ai * y.aj < y.ai * x.aj;
    });

    long long total = 0;
    int ptr = 0;
    int m = n * n;

    for (const auto& q : queries) {
        // 推进 ptr，跳过所有 b_q/b_p < a_i/a_j 的比值
        while (ptr < m) {
            auto& r = ratios[ptr];
            // r.first/r.second < q.ai/q.aj  <=>  r.first * q.aj < q.ai * r.second
            if (r.first * q.aj < q.ai * r.second)
                ptr++;
            else
                break;
        }

        long long cnt = ptr;
        if (q.ai_gt_aj) cnt -= n; // 排除 p=q（比值=1）的 n 个对角线
        total = (total + cnt % MOD + MOD) % MOD;
    }

    long long denom = (long long)n * (n - 1) % MOD;
    long long ans = total * modinv(denom) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
