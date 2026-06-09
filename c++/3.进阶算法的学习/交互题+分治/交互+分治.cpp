#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int solve(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    int ml = solve(l, mid);
    int mr = solve(mid + 1, r);
    
    int f_ml_mr = query(ml, mr);
    int f_inner;
    if (ml + 1 <= mr - 1) {
        f_inner = query(ml + 1, mr);
    } else {
        f_inner = 0;
    }
    
    int diff = f_ml_mr - f_inner;
    if (diff == mr - ml) {
        return ml;
    } else {
        return mr;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = solve(1, n);
        cout << "! " << ans << "\n";
        cout.flush();
    }
    return 0;
}
