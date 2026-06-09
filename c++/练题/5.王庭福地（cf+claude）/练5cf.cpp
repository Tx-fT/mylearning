//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXV = 1000005;
//vector<int> used_stamp(MAXV);
//vector<int> seen_stamp(MAXV);
//int used_ver, seen_ver;
//
//void solve() {
//    used_ver++;
//    int n;
//    cin >> n;
//
//    vector<vector<int>> r(n);
//    for (int i = 0; i < n; i++) {
//        int l;
//        cin >> l;
//        vector<int> a(l);
//        for (int j = 0; j < l; j++) cin >> a[j];
//        seen_ver++;
//        for (int j = l - 1; j >= 0; j--) {
//            if (seen_stamp[a[j]] != seen_ver) {
//                seen_stamp[a[j]] = seen_ver;
//                r[i].push_back(a[j]);
//            }
//        }
//    }
//
//    vector<bool> done(n);
//    vector<int> ans;
//
//    while (true) {
//        int best = -1;
//        for (int i = 0; i < n; i++) {
//            if (done[i]) continue;
//            int pi = 0;
//            while (pi < (int)r[i].size() && used_stamp[r[i][pi]] == used_ver) pi++;
//            if (pi == (int)r[i].size()) { done[i] = true; continue; }
//            if (best == -1) { best = i; continue; }
//
//            int pb = 0;
//            while (pb < (int)r[best].size() && used_stamp[r[best][pb]] == used_ver) pb++;
//
//            int ci = pi, cb = pb;
//            while (true) {
//                if (ci == (int)r[i].size() && cb == (int)r[best].size()) break;
//                if (ci == (int)r[i].size()) { best = i; break; }
//                if (cb == (int)r[best].size()) break;
//                if (r[i][ci] < r[best][cb]) { best = i; break; }
//                if (r[i][ci] > r[best][cb]) break;
//                ci++; cb++;
//                while (ci < (int)r[i].size() && used_stamp[r[i][ci]] == used_ver) ci++;
//                while (cb < (int)r[best].size() && used_stamp[r[best][cb]] == used_ver) cb++;
//            }
//        }
//        if (best == -1) break;
//        for (int x : r[best]) {
//            if (used_stamp[x] != used_ver) {
//                ans.push_back(x);
//                used_stamp[x] = used_ver;
//            }
//        }
//        done[best] = true;
//    }
//
//    for (size_t i = 0; i < ans.size(); i++) {
//        if (i) cout << ' ';
//        cout << ans[i];
//    }
//    cout << '\n';
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int t;
//    cin >> t;
//    while (t--) solve();
//}
//D
//#include<bits/stdc++.h>
//using namespace std;
//long long a[100010];
//void solve(){
//	long long sum=(1ll<<63);
//	string s;
//	cin>>s;
//	int cnt=0;
//	for(int i=0;i<s.size();i++){
//		a[i]=i+1;
//		if(s[i]=='1'){
//			a[i]+=sum;
//			cnt++;
//		}
//	}
//	if(cnt&&cnt%2==0){
//		for(int i=0;i<s.size();i++){
//			if(s[i]=='1'){
//				a[i]-=sum;
//				break;
//			}
//		}
//	}
//	else if(!cnt){
//		for(int i=0;i<s.size();i++){
//			if(s[i]=='0'){
//				a[i]+=sum;
//				break;
//			}
//		}
//	}
//	for(int i=0;i<s.size();i++){
//		cout<<a[i]<<" ";
//	}
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int T=1;
////	cin>>T;
//	while(T--){
//		solve();
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int dp[27][200010];
//int la[27][200010];
//set<pair<char,char>> mm;
//void solve(){
//	int n,m,k;
//	cin>>n>>m>>k;
//	mm.clear();
//	memset(dp,0,sizeof(dp));
//	string s;
//	cin>>s;
//	for(int i=1;i<=m;i++){
//		char a,b;
//		cin>>a>>b;
//		mm.insert({a,b});
//	}
//	for(int i=1;i<=26;i++){
//		dp[i][n]=0;
//	}
//	int mx=0;
//	for(int i=n-1;i>=0;i--){
//		int now=(int)(s[i]-'a'+1);
//		for(int j=1;j<=26;j++){
//			dp[j][i]=dp[j][i+1];
//			la[j][i]=la[j][i+1];
//		}
//		for(int j=1;j<=26;j++){
//			if(mm.find({s[i],(char)(j+'a'-1)})==mm.end()){
//				if(dp[j][i+1]+1>dp[now][i]){
//					dp[now][i]=dp[j][i+1]+1;
//					la[now][i]=i;
//				}
//			}
//		}
//		if(dp[now][i]>mx){
//			mx=dp[now][i];
//		}
//	}
//	if(mx<k){
//		cout<<-1<<endl;
//		return;
//	}
//	int cnt=0;
//	string ans="";
//	int p=0;
//	int sel=-1;
//	int pre=0;
//	do{
//		char ch=(char)(pre+'a'-1);
//		for(int i=1;i<=26;i++){
//			if(dp[i][p]+cnt>=k&&mm.find({ch,'a'+i-1})==mm.end()){
//				sel=dp[i][p];
//				pre=i;
//				ans+=(char)('a'+i-1);
//				cnt++;
//				break;
//			}
//		}
//		p=la[pre][p]+1;
//	}while(cnt!=k);
//	cout<<ans<<endl;
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
//#include <bits/stdc++.h>
//using namespace std;
//struct node{
//  int tar,w;
//};
//vector<int> q;
//vector<node> g[305];
//long long ans=0;
//void dfs(int r,int now,int f){
//  for(auto i:g[now]){
//  	bool v=false;
//    if(i.tar==f){
//      continue;
//    }
//    if(find(q.begin(),q.end(),i.w)==q.end()){
//    	v=true;
//      	q.push_back(i.w);
//    }
//    ans+=q.size();
//    dfs(r,i.tar,now);
//	if(v){
//	    q.pop_back();
//	}
//  }
//}
//void solve(){
//  int n;
//  cin>>n;
//  for(int i=1;i<n;i++){
//    int a,b,w;
//    cin>>a>>b>>w;
//    g[a].push_back({b,w});
//    g[b].push_back({a,w});
//  }
//  for(int i=1;i<=n;i++){
//    dfs(i,i,-1);
//  }
//  cout<<ans;
//}
//int main()
//{
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
//  solve();
//  return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//using PII=pair<int,int>;
//
//const int N=500010;
//int n,res;
//int a[N],s[N]; // a[公司]：该公司连通块大小；s[u]：子树大小
//vector<PII> g[N];//邻接表存树
//
//
//// 第一次 DFS：计算每个节点的子树大小
//void dfs1(int u,int fa)
//{
//  s[u]=1;// 自身算一个节点
//  for(auto [v,w]:g[u])
//  {
//    if(v!=fa)
//    {
//      dfs1(v,u);
//      s[u]+=s[v];// 累加子树大小
//    }
//  }
//}
//
//
//// 第二次 DFS：换根 DP，动态维护每个公司的连通块大小
//void dfs2(int u,int fa)
//{
//  for(auto [v,w]:g[u])
//  {
//    if(v!=fa)
//    {
//      int t=a[w];// 暂存原来公司 w 的大小
//      a[w]=s[v];// 以 v 为根的子树属于公司 w
//      dfs2(v,u);
//      res-=a[w]*(a[w]-1);// 减去非法点对（同一公司内部）
//      a[w]=t-s[v];// 恢复为另一部分连通块
//    }
//  }
//}
//
//signed main()
//{
//  // 请在此输入您的代码
//  cin >> n;
//  res=n*n*(n-1);// 初始化为所有可能的点对数量
//
//  for(int i=1;i<=n;i++) a[i]=n;
//
//  for(int i=1;i<n;i++)
//  {
//    int u,v,w;cin >> u >> v >> w;
//    g[u].push_back({v,w});
//    g[v].push_back({u,w});
//  }
//
//  dfs1(1,0);// 计算子树大小
//  dfs2(1,0);// 换根 DP
//  for(int i=1;i<=n;i++)
//  {
//    res-=a[i]*(a[i]-1);
//  }
//  cout << res << endl;
//  return 0;
//}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int n,m;
//int x[100010];
//int y[100010];
//bool check(int d){
//	int len=d+1;
//	long long sum=0;
//	for(int i=1;i<=m;i++){
//		sum+=x[i]*(y[i]/len);
//		if(y[i]%len){
//			sum+=x[i];
//		}
//		if(sum>=n){
//			return true;
//		}
//	}
//	return false;
//}
//void solve(){
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		cin>>x[i]>>y[i];
//	}
//	int l=0,r=1e9;
//	while(l<r){
//		int mid=(l+r+1)/2;
//		if(check(mid)){
//			l=mid;
//		}
//		else{
//			r=mid-1;
//		}
//	}
//	cout<<l;
//}
//signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	solve();
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//string m="fjcpc";
//void solve(){
//	string s;
//	cin>>s;
//	int cnt=0;
//	int ans=0;
//	for(char i:s){
//		if(i==m[cnt]){
//			cnt++;
//		}else{
//			if(i=='f'){
//				cnt=1;
//			}else{
//				cnt=0;
//			}
//		}
//		if(cnt==5){
//			cnt=0;
//			ans++;
//		}
//	}
//	cout<<ans;
//}
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int T=1;
////	cin>>T;
//	while(T--){
//		solve();
//	}
//	return 0;
//}
//这里曼哈顿距离不好用
//#include <bits/stdc++.h>
//using namespace std;
//int ans[4][4]={
//  {0,0,0,0},
//  {0,1,2,3},
//  {0,4,5,6},
//  {0,7,8,9}
//};
//int a[4][4];
//int mhd(){
//  int sum=0;
//  for(int i=1;i<=3;i++){
//    for(int j=1;j<=3;j++){
//      int t1=(a[i][j]-1)/3+1;
//      int t2=(a[i][j]-1)%3+1;
//      sum+=abs(i-t1)+abs(j-t2);
//    }
//  }
//  return sum;
//}
//bool f=false;
//int k=0;
//void dfs(int dep,int pre){
//  if(f){
//    return;
//  }
//  int p=mhd();
//  // if(p-dep*4>=pre){
//  //   return;
//  // }
//  if(!p){
//    f=true;
//    return;
//  }
//  if(dep>=k){
//    return;
//  }
//  for(int i=1;i<=4;i++){
//    if(i==1){
//      // 顺时针旋转左上角2x2
//      int t=a[1][1];
//      a[1][1]=a[2][1];
//      a[2][1]=a[2][2];
//      a[2][2]=a[1][2];
//      a[1][2]=t;
//      
//      dfs(dep+1,p);
//      
//      // 逆时针旋转回来（回溯）
//      t=a[1][1];
//      a[1][1]=a[1][2];
//      a[1][2]=a[2][2];
//      a[2][2]=a[2][1];
//      a[2][1]=t;
//      
//    }else if(i==2){
//      // 顺时针旋转右上角2x2
//      int t=a[1][2];
//      a[1][2]=a[2][2];
//      a[2][2]=a[2][3];
//      a[2][3]=a[1][3];
//      a[1][3]=t;
//      
//      dfs(dep+1,p);
//      
//      // 逆时针旋转回来
//      t=a[1][2];
//      a[1][2]=a[1][3];
//      a[1][3]=a[2][3];
//      a[2][3]=a[2][2];
//      a[2][2]=t;
//      
//    }else if(i==3){
//      // 顺时针旋转右下角2x2
//      int t=a[2][2];
//      a[2][2]=a[3][2];
//      a[3][2]=a[3][3];
//      a[3][3]=a[2][3];
//      a[2][3]=t;
//      
//      dfs(dep+1,p);
//      
//      // 逆时针旋转回来
//      t=a[2][2];
//      a[2][2]=a[2][3];
//      a[2][3]=a[3][3];
//      a[3][3]=a[3][2];
//      a[3][2]=t;
//      
//    }else{
//      // 顺时针旋转左下角2x2
//      int t=a[2][1];
//      a[2][1]=a[3][1];
//      a[3][1]=a[3][2];
//      a[3][2]=a[2][2];
//      a[2][2]=t;
//      
//      dfs(dep+1,p);
//      
//      // 逆时针旋转回来
//      t=a[2][1];
//      a[2][1]=a[2][2];
//      a[2][2]=a[3][2];
//      a[3][2]=a[3][1];
//      a[3][1]=t;
//    }
//  }
//}
//void solve(){
//  k=0;
//  f=false;
//  for(int i=1;i<=3;i++){
//    for(int j=1;j<=3;j++){
//      cin>>a[i][j];
//    }
//  }
//  if(!mhd()){
//    cout<<0<<endl;
//    return;
//  }
//  while(!f){
//    ++k;
//    dfs(0,100);
//  }
//  cout<<k<<endl;
//}
//int main()
//{
//  ios::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
//  int T;
//  cin>>T;
//  while(T--){
//    solve();
//  }
//  return 0;
//}
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//  unordered_map<string, int> mp;
//  queue<pair<string, int>> que;
//  que.push({"123456789", 0});
//  mp["123456789"] = 0;
//  const int a[4] = {0,1,3,4};
//  while (!que.empty()) {
//    auto [s, c] = que.front();
//    que.pop();
//    for (int i=0; i<4; i++) {
//      string t = s;
//      char ch = t[a[i]];
//      t[a[i]] = t[a[i]+1];
//      t[a[i]+1] = t[a[i]+4];
//      t[a[i]+4] = t[a[i]+3];
//      t[a[i]+3] = ch;
//      if (mp.find(t) == mp.end())
//        que.push({t, c+1}), mp[t] = c+1;
//    }//用目标倒推是逆时针
//  }
//  int t;
//  cin>>t;
//  while (t--) {
//    string s;
//    char ch;
//    for (int i=0; i<9; i++)
//      cin>>ch, s += ch;
//    cout<<mp[s]<<'\n';
//  }
//  
//  return 0;
//}
//自动ac机
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//#include<queue>
//#include<map>
//#include<set>
//#include<stack>
//#include<iomanip>
//#include<string>
//#include<cmath>
//#define inf 0x3f3f3f3f
////#define int long long
//using namespace std;
//using ll = long long;
//const int N = 1e5 + 7, mod = 1e9 + 7;
//int cnt = 0,T;
//map<string, int>mp, task;
//queue<string>q;
//string st = "123456789", tar;
//vector<string>vec;
//void f(int p, string t)
//{
//    string s = t;
//    char ch = s[p];
//    s[p] = s[p + 1];
//    s[p + 1] = s[p + 4];
//    s[p + 4] = s[p + 3];
//    s[p + 3] = ch;
//    if (mp.count(s) == 0)
//    {
//        mp[s] = mp[t] + 1;
//        q.push(s);
//    }
//}
//int main()
//{
//    cin >> T;
//    while (T--)
//    {
//        tar.clear();
//        for (int i = 1; i <= 3; i++)
//            for (int j = 1; j <= 3; j++)
//            {
//                char ch; cin >> ch;
//                tar += ch;
//            }
//        task[tar] = 1;
//        vec.push_back(tar);
//    }
//    mp[st] = 0;
//    q.push(st);
//    while (q.size())
//    {
//        string s = q.front(); q.pop();
//        if (task.count(s))task.erase(s);
//        if (task.empty())break;
//        f(0, s),f(1, s),f(3, s),f(4, s);
//    }
//    for (auto s : vec)cout << mp[s] << endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int a[105];
//void solve(){
//	map<int,int> mp;
//	int n;
//	cin>>n;
//	int cnt=0;
//	int idx=-1;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		if(!mp[a[i]]){
//			mp[a[i]]=1;
//		}else{
//			cnt++;
//		}
//	}
//	if(cnt>=2){
//		cout<<-1<<endl;
//		return;
//	}
//	sort(a+1,a+n+1,[&](int b,int c){
//		return b>c;	
//	});
//	bool f=true;
//	for(int i=3;i<=n;i++){
//		if(a[i]!=a[i-2]%a[i-1]){
//			f=false;
//			break;
//		}
//	}
//	if(f){
//		cout<<a[1]<<" "<<a[2]<<endl;
//	}else{
//		cout<<-1<<endl;
//	}
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

//#include <string>
//using namespace std;
//
//string s = "123456789012345";
//long long x = stoll(s);        // 转为 long long
//int y = stoi(s);               // 转为 int（可能溢出）
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//long long n;
//bool f1=false;
//bool f2=false;
//void dfs(int l,int r){
//	if(f1||f2){
//		return;
//	}
//	if(l>r){
//		long long ans=stoll(s.substr(1));
//		if(n<ans){
//			f2=true;
//		}
//		if((n-ans)%12==0){
//			cout<<ans<<" "<<n-ans<<endl;
//			f1=true;
//		}
//		return;
//	}
//	for(int i=0;i<=9;i++){
//		if(l==1&&i==0){
//			continue;
//		}
//		s[l]=s[r]=i+'0';
//		dfs(l+1,r-1);
//	}
//}
//void solve(){
//	f1=f2=false;
//	cin>>n;
//	if(n%12==0){
//		cout<<0<<" "<<n<<endl;
//		return;
//	}
//	int d=to_string(n).size();
//	for(int i=1;i<=d;i++){
//		s.clear();
//		s.resize(i+2);
//		dfs(1,i);
//	}
//	if(!f1){
//		cout<<-1<<endl;
//	}
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





























