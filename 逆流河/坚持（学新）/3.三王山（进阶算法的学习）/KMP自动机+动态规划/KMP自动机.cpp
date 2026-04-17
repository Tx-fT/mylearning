// #include <bits/stdc++.h> // removed for portability
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define int long long
const int N = 3000 + 5;
const int mod = 998244353;
int n, m;
int a[N];
int p[N][5];
int nxt[N];
int go[N][5];
int dp[N][N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	string tmp;
	cin >> tmp;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 'A') a[i + 1] = 1;
		if (tmp[i] == 'T') a[i + 1] = 2;
		if (tmp[i] == 'G') a[i + 1] = 3;
		if (tmp[i] == 'C') a[i + 1] = 4;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && a[j + 1] != a[i]) j = nxt[j];
		if (a[j + 1] == a[i]) j++;
		nxt[i] = j;
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			if (a[i + 1] == j) go[i][j] = i + 1;
			else go[i][j] = go[nxt[i]][j];
		}
	}//�����нڵ�ɴ�״̬�г���
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!dp[i][j]) continue;
			for (int c = 1; c <= 4; c++) {
				if (go[j][c] == m) continue;
				dp[i + 1][go[j][c]] = (dp[i + 1][go[j][c]] % mod + dp[i][j] % mod * p[i + 1][c] % mod) % mod;
			}
		}
	}
	int res = 0;
	for (int j = 0; j < m; j++) res = (res + dp[n][j] % mod) % mod;
	cout << (1 - res + mod) % mod;
	return 0;
}





























