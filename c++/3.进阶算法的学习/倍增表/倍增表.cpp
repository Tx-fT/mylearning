#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 顺时针周长坐标: 底边[0,S] 右边[S,2S] 顶边[2S,3S] 左边[3S,4S]
int pos(int x, int y, int S) {
    if (y == 0) return x;
    if (x == S) return S + y;
    if (y == S) return 2 * S + (S - x);
    return 3 * S + (S - y);
}
int md(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// 求从 (px,py) 出发，顺时针方向第一个曼哈顿距离 ≥ D 的周长坐标
int next_pos(int px, int py, int S, int D) {
    if (D == 0) return pos(px, py, S) + 1;

    int u = px + py, v = px - py, L = D - 1, C = 4 * S;
    vector<pair<int,int>> iv;

    // 底边: u=v, t=u
    { int l = max({u-L, v-L, 0}), r = min({u+L, v+L, S});
      if (l <= r) iv.push_back({l, r}); }
    // 右边: u+v=2S, t=u
    { int l = max({u-L, 2*S-v-L, S}), r = min({u+L, 2*S-v+L, 2*S});
      if (l <= r) iv.push_back({l, r}); }
    // 顶边: u-v=2S, t=4S-u
    { int l = max({u-L, v+2*S-L, S}), r = min({u+L, v+2*S+L, 2*S});
      if (l <= r) iv.push_back({C-r, C-l}); }
    // 左边: u+v=0, t=4S-u
    { int l = max({u-L, -v-L, 0}), r = min({u+L, -v+L, S});
      if (l <= r) iv.push_back({C-r, C-l}); }

    if (iv.empty()) return pos(px, py, S) + 1;

    // 合并重叠区间
    sort(iv.begin(), iv.end());
    vector<pair<int,int>> mg;
    for (auto [l, r] : iv) {
        if (mg.empty() || l > mg.back().second + 1)
            mg.push_back({l, r});
        else mg.back().second = max(mg.back().second, r);
    }

    // 处理跨越 4S 边界
    if (mg.size() >= 2 && mg[0].first == 0 && mg.back().second == C - 1) {
        mg[0].first = mg.back().first - C;
        mg.pop_back();
        sort(mg.begin(), mg.end());
        vector<pair<int,int>> mg2;
        for (auto [l, r] : mg) {
            if (mg2.empty() || l > mg2.back().second + 1)
                mg2.push_back({l, r});
            else mg2.back().second = max(mg2.back().second, r);
        }
        mg = move(mg2);
    }

    // 跳过所有覆盖它的不兼容区间，找到第一个兼容位置
    int tp = pos(px, py, S);
    for (bool done = false; !done; ) {
        done = true;
        for (auto [l, r] : mg) {
            int L = l < 0 ? l + C : l;
            if (L <= tp && tp <= r) {
                tp = r + 1; done = false;
                if (tp >= C) tp -= C;
            }
        }
    }
    return tp;
}

struct Pt { int x, y, t; };

// 检查能否选出 n 个点，两两曼哈顿距离 ≥ D
bool check(int S, int n, const vector<Pt>& pts, int D) {
    int m = pts.size();
    if (n <= 1) return true;

    long long C = 4LL * S;
    vector<long long> pos(2 * m);
    for (int i = 0; i < m; i++)
        pos[i] = pts[i].t, pos[i + m] = pts[i].t + C;

    // 算 next[i]：二分查找第一个周长坐标 ≥ 兼容起点 的点
    vector<int> nxt(2 * m, 2 * m);
    for (int i = 0; i < m; i++) {
        int tgt = next_pos(pts[i].x, pts[i].y, S, D);
        while (tgt <= pts[i].t) tgt += (int)C;

        int lo = i + 1, hi = i + m;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pos[mid] >= tgt) hi = mid;
            else lo = mid + 1;
        }
        if (lo < i + m) {
            nxt[i] = lo;
            if (lo + m < 2 * m) nxt[i + m] = lo + m;
        }
    }

    // 倍增跳表 up[k][i] = 从 i 跳 2^k 步到达的点******
    const int K = 20;
    vector<vector<int>> up(K, vector<int>(2 * m + 1, 2 * m));
    for (int i = 0; i < 2 * m; i++) up[0][i] = nxt[i];
    for (int k = 1; k < K; k++)
        for (int i = 0; i <= 2 * m; i++)
            up[k][i] = up[k-1][up[k-1][i]];

    // 枚举起点，跳 n-1 次
    for (int i = 0; i < m; i++) {
        int cur = i, r = n - 1;
        for (int k = K - 1; k >= 0; k--)
            if (r & (1 << k)) {
                cur = up[k][cur];
                if (cur >= i + m) { r = -1; break; }
                r ^= (1 << k);
            }
        if (r != 0) continue;
        // 检查首尾是否也 ≥ D（环上相邻）
        if (md(pts[i].x, pts[i].y, pts[cur % m].x, pts[cur % m].y) >= D)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int S, n, m; cin >> S >> n >> m;
        vector<Pt> pts(m);
        for (int i = 0; i < m; i++) {
            cin >> pts[i].x >> pts[i].y;
            pts[i].t = pos(pts[i].x, pts[i].y, S);
        }
        sort(pts.begin(), pts.end(), [](Pt& a, Pt& b) { return a.t < b.t; });

        int lo = 0, hi = 2 * S;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(S, n, pts, mid)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}
