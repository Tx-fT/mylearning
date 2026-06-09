#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string t;
    cin >> t;

    bool bad[27][27] = {};
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        bad[a - 'a' + 1][b - 'a' + 1] = true;
    }

    vector<array<int, 27>> dp(n + 1);
    vector<array<int, 27>> la(n + 1);

    int mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        int now = t[i] - 'a' + 1;
        dp[i] = dp[i + 1];
        la[i] = la[i + 1];

        for (int j = 1; j <= 26; j++) {
            if (!bad[now][j] && dp[i + 1][j] + 1 >= dp[i][now]) {
                dp[i][now] = dp[i + 1][j] + 1;
                la[i][now] = i;
            }
        }
        mx = max(mx, dp[i][now]);
    }

    if (mx < k) {
        cout << "-1\n";
        return;
    }

    string ans;
    ans.reserve(k);
    int p = 0, pre = 0;
    while ((int)ans.size() < k) {
        for (int c = 1; c <= 26; c++) {
            if (!bad[pre][c] && dp[p][c] + (int)ans.size() >= k) {
                pre = c;
                ans.push_back(char(c + 'a' - 1));
                p = la[p][c] + 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}
