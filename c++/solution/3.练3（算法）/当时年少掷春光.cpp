//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node{
//	int cap=0;
//	int d[21];
//	int now=0;
//};
//node a[105];
//bool cmp(node a,node b){
//	return a.now>b.now;
//} 
//int n,m,k;
//int b[21]={0};
//int ans=0;
//int cnt=0;
//int main(){
//	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++){
//		int pre=0;
//		for(int j=1;j<=k;j++){
//			int t;
//			cin>>t;
//			if(t==pre) continue;
//			a[i].d[++a[i].cap]=t;
//			pre=t;
//		}
//		a[i].now=a[i].cap;	
//	}
//	for(int i=1;i<=n;i++){
//		if(cnt==m){
//			break;
//		}
//		sort(a+1,a+n+1,cmp);
//		if(a[1].now==0){
//			break;
//		}
//		for(int j=1;j<=a[1].cap;j++){
//			if(!b[a[1].d[j]]){
//				b[a[1].d[j]]=1;
//				cnt++;
//			}
//		}
//		ans++;
//		a[1].now=0;
//		for(int j=2;j<=n;j++){
//		    if(a[j].now==0){
//				continue;
//			}
//			for(int u=1;u<=a[j].cap;u++){
//				if(b[a[j].d[u]]){
//					a[j].now--;
//				}
//			}
//		}	
//	}
//	if(cnt<m){
//		cout<<-1;
//	}
//	else{
//		cout<<ans;
//	}
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n,m,k;
//int a[105]={0};
//int dp[1<<20];
//
//int main(){
//	memset(dp,0x3f,sizeof(dp));
//	cin>>n>>m>>k;
//	const long long mx=(1<<m);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=k;j++){
//			int t;
//			cin>>t;
//			t--;
//			a[i]=a[i]|(1<<t);
//		}
//	}
//	dp[0]=0;
//	for(int i=0;i<mx;i++){
//		for(int j=1;j<=n;j++){
//			dp[i|a[j]]=min(dp[i|a[j]],dp[i]+1);
//		}
//	}
//	if(dp[mx-1]>100){
//		cout<<-1;
//	}
//	else{
//		cout<<dp[mx-1];	
//	}
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int q;
//int n,m;
//char a[55][55];
//int st[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,1},{1,0},{1,-1}};
//bool solve(){
//	bool f=true;
//	for(int i=1;i<=n;i++){
//		if(!f){
//			break;
//		}
//		for(int j=1;j<=m;j++){
//			if(a[i][j]=='.') continue;
//			int cnt=0;
//			for(int u=0;u<8;u++){
//				int nx=i+st[u][0];
//				int ny=j+st[u][1];
//				if(nx<1||nx>n||ny<1||ny>m){
//					continue;
//				}
//				if(a[nx][ny]=='*'){
//					cnt++;
//				}
//			}
//			if(cnt!=2){
//				f=false;
//				break;
//			} 
//		}
//	}
//	return f;
//}
//int main(){
//	cin>>q;
//	while(q--){
//		cin>>n>>m;
//		memset(a,0,sizeof(a));
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cin>>a[i][j];
//			}
//		}
//		if(solve()){
//			cout<<"YES"<<endl;
//		}
//		else{
//			cout<<"NO"<<endl;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int ch[10]={13,1,2,3,5,4,4,2,2,2};
//int m1[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
//int main(){
//    int ans=0;
//    for(int y=2000;y<=2023;y++){
//        int ycnt=0;
//        ycnt=ch[y%10]+ch[y/10%10]+ch[y/100%10]+ch[y/1000];
//        for(int m=1;m<=12;m++){
//            int mcnt=0;
//            if(m<10){
//                mcnt=ch[m]+ch[0];
//            }
//            else{
//                mcnt=ch[m%10]+ch[m/10];
//            }
//            if(m==2){
//                m1[m]=y%4==0?29:28;
//            }
//            for(int d=1;d<=m1[m];d++){
//                int dcnt=0;
//                if(d<10){
//                    dcnt=ch[d]+ch[0];
//                }
//                else{
//                    dcnt=ch[d%10]+ch[d/10];
//                }                
//                if(dcnt+mcnt+ycnt>50){
//                    ans++;
//                }
//            }
//        }
//    }
//    int ycnt1=22;
//    m1[2]=29,m1[4]=13;
//    for(int m=1;m<=4;m++){
//        int mcnt=0;
//        mcnt=ch[m]+ch[0];
//        for(int d=1;d<=m1[m];d++){
//            int dcnt=0;
//            if(d<10){
//                dcnt=ch[d]+ch[0];
//            }
//            else{
//                dcnt=ch[d%10]+ch[d/10];
//            }                
//            if(dcnt+mcnt+ycnt1>50){
//                ans++;
//            }
//        }
//    }
//    cout<<ans;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//
//int ans=0;
//
//void solve(){
//	for(long long i=(1<<25)-1;i>=(1<<12);i--){
//		int cnt1=0,cnt2=0;
//		int f=1;
//		for(int j=0;j<25;j++){
//			if((i>>j)&1){
//				cnt1++;
//			}
//			else{
//				cnt2++;
//			}
//			if(cnt1>12||cnt2>13){
//				f=0;
//				break;
//			}
//			
//		}
//		if(!f){
//			continue;
//		}
//		else{
//			int bx[6]={0},by[6]={0},wx[6]={0},wy[6]={0},pw1=0,pw2=0,pb1=0,pb2=0;
//			for(int j=0;j<25;j++){
//			    if((i>>j)&1){
//			        int x = j/5 + 1;
//			        int y = j%5 + 1;
//			        if(bx[x]==4 || by[y]==4){
//			            f=0;
//			            break;
//			        }
//			        if(x==y && pw2==4){
//			            f=0;
//			            break;
//			        }
//			        if(x+y==6 && pw1==4){
//			            f=0;
//			            break;
//			        }
//			        bx[x]++;
//			        by[y]++;
//			        if(x+y==6) pw1++;
//			        if(x==y) pw2++;
//			    }
//			    else{
//			        int x = j/5 + 1;
//			        int y = j%5 + 1;
//			        if(wx[x]==4 || wy[y]==4){
//			            f=0;
//			            break;
//			        }
//			        if(x==y && pb2==4){
//			            f=0;
//			            break;
//			        }
//			        if(x+y==6 && pb1==4){
//			            f=0;
//			            break;
//			        }
//			        wx[x]++;
//			        wy[y]++;
//			        if(x+y==6) pb1++;
//			        if(x==y) pb2++;
//			    }
//			}
//			if(!f){
//				continue;
//			}
//			ans++;
//		}
//	}
//}
//int main(){
//	solve();
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node{
//	int v;
//	int num;
//};
//int n,s;
//node a[100010];
//bool cmp(node a,node b){
//	return a.num<b.num;
//}
//long long ans=0;
//int main(){
//	cin>>n>>s;
//	int mn=0x3f3f;
//	long long sum=0;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].v>>a[i].num;
//		sum+=a[i].v;
//	}	
//	sort(a+1,a+n+1,cmp);
//	int cnt=1;
//	int pre=0;
//	a[0].num=0;
//	while(sum>=s){
//		pre=cnt;
//		while(1){
//			sum-=a[cnt].v;
//			if(cnt<n&&a[cnt].num==a[cnt+1].num){
//				cnt++;
//			}
//			else{
//				break;
//			}
//		}
//	}
//	int sol=a[pre].num;
//	ans+=sol*s;
//	for(int i=pre+1;i<=n;i++){
//		ans+=(a[i].num-sol)*a[i].v;
//	}
//	cout<<ans;
//	return 0;
//}
//01trie
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//vector<int> g[200005],t[200005];
//int n,m;
//int gn[200005],tn[200005];
//unordered_map<int,int> ma[200005];
//void init(int r,int fa){
//	for(int i:g[r]){
//		if(i==fa) continue;
//		ma[r][gn[i]]=i;
//		init(i,r);
//	}
//}
//int solve(int r,int fa,int ot){
//	int ans=0;
//	for(int i:t[r]){
//		if(i==fa) continue;
//		if(ma[ot][tn[i]]){
//			ans=max(ans,solve(i,r,ma[ot][tn[i]])+1);
//		}
//	}
//	return ans;	
//}
//signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>gn[i];
//	}	
//	for(int i=1;i<=m;i++){
//		cin>>tn[i];
//	}
//	for(int i=1;i<=n-1;i++){
//		int a,b;
//		cin>>a>>b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	for(int i=1;i<=m-1;i++){
//		int a,b;
//		cin>>a>>b;
//		t[a].push_back(b);
//		t[b].push_back(a);
//	}
//	init(1,0);
//	if(gn[1]==tn[1]) cout<<solve(1,0,1)+1;
//	else cout<<0;
//	return 0;
//}
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[100005];
//int n,k,c;
//bool check(int x){
//	int b[100005];
//	for(int i=1;i<=x;i++){
//		b[i]=a[i];
//	}
//	sort(b+1,b+x+1);
//	int sum1[100005]={0},sum2[100005]={0};
//	for(int i=1;i<=x;i++){
//		sum1[i]=sum1[i-1]+b[i];
//		sum2[i]=sum2[i-1]+b[i]*b[i];
//	}
//	double ans=1e300;
//	for(int i=k;i<=x;i++){
//		ans=min(ans,1.00*1ll*(sum1[i]-sum1[i-k])/k*1.00*(sum1[i]-sum1[i-k])/k+1ll*(sum2[i]-sum2[i-k]-1ll*2*(1.00*sum1[i]-sum1[i-k])/k*(1.00*sum1[i]-sum1[i-k]))/k);
//	}
//	return ans<c;
//}
//signed main(){
//	cin>>n>>k>>c;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	int l=k,r=n,ans=-1;
//	while(l<r){
//		int mid=(l+r)/2;
//		if(check(mid)){
//			r=mid;
//			ans=mid;
//		}
//		else{
//			l=mid+1;
//		}
//	}
//	cout<<ans;	
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int ans=0;
//    for(long long i=1;i<=100000000;i++){
//		string s=to_string(i);
//		int len=s.size();
//		if(len%2==1){
//			continue;
//		}
//		int sum1=0,sum2=0;
//		for(long long j=0,u=len-1;j<u;j++,u--){
//			sum1+=s[j]-'0';
//			sum2+=s[u]-'0';
//		}
//		if(sum1==sum2) ans++;
//	}
//	cout<<ans;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//long long ans=0;
//void dfs(int soc,int cnt){
//	if(cnt>30||soc==100){
//		return;
//	}
//	if(soc==70){
//		ans++;
//	}
//	dfs(soc+10,cnt+1);
//	dfs(0,cnt+1);
//}
//int main(){
//	dfs(0,0);
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<math.h>
//using namespace std;
//long long ans=0;
//int main(){
//	int l,r;
//	cin>>l>>r;
//	int st=0,ed=0;
//	int f=1;
//	for(int i=1;;i++){
//		if(f&&i*i>=l){
//			st=i;
//			f=0;
//		}
//		if((i+1)*(i+1)-i*i>r){
//			ed=i;
//			break;
//		}
//	}
//	for(int i=st;i<=ed;i++){
//		for(int j=0;j<=i;j++){
//			long long sum=i*i-j*j;
//			if(sum>=l&&sum<=r){
//				ans++;
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef long long ll;
//ll dp[5005][5005];
//bool f[5005][5005]={false};
//int a[5005];
//int main(){
//	string s;
//	cin>>s;
//	int len=s.size();
//	for(int i=0;i<len;i++){
//		int idx=i+1;
//		a[idx]=s[i]-'0';
//		dp[idx][idx]=0;
//		f[idx][idx]=false;
//	}
//	for(int k=2;k<=len;k++){
//		for(int i=1,j=i+k-1;j<=len;i++,j++){
//			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
//			if(a[i]>a[j]){
//				dp[i][j]++;
//				f[i][j]=true;
//			}
//			else if(a[i]==a[j]){
//				if(f[i+1][j-1]){
//					dp[i][j]++;
//				}
//				f[i][j]=f[i+1][j-1];
//			}
//			else{
//				f[i][j]=false;	
//			}
//		}
//	}
//	cout<<dp[1][len];
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 2e5 + 5;
//const int MAXC = 2e5 + 5;
//
//int n;
//vector<int> g[MAXN];
//int color[MAXN];        // C[i]
//int sz[MAXN], son[MAXN];
//int cntColor[MAXC];     // 每种颜色的出现次数
//int cntTimes[MAXN];     // cntTimes[x] = 出现次数为 x 的颜色数量
//int maxCnt = 0;         // 当前子树中最大的出现次数
//int totalColor = 0;     // 当前子树中不同颜色的数量
//int ans = 0;
//
//// 第一次 DFS：求子树大小和重儿子
//void dfsSize(int u) {
//    sz[u] = 1;
//    son[u] = 0;
//    int maxSon = 0;
//    for (int v : g[u]) {
//        dfsSize(v);
//        sz[u] += sz[v];
//        if (sz[v] > maxSon) {
//            maxSon = sz[v];
//            son[u] = v;
//        }
//    }
//}
//
//// 添加节点 u 的颜色到统计中
//void add(int u) {
//    int c = color[u];
//    // 旧出现次数
//    int oldCnt = cntColor[c];
//    if (oldCnt > 0) {
//        cntTimes[oldCnt]--;
//    }
//    cntColor[c]++;
//    int newCnt = cntColor[c];
//    cntTimes[newCnt]++;
//    
//    if (newCnt > maxCnt) maxCnt = newCnt;
//    if (oldCnt == 0) totalColor++;  // 新颜色出现
//}
//
//// 删除节点 u 的颜色（只用于清空轻儿子时）
//void del(int u) {
//    int c = color[u];
//    int oldCnt = cntColor[c];
//    cntTimes[oldCnt]--;
//    cntColor[c]--;
//    int newCnt = cntColor[c];
//    if (newCnt > 0) {
//        cntTimes[newCnt]++;
//    }
//    if (oldCnt == maxCnt && cntTimes[oldCnt] == 0) maxCnt--;
//    if (oldCnt == 1) totalColor--;
//}
//
//// 递归添加或删除一棵子树
//void operateSubtree(int u, bool isAdd) {
//    if (isAdd) add(u);
//    else del(u);
//    for (int v : g[u]) {
//        operateSubtree(v, isAdd);
//    }
//}
//
//// DSU on tree
//void dfs(int u, bool keep) {
//    // 先处理轻儿子
//    for (int v : g[u]) {
//        if (v == son[u]) continue;
//        dfs(v, false);
//    }
//    // 处理重儿子（保留数据）
//    if (son[u]) {
//        dfs(son[u], true);
//    }
//    // 加入当前节点 u 和所有轻儿子
//    add(u);
//    for (int v : g[u]) {
//        if (v == son[u]) continue;
//        operateSubtree(v, true);   // 加入轻儿子子树
//    }
//    
//    // 判断以 u 为根的子树是否颜色平衡
//    if (maxCnt * totalColor == sz[u]) {
//        ans++;
//    }
//    
//    // 如果不保留（keep==false），则清空当前子树信息
//    if (!keep) {
//        operateSubtree(u, false);
//        maxCnt = 0;
//        totalColor = 0;
//    }
//}
//
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        int fa;
//        cin >> color[i] >> fa;
//        if (fa != 0) {
//            g[fa].push_back(i);
//        }
//    }
//    
//    dfsSize(1);
//    dfs(1, true);
//    cout << ans << endl;
//    
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//long long n,m,x;
//long long a[5005],b[5005];
//long long dp[5005];
//int main(){
//    memset(dp,0x3f,sizeof(dp));
//    cin>>n>>m>>x;
//    for(int i=1;i<=m;i++){
//        cin>>a[i]>>b[i];
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            dp[i]=min(dp[i],a[j]*i+i*(i-1)/2*b[j]+x);
//        }
//    }
//    for(int i=2;i<=n;i++){
//        for(int j=1;j<i;j++){
//            dp[i]=min(dp[i],dp[j]+dp[i-j]);
//        }
//    }
//    cout<<dp[n]-x;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int q;
//
//int main(){
//    cin>>q;
//
//    while(q--){
//        int cnt=0;
//        int n,c,k;
//        cin>>n>>c>>k;
//        if(k%c!=0){
//            cout<<-1<<endl;
//            continue;
//        }
//        int num=k/c;
//        while(num!=0){
//            ++cnt;
//            for(int i=1;i<=n;i++){
//                long long sum=n*(n+1)/2;
//                if(sum==num){
//                    num=0;
//                    break;
//                }
//                else if(sum>num){
//                    num-=n*(n-1)/2;
//                    break;
//                }
//            }        
//        }
//        cout<<cnt<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int a[105];
//int n;
//int dep[105];
//int fa[105];
//int b[105];
//int main(){
//	memset(b,0,sizeof(b));
//	int mx=0;
//	cin>>n;
//	dep[1]=1;
//	a[1]=1;
//	fa[1]=0;
//	for(int i=1;i<n;i++){
//		int a1,b;
//		cin>>a1>>b;
//		dep[b]=dep[a1]+1;
//		a[dep[b]]++;
//		fa[b]=a1;
//	}
//	int st,ed;
//	cin>>st>>ed;
//	int mxh=0,mxb=0;
//	for(int i=1;i<n;i++){
//		mxh=max(dep[i],mxh);
//		mxb=max(a[i],mxb);
//	}
//	cout<<mxh<<endl<<mxb<<endl;
//	int t=st;
//	while(t){
//		b[t]=1;
//		t=fa[t];
//	}
//	t=ed;
//	int f=1;
//	while(t){
//		if(b[t]){
//			f=t;
//			break;
//		}
//		t=fa[t];
//	}
//	
//	cout<<(dep[st]-dep[f])*2+dep[ed]-dep[f]<<endl;
//	return 0;
//}
//用深度做lca
//int getlca(int x,int y)
//{
//	while(x!=y)
//	{
//		if(de[x]>=de[y])
//		{
//			x=fa[x];
//		}
//		else
//		y=fa[y];
//	}
//	return x;
//}
//#include<iostream>
//using namespace std;
//string a,b;
//void solve(int l1,int r1,int l2,int r2){
//	if(l1>r1){
//		return;
//	}
//	if(l1==r1){
//		cout<<a[l1];
//		return;
//	}
//	char r=b[l2];
//	int idx=a.find(r);
//	solve(l1,idx-1,l2+1,l2+idx-l1);
//	solve(idx+1,r1,l2+idx-l1+1,r2);
//	cout<<r;
//}
//
//int main(){
//	cin>>a>>b;
//	int len1=a.size()-1;
//	int len2=b.size()-1;
//	solve(0,len1,0,len2);
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<queue>
//using namespace std;
//int n,m;
//const long long mod=80112002;
//queue<int> q;
//vector<int> g[5005];
//int bk[5005];
//int fa[5005],son[5005];
//long long dp[5005];
//void bfs(int st){
//	q.push(st);
//	while(!q.empty()){
//		int idx=q.front();
//		q.pop();
//		if(g[idx].empty()){
//			continue;
//		}
//		for(int i:g[idx]){
//			dp[i]=(dp[i]+dp[idx])%mod;
//			bk[i]--;
//			if(!bk[i]){
//				q.push(i);
//			}
//		}
//	}
//}
//int main(){
//	memset(bk,0,sizeof(bk));
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		int a,b;
//		cin>>a>>b;
//		g[b].push_back(a);
//		bk[a]++;
//	}
//	int idx1=0,idx2=0;
//	for(int i=1;i<=n;i++){
//		if(g[i].empty()){
//			son[++idx1]=i;
//		}
//		if(!bk[i]){
//			fa[++idx2]=i;
//		}
//	}
//	for(int i=1;i<=idx2;i++){
//		dp[fa[i]]=1;
//		bfs(fa[i]);
//	}
//	long long ans=0;
//	for(int i=1;i<=idx1;i++){
//		ans=(ans+dp[son[i]])%mod;
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n;
//long long dp[35][35];
//int p[35][35];
//void dfs(int l,int r){
//	if(l>r){
//		return;
//	}
//	int root=p[l][r];
//	cout<<root<<" ";
//	dfs(l,root-1);
//	dfs(root+1,r);
//}
//int main(){
//	memset(dp,0,sizeof(dp));
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>dp[i][i];
//		p[i][i]=i;
//	}
//	for(int k=2;k<=n;k++){
//		for(int i=1;i<=n-k+1;i++){
//			int l=i,r=i+k-1;
//			for(int j=l;j<=r;j++){
//				if(j==l){
//					dp[l][r]=dp[l][l]+dp[l+1][r];
//					p[l][r]=j;
//				}
//				else if(j==r){
//					if(dp[l][r]<dp[r][r]+dp[l][r-1]){
//						dp[l][r]=dp[r][r]+dp[l][r-1];
//						p[l][r]=j;
//					}			
//				}
//				else{
//					if(dp[l][r]<dp[l][j-1]*dp[j+1][r]+dp[j][j]){
//						dp[l][r]=dp[l][j-1]*dp[j+1][r]+dp[j][j];
//						p[l][r]=j;
//					}					
//				}
//			}
//		}
//	}
//	cout<<dp[1][n]<<endl;
//	dfs(1,n);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int q;
//int main(){
//    cin>>q;
//    while(q--){
//        long long n,k,m;
//        cin>>n>>m>>k;
//        if(!(n%k)){
//			cout<<0<<endl;
//			continue;
//		}
//        long long c=(k-n%k)+1;
//        if(m>=c){
//            cout<<0<<endl;
//        }
//        else{
//            if(m){
//                cout<<n%k<<endl;
//            }
//            else{
//                cout<<n<<endl;
//            }
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main(){
//	int q;
//	cin>>q;
//	while(q--){
//		int n,m,k;
//		cin>>n>>m>>k;
//		while(k--){
//			if(n-m<=0){
//				n=0;
//				break;
//			}
//			n=n&max(n-m,0);
//			if(!n){
//				break;
//			}
//		}
//		cout<<n<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#define int long long
//using namespace std;
//const int mod=1000000007;
//class matrix{
//public:
//	int a[3][3];
//	matrix(){
//		memset(a,0,sizeof(a));
//	}
//	matrix operator *(const matrix& b) const{
//		matrix c;
//		for(int i=1;i<=2;i++){
//			for(int j=1;j<=2;j++){
//				for(int u=1;u<=2;u++){
//					c.a[i][j]+=a[i][u]*b.a[u][j];
//				}
//			}
//		}
//		return c;
//	}
//}ans,q;
//void init(){
//	ans.a[1][1]=ans.a[1][2]=1;
//	q.a[1][1]=q.a[1][2]=q.a[2][1]=1;
//}
//void qpow(int n){
//	while(n){
//		if(n&1){
//			ans=ans*q;
//		}
//		q=q*q;
//		n>>=1;
//	}
//}
//int main(){
//	int n;
//	cin>>n;
//	if(n<=2){
//		cout<<1;
//	}
//	else{
//		init();
//		qpow(n-2);
//		cout<<ans.a[1][1]%mod;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person{
//public:
//	string name;
//	int age;
//	person(string n,int a):name(n),age(a){}
//	void sleep(){
//		cout<<name<<"is sleeping";
//	}
//	void learn(){
//		cout<<name<<"is learning";
//	}
//};
//class student:person{
//public:
//	student(string n,int a):person(n,a){}
//	void play(){
//		cout<<name<<"is playing";
//	}
//};
//class teacher:public person{
//public:
//	string title;
//	teacher(string n,int a,string t):person(n,a),title(t){}
//	void teach(string b){
//		cout<<name<<"is teaching"<<b;
//	}	
//};
//int main(){
//	teacher t("hhh",33,"111");
//	cout<<t.age<<endl;
//	t.teach("222");
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int q;
//struct node{
//	int a,b,c;
//	int t1,t2;
//};
//node stu[1005];
//bool cmp(node a,node b){
//	if(a.t1==b.t1){
//		return a.t2<b.t2;
//	}
//	return a.t1<b.t1;
//}
//int main(){
//	cin>>q;
//	for(int i=1;i<=q;i++){
//		cin>>stu[i].a>>stu[i].b>>stu[i].c;
//		stu[i].t2=stu[i].a+stu[i].b;
//		stu[i].t1=stu[i].t2+stu[i].c;
//	}
//	sort(stu+1,stu+q+1,cmp);
//	long long ans=0;
//	for(int i=1;i<=q;i++){
//		ans+=stu[i].t2;
//		ans+=stu[i].t1*(q-i);
//	}
//	cout<<ans;
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std ;
//int n , d ;
//double ans = DBL_MAX , x[25] , y[25] , dp[1 << 20][25] , dis[25][25] ;
//bool vis[25] ;
//double jl(int a , int b)
//{
//	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])) ;
//}
//int main()
//{
//	memset(dp , 0x7f , sizeof dp) ;
//	memset(dis , 0x7f , sizeof dis) ;
//	cin >> n >> d ;
//	for(int i = 0 ; i < n ; i++)	cin >> x[i] >> y[i] ;
//	for(int i = 0 ; i < n ; i++)	for(int j = 0 ; j < n ; j++)	if(jl(i , j) <= d)	dis[i][j] = jl(i , j) ;
//	for(int i = 0 ; i < n ; i++)
//		for(int j = 0 ; j < n ; j++)
//			for(int k = 0 ; k < n ; k++)
//				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]) ;
//	dp[1][0] = 0 ;
//	for(int i = 1 ; i < (1 << n) ; i++)
//	{
//		for(int j = 0 ; j < n ; j++)
//		{
//			if(!((i >> j) & 1))	continue ;
//			int tmp = i ^ (1 << j) ;
//			for(int k = 0 ; k < n ; k++)
//			{
//				if(!((tmp >> k) & 1))	continue ;
//				dp[i][j] = min(dp[i][j] , dp[tmp][k] + dis[j][k]) ;
//			}
//		}
//	}
//	for(int i = 1 ; i < n ; i++)
//		ans = min(ans , dp[(1 << n) - 1][i] + dis[i][0]) ;
//	printf("%.2lf" , ans) ;
//	return 0 ;
//}
//#include <bits/stdc++.h>
//using namespace std;
//const long long MOD = 998244353;
//signed main() {
//    long long n, m, k;
//    cin >> n >> m >> k;
//    unordered_map<long long, long long> cnt; // key为冰山体积，value为该体积的冰山数量
//    for (long long i = 0; i < n; ++i) {
//        long long v;
//        cin >> v;
//        cnt[v]++;
//    }
//    while (m--) {
//        long long x, y;
//        cin >> x >> y;
//        unordered_map<long long, long long> newcnt; // 存储处理后的冰山状态
//        for (auto& [u, v] : cnt) {//map遍历可用元组或auto& i然后i.first/i.second:c11
//        	long long t = u + x;
//            if (t <= 0) {
//                continue; 
//            }
//            if (t <= k) {
//                newcnt[t] += v; 
//            } 
//            else {
//                newcnt[k] += v;
//                newcnt[k] %= MOD;
//                newcnt[1] += (v * ((t - k) % MOD)) % MOD;
//            }
//        }
//        if (y > 0) {
//            newcnt[y]++;
//        }
//        cnt = newcnt;
//        long long sum = 0;
//        for (auto& [u, v] : newcnt) {
//            sum = (sum + (u % MOD) * (v % MOD) % MOD) % MOD; 
//        }
//        cout << sum << '\n';
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//unordered_set<int> s,ans;
//int main(){
//    int n,q;
//    cin>>n>>q;
//    int mx=0;
//    for(int i=1;i<=n;i++){
//        int t;
//        cin>>t;
//        mx=max(mx,t);
//        if(!s.count(t)){
//            s.insert(t);
//        }
//        else{
//            ans.insert(1);
//        }
//    }
//    for(int i:s){
//        for(int j=2;i*j<=mx;j++){
//            if(s.count(i*j)){
//                ans.insert(j);
//            }
//        }
//    }
//    while(q--){
//        int t;
//        cin>>t;
//        if(ans.count(t)){
//            cout<<"YES"<<endl;
//        }
//        else{
//            cout<<"NO"<<endl;
//        }
//    }
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    
//    // 找出所有错误连续段
//    vector<pair<int, int>> segments;
//    int i = 0;
//    while (i < n) {
//        if (a[i] != i + 1) {
//            int l = i;
//            while (i < n && a[i] != i + 1) {
//                i++;
//            }
//            int r = i - 1;
//            segments.push_back({l, r});
//        } else {
//            i++;
//        }
//    }
//    
//    // 情况1: 已经有序
//    if (segments.empty()) {
//        cout << "Yes\n";
//        return;
//    }
//    
//    // 情况2: 错误段超过2个
//    if (segments.size() > 2) {
//        cout << "No\n";
//        return;
//    }
//    
//    // 情况3: 只有1个错误段
//    if (segments.size() == 1) {
//        // 只有一个错误段时，无法通过一次交换两个区间变成有序
//        cout << "No\n";
//        return;
//    }
//    
//    // 情况4: 恰好2个错误段
//    int l1 = segments[0].first, r1 = segments[0].second;
//    int l2 = segments[1].first, r2 = segments[1].second;
//    
//    // 检查中间部分是否全都正确
//    bool ok = true;
//    for (int i = r1 + 1; i < l2; i++) {
//        if (a[i] != i + 1) {
//            ok = false;
//            break;
//        }
//    }
//    
//    if (!ok) {
//        cout << "No\n";
//        return;
//    }
//    
//    // 检查两个段长度是否相等
//    int len1 = r1 - l1 + 1;
//    int len2 = r2 - l2 + 1;
//    if (len1 != len2) {
//        cout << "No\n";
//        return;
//    }
//    
//    // 检查交换后能否正确
//    for (int k = 0; k < len1; k++) {
//        if (a[l1 + k] != l2 + 1 + k) {  // 需要 l1+k 位置得到 l2+1+k
//            ok = false;
//            break;
//        }
//        if (a[l2 + k] != l1 + 1 + k) {  // 需要 l2+k 位置得到 l1+1+k
//            ok = false;
//            break;
//        }
//    }
//    
//    cout << (ok ? "Yes\n" : "No\n");
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    int T;
//    cin >> T;
//    while (T--) {
//        solve();
//    }
//    
//    return 0;
//}
//string题
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//bool cmp(char a,char b){
//    return a<b;
//}
//int main(){
//    string s;
//    cin>>s;
//    int len=s.size();
//    sort(s.begin(),s.end(),cmp);
//    size_t idx=s.find('u');
//    size_t idx1=s.find('f');
//    if(idx==string::npos||s[len-1]!='z'||idx1==string::npos){
//        cout<<s;
//    }
//    else{
//        int cnt=0;
//        while(s[idx+cnt]=='u'){
//            cnt++;
//        }
//        string s1=s.substr(0,idx);
//        string s2=s.substr(idx+cnt,len);
//        cout<<s1+s2;
//        for(int i=1;i<=cnt;i++){
//            cout<<'u';
//        }
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//const long long mod=998244353;
//const int mx=300010;
//vector<int> g[mx];
//long long dp[mx][3];
//int qpow(long long d,long long m){
//	d=d%mod;
//	long long res=1;
//	while(m){
//		if(m&1){
//			res=1ll*res*d%mod;
//		}
//		d=1ll*d*d%mod;
//		m>>=1;
//	}
//	return res;
//}
//long long inv(long long x){
//	return qpow(x,mod-2);
//}
//void dfs(int x,int r){
//	dp[x][0]=1;
//	dp[x][2]=1;
//	dp[x][1]=0;
//	int res1=1;
//	for(auto i:g[x]){
//		if(i==r) continue;
//		dfs(i,x);
//		dp[x][0]=dp[i][2]*dp[x][0]%mod;
//		dp[x][2]=(dp[i][1]+dp[i][2])*dp[x][2]%mod;
//		res1=res1*(dp[i][1]+dp[i][2])%mod;
//	}
//	int res2=1;
//	for(auto i:g[x]){
//		if(i==r) continue;
//		res1=res1*inv(dp[i][1]+dp[i][2])%mod;
//		dp[x][1]=(dp[x][1]+(dp[i][0]*res1%mod*res2%mod))%mod;
//		res2=res2*(dp[i][1]+dp[i][2])%mod;
//	}
//}
//int main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<n;i++){
//		int a,b;
//		cin>>a>>b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	dfs(1,-1);
//	cout<<(dp[1][0]+dp[1][1]+dp[1][2]-1+mod)%mod;
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<limits.h>
//using namespace std;
//long long n,m;
//struct node{
//	long long a,b;
//};
//node c[200010];
//bool cmp(node a1,node b1){
//	return a1.a<b1.a;
//}
//bool check(int x){
//	long long sum=0;
//	for(int i=1;i<=n;i++){
//		sum+=x-c[i].a;
//		if(sum>m){
//			return false;
//		}
//	}
//	return true;
//}
//int main(){
//	
//	cin>>n>>m;
//	long long l,r;
//	l=r=INT_MAX;
//	for(int i=1;i<=n;i++){
//		cin>>c[i].a;
//		l=min(l,c[i].a);
//	}
//	for(int i=1;i<=n;i++){
//		cin>>c[i].b;
//		r=min(r,c[i].a+c[i].b);
//	}
//	sort(c+1,c+n+1,cmp);
//	while(l<r){
//		int m=(l+r+1)/2;
//		if(check(m)){
//			l=m;
//		}
//		else{
//			r=m-1;
//		}
//	}
//	cout<<r;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//using namespace std;
//vector<int> g[1005];
//int val[1005][1005];
//int w[1005];
//int n,m;
//int dist[1005];
//int v[1005];
//void bfs(){
//    while(1){
//        int idx;
//        int mi=0x3f3f3f3f;
//        for(int i=1;i<=n;i++){
//            if(v[i]) continue;
//            if(dist[i]<mi){
//                mi=dist[i];
//                idx=i;
//            }
//        }
//        if(idx==n){
//            break;
//        }
//        v[idx]=1;
//        for(int i:g[idx]){
//            if(dist[i]>dist[idx]+val[idx][i]){
//                dist[i]=dist[idx]+val[idx][i];
//            }
//        }
//    }
//    cout<<dist[n]-w[n];
//}
//int main(){
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>w[i];
//    }
//    for(int i=1;i<=m;i++){
//        int a,b,v;
//        cin>>a>>b>>v;
//        g[a].push_back(b);
//        g[b].push_back(a);
//        val[a][b]=val[b][a]=v;
//        val[a][b]+=w[b];
//        val[b][a]+=w[a];
//    }
//    memset(dist,0x3f,sizeof(dist));
//    for(int i:g[1]){
//        dist[i]=val[1][i];
//    }
//    memset(v,0,sizeof(v));
//    v[1]=1;
//    bfs();
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n,m;
//double a[45],b[45][25];
//bool v[45];
//int c[25];
//struct node{
//	int idx;
//	double p;
//};
//node ans[45];
//bool cmp(node a,node b){
//	if(a.p==b.p){
//		return a.idx<b.idx;
//	}
//	return a.p>b.p;
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin>>b[i][j];
//		}
//	}
//	int q;
//	cin>>q;
//	memset(v,false,sizeof(v));
//	memset(c,0,sizeof(c));
//	for(int i=1;i<=q;i++){
//		int w;
//		cin>>w;
//		c[w]=1;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(c[j]&&!b[i][j]){
//				a[i]=0.00;
//				v[i]=true;
//				break;			
//			}
//			else if(b[i][j]){
//				if(c[j]){
//					a[i]=a[i]*b[i][j]/100;
//				}
//				else{
//					a[i]=a[i]*(100-b[i][j])/100;
//				}
//			}
//		}
//		if(v[i]){
//			continue;
//		}
//	}
//	double sum=0;
//	for(int i=1;i<=n;i++){
//		if(v[i]) continue;
//		sum+=a[i];
//	}
//	for(int i=1;i<=n;i++){
//		ans[i].idx=i;
//		ans[i].p=a[i]/sum*100;
//	}
//	sort(ans+1,ans+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<ans[i].idx<<" ";
//		printf("%.2lf\n",ans[i].p);
//	}	
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int q;
//int a[200005];
//int main(){
//	cin>>q;
//	while(q--){
//		int n;
//		cin>>n;
//		a[0]=0;
//        int idx[3];
//        map<long long,bool> m;
//        int c=0;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//			a[i]^=a[i-1];
//			if(m[a[i]]){
//				continue;
//			}
//            if(a[i]&&c<2){
//                idx[++c]=i;
//                m[a[i]]=true;
//            }
//		} 
//		if(a[n]){
//            cout<<"Yes"<<endl;
//            cout<<2<<endl;
//            cout<<1<<" "<<1<<endl;
//            cout<<2<<" "<<n<<endl;			
//		}
//		else{
//			if(c<2){
//				cout<<"No"<<endl;
//				continue;
//			}
//            else{
//                cout<<"Yes"<<endl;
//                cout<<3<<endl;
//                cout<<1<<" "<<idx[1]<<endl;
//                cout<<idx[1]+1<<" "<<idx[2]<<endl;
//                cout<<idx[2]+1<<" "<<n<<endl;
//            }
//		}
//	}
//	return 0;
//} 
//树上前缀和
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//vector<int> g[100010];
//int n,m;
//int b[100010];
//int p[100010];
//int d[100010];
//map<pair<int,int>,int> mm;
//void dfs(int x,int r,int dep){
//	p[x]=r;
//	d[x]=dep;
//	b[x]=g[x].size()+b[r];
//	for(int i:g[x]){
//		if(i==r) continue;
//		dfs(i,x,dep+1);
//	}
//}
//int lca(int x,int y){
//	if(x==y){
//		return x;
//	}
//	if(d[x]>=d[y]){
//		lca(p[x],y);
//	}
//	return x;
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<n;i++){
//		int a,b;
//		cin>>a>>b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	b[0]=0;
//	dfs(1,0,1);
//	while(m--){
//		int x,y;
//		cin>>x>>y;
//		if(x==y){
//			cout<<g[x].size()<<endl;
//		}
//		else{
//			int r=lca(x,y);
//			cout<<b[x]+b[y]-2*b[r]+g[r].size()<<endl;		
//		}
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//const long long mod=1000000007;
//long long ans=0;
//void dfs(int l,int ml,int mr,int r){
//  if(l+1==ml&&mr+1==r){
//      ans=(ans+1)%mod;
//      return;
//  }
//  if(l+1<ml){
//    dfs(l+1,ml,mr,r);
//    dfs(l,ml-1,mr,r);
//  }
//  if(ml+1<mr){
//    dfs(l,ml,mr-1,r);
//    dfs(l,ml+1,mr,r);    
//  }
//  if(mr+1<r){
//    dfs(l,ml,mr+1,r);
//    dfs(l,ml,mr,r-1);    
//  }  
//}
//int main()
//{
//  for(int i=2;i<=2024;i++){
//    dfs(1,i,i,2025);
//  }
//  cout<<ans;
//  return 0;
//}

//tuple
//#include <iostream>
//#include <cstring>
//#include <set>
//#include <algorithm>
//#include <tuple>
//using namespace std;
//
//bool used[8];
//int cards[8] = {0,0,2,2,5,5,1,6};
//set<tuple<int,int,int>> triangles;
//
//void dfs(int a, int b, int c, int idx) {
//    if (a && b && c ) {
//        if ( a+b>c && a+c>b && b+c>a) {
//            int x = min({a,b,c});
//            int z = max({a,b,c});
//            int y = a+b+c - x - z;
//            triangles.insert({x,y,z});
//        }
//        if(idx==8){
//			return;
//		}
//    }
//    for (int i = 0; i < 8; i++) {
//        if (used[i]) continue;
//        used[i] = true;
//        dfs(a*10 + cards[i], b, c, idx+1);
//        dfs(a, b*10 + cards[i], c, idx+1);
//        dfs(a, b, c*10 + cards[i], idx+1);
//        used[i] = false;
//    }
//}
//int main() {
//    sort(cards, cards+8);
//    memset(used, 0, sizeof(used));
//    dfs(0,0,0,0);
//    cout << triangles.size() << endl;
//    return 0;
//}
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int sum[1000010];
//bool v[1000010];
//int main()
//{
//  memset(sum,0,sizeof(sum));
//  memset(v,false,sizeof(v));
//  int n;
//  cin>>n;
//  int pre=-1;
//  int mx=-1;
//  int last;
//  for(int i=1;i<=n;i++){
//    int t;
//    cin>>t;
//    v[t]=true;
//    mx=max(t,mx);
//    if(i!=1&&pre!=t){
//      sum[t]+=t;
//    }
//    pre=t;
//    if(i==n){
//      last=t;
//    }
//  }
//  int ans=0x3f3f3f3f;
//  for(int i=1;i<=mx;i++){
//    if(i!=last&&v[i]){
//      sum[i]+=i;
//      ans=min(ans,sum[i]);
//    }
//  }
//  ans=min(ans,sum[last]);
//  cout<<ans;
//  return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN = 5e5 + 10;
//const int MOD = 6;  // 2和3的最小公倍数，核心优化点
//
//// 保留我原始的线段树节点结构，扩展为模6分组
//struct SegNode {
//    int l, r;
//    int cnt[MOD];    // 每个模6分组的1的数量（替代原单一cnt）
//    int len[MOD];    // 每个模6分组的元素个数（新增）
//    int sta;         // 6位二进制懒标记：第i位=1表示模6=i的分组需要翻转（替代原多bool标记）
//} tree[4 * MAXN];
//
//int coin[MAXN];  // 保留原始硬币数组（1-based）
//int a[3];        // 临时存储步长对应的模6分组
//
//// 保留我原始的函数命名
//inline int ls(int idx) { return idx << 1; }
//inline int rs(int idx) { return idx << 1 | 1; }
//
//// 新增：计算1~x中模6=t的数的个数（公式化，替代遍历）
//int get_mod_count(int x, int t) {
//    if (t == 0) return x / MOD;
//    return x / MOD + (x % MOD >= t ? 1 : 0);
//}
//
//// 新增：计算[L,R]中模6=t的数的个数
//int get_range_mod_count(int L, int R, int t) {
//    return get_mod_count(R, t) - get_mod_count(L - 1, t);
//}
//
//// 修正pushup：合并模6分组的cnt和len
//void push_up(int idx) {
//    for (int i = 0; i < MOD; ++i) {
//        tree[idx].cnt[i] = tree[ls(idx)].cnt[i] + tree[rs(idx)].cnt[i];
//        tree[idx].len[i] = tree[ls(idx)].len[i] + tree[rs(idx)].len[i];
//    }
//}
//
//// 修正build：初始化模6分组的cnt和len
//void build(int idx, int l, int r) {
//    tree[idx].l = l;
//    tree[idx].r = r;
//    tree[idx].sta = 0;
//    memset(tree[idx].cnt, 0, sizeof(tree[idx].cnt));
//    memset(tree[idx].len, 0, sizeof(tree[idx].len));
//
//    if (l == r) {
//        // 保留原始的coin数组赋值逻辑
//        int mod = l % MOD;
//        tree[idx].cnt[mod] = coin[l];  // coin[l]是0/1，直接赋值
//        tree[idx].len[mod] = 1;        // 单个节点，对应模分组长度为1
//        return;
//    }
//
//    int mid = (l + r) / 2;
//    build(ls(idx), l, mid);
//    build(rs(idx), mid + 1, r);
//    push_up(idx);
//}
//
//// 新增：添加翻转标记（整合操作1/2/3的翻转逻辑）
//void add_tag(int idx, int op, int L) {
//    int pl = tree[idx].l;
//    int pr = tree[idx].r;
//
//    if (op == 3) {  // 操作3：全翻转，所有模6分组
//        for (int i = 0; i < MOD; ++i) {
//            if (get_range_mod_count(pl, pr, i) == 0) continue;
//            tree[idx].sta ^= (1 << i);  // 位运算标记翻转
//            tree[idx].cnt[i] = tree[idx].len[i] - tree[idx].cnt[i];
//        }
//    } else if (op == 1 || op == 2) {  // 操作1/2：步长翻转，对应模6分组
//        bool is_valid[3] = {false, false, false};
//        if (op == 1) {  // 步长2 → 模6分组：L%6, L%6+2, L%6+4
//            a[0] = L % MOD;
//            a[1] = (a[0] + 2) % MOD;
//            a[2] = (a[1] + 2) % MOD;
//            is_valid[0] = (get_range_mod_count(pl, pr, a[0]) != 0);
//            is_valid[1] = (get_range_mod_count(pl, pr, a[1]) != 0);
//            is_valid[2] = (get_range_mod_count(pl, pr, a[2]) != 0);
//        } else {  // 步长3 → 模6分组：L%6, L%6+3
//            a[0] = L % MOD;
//            a[1] = (a[0] + 3) % MOD;
//            is_valid[0] = (get_range_mod_count(pl, pr, a[0]) != 0);
//            is_valid[1] = (get_range_mod_count(pl, pr, a[1]) != 0);
//            is_valid[2] = false;
//        }
//
//        // 翻转对应模6分组
//        for (int i = 0; i < 3; ++i) {
//            if (!is_valid[i]) continue;
//            tree[idx].sta ^= (1 << a[i]);
//            tree[idx].cnt[a[i]] = tree[idx].len[a[i]] - tree[idx].cnt[a[i]];
//        }
//    }
//}
//
//// 修正push_down：位运算下传模6分组的翻转标记
//void push_down(int idx) {
//    if (tree[idx].sta == 0) return;
//
//    // 遍历6个模分组，批量下传翻转
//    for (int i = 0; i < MOD; ++i) {
//        if ((tree[idx].sta >> i) & 1) {
//            tree[ls(idx)].cnt[i] = tree[ls(idx)].len[i] - tree[ls(idx)].cnt[i];
//            tree[rs(idx)].cnt[i] = tree[rs(idx)].len[i] - tree[rs(idx)].cnt[i];
//        }
//    }
//
//    // 传递标记（异或）
//    tree[ls(idx)].sta ^= tree[idx].sta;
//    tree[rs(idx)].sta ^= tree[idx].sta;
//    tree[idx].sta = 0;
//}
//
//// 修正update：整合所有操作的更新逻辑，替换原单点更新
//void update(int idx, int L, int R, int op, int x) {
//    int l = tree[idx].l;
//    int r = tree[idx].r;
//
//    if (L <= l && r <= R) {
//        add_tag(idx, op, x);  // 区间全覆盖，添加标记
//        return;
//    }
//
//    push_down(idx);  // 下传标记
//    int mid = (l + r) / 2;
//    if (L <= mid) update(ls(idx), L, R, op, x);
//    if (R > mid) update(rs(idx), L, R, op, x);
//    push_up(idx);    // 合并更新结果
//}
//
//// 修正query：累加模6分组的cnt，替换原单一cnt查询
//int query(int idx, int L, int R) {
//    int l = tree[idx].l;
//    int r = tree[idx].r;
//
//    if (L <= l && r <= R) {
//        int sum = 0;
//        for (int i = 0; i < MOD; ++i) sum += tree[idx].cnt[i];
//        return sum;
//    }
//
//    push_down(idx);
//    int res = 0;
//    int mid = (l + r) / 2;
//    if (L <= mid) res += query(ls(idx), L, R);
//    if (R > mid) res += query(rs(idx), L, R);
//    return res;
//}
//
//// 保留我原始的main函数结构，仅修正调用逻辑
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n, m;
//    cin >> n >> m;
//
//    // 保留原始的coin数组输入逻辑
//    for (int i = 1; i <= n; ++i) {
//        cin >> coin[i];
//    }
//
//    // 保留原始的线段树构建逻辑
//    build(1, 1, n);
//
//    // 保留原始的操作处理逻辑
//    while (m--) {
//        int op, x, y;
//        cin >> op >> x >> y;
//
//        if (op == 1 || op == 2 || op == 3) {
//            update(1, x, y, op, x);  // 修正为区间更新，替代原单点更新
//        } else if (op == 4) {
//            cout << query(1, x, y) << '\n';  // 保留查询逻辑，替换endl为'\n'加速
//        }
//    }
//
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int a[8]={'s'-97,'h'-97,'a'-97,'n'-97,'g'-97,'i'-97};
//int b[256];
//int main(){
//    memset(b,0,sizeof(b));
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        char t;
//        cin>>t;
//        if(t>97){
//            t=t-'a';
//        }
//        else{
//            t=t-'A';
//        }
//        a[t]++;
//    }
//    int mi=0x3f3f3f3f;
//    for(int i=0;i<=5;i++){
//        if(i==1||i==2){
//            b[a[i]]/=2;
//        }
//        mi=min(b[a[i]],mi);
//    }
//    cout<<mi;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int n,m;
//int b[105][105];
//void solve(int x,int y){
//	int sum=0;
//	int mx=max(max(x-1,n-x),max(y-1,m-y));
//	for(int i=1;i<=mx;i++){
//		
//	}
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=m+1;i++){
//		for(int j=1;j<=n+1;j++){
//			solve(i,j);
//		}
//	}
//	for(int i=1;i<=m+1;i++){
//		for(int j=1;j<=n+1;j++){
//			
//		}
//	}
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//#define int long long
//#define pii pair<int,int>
//
//
//const int N = 5e3+5;
//const int mod = 998244353;
//
//int ans[105][105];
//
//void solve(){
//    int n,m;
//    cin>>n>>m;
//    for(int i=0;i<=n/2;i++){
//        for(int j=0;j<=m/2;j++){
//            int x1=i,x2=n-i,y1=j,y2=m-j;
//            for(int x=0;x<x1;x++){
//                ans[i][j]+=max(min(y1,n-x)-max(0ll,x1-x),0ll);
//                ans[i][j]+=max(min(y2,n-x)-max(0ll,x1-x),0ll);
//            }
//            for(int y=0;y<y1;y++){
//                ans[i][j]+=max(min(x1,m-y)-max(0ll,y1-y),0ll);
//                ans[i][j]+=max(min(x2,m-y)-max(0ll,y1-y),0ll);
//            }
//            ans[i][j]+=(min(x1,y2)+min(x2,y1)+min(y2,x2)+min(x1,y1));
//        }
//    }
//
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            if(i<=n/2){
//                if(j<=m/2)cout<<ans[i][j]<<" ";
//                else cout<<ans[i][m-j]<<" ";
//            }
//            else{
//                if(j<=m/2)cout<<ans[n-i][j]<<" ";
//                else cout<<ans[n-i][m-j]<<" ";
//            }
//        }
//        cout<<"\n";
//    }
//}
//
//
//signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//   // int T;cin >> T;
//   // while (T--) 
//    solve();
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//int c[500010];
//bool v[500010];
//void solve() {
//    int n,m,k;
//    cin >> n >> m >> k;
//    vector<int>fa(n+1,0);
//    fa[1] = -1;
//    for(int i = 1;i <= n;i++){
//        int num;
//        cin >> num;
//        int x;
//        for(int j = 0;j < num;j++){
//            cin >> x;
//            fa[x] = i;
//            c[i]++;
//        }
//    }
//    unordered_map<int,int>p;
//    int x,y;
//    for(int i = 0;i < m;i++){
//        cin >> x >> y;
//        if(v[x]) continue;
//        p[y] = x;
//        v[x]=true;
//    }
//    vector<int>b(k+1,0);
//    for(int i = 1;i <= k;i++){
//        cin >> b[i];
//    }
//    int ans = INT_MAX;
//    for(int i = 1;i <= k;i++){
//        bool flag = true;
//        int cnt = 0;
//        for(int j = b[i];fa[j] != -1;){
//        	if(c[fa[j]]==1){
//        		j=fa[j];
//			}
//            else if(p.find(j) != p.end()){
//                j = p[j];
//                cnt++;
//            }
//            else{
//                flag = false;
//                break;
//            }
//        }
//        if(flag){
//            ans = min(ans,cnt);
//        }
//    }
//    if(ans != INT_MAX)cout << ans << endl;
//    else cout << -1 << endl;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr); 
//    memset(c,0,sizeof(c));
//    memset(v,false,sizeof(v));
//    int t;
//    cin >> t;
//    while(t--)solve();
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//vector<int> g[500010];
//int fa[500010];
//long long dp[500010];
//bool v[500010];
//int n,m,k;
//int main(){
//	int q;
//	cin>>q;
//	while(q--){
//		cin>>n>>m>>k;
//		for(int i=1;i<=n;i++){
//			int num;
//			cin>>num;
//			for(int j=1;j<=num;j++){
//				int to;
//				cin>>to;
//				g[i].push_back(to);
//				fa[to]=i;
//			}
//		}
//		unordered_map<int,int> p;
//		for(int i=1;i<=m;i++){
//			int a,b;
//			cin>>a>>b;
//			p[b]=a;
//		}
//		queue<int> tar;
//		for(int i=1;i<=k;i++){
//			int t;
//			cin>>t;
//			tar.push(t);
//		}
//		while(!tar.empty()){
//			int idx=tar.front();
//			tar.pop();
//			int r=fa[idx];
//			int sum=0;
//			for(int i:g[r]){
//				sum+=dp[i];
//			}
//			dp[r]=min(sum,)			
//		}
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	long long ans=0;
//	int m=0;
//	if(n%2==1){
//		ans=(n/2+1)*(n/2)/2;
//		m=n/2+1;
//	}
//	else{
//		ans=(n/2)*(n/2-1)/2;
//		m/=2;
//	}
//	cout<<ans<<endl;
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<i;j++){
//			cout<<i<<" "<<j<<endl;
//		}
//	}
//	if(n%2==0){
//		m++;
//	}
//	for(int i=m;i<=n;i++){
//		for(int j=m;j<i;j++){
//			cout<<i<<" "<<j<<endl;
//		}
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//
//int n;
//struct node{
//	int p,l,r;
//};
//vector<int> g[200010];
//node buk[200010];
//int tim=0;
//int dfn[200010];
//int low[200010];
//stack<int> st;
//bool v[200010];
//int cnt=0;
//int id[200010];
//
//void tarjan(int x){
//	dfn[x]=low[x]=++tim;
//	st.push(x);
//	v[x]=true;
//	
//	for(auto i:g[x]){
//		if(!dfn[i]){
//			tarjan(i);
//			low[x]=min(low[x],low[i]);
//		}
//		else if(v[i]){
//			low[x]=min(low[x],dfn[i]);
//		}
//	}//总会有回路
//	
//	//实在所有子节点遍历完后再做的判断
//	if(low[x]==dfn[x]){
//		++cnt;
//		int t;
//		do{
//			t=st.top();
//			st.pop();
//			id[t]=cnt;
//			v[t]=false;			
//		}while(t!=x);
//	}	
//}
//
//int main(){
//	//build graph
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		int a,b,c;
//		cin>>a>>b>>c;
//		buk[i]={a,b,c};
//	}
//	sort(buk+1,buk+n+1,[&](node &a,node &b){
//		return a.p<b.p;
//	});
//	for(int i=1;i<=n;i++){
//		int l=buk[i].p-buk[i].l;
//		int r=buk[i].p+buk[i].r;
//		for(int j=i-1;j>=1&&buk[j].p>=l;j--){
//			g[i].push_back(j);
//		}
//		for(int j=i+1;j<=n&&buk[j].p<=r;j++){
//			g[i].push_back(j);
//		}
//	}
//	
//	//tarjan
//	for(int i=1;i<=n;i++){
//		if(!dfn[i]){
//			tarjan(i);
//		}
//	}
//	
//	//judge in_deg(入度)
//	int in_deg[cnt+5];
//	fill(in_deg,in_deg+cnt+5,0);
//	for(int i=1;i<=n;i++){
//		for(int j:g[i]){
//			if(id[j]!=id[i]){
//				in_deg[id[j]]=1;
//			}
//		}
//	}
//	
//	//count
//	int ans=0;
//	for(int i=1;i<=cnt;i++){
//		if(!in_deg[i]){
//			ans++;
//		}
//	}
//	
//	cout<<ans;
//	return 0;
//}



















