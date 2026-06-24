#include<bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int dp[200010];
int n,k;
long long ans[200010];

void dfs1(int now,int f){
    dp[now]=1;
    for(int i:g[now]){
        if(i==f){
            continue;
        }
        dfs1(i,now);
        dp[now]+=dp[i];
    }
    if(dp[now]>=k){
        ans[1]++;
    }
}

void dfs2(int now,int f){
    for(int i:g[now]){
        if(i==f){
            continue;
        }
        ans[i]=ans[now];
        int tep=dp[i];
        dp[now]-=dp[i];
        dp[i]=n;
        if(tep<k){
            ans[i]+=1;
        }
        if(dp[now]<k){
            ans[i]-=1;
        }
        dfs2(i,now);
        dp[now]=n;
        dp[i]=tep;
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans[1]=0;
    dfs1(1,-1);
    dfs2(1,-1);
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=ans[i];
    }
    cout<<sum<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
