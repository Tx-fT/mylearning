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
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
const long long mod=80112002;
queue<int> q;
vector<int> g[5005];
int bk[5005];
int fa[5005],son[5005];
long long dp[5005];
void bfs(int st){
	q.push(st);
	while(!q.empty()){
		int idx=q.front();
		q.pop();
		if(g[idx].empty()){
			continue;
		}
		for(int i:g[idx]){
			dp[i]=(dp[i]+dp[idx])%mod;
			bk[i]--;
			if(!bk[i]){
				q.push(i);
			}
		}
	}
}
int main(){
	memset(bk,0,sizeof(bk));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g[b].push_back(a);
		bk[a]++;
	}
	int idx1=0,idx2=0;
	for(int i=1;i<=n;i++){
		if(g[i].empty()){
			son[++idx1]=i;
		}
		if(!bk[i]){
			fa[++idx2]=i;
		}
	}
	for(int i=1;i<=idx2;i++){
		dp[fa[i]]=1;
		bfs(fa[i]);
	}
	long long ans=0;
	for(int i=1;i<=idx1;i++){
		ans=(ans+dp[son[i]])%mod;
	}
	cout<<ans;
	return 0;
}







































