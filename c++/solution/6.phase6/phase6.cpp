#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int a[200010];
int v[200010];
void solve(){
    int n;
    cin>>n;
    fill(v,v+n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            int l=max(1,i-a[i]+1);
            v[l]++;
            int r=min(n,i+a[i]-1);
            v[r+1]--;
        }
    }
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(v[i]){
                cout<<-1<<endl;
                return;
            }else{
                ans[i]=1;
            }
        }else if(a[i]>0){
            bool f=false;
            if(i-a[i]>=1){
                if(v[i-a[i]]==0){
                    ans[i-a[i]]=1;
                    f=true;
                }
            }
            if(i+a[i]<=n){
                if(v[i+a[i]]==0){
                    ans[i+a[i]]=1;
                    f=true;
                }
            }
            if(!f){
                cout<<-1<<endl;
                return;                
            }
        }else{
            if(v[i]) ans[i]=0;
            else{
                ans[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<endl;
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