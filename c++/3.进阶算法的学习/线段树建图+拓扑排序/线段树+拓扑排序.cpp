#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define req(i, r, l) for(int i = (r); i >= (l); i--)
#define testcase int T; cin >> T; while(T--) solve();
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define fi first
#define se second
#define all(x) begin(x), end(x)
using namespace std;
constexpr int N = 2e5 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f, INF = 0x7f7f7f7f, mod = 998244353;
constexpr double eps = 1e-9;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int n, tot, rt1, rt2, m;
struct B {int p, l, r;}c[N];
vector<int> e[M];
void add(int u, int v) {e[u].push_back(v);}
struct SEGT {
    int ls[M], rs[M];
    int nw() {++tot; ls[tot] = rs[tot] = 0; return tot;}
    void build(int &id, int l, int r, int op) {
        if(!id) id = nw();
        if(l == r) return;
        int mid = (l + r) / 2; build(ls[id], l, mid, op); build(rs[id], mid + 1, r, op);
        if(op == 0) add(id, ls[id]), add(id, rs[id]);
        else add(ls[id], id), add(rs[id], id);
    }
    void add0(int id, int l, int r, int x, int y, int u, int op) { 
        if(x <= l && r <= y) {
            if(op == 0) add(u, id);
            else add(id, u);
            return;
        }
        int mid = (l + r) / 2;
        if(x <= mid) add0(ls[id], l, mid, x, y, u, op);
        if(y > mid) add0(rs[id], mid + 1, r, x, y, u, op);
    }
}tt;
void init() {
    tot = n;
    tt.build(rt1, 1, m, 0); tt.build(rt2, 1, m, 1);
    rep(i, 1, n) {
        auto [p, l, r] = c[i];
        assert(p);
        tt.add0(rt1, 1, m, p, p, i, 1);
        tt.add0(rt2, 1, m, p, p, i, 0);
        tt.add0(rt1, 1, m, max(1, p - l), min(m, p + r), i, 0);
    }
}

struct Tarjan {
    int dfn[M], low[M], dfc, cnt, bel[M], in[M];
    vi stk;
    bool ok[M], cov[M], instk[M];
    vector<int> g[M];
    void tarjan(int x) {
        low[x] = dfn[x] = ++dfc, instk[x] = 1;
        stk.push_back(x);
        for(int ed : e[x]) {
            if(!dfn[ed]) tarjan(ed), low[x] = min(low[x], low[ed]);
            else if(instk[ed]) low[x] = min(low[x], dfn[ed]);
        }
        if(low[x] == dfn[x]) {
            ++cnt;
            int v; 
            do {
                v = stk.back(); stk.pop_back();
                instk[v] = 0, bel[v] = cnt;
                if(v <= n) ok[cnt] = 1;
            }while(v != x);
        }
    }
    int calc() {
        rep(i, 1, tot) if(!dfn[i]) tarjan(i);
        rep(i, 1, tot) for(int ed : e[i]) if(bel[i] != bel[ed]) g[bel[i]].push_back(bel[ed]), in[bel[ed]]++;
        queue<int> q;
        rep(i, 1, cnt) if(!in[i]) q.push(i);
        int ans = 0;
        while(q.size()) {
            int x = q.front(); q.pop();
            if(!cov[x] && ok[x]) ans++, cov[x] = 1;
            for(int ed : g[x]) {
                cov[ed] |= cov[x];
                if(!--in[ed]) q.push(ed);
            }    
        }
        return ans;
    }
}T;
signed main() {
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;
    rep(i, 1, n) {cin >> c[i].p >> c[i].l >> c[i].r; c[i].p++; chkmax(m, c[i].p);}
    init(); 
    cout << T.calc() << "\n";
    return 0;
}
