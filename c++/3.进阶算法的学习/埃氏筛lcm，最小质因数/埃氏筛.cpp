// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long;
// const ll MOD=1000000007;
// const int MAXA=500000;

// int spf[MAXA+1];
// ll sum[MAXA+1];
// vector<int> used;

// //这个函数用埃氏筛的思想计算每个数的最小质因子
// void precompute(){
//     for(int i=2; i<=MAXA; i++){          // 从小到大遍历每个数
//         if(spf[i]==0){                     // i 是质数（还没被标记过）
//             spf[i]=i;                      // 质数的最小质因子就是它自己
//             for(ll j=1LL*i*i; j<=MAXA; j+=i){  // 从 i² 开始标记 i 的倍数
//                 if(spf[j]==0) spf[j]=i;    // 第一次被标记 → i 就是最小质因子
//             }
//         }
//     }
// }

// void solve(){
//     int n,x;
//     cin>>n>>x;
//     for(int i=0;i<n;i++){
//         int val;
//         cin>>val;
//         while(val>1){
//             int p=spf[val];
//             int cnt=0;
//             while(val%p==0){
//                 val/=p;
//                 cnt++;
//             }
//             if(sum[p]==0) used.push_back(p);
//             sum[p]+=cnt;//每次只能出现唯一项质因子
//         }
//     }
//     ll ans=1;
//     for(int p:used){
//         ans=ans*((sum[p]+1)%MOD)%MOD;//有+无
//         sum[p]=0;
//     }
//     used.clear();
//     cout<<ans<<'\n';
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     precompute();
//     int t;
//     cin>>t;
//     while(t--) solve();
// }


#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1000000007;
const int mxn=500010;
int spf[mxn];
int cnt[mxn];
//用埃氏筛的思想计算每个数的最小质因子
//lcm由最大项质因子乘积所得
void prec(){
    for(int i=2;i<mxn;i++){
        if(!spf[i]){
            spf[i]=i;
            for(ll j=1LL*i*i;j<mxn;j+=i){
                if(!spf[j]){
                    spf[j]=i;
                }
            }
        }
    }
}
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> q;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(t>1){
            int p=spf[t];
            if(!cnt[p]){
                q.push_back(p);
            }
            while(t%p==0){
                cnt[p]++;
                t/=p;
            }
        }
    }
    ll ans=1;
    for(int i:q){
        ans=1ll*ans*(cnt[i]+1)%mod;
        cnt[i]=0;
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}