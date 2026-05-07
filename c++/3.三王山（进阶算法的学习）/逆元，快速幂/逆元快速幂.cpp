//#include <iostream>
//#include <cstring>
//#define mod 1000000007
//using namespace std;
//
//int n, s;
//int mx = 0;
//int b[500005];
//long long ans = 0;
//
//long long pow_mod(long long a, long long b) {
//    long long res = 1;
//    a %= mod;
//    while (b) {
//        if (b & 1) res = res * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return res;
//}
//long long inv(long long x) {
//    return pow_mod(x, mod - 2);
//}
//long long solve(int cnt) {
//    long long sum = 1;
//    for (int i = 1; i <= mx; i++) {
//        if (b[i] <= 0) continue;
//        for (int j = 1; j <= b[i]; j++, cnt--) {
//            sum = sum * cnt % mod;
//            sum = sum * inv(j) % mod;
//        }
//        if (cnt == 0) break;
//    }
//    return sum;
//}
//
//int main() {
//    memset(b, 0, sizeof(b));
//    cin >> n;
//    s = n - 2;
//
//    for (int i = 1; i <= n; i++) {
//        int t;
//        cin >> t;
//        if (t > mx) mx = t;
//        b[t]++;
//    }
//
//    for (int i = 1; i * i <= s; i++) {
//        if (s % i != 0) continue;
//        int j = s / i;
//        if (b[i] && b[j]) {
//            int ch = (i == j) ? 1 : 2;
//            b[i]--;
//            if (i != j) b[j]--;
//            ans = (ans + ch * solve(s)) % mod;
//            b[i]++;
//            if (i != j) b[j]++;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
//扩展欧几里得算法
#include <iostream>
using namespace std;

typedef long long ll;

// 扩展欧几里得算法
// 返回值：gcd(a, b)
// x, y: 满足 a*x + b*y = gcd(a, b) 的一组解
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    ll gcd = exgcd(b, a % b, y, x);  // 注意这里x和y交换了位置！
    y -= (a / b) * x;
    
    return gcd;
}

// 求 a 在模 p 下的逆元（要求 gcd(a, p) = 1）
ll mod_inverse(ll a, ll p) {
    ll x, y;
    ll gcd = exgcd(a, p, x, y);
    
    if (gcd != 1) {
        return -1;  // 逆元不存在
    }
    
    // 保证 x 是正数
    x = (x % p + p) % p;
    return x;
}

int main() {
    ll a, p;
    cout << "请输入 a 和模数 p：";
    cin >> a >> p;
    
    ll inv = mod_inverse(a, p);
    
    if (inv == -1) {
        cout << a << " 在模 " << p << " 下没有逆元（不互质）" << endl;
    } else {
        cout << a << " 在模 " << p << " 下的逆元是：" << inv << endl;
        cout << "验证： " << a << " * " << inv << " = " << (a * inv) % p << " (mod " << p << ")" << endl;
    }
    
    return 0;
}
//线性阶乘逆元
#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
const int N = 3e6 + 5;

int n, p;
int inv[N], fact[N], inv_fact[N];

// 快速幂
int qpow(int a, int b, int mod) {
    int res = 1;
    while(b) {
        if(b & 1) res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &p);
    
    // 1. 求阶乘
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (ll)fact[i-1] * i % p;
    }
    
    // 2. 求 n! 的逆元
    inv_fact[n] = qpow(fact[n], p-2, p);
    
    // 3. 递推求所有阶乘逆元
    for(int i = n-1; i >= 0; i--) {
        inv_fact[i] = (ll)inv_fact[i+1] * (i+1) % p;
    }
    
    // 4. 求 1~n 的逆元
    for(int i = 1; i <= n; i++) {
        inv[i] = (ll)fact[i-1] * inv_fact[i] % p;
        printf("%d\n", inv[i]);
    }
    
    return 0;
}
