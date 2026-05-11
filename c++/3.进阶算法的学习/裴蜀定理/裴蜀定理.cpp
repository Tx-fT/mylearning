#include <iostream>
#include <algorithm>
using namespace std;

int n, a, ans;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> a;
    ans = a;
    for (int i = 2; i <= n; ++i)
        cin >> a, ans = __gcd(ans, abs(a));//取最小公因数辗转反侧法
    cout << ans << '\n';
    return 0;
}
