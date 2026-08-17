#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int mx=500010;
const int lg=19;
int a[mx],r[mx],tb[lg][mx];
void solve() {
    ll ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tb[0][i]=a[i];
        ans+=1ll*i*(i-1)/2;
    }
    vector<int> s;
    a[0]=a[n+1]=0;
    s.push_back(n+1);
    for(int i=n;i>=1;i--){
        while(a[s.back()]>a[i]){
            s.pop_back();
        }
        r[i]=s.back();
        s.push_back(i);
    }
    for(int i=1;i<lg;i++){
        for(int j=(1<<i);j<=n;j++){
            tb[i][j]=max(tb[i-1][j],tb[i-1][j-(1<<(i-1))]);
        }
    }
    s.clear();
    s.push_back(0);
    for(int i=1;i<=n;i++){
        int right=r[i]-i;
        while(a[s.back()]>a[i]){
            s.pop_back();
        }
        int lr=s.back();
        for(int j=lg-1;j>=0;j--){
            if(lr>=(1<<j)&&tb[j][lr]<a[i]){
                lr-=(1<<j);
            }
        }
        ans-=1ll*right*(s.back()-lr);
        s.push_back(i);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);   
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
//单调队列模板存索引
deque<int> q;  // 存索引

for (int i = 0; i < n; i++) {
    // 1. 维护单调递减：弹出队尾所有比当前元素小的（通过索引取值比较）
    while (!q.empty() && a[q.back()] < a[i]) {
        q.pop_back();
    }
    q.push_back(i);  // 入队当前索引
    
    // 2. 移除过期元素（窗口左边界是 i-k+1）
    if (q.front() < i - k + 1) {
        q.pop_front();
    }
    
    // 3. 窗口形成后，队头就是最大值
    if (i >= k - 1) {
        cout << a[q.front()] << " ";
    }
}