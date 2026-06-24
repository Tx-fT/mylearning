#include<bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r, v;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Interval> cons(m);
    for (int i = 0; i < m; i++) {
        cin >> cons[i].l >> cons[i].r >> cons[i].v;
    }

    const int INF = 2e9;
    vector<int> a(n + 1, INF);

    // DSU: nxt[i] = next unset position (>= i)
    vector<int> nxt(n + 2);
    iota(nxt.begin(), nxt.end(), 0);//全部指向自己

    function<int(int)> find = [&](int x) -> int {
        return nxt[x] == x ? x : nxt[x] = find(nxt[x]);
    };//函数

    // Sort by v ascending: each position gets the MINIMUM v among its intervals
    sort(cons.begin(), cons.end(),
         [](const Interval& x, const Interval& y) { return x.v < y.v; });

    for (auto [l, r, v] : cons) {
        for (int i = find(l); i <= r; i = find(i)) {//并查集标记用法
            a[i] = v;
            nxt[i] = i + 1;
        }
    }

    // Positions not covered by any constraint: set to 1
    for (int i = 1; i <= n; i++) {
        if (a[i] == INF) a[i] = 1;
    }

    // Group positions by value for verification
    map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    // Verify: each constraint must have at least one position == v in [l, r]
    bool ok = true;
    for (auto [l, r, v] : cons) {
        auto it = pos.find(v);
        if (it == pos.end()) { ok = false; break; }
        auto& vec = it->second;
        auto lb = lower_bound(vec.begin(), vec.end(), l);//二分厉害
        if (lb == vec.end() || *lb > r) { ok = false; break; }
    }

    if (!ok) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}