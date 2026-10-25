#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const ll mod=998244353;
ll qpow(ll b,ll x){
    ll res=1;
    while(x){
        if(x&1){
            res=1ll*res*b%mod;
        }
        b=1l*b*b%mod;
        x>>=1;
    }
    return res;
}
ll inv(ll num){
    return qpow(num,mod-2);
}
void solve(){
    int n;
    cin>>n;
    vector<int> g[n+5];
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    vector<ll> cn(n+5);
    //function<void(int,int)>dfs=[&](int a,int b)->void{
    //};
    function<void(int,int,int)> dfs = [&](int nw,int p,int dep)->void{//auto dfs =【&】（auto self，……）{self（self，……）}；dfs（dfs，……）；
        cn[dep]++;
        if(g[nw].size()==0){
            return;
        }
        for(int i:g[nw]){
            if(i==p){
                continue;
            }
            dfs(i,nw,dep+1);
        }
    };
    dfs(1,0,1);
    cn[1]=1;
    ll ans=1+cn[2];
    ll pre=cn[2];
    for(int i=3;;i++){
        if(!cn[i]){
            break;
        }
        ll t=cn[i];
        cn[i]=1ll*cn[i-1]*cn[i]%mod*inv(pre)%mod*(pre-1)%mod;//mod的除法要用inv，用到inv每×都要mol一下
        pre=t;
        if(!cn[i]){
            break;
        }
        ans+=cn[i];
        ans%=mod;
    }
    // cout<<cn[3]<<endl;
    cout<<ans%mod<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}