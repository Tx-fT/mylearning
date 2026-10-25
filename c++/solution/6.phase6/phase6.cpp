#include<bits/stdc++.h>
#define endl '\n'
// #define int ll
using namespace std;
using ll = long long;
vector<int> g[100010];
bool v[100010];
int cn[100010];
ll ans=0;
void dfs(int n,int p){
    if(g[n].size()==1&&n!=1){
        return;
    }
    int cnt=0;
    int sum=0;
    for(int i:g[n]){
        if(i==p){
            continue;
        }
        dfs(i,n);
        if(cn[i]||v[i]){
            cn[n]=max(cn[n],cn[i]+1);
            cnt++;
            sum+=cn[i]+1;
        }
    }
    if(cnt>=2){
        ans+=2*sum;
        cn[n]=0;
        v[n]=true;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        v[t]=true;
    }
    dfs(1,-1);
    ans+=2*cn[1];
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}