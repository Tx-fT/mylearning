#include<bits/stdc++.h>
using namespace std;

const int MAXV = 1000002;
long long cnt[MAXV];
long long pcnt[MAXV];  // 个数前缀和
long long psum[MAXV];  // 加权前缀和

void solve(){
    int n; long long k;
    cin >> n >> k;

    int M = 0; long long S = 0;
    vector<int> vals(n);
    for(int i=0;i<n;i++){
        cin >> vals[i];
        M = max(M, vals[i]);
        S += vals[i];
    }

    fill(cnt,  cnt+M+2,  0LL);
    fill(pcnt, pcnt+M+2, 0LL);
    fill(psum, psum+M+2, 0LL);
    for(int v : vals) cnt[v]++;
    for(int i=1;i<=M;i++){
        pcnt[i] = pcnt[i-1] + cnt[i];
        psum[i] = psum[i-1] + cnt[i]*(long long)i;
    }

    long long ans = 1;

    // 1. 枚举 d 从 1 到 M，用前缀和 O(M log M) 计算 cost
    for(int d=1;d<=M;d++){
        long long cost = 0;
        bool ok = true;
        for(long long lo=0; lo<M; lo+=d){
            long long hi = min(lo+d, (long long)M);
            long long c = pcnt[hi] - pcnt[lo];
            long long s = psum[hi] - psum[lo];
            cost += (lo+d)*c - s;   // 区间(lo, lo+d]内元素加到lo+d
            if(cost > k){ ok=false; break; }
        }
        // 恰好k次：剩余 k-cost 必须是d的倍数才能"消化"
        if(ok && (k - cost) % d == 0)
            ans = max(ans, (long long)d);
    }

    // 2. d > M 的情况：cost = n*d - S
    //    条件：n*d-S <= k 且 (k-(n*d-S)) % d == 0
    //    即 (k+S) % d == 0 且 d <= (S+k)/n
    long long best_large = (S + k) / n;
    if(best_large > M){
        long long KS = k + S;
        long long best = 0;
        for(long long f=1; f*f<=KS; f++){//枚举约数
            if(KS % f == 0){
                if(f > M && f <= best_large) best = max(best, f);
                long long f2 = KS / f;
                if(f2 > M && f2 <= best_large) best = max(best, f2);//挑最大的
            }
        }
        ans = max(ans, best);
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
