//#include<bits./stdc++.h>
//using namespace std;
//
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//int query(int l, int r) {
//    cout << "? " << l << " " << r << "\n";
//    cout.flush();
//    int x;
//    cin >> x;
//    return x;
//}
//
//int solve(int l, int r) {//���δ���
//    if (l == r) return l;
//    int mid = (l + r) / 2;
//    int ml = solve(l, mid);
//    int mr = solve(mid + 1, r);
//    
//    int f_ml_mr = query(ml, mr);
//    int f_inner;
//    if (ml + 1 <= mr - 1) {
//        f_inner = query(ml + 1, mr);
//    } else {//����
//        f_inner = 0;
//    }
//    
//    int diff = f_ml_mr - f_inner;
//    if (diff == mr - ml) {
//        return ml;
//    } else {
//        return mr;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    int T;
//    cin >> T;
//    while (T--) {
//        int n;
//        cin >> n;
//        int ans = solve(1, n);
//        cout << "! " << ans << "\n";
//        cout.flush();
//    }
//    return 0;
//}
//Ư�����㷨
//#include<bits/stdc++.h>
//using namespace std;
//int sum[100010];
//void solve(){
//	int n;
//	cin>>n;
//	int idx=-1;
//	int cnt=0;
//	string s;
//	cin>>s;
//	char pre=' ';
//	for(int i=0;i<n;i++){
//		if(s[i]!=pre){
//			pre=s[i];
//			sum[++idx]=cnt;
//			if(idx){
//				sum[idx]+=sum[idx-1];
//			}
//			cnt=0;
//		}
//		cnt++;
//	}
//	int c[100010];
//	memset(c,0,sizeof(c));
//	sum[++idx]=cnt+sum[idx-1];
//	int a[100010];
//	int b[100010];
//	int idx1=0,idx2=0;
//	for(int i=1;i<=idx-2;i++){
//		int w1=min(sum[i]-sum[i-1]-c[i],sum[i+2]-sum[i+1]-c[i+2]);
//		int w2=(sum[i+1]-sum[i]-c[i+1])/2;
//		if(w1>=w2){
//			int cn=1;
//			while(cn<=w1){
//				a[++idx1]=sum[i-1]+c[i]+cn;
//				b[++idx2]=sum[i+1]+c[i+2]+cn;
//				cn++;
//			}
//			c[i+2]+=w1;
//		}
//		else{
//			for(int j=1;j<=w2;j++){
//				a[++idx1]=sum[i]+c[i+1]+j;
//			}
//			for(int j=1;j<=w2;j++){
//				b[++idx2]=sum[i]+c[i+1]+j+w2;
//			}
//			c[i+1]+=2*w2;
//		}
//	}
//	cout<<idx1<<endl;
//	for(int i=1;i<=idx1;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=idx2;i++){
//		cout<<b[i]<<" ";
//	}
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	solve();
//	return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//vector<int> g[300010];
//queue<int> q;
//const int inf=0x3f3f3f3f;
//int dist[300010];
//void solve(){
//    int n,m,k;
//    cin>>n>>m>>k;
//    for(int i=1;i<=m;i++){
//        int a,b;
//        cin>>a>>b;
//        g[a].push_back(b);
//        g[b].push_back(a);
//    }
//    fill(dist+1,dist+n+5,inf);
//    for(int i=1;i<=k;i++){
//        int p;
//        cin>>p;
//        q.push(p);
//        dist[p]=0;
//    }    
//    auto bfs=[&]()->void {
//        while(!q.empty()){
//            int now=q.front();
//            q.pop();
//            for(int i:g[now]){
//                if(dist[i]!=inf) continue;
//                else{
//                    dist[i]=dist[now]+1;
//                    q.push(i);
//                }
//            }
//        }
//    };
//    bfs();
//    int mx=0;
//    bool f=true;
//    for(int i=1;i<=n;i++){
//        if(dist[i]==inf){
//            f=false;
//            break;
//        }
//        mx=max(mx,dist[i]);
//    }
//    f?cout<<mx:cout<<-1;
//}
//int main( )
//{
//    solve();   
//    return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//
//void solve(){
//	
//}
//int main(){
//	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}
//	
//	
//	return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//const int mod=676767677;
//int a[200010];
//void solve(){
//	int x,y;
//	cin>>x>>y;
//	int c=abs(x-y);
//	int ans=1;
//	for(int i=1;i<c;i++){
//		if(c%i==0){
//			ans++;
//		}
//	}
//	cout<<ans<<endl;
//	for(int i=1;i<=y;i++){
//		cout<<-1<<" ";
//	}
//	for(int j=1;j<=x;j++){
//		cout<<1<<" ";
//	}
//	cout<<endl;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}	
//	return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//int a[100010];
//void solve(){
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	int l=1;
//	long long sum=0;
//	int ans=0;
//	int cnt=0;
//	for(int r=1;r<=n;r++){
//		sum+=a[r];
//		++cnt;
//		if(sum<=m){
//			ans=max(ans,cnt);
//			continue;
//		}
//		else{
//			while(sum>m){
//				sum-=a[l];
//				l++;
//				cnt--;
//			}
//		}
//	}
//	cout<<ans;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
////	cin>>t;
//	t=1;
//	while(t--){
//		solve();
//	}
//	
//	return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//int ans=0x3f3f3f3f;
//int v[20010];
//void dfs(int now,int tar,int cnt){
//	if(v[now]<=cnt){
//		return;
//	}
//	else{
//		v[now]=cnt;
//	}
//	if(now==tar){
//		ans=min(ans,cnt);
//		return;
//	}
//	if(now<tar){
//		dfs(now*2,tar,cnt+1);
//	}
//	if(now>0){
//		dfs(now-1,tar,cnt+1);
//	}
//}
//void solve(){
//	memset(v,0x3f,sizeof(v));
//	int n,m;
//	cin>>n>>m;
//	dfs(n,m,0);
//	cout<<ans;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
////	cin>>t;
//	t=1;
//	while(t--){
//		solve();
//	}
//	return 0;
//}
//#include<bits/stdc++.h> 
//using namespace std;
//void solve(){
//	int x,y;
//	cin>>x>>y;
//	if(x>y||(x==0&&y%2==0)){
//		cout<<"NO"<<endl;
//		return;
//	}
//	else{
//		int l=y-x;
//		int u=x;
//		cout<<"YES"<<endl;
//		if(l%2==0){
//			u--;
//			for(int i=1;i<=u;i++){
//				cout<<2*i<<" "<<2*i+1<<endl;
//				cout<<1<<" "<<2*i<<endl;
//			}
//			for(int i=2*u+2;i<=x+y;i++){
//				cout<<1<<" "<<i<<endl;
//			}
//		}
//		else{
//			for(int i=1;i<=u;i++){
//				cout<<2*i<<" "<<2*i+1<<endl;
//				cout<<1<<" "<<2*i<<endl;
//			}
//			for(int i=2*u+2;i<=x+y;i++){
//				cout<<1<<" "<<i<<endl;
//			}			
//		}
//	}
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}
//	return 0;
//}
//#include<bits/stdc++.h> 
//#define int long long
//using namespace std;
//int d[2010];
//int sum[2010];
//void solve(){
//	int n,h;
//	cin>>n>>h;
//	for(int i=1;i<=n;i++){
//		cin>>d[i];
//		sum[i]=h-d[i];
//	}
//	for(int i=1;i<=n;i++){
//		int cur=d[i];
//		for(int j=i-1;j>=1;j--){
//			cur=max(cur,d[j]);
//			sum[i]+=h-cur;
//		}
//		cur=d[i];
//		for(int j=i+1;j<=n;j++){
//			cur=max(cur,d[j]);
//			sum[i]+=h-cur;			
//		}
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		int hi=d[i];
//		int idx=i;
//		for(int j=i-1;j>=1;j--){
//			if(hi<d[j]){
//				hi=d[j];
//				idx=j;
//			}
//			ans=max(ans,sum[i]+sum[j]-sum[idx]);
//		}
//		ans=max(ans,sum[i]);
//	}
//	cout<<ans<<endl;
//}
//signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int t[200010];
//struct node{
//	int h1;
//	int num1;
//	int h2;
//	int num2;
//};
//void solve(){
//	int n,m,l;
//	cin>>n>>m>>l;
//	for(int i=1;i<=n;i++){
//		cin>>t[i];	
//	}
//	node pre;
//	t[0]=0;
//	int val=t[1]-t[0];
//	int cnt=min(n+1,m);
//	int d=val/cnt;
//	int yu=val%cnt;
//	if(yu>1){
//		pre={d+1,yu-1,d,cnt-yu};	
//	}
//	else{
//		pre={d,cnt-1,d,0};
//	}
//	for(int i=2;i<=n;i++){
//		val=t[i]-t[i-1];
//		cnt=n-i+2;
//		cnt=min(cnt,m);
//		d=val/cnt;
//		yu=val%cnt;
//		if(!pre.num1){
//			if()
//		}
//		pre.h1+=d;
//		pre.h2+=d;
//		if(yu<=pre.num2){
//			pre={pre.h1,pre.num1-1+yu,pre.h2,pre.num2-yu};
//			continue;
//		}
//		else{
//			yu-=pre.num2;
//			if(yu>1){
//				pre={pre.h1+1,yu-1,pre.h1,cnt+1-yu};
//			}
//			else{
//				pre={pre.h1,cnt-1,pre.h2,0};
//			}
//		}	
//	}
//	if(pre.num1){
//		cout<<pre.h1+(l-t[n])<<endl;
//	}
//	else{
//		cout<<l-t[n]<<endl;
//	}
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}
//	return 0;
//}
//good
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int b[200010];
//int t[200010];
//void solve(){
//	int n,m,l;
//	cin>>n>>m>>l;
//	for(int i=1;i<=n;i++){
//		cin>>t[i];
//	}
//	t[0]=0;
//	for(int i=1;i<=n;i++){
//		int cnt=n+2-i;
//		cnt=min(cnt,m);
//		int val=t[i]-t[i-1];
//		int f=0;
//		for(int i=cnt;i>1;i--){
//			while(b[i-1]>b[i]){
//				for(int j=cnt;j>=i;j--){
//					b[j]++;
//					val--;
//					if(!val){
//						f=1;
//						break;
//					}
//				}
//				if(f){
//					break;
//				}			
//			}
//			if(f){
//				break;
//			}
//		}
//		if(val){
//			int d=val/cnt;
//			int d1=val%cnt;
//			for(int i=1;i<=cnt;i++){
//				if(d1&&i<=d1){
//					b[i]+=d+1;
//				}
//				else{
//					b[i]+=d;
//				}
//			}
//		}
//		b[1]=0;
//		sort(b+1,b+cnt+1,[&](int l1,int l2){
//			return l1>l2;
//		});
//	}
//	cout<<b[1]+(l-t[n])<<endl;
//	b[1]=0;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}	
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int T;
//    cin >> T;
//    while (T--) {
//        int n, m, l;
//        cin >> n >> m >> l;
//        vector<int> a(n);
//        for (int i = 0; i < n; ++i) cin >> a[i];
//        vector<int> lvls(m, 0);          // Σ��ֵ����������
//        int curr = n;                    // ʣ���������
//        for (int i = 0; i < l; ++i) {    // i ��ʾ�� i+1 �����
//            // ����ѡ����ܴ��� curr+1 �������Σ������һ������
//            int idx = min(m, curr + 1) - 1;
//            lvls[idx]++;
//            // ���ֽ���
//            sort(lvls.begin(), lvls.end(), greater<int>());
//            // ����Ƿ���Ҫ����
//            if (curr > 0 && a[n - curr] - 1 == i) {
//                lvls[0] = 0;             // �����Σ�յ����
//                sort(lvls.begin(), lvls.end(), greater<int>());
//                curr--;                  // �õ�һ������
//            }
//        }
//        cout << lvls[0] << '\n';         // �������Σ�ն�
//    }
//    return 0;
//}
//ÿ��sort���־��ȣ�����l
//ͼ��dfs
//#include<iostream>
//#include<vector>
//using namespace std;
//const long long mod=1000000007;
//vector<int> g[300010];
//long long dfn[300010];
//void dfs1(int x){
//	if(!g[x].size()){
//		dfn[x]=0;
//		return;
//	}
//	for(int i:g[x]){
//		dfs1(i);
//		dfn[x]+=dfn[i];
//	}
//	dfn[x]+=4;
//}
//void dfs2(int x){
//	if(!g[x].size()){
//		return;
//	}
//	for(int i=0;i<g[x].size();i++){
//		dfn[g[x][i]]=(dfn[x]+dfn[g[x][i]]+1)%mod;
//		dfs2(g[x][i]);
//	}
//}
//void solve(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		g[i].clear();
//	}
//	fill(dfn+1,dfn+n+5,0);
//	for(int i=1;i<=n;i++){
//		int a,b;
//		cin>>a>>b;
//		if(a){
//			g[i].push_back(a);
//			g[i].push_back(b);
//		}
//	}
//	dfs1(1);
//	dfs2(1);
//	for(int i=1;i<=n;i++){
//		cout<<(dfn[i]+1)%mod<<" ";
//	}
//	cout<<endl;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int T;
//	cin>>T;
//	while(T--){
//		solve();
//	}
//	return 0;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin>>t;
//	while(t--){
//		solve();
//	}	
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int a[200010];
//int b[200010];
//int g[200010];
//int main(){
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//        b[i]=a[i];
//    }
//    sort(b+1,b+n+1,[](int c1,int c2){
//        return c1>c2;    
//    });
//    map<long long,int> mp;
//    long long ans=0;
//    int cnt1=0;
//    bool f=false;
//    for(int i=1;i<=2*m&&i<=n;i++){
//        if(b[i]<0){
//            break;
//        }
//        if(b[i]==a[n]){
//            f=true;
//        }    
//        mp[b[i]]++;
//        ans+=b[i];
//        cnt1++;
//    }
//    if(!f){
//    	ans+=a[n];
//    	mp[a[n]]++;
//    	if(cnt1==2*m){
//	        mp[b[2*m]]--;
//	        ans-=b[2*m];
//			cnt1--;	
//    	}
//    	cnt1++;
//    }
//    if(cnt1==1){
//    	if(b[1]==a[n]){
//			ans+=b[2];
//			mp[b[2]]++;
//		}
//		else{
//			ans+=b[1];
//			mp[b[1]]++;	
//		}
//		cnt1++;	
//	}
//    int cnt=0;
//    int cnt2=0;
//    int sum=1;
//    g[n]=1;
//    for(int i=n;i>=1;i--){
//        if(mp[a[i]]){
//            mp[a[i]]--;
//            cnt++;
//            if(cnt>2){
//                cnt=1;
//                sum++;
//            }
//            cnt2++;
//        }
//        g[i]=sum;
//        if(cnt2==cnt1&&cnt1%2==1){
//			sum--;
//			cnt2--;
//		}
//    }
//    cout<<ans<<endl;
//    for(int i=1;i<=n;i++){
//        cout<<g[i]<<" ";
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int a[150005];
//int v[150005];
//int find(int x){
//	if(x==v[x]){
//		return x;
//	}
//	return v[x]=find(v[x]);
//}
//void comb(int x,int y){
//	int r1=find(x);
//	int r2=find(y);
//	if(r1!=r2){
//		v[r1]=r2;
//	}
//}
//int main(){
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n+1;i++){
//		v[i]=i;
//	}
//	for(int i=1;i<=m;i++){
//		int sum;
//		cin>>sum;
//		int ans=0;
//		while(sum<=n){
//			int now=sum;
//			if(a[now]==1){
//				comb(now,now+1);
//			}
//			if(v[now]!=now){
//				ans+=v[now]-now;
//				sum+=v[now]-now;
//				continue;
//			}
//			ans++;
//			sum+=a[now];
//			if(a[now]!=1){
//				a[now]--;
//			}
//			if(a[now]==1){
//				comb(now,now+1);
//			}
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//void solve(){
//	
//}
//int main(){	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int T;
//	cin>>T;
//	while(T--){
//		solve();
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<map>
//using namespace std;
//string a[3010];
//void solve(){
//	int n;
//	cin>>n;
//	for(int i=0;i<=n;i++){
//		int l;
//		cin>>l;
//		for(int j=0;j<l;j++){
//			char t;
//			cin>>t;
//			a[i]+=t;
//		}
//		reverse(a[i].begin(),a[i].end());
//		for(){
//			if()	
//		}
//	}
//	sort(a,a+n,[&](string b,string c){
//		return b>c;
//	});
//	string ans="";
//	for(int i=1;i<=n;i++){
//		string temp="";
//		for(char j:ans){
//			if(a[i].find(j)!=a[i].size()){
//				temp+=j;
//			}
//		}
//		ans=a[i]+temp;
//	}
//	for(char i:ans){
//		cout<<i<<" ";
//	}
//	cout<<endl;
//}
// #include<bits/stdc++.h>
// using namespace std;
// long long cnt[66];
// int main(){
// 	string a;
// 	cin>>a;
// 	int len=a.size();
// 	for(int i=0;i<len;i++){
// 		cnt[i]=pow(2,i);
// 	}
// 	int idx=len-1;
// 	for(int i=0;i<len-1;i++){
// 		if(a[i]=='0'){
// 			cnt[idx]^=cnt[i];
// 		}
// 	}
// 	for(int i=0;i<len;i++){
// 		cout<<cnt[i]<<" ";
// 	}
// 	return 0;
// }































