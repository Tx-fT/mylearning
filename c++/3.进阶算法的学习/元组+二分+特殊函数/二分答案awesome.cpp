#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> emp(n);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        emp[i]={a,b,i+1};
    }

    // 按职级升序，同职级按b降序
    sort(emp.begin(), emp.end(), [](auto& x, auto& y){
        if(get<0>(x) != get<0>(y)) return get<0>(x) < get<0>(y);
        return get<1>(x) > get<1>(y);
    });

    // check(k): 能否选k人？
    // 对同职级一批（s人，b降序），前面已选prev个，这批选x个
    // 条件：第x个人（b最小）满足 b[x-1] + x + prev >= k
    // 从 min(s, k-prev) 往下找最大合法x
    auto check = [&](int k) -> pair<bool, vector<int>> {
        vector<int> chosen;
        int prev = 0, i = 0;
        while(i < n && prev < k){
            int j = i;
            while(j < n && get<0>(emp[j]) == get<0>(emp[i])) j++;
            int s = j - i;
            int maxX = min(s, k - prev);
            int x = 0;
            for(int xi = maxX; xi >= 1; xi--){
                if(get<1>(emp[i+xi-1]) + xi + prev >= k){
                    x = xi; break;
                }
            }
            for(int t=i; t<i+x; t++) chosen.push_back(get<2>(emp[t]));
            prev += x;
            i = j;
        }
        return {prev == k, chosen};
    };

    int lo=0, hi=n, ans=0;
    vector<int> res;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        auto [ok, v] = check(mid);
        if(ok){ ans=mid; res=v; lo=mid+1; }
        else hi=mid-1;
    }

    cout << ans << "\n";
    for(int k=0;k<(int)res.size();k++){
        if(k) cout<<" ";
        cout<<res[k];
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
