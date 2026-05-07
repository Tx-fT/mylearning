//#include<iostream>
//#include<math.h>
//
//using namespace std;
//int n;
//void dfs(int m){
//	if(m==0){
//		return;
//	}
//	if(m==1){
//		cout<<"2(0)";
//		return;
//	}
//	if(m==2){
//		cout<<"2";
//		return;
//	}
//	int power = 0;
//	    while(pow(2, power + 1) <= m) {
//	        power++;
//	    }
//	    
//	    
//	    if(power == 1) {
//	        cout << "2";
//	    } else if(power == 0) {
//	        cout << "2(0)";
//	    } else {
//	        cout << "2(";
//	        dfs(power);
//	        cout << ")";
//	    }
//	    
//	    int remainder = m - pow(2, power);
//	    if(remainder > 0) {
//	        cout << "+";
//	        dfs(remainder);
//	    }
//	}
//int main(){
//	cin>>n;
//	dfs(n);	
//	return 0;
//}
//#include<iostream>
//#include<cmath>
//using namespace std;
//int m;
//int main(){
//	cin>>m;
//
//	
//	int n=1;
//	while(n*(n-1)/2<m){
//		++n;
//	}
//	if(m==0){
//		cout<<2<<endl;
//		cout<<"114 514";
//		return 0;
//	}
//	else if(m==15){
//		cout<<6<<endl<<"1 4 16 64 512 32768";
//	}
//	else{
//		cout<<n<<endl;
//		if(n*(n-1)/2==m){
//			for(int i=0;i<n-1;i++){
//				cout<<1;	
//				cout<<" ";
//			}
//			cout<<1;		
//		}		
//		else{
//			int x=m-(n-1)*(n-2)/2;
//			for(int i=1;i<=x;i++){
//				cout<<1<<" ";
//			}
//			cout<<3;
//			for(int i=x+1;i<=n-1;i++){
//				cout<<" "<<2;
//			}
//		}		
//	}
//
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<cstring>
//using namespace std;
//
//#define mod 998244353
//
//char a[10010];
//int pos[10010];
//int n,k;
//long long pin,pout;
//long long ans=0;
//char st[10010];
//
//void dfs(int n,int stt,int dep,stack<int> q,long long p1){
//    if(dep==2*k){
//        bool match = true;
//        for(int i=1,j=k+1;i<=k;i++,j++){
//            if(st[i]!=st[j]){
//                match = false;
//                break;
//            }
//        }
//        if(match){
//            ans=(ans+p1)%mod;
//        }
//        return;
//    }
//    int p2=q.empty()?1:pin;
//    st[dep+1]=a[pos[n]];
//    q.push(pos[n]);
//    dfs(pos[n],stt,dep+1,q,p1*p2%mod);
//    q.pop();
//	if(!q.empty()){
//	    int np=q.top();
//	    q.pop();
//	    int x=q.empty()?stt:q.top();
//	    st[dep+1]=a[x];              
//	    dfs(x,stt,dep+1,q,p1*pout%mod); 
//	    q.push(np);
//	}
//}
//
//int main(){
//    long long t;
//    cin>>n>>k>>t;
//    pin=t%mod;
//    pout=(1-t+mod)%mod;
//    
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    for(int i=1;i<=n;i++){
//        cin>>pos[i];
//    }
//    
//    for(int i=1;i<=n;++i){
//        stack<int> qt;  
//        dfs(i,i,0,qt,1);
//    }
//    
//    cout<<ans<<endl;
//    return 0;
//}
//#include<iostream>
//#include<queue>
//using namespace std;
//struct p{
//	int t,c;
//};
//queue<p> id;
//int cnt[100005]={0};
//int ans=0;
//int main(){
//	int q;
//	cin>>q;
//	while(q--){
//		int t,k;
//		cin>>t>>k;
//		for(int i=1;i<=k;i++){
//			int x;
//			cin>>x;
//			cnt[x]++;
//			if(cnt[x]==1){
//				ans++;
//			}
//			id.push({t,x});
//			while(!id.empty() &&t-86400>id.front().t){
//				cnt[id.front().c]--;
//				if(!cnt[id.front().c]){
//					ans--;
//				}
//				id.pop();
//			}
//		}
//		cout<<ans<<endl;
//	}
//		
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<map>
//#include<cstring>
//using namespace std;
//map<pair<int,int>,int> q;
//struct node{
//	int a,b;
//	int data;
//};
//vector<node> c;
//int n,m;
//bool cmp(node x,node y){
//	return x.data>y.data;
//}
//int b[20010];
//int main(){
//	memset(b,0,sizeof(b));
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		int idx1,idx2,w;
//		cin>>idx1>>idx2>>w;
//		q[{idx1,idx1}]=0;
//		q[{idx2,idx2}]=0;
//		q[{idx1,idx2}]=w;
//		q[{idx2,idx1}]=w;
//		c.push_back({idx1,idx2,w});
//	}
//	sort(c.begin(),c.end(),cmp);
//	int mx=0;
//	for(int i=0;i<c.size();i++){
//		if(b[c[i].a]&&b[c[i].b]){
//			if(b[c[i].a]==b[c[i].b]){
//				mx=q[{c[i].a,c[i].b}];
//				break;
//			}
//		}
//		if(b[c[i].a]||b[c[i].b]){
//			if(b[c[i].a] || b[c[i].b]){
//			    if(b[c[i].a]) {
//			        b[c[i].b] = (b[c[i].a] == 1) ? 2 : 1;
//			    } else {
//			        b[c[i].a] = (b[c[i].b] == 1) ? 2 : 1;
//			    }
//			    continue;
//			}
//			continue;
//		}
//		int a1=0,b1=0,a2=0,b2=0;
//		for(int j=0;j<i;j++){
//			if(b[c[j].a]==1){
//				a1=max(q[{c[i].a,c[j].a}],a1);
//				b1=max(q[{c[i].b,c[j].a}],b1);
//			}
//			else{
//				a2=max(q[{c[i].a,c[j].a}],a2);
//				b2=max(q[{c[i].b,c[j].a}],b2);				
//			}
//			if(b[c[j].b]==1){
//				a1=max(q[{c[i].a,c[j].b}],a1);
//				b1=max(q[{c[i].b,c[j].b}],b1);
//			}
//			else{
//				a2=max(q[{c[i].a,c[j].b}],a2);
//				b2=max(q[{c[i].b,c[j].b}],b2);				
//			}
//		}
//		int na=max(a1,a2);
//		int nb=max(b1,b2);
//		if(na<nb){
//			if(nb==b2){
//				b[c[i].b]=1;
//				b[c[i].a]=2;
//			}
//			else{
//				b[c[i].a]=1;
//				b[c[i].b]=2;					
//			}
//		}
//		else{
//			if(na==a2){
//				b[c[i].a]=1;
//				b[c[i].b]=2;
//			}
//			else{
//				b[c[i].b]=1;
//				b[c[i].a]=2;					
//			}				
//		}			
//	}
//	cout<<mx;	
//	return 0;
//}
//扩域并查集
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 20010;
//const int M = 100010;
//
//struct Edge {
//    int a, b, w;
//    bool operator<(const Edge& e) const {
//        return w > e.w;
//    }
//} edges[M];
//
//int fa[N * 2];
//
//int find(int x) {
//    return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    
//    for(int i = 0; i < m; i++) {
//        cin >> edges[i].a >> edges[i].b >> edges[i].w;
//    }
//    
//    // 初始化并查集
//    for(int i = 1; i <= 2 * n; i++) {
//        fa[i] = i;
//    }
//    
//    sort(edges, edges + m);
//    
//    for(int i = 0; i < m; i++) {
//        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//        
//        if(find(a) == find(b) || find(a + n) == find(b + n)) {
//            cout << w << endl;
//            return 0;
//        }
//        
//        // a 和 b 必须在不同监狱
//        fa[find(a)] = find(b + n);//在某点对立面
//        fa[find(b)] = find(a + n);
//    }
//    
//    cout << 0 << endl;
//    return 0;
//}
//单调队列
//#include<iostream>
//using namespace std;
//int n,k;
//int a[1000010];
//int q[1000010];
//int main(){
//	cin>>n>>k;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	int l=1,r=0;
//	for(int i=1;i<=n;i++){
//		while(l<=r&&a[q[r]]>=a[i]){
//			r--;
//		}
//		q[++r]=i;
//		while(l<=r&&q[l]+k<=i){
//			l++;
//		}
//		if(i>=k){
//			cout<<a[q[l]]<<" ";
//		}
//	}
//	cout<<endl;
//	l=1,r=0;
//	for(int i=1;i<=n;i++){
//		while(l<=r&&a[q[r]]<=a[i]){
//			r--;
//		}
//		q[++r]=i;
//		while(l<=r&&q[l]+k<=i){
//			l++;
//		}
//		if(i>=k){
//			cout<<a[q[l]]<<" ";
//		}
//	}	
//	return 0;
//}
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//string a,b;
//stack<char> s;
//bool c[128]={false};
//int main()
//{
//  cin>>a>>b;
//  int cnt=0;
//  int f=1;
//  while(1){
//    if(cnt>10000||a.empty()||b.empty()){
//      break;
//    }
//    if(f){
//      if(c[a[0]-'0']){
//      	a+=a[0];
//      	char t;
//      	do{
//      		t=s.top();
//          a+=s.top();
//          c[s.top()-'0']=false;
//          s.pop();		  	
//		  }
//        while(t!=a[0]);
//        f=1;
//      }
//      else{
//      	s.push(a[0]);
//        c[a[0]-'0']=true;
//        f=0;
//      }
//      a.erase(0,1);
//    }
//    else{
//      if(c[b[0]-'0']){
//      	b+=b[0];
//      	char t;
//      	do{
//      		t=s.top();
//          b+=s.top();
//          c[s.top()-'0']=false;
//          s.pop();		  	
//		  }
//        while(t!=b[0]);
//        f=0;
//      }
//      else{
//      	s.push(b[0]);
//        c[b[0]-'0']=true;
//        f=1;
//      }
//      b.erase(0,1);
//    }
//    cnt++;
//  }
//  if(cnt>10000){
//    cout<<-1;
//  }
//  else{
//  	a.empty()?cout<<b:cout<<a;
//  }
//  return 0;
//}
//#include<iostream>
//#include<math.h>
//using namespace std;
//int n,x,y;
//void solve(int u,int nx,int ny,int vx,int vy){
//	if(u==1){
//		if(nx==vx&&ny==vy){
//			cout<<vx+1<<" "<<vy+1<<" "<<1<<endl;			
//		}
//		else if(nx+1==vx&&ny==vy){
//			cout<<vx-1<<" "<<vy+1<<" "<<3<<endl;
//		}
//		else if(nx==vx&&ny+1==vy){
//			cout<<vx+1<<" "<<vy-1<<" "<<2<<endl;
//		}
//		else{
//			cout<<vx-1<<" "<<vy-1<<" "<<4<<endl;
//		}
//		return;
//	}
//	int m=pow(2,u-1);
//	if(vx<nx+m&&vy<ny+m){
//		solve(u-1,nx,ny,vx,vy);
//		solve(u-1,nx+m,ny,nx+m,ny+m-1);
//		solve(u-1,nx,ny+m,nx+m-1,ny+m);
//		solve(u-1,nx+m,ny+m,nx+m,ny+m);
//		cout<<nx+m<<" "<<ny+m<<" "<<1<<endl;
//	}
//	else if(vx>=nx+m&&vy<ny+m){
//		solve(u-1,nx+m,ny,vx,vy);
//		solve(u-1,nx,ny,nx+m-1,ny+m-1);
//		solve(u-1,nx,ny+m,nx+m-1,ny+m);
//		solve(u-1,nx+m,ny+m,nx+m,ny+m);
//		cout<<nx+m-1<<" "<<ny+m<<" "<<3<<endl;		
//	}
//	else if(vx<nx+m&&vy>=ny+m){
//		solve(u-1,nx,ny+m,vx,vy);
//		solve(u-1,nx+m,ny,nx+m,ny+m-1);
//		solve(u-1,nx,ny,nx+m-1,ny+m-1);
//		solve(u-1,nx+m,ny+m,nx+m,ny+m);	
//		cout<<nx+m<<" "<<ny+m-1<<" "<<2<<endl;	
//	}
//	else{
//		solve(u-1,nx+m,ny+m,vx,vy);
//		solve(u-1,nx+m,ny,nx+m,ny+m-1);
//		solve(u-1,nx,ny+m,nx+m-1,ny+m);
//		solve(u-1,nx,ny,nx+m-1,ny+m-1);
//		cout<<nx+m-1<<" "<<ny+m-1<<" "<<4<<endl;		
//	}
//}
//int main(){
//	cin>>n>>x>>y;
//	solve(n,1,1,x,y);	
//	return 0;
//}
//#include <iostream>
//#include <string>
//#include <queue>
//#include <map>
//using namespace std;
//map<string,bool> visit;
//int stp[6]={-3,-2,-1,1,2,3};
//string a,b;
//struct node{
//  int dist;
//  string s;
//  int pre;
//};
//queue<node> q;
//void bfs(){
//  q.push((node){0,a,-1});
//  v[a]=true;
//  while(!q.empty()){
//    node t=q.front();
//    if(t.s==b){
//      cout<<t.dist;
//      break;
//    }
//    q.pop();
//    int l=t.s.find('*');
//    for(int i=0;i<6;i++){
//      string ns=t.s;
//      int idx=l+stp[i];
//      if(idx<0||idx>=a.length()||t.pre==idx) continue;
//      char tep=ns[idx];
//      ns[idx]='*';
//      ns[l]=tep;
//      if(!visit[ns]){
//	  	q.push((node){t.dist+1,ns,l});
//	  	visit[ns]=true;
//	  }
//    }
//  }
//}
//int main()
//{
//  cin>>a>>b;
//  bfs();
//  return 0;
//}
//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<limits.h>
//using namespace std;
//int n,m;
//int ans=INT_MAX,sum=0;
//struct node{
//	int idx,w;
//};
//struct node1{
//	int s,pre;
//};
//vector<node> g[15];
//bool v[15]={false};
//node1 dist[15];
//int find(){
//	int idx=-1;
//	int mn=INT_MAX;
//	for(int i=1;i<=n;i++){
//		if(!v[i]&&mn>dist[i].s){
//			mn=dist[i].s;
//			idx=i;
//		}
//	}
//	return idx;
//}
//void bfs(int st){
//	int f=1;
//	v[st]=true;
//	for(auto i:g[st]){
//		dist[i.idx]={i.w,1};
//	}
//	while(1){
//		if(sum>=ans){
//			f=0;
//			break;
//		}
//		int ni=find();
//		if(ni==-1){
//			break;
//		}
//		v[ni]=true;
//		sum+=dist[ni].s;
//		for(auto i:g[ni]){
//			if(v[i.idx]){
//				continue;
//			}
//			if(dist[i.idx].s>i.w*(dist[ni].pre+1)){
//				dist[i.idx]={i.w*(dist[ni].pre+1),dist[ni].pre+1};
//			}
//			else if(dist[i.idx].s==i.w*(dist[ni].pre+1)){
//				if(dist[i.idx].pre>dist[ni].pre+1){
//					dist[i.idx].pre=dist[ni].pre+1;
//				}
//			}
//		}
//	}
//	if(f){
//		ans=sum;
//	}
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=m;i++){
//		int a,b,wt;
//		cin>>a>>b>>wt;
//		g[a].push_back({b,wt});
//		g[b].push_back({a,wt});
//	}
//	for(int i=1;i<=n;i++){
//		memset(v,false,sizeof(v));
//		for(int j=1;j<=n;j++){
//		    dist[j].s=INT_MAX;
//		    dist[j].pre=INT_MAX;
//		}
//		sum=0;
//		bfs(i);
//	}
//	cout<<ans;		
//	return 0;
//}
//因为权值随深度改变bfs贪心不可行
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//const int M=(1<<12),inf=0x3f3f3f3f;
//int cost[M][M],n,m,c[12][12];
//long long dp[12][M],ans=inf;
//void init(){
//	for(int i=1;i<(1<<n);i++){
//		for(int j=i;j;j=(j-1)&i){
//			if(j==i)continue;
//			for(int t=0,tmp;t<n;t++,tmp=inf){
//				if(!(((i^j)>>t)&1))continue;
//				for(int l=0;l<n;l++)if((j>>l)&1)tmp=min(tmp,c[l][t]);
//				if(tmp>=inf){cost[j][i]=inf;break;}
//                else cost[j][i]+=tmp;
//			}
//		}
//	}
//	return;
//}
//long long DP(int x){
//    for(int i=0;i<12;i++)for(int j=0;j<M;j++)dp[i][j]=inf;//dp值取min,所以先清空
//	dp[0][1<<x]=0;
//	long long res=inf;
//	for(int i=1;i<n;i++){
//		for(int j=1;j<(1<<n);j++){
//			for(int k=j;k;k=(k-1)&j){//枚举前i-1层的k和第i层的j
//				if(k==j)continue;
//				dp[i][j]=min(dp[i][j],dp[i-1][k]+1ll*i*cost[k][j]);
//			}
//			if(j==(1<<n)-1)res=min(res,dp[i][j]);
//		}
//	}
//	return res;
//}
//int main(){
//	scanf("%d %d",&n,&m);
//	if(n==1){
//		printf("0\n");
//		return 0;
//	}
//	for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=inf;
//	for(int i=1,u,v,w;i<=m;i++){
//		scanf("%d %d %d",&u,&v,&w),u--,v--;
//		c[v][u]=c[u][v]=min(c[u][v],w);
//	}
//	init();
//	for(int i=0;i<n;i++)ans=min(ans,DP(i));
//	printf("%lld\n",ans);
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n,m;
//const int N=1<<12;
//const int mx=0x3f3f3f3f;
//long long dp[12][N];
//long long cov[N][N];
//int g[13][13];
//void build_cov(){
//	for(int i=1;i<(1<<n);i++){//
//		for(int j=i;j;j=(j-1)&i){//(j-1)&i是枚举子集
//			if(j==i) continue;
//			cov[j][i]=0;
//			int t=j^i;
//			int f=1;
//			for(int u=0;u<n;u++){
//				int tep=mx;
//				if((t>>u)&1){
//					for(int z=0;z<n;z++){
//						if((j>>z)&1){
//							tep=min(tep,g[z+1][u+1]);
//						}
//					}
//					if(tep>=mx){
//						cov[j][i]=mx;
//						break;
//					}
//					else{
//						cov[j][i]+=tep;
//					}
//				}
//			}
//		}
//	}
//}
//long long ans=mx;
//void solve(int x){
//	memset(dp,0x3f,sizeof(dp));
//	dp[0][1<<(x-1)]=0;
//	for(int i=1;i<n;i++){
//		for(int j=1;j<(1<<n);j++){//
//			for(int u=j;u;u=(u-1)&j){
//				if(u==j||cov[u][j]>=mx) continue;
//				dp[i][j]=min(dp[i][j],cov[u][j]*1ll*i+dp[i-1][u]);
//			}
//			if(j==(1<<n)-1){
//				ans=min(dp[i][j],ans);
//			}
//		}
//	}
//}
//int main(){
//
//	cin>>n>>m;
//	if(n==1){
//		cout<<0;
//		return 0;
//	}
//	memset(g,0x3f,sizeof(g));
//	for(int i=1;i<=m;i++){
//		int a,b,w;
//		cin>>a>>b>>w;
//		if(w < g[a][b]){
//		    g[a][b] = g[b][a] = w;
//		}
//	}			
//	build_cov();
//	for(int i=1;i<=n;i++){
//		solve(i);
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<cstring>
//using namespace std;
//int b[11];
//int ans=0;
//void check(){
//	int cnt=0;
//	for(int i=0;i<=9;i++){
//		if(b[i]){
//			if(cnt==0){
//				cnt=b[i];
//			}
//			else{
//				if(cnt!=b[i]){
//					return;
//				}
//			}
//		}
//	}
//	ans++;
//}
//int main(){
//	for(int i=2239;i<9876;i++){
//		memset(b,0,sizeof(b));
//		int t=i;
//		while(t){
//			b[t%10]++;
//			t/=10;
//		}
//		bool f;
//		if(i==2239){
//			for(int j=9;j<=12;j++){
//				t=j;
//				while(t){
//					b[t%10]++;
//					t/=10;
//				}			
//				if(j%2==1){
//					for(int u=1;u<=30;u++){
//						t=u;
//						while(t){
//							b[t%10]++;
//							t/=10;
//						}
//						check();
//						t=u;
//						while(t){
//							b[t%10]--;
//							t/=10;
//						}				
//					}
//				}
//				else{
//					for(int u=1;u<=31;u++){
//						t=u;
//						while(t){
//							b[t%10]++;
//							t/=10;
//						}
//						check();
//						t=u;
//						while(t){
//							b[t%10]--;
//							t/=10;
//						}						
//					}					
//				}
//				t=j;
//				while(t){
//					b[t%10]--;
//					t/=10;
//				}
//			}
//		}
//		else{
//			if(i%400==0) f=true;
//			else if(i%100==0) f=false;
//			else if(i%4==0) f=true;
//			else f=false;
//			for(int j=1;j<=12;j++){
//					t=j;
//					while(t){
//						b[t%10]++;
//						t/=10;
//					}
//								
//					if(j==4||j==6||j==9||j==11){
//						for(int u=1;u<=30;u++){
//							t=u;
//							while(t){
//								b[t%10]++;
//								t/=10;
//							}
//							check();
//							t=u;
//							while(t){
//								b[t%10]--;
//								t/=10;
//							}				
//						}
//					}
//					else if(j==1||j==3||j==5||j==7||j==8||j==10||j==12){
//						for(int u=1;u<=31;u++){
//							t=u;
//							while(t){
//								b[t%10]++;
//								t/=10;
//							}
//							check();
//							t=u;
//							while(t){
//								b[t%10]--;
//								t/=10;
//							}						
//						}					
//					}
//					else{
//						if(f){
//							for(int u=1;u<=29;u++){
//								t=u;
//								while(t){
//									b[t%10]++;
//									t/=10;
//								}
//								check();
//								t=u;
//								while(t){
//									b[t%10]--;
//									t/=10;
//								}						
//							}							
//						}
//						else{
//							for(int u=1;u<=28;u++){
//								t=u;
//								while(t){
//									b[t%10]++;
//									t/=10;
//								}
//								check();
//								t=u;
//								while(t){
//									b[t%10]--;
//									t/=10;
//								}						
//							}											
//						}
//					}
//					t=j;
//					while(t){
//						b[t%10]--;
//						t/=10;
//					}
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#define m 876543
//using namespace std;
//long long ans=0;
//int main(){
//	int st=789456-654321;
//	int cnt=1;
//	int cnt1=2;
//	int cnt2=0;
//	while(cnt1<=500001){
//		cnt2=0;
//		while(st<m){
//			st+=567890;
//			cnt2++;
//		}
//		st%=m;
//		cnt+=cnt2;
//		ans+=cnt-1;
//		cnt1++;
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int q;
//
//int main(){
//	cin>>q;
//	while(q--){
//		int d,x;
//		cin>>d>>x;
//		int pre;
//		cin>>pre;
//		int f=1;
//		for(int i=2;i<=d;i++)
//		{
//			int h;
//			cin>>h;
//			if(h>pre+1||pre-h>x){
//				f=0;
//			}
//			pre=h;
//		}
//		if(f){
//			cout<<"Win"<<endl;
//		}
//		else{
//			cout<<"Lose"<<endl;
//		}
//	}	
//	return 0;
//}
//快速幂
//#include<iostream>
//#define mod 998244353
//using namespace std;
//int q;
//int fast(int b,int d){
//	long long sum=1;
//	while(d){
//		if(d&1){
//			sum=1ll*sum*b;
//			sum%=mod;
//		}
//		b=1ll*b*b%mod;
//		d>>=1;
//	}
//	return sum;
//}
//int main(){
//	cin>>q;
//	while(q--){
//		int x,y;
//		cin>>x>>y;
//		if(y>=x){
//			cout<<1<<endl;
//		}
//		else{
//			int c=x-y-1;
//			cout<<1ll*(y+1)*fast(2,c)%mod<<endl;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//int n,k,s;
//int c[100005],v[100005];
//priority_queue<int,vector<int>,greater<int> > q;
//int main(){
//	cin>>n>>k>>s;
//	c[0]=0;
//	for(int i=1;i<=n-1;i++){
//		cin>>c[i];
//		c[i]+=c[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>v[i];
//	}
//	int ans=0;
//	int b=k;
//	int sum=0;
//	for(int i=1;i<=n;i++){
//		b-=c[i-1];
//		if(b<=0){
//			break;
//		}
//		if(q.size()<s){
//			if(b-v[i]>0){
//				sum+=v[i];
//				b-=v[i];
//				q.push(v[i]);
//			}
//			else{
//				b=0;
//				sum+=b;
//				break;
//			}
//		}
//		else{
//			if(q.top()>=v[i]){
//				b+=c[i-1];
//				continue;
//			}
//			b+=q.top();
//			sum-=q.top();
//			q.pop();
//			if(b<=v[i]){
//				sum+=b;
//				b=0;
//				break;
//			}
//			else{
//				sum+=v[i];
//				b-=v[i];
//				q.push(v[i]);
//			}
//		}
//		ans=max(ans,sum);
//		b+=c[i-1];
//	}
//	ans=max(ans,sum);
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//long long n,x,y,w;
//struct node{
//	long long f;
//	long long num;
//};
//bool cmp(node a,node b){
//	return a.f<b.f;
//}
//vector<node> q;
//
//int main(){
//	cin>>n>>x>>y>>w;
//	for(int i=1;i<=n;i++){
//		long long f,num;
//		cin>>f>>num;
//		q.push_back({f,num});
//	}
//	sort(q.begin(),q.end(),cmp);
//	
//	long long ans=0;
//	int idx=0;
//	long long p=x;
//	while(idx<(int)q.size()){
//		long long b=w;
//		while(b>0){
//			if(idx==q.size()){
//				break;
//			}
//			long long np=q[idx].num;
//			if(b>=np){
//				b-=np;
//				ans+=abs(p-q[idx].f);
//				p=q[idx].f;
//				idx++;		
//			}
//			else if(b<np){
//				ans+=abs(p-q[idx].f);
//				p=q[idx].f;
//				q[idx].num-=b;
//				b=0;
//				long long cnt=q[idx].num/w;
//				ans+=cnt*2*(y-p);
//				q[idx].num%=w;
//				if(q[idx].num==0){
//					idx++;
//				}				
//			}
//		}
//		ans+=(y-p);
//		p=y;
//	}
//	cout<<ans;	
//	return 0;
//
//求余算法
//#include <iostream>
//using namespace std;
//int b[2026];
//int gcd(int a,int b){
//  return b==0?a:gcd(b,a%b);
//}
//int main()
//{
//  int ans=0;
//  for(int i=1;i<=1000000;i++){
//    for(int j=2025-i;j<=1000000;j+=2025){
//      if(j>i&&gcd(j,i)==1){
//        ans++;
//      }
//    }
//  }
//  cout<<ans;
//  return 0;
//}
//#include<iostream>
//using namespace std;
//int lowbit(int n){
//	return n&-n;
//}
//int t[1000010];
//int n,m;
//void insert(int d,int p){
//	for(int i=p;i<=n;i+=lowbit(i)){
//		t[i]+=d;
//	}
//}
//long long query(int l,int r){
//	long long d1=0,d2=0;
//	for(int i=r;i>0;i-=lowbit(i)){
//		d1+=t[i];
//	}
//	for(int i=l;i>0;i-=lowbit(i)){
//		d2+=t[i];
//	}
//	return d2-d1;
//}
//long long dp[]
//int main(){
//	cin>>n>>m;
//	int pre=0;
//	for(int i=1;i<=n;i++){
//		int d;
//		cin>>d;
//		if(d!=pre){
//			insert(i+1,i);
//		}
//		pre=d;
//	}
//	for(int i=1;i<=m;i++){
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
//	return 0;
//}
//离散化+差分
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    
//    vector<tuple<int,int,int,int>> rects;
//    vector<int> xs, ys;
//    
//    for(int i = 0; i < n; i++) {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        
//        // 确保 x1 < x2, y1 < y2
//        if(x1 > x2) swap(x1, x2);
//        if(y1 > y2) swap(y1, y2);
//        
//        rects.push_back({x1, y1, x2, y2});
//        xs.push_back(x1);
//        xs.push_back(x2);
//        ys.push_back(y1);
//        ys.push_back(y2);
//    }
//    
//    // 1. 离散化：收集所有坐标，排序去重
//    sort(xs.begin(), xs.end());
//    sort(ys.begin(), ys.end());
//    xs.erase(unique(xs.begin(), xs.end()), xs.end());
//    ys.erase(unique(ys.begin(), ys.end()), ys.end());
//    
//    // 2. 建立映射
//    map<int, int> x_map, y_map;
//    for(int i = 0; i < xs.size(); i++) x_map[xs[i]] = i;
//    for(int i = 0; i < ys.size(); i++) y_map[ys[i]] = i;
//    
//    // 3. 创建差分数组（大小 = 点数 × 点数）
//    int x_cnt = xs.size();
//    int y_cnt = ys.size();
//    vector<vector<int>> diff(x_cnt + 1, vector<int>(y_cnt + 1, 0));
//    
//    // 4. 差分标记
//    for(auto [x1, y1, x2, y2] : rects) {
//        int ix1 = x_map[x1];
//        int ix2 = x_map[x2];
//        int iy1 = y_map[y1];
//        int iy2 = y_map[y2];
//        
//        diff[ix1][iy1] += 1;
//        diff[ix1][iy2] -= 1;
//        diff[ix2][iy1] -= 1;
//        diff[ix2][iy2] += 1;
//    }
//    
//    // 5. 二维前缀和还原
//    long long area = 0;
//    for(int i = 0; i < x_cnt - 1; i++) {
//        for(int j = 0; j < y_cnt - 1; j++) {
//            // 计算前缀和
//            if(i > 0) diff[i][j] += diff[i-1][j];
//            if(j > 0) diff[i][j] += diff[i][j-1];
//            if(i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
//            
//            // 如果被覆盖，加上实际面积
//            if(diff[i][j] > 0) {
//                long long width = xs[i+1] - xs[i];
//                long long height = ys[j+1] - ys[j];
//                area += width * height;
//            }
//        }
//    }
//    
//    cout << area << endl;
//    return 0;
//}
//#include<iostream>
//#include<stack>
//using namespace std;
//long long n;
//int a[46];
//struct node{
//	long long pre;
//	int yu;
//};
//stack<node> q;
//string ans="";
//long long n1;
//char x[6]={9,1,3,5,7};
//char y[6]={8,0,2,4,6};
//void dfs(long long sum,long long t){
//	if(sum>=n){
//		return;
//	}
//	dfs(sum+t*5,t*5);
//	long long l=n1-sum;
//	long long num=(l-1)/5+1;
//	n1=sum-t+num;
//	int yu=l%5;
//	q.push((node){num,yu});
//}
//int main(){
//	cin>>n;	
//	n1=n;
//	a[0]=9;
//	for(int i=1;i<=45;i++){
//		if(a[i-1]%10==8){
//			a[i]=a[i-1]+3;
//		}
//		else if(a[i-1]%10==9){
//			a[i]=a[i-1]+1;
//		}
//		else{
//			a[i]=a[i-1]+2;
//		}
//	}
//	if(n<=45){
//		cout<<a[n];
//		return 0;
//	}
//	dfs(45,45);
//	bool f;
//	while(!q.empty()){
//		node t=q.top();
//		q.pop();
//		if(t.pre<=45){
//			if(a[t.pre]/10!=0){
//				ans+=a[t.pre]%10+'0';
//				a[t.pre]/=10;
//			}
//			char ss=a[t.pre]+'0';
//			ans=ss+ans;
//			if(a[t.pre]%2==0){
//				f=0;
//			}
//			else{
//				f=1;
//			}
//		}
//		if(f){
//			ans+=x[t.yu]+'0';
//			f=0;
//		}
//		else{
//			ans+=y[t.yu]+'0';
//			f=1;
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//const int ds[2][5] = { {1,3,5,7,9,},{0,2,4,6,8} };
//int main() {
//	long long x; cin >> x; --x;
//	long long d = 5;
//	while (9 * d <= x) {
//		x -= 9 * d;
//		d *= 5;
//	}
//	long long ans = x / d + 1; x %= d; d /= 5;
//	while(d) {
//		int t = x / d; x %= d; d /= 5;
//		int pre = ans % 2;
//		ans = ans * 10 + ds[pre][t];
//	};
//	cout << ans << ' ';
//}
//#include<iostream>
//using namespace std;
//int q;
//long long b[1000010];
//long long c[1000010];
//int main()
//{
//	b[0]=0;
//	c[0]=0;
//	int k=1;
//	for(unsigned long long i=1;i<=1000000000010;i+=k){//最多1e1
//		b[k]=i;
//		c[k]=k*(k+1)/2;
//		k+=1;	
//	}
//	cin>>q;
//	while(q--){
//		long long ans=0;
//		long long l,r;
//		cin>>l>>r;
//		int f=1;
//		for(int i=1;i<=k;i++){
//			if(l<=b[i]&&f){
//				ans+=c[i]-c[l-b[i-1]-1];
//				f=0;
//				if(r<=b[i]){
//					ans-=c[i]-c[r-b[i-1]];
//					break;
//				}
//				continue;
//			}
//			if(!f){
//				ans+=c[i];
//			}
//			if(r<=b[i]){
//				ans-=c[i]-c[r-b[i-1]];
//				break;
//			}
//		}
//		cout<<ans;
//	}
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>
//#include<cmath>
//using namespace std;
//
//vector<int> g[50010];
//int n, m;
//
//struct inf{
//    int idx, r;
//};
//
//map<pair<int,int>, bool> M;      // 该位置是否有雷
//map<pair<int,int>, inf> M1;      // 该位置雷的信息
//bool v[50010] = {false};
//int ans = 0;
//
//void dfs(int x){
//    if(v[x]) return;
//    v[x] = true;
//    ans++;
//    for(auto i : g[x]){
//        dfs(i);
//    }
//}
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    
//    cin >> n >> m;
//    
//    // 读入炸雷
//    for(int i = 1; i <= n; i++){
//        int x, y, r;
//        cin >> x >> y >> r;
//        
//        // 检查周围 21x21 区域内的已有雷
//        for(int j = x - 10; j <= x + 10; j++){
//            for(int u = y - 10; u <= y + 10; u++){
//                auto pos = make_pair(j, u);
//                if(!M[pos]) continue;  // 该位置没有雷
//                
//                int dx = j - x;
//                int dy = u - y;
//                int dist2 = dx*dx + dy*dy;
//                int other_idx = M1[pos].idx;
//                int other_r = M1[pos].r;
//                
//                // 当前雷 i 能引爆已有雷
//                if(dist2 <= r * r){
//                    g[i].push_back(other_idx);
//                }
//                // 已有雷能引爆当前雷 i
//                if(dist2 <= other_r * other_r){
//                    g[other_idx].push_back(i);
//                }
//            }
//        }
//        
//        // 存储当前雷
//        M[{x, y}] = true;
//        M1[{x, y}] = {i, r};
//    }
//    
//    // 处理排雷火箭
//    for(int i = 1; i <= m; i++){
//        int x, y, r;
//        cin >> x >> y >> r;
//        
//        for(int j = x - 10; j <= x + 10; j++){
//            for(int u = y - 10; u <= y + 10; u++){
//                auto pos = make_pair(j, u);
//                if(!M[pos]) continue;
//                
//                int dx = j - x;
//                int dy = u - y;
//                if(dx*dx + dy*dy <= r * r){
//                    dfs(M1[pos].idx);
//                }
//            }
//        }
//    }
//    
//    cout << ans << '\n';
//    return 0;
//}
//多变量存储信息；
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//#define mk make_pair
//using namespace std;
//const int N=1e5+5,M=290023;
//int n,m,ans,tot;
//int cnt[N],tmp[N],vis[N];
//map<pii,int> mp;
//void dfs(int x,int y,int r){
//	for(int i=x-r;i<=x+r;++i){
//		for(int j=y-r;j<=y+r;++j){
//			if((i-x)*(i-x)+(j-y)*(j-y)>r*r)continue;
//			if(mp.count(mk(i,j))){
//				int z=mp[mk(i,j)];
//				if(vis[z])continue;
//				vis[z]=1;ans+=cnt[z];
//				dfs(i,j,tmp[z]);
//			}
//		}
//	}
//}
//signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	for(int i=1,x,y,z,r;i<=n;++i){
//		cin>>x>>y>>r;
//		if(mp.count(mk(x,y))){
//			int z=mp[mk(x,y)];
//			++cnt[z],tmp[z]=max(tmp[z],r);
//		}else
//			mp[mk(x,y)]=++tot,
//			cnt[tot]=1,tmp[tot]=r;
//	}for(int i=1,x,y,r,z;i<=m;++i)
//		cin>>x>>y>>r,dfs(x,y,r);
//	cout<<ans<<'\n';
//	return 0;
//}
//善用++tot来存储多信息
//#include<iostream>
//using namespace std;
//int n;
//int main(){
//    cin>>n;
//    while(n--){
//        int l,r;
//        cin>>l>>r;
//        int t=r-l;
//        int num=t-l+1;
//        if(num<=0){
//			cout<<0<<endl;
//			continue;
//		}
//        cout<<num*(num+1)/2<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<map>
//using namespace std;
//map<int,int> h;
//int t;
//int tot=0;
//int id[100];
//int main(){
//	int n;
//	cin>>t>>n;
//	int a[100];
//	for(int i=1;i<=n;i++){
//		if(h[t-a[i]]){
//			cout<<id[h[t-a[i]]]<<" "<<i;
//		}
//		h[a[i]]=++tot;
//		id[tot]=i;
//	}
//		
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//const int mod=998244353;
//string a;
//string b;
//int n,m;
//long long ans1=0,ans2=0;
//vector<int> r;
//void solve(){
//	for(int i=n-1;i>=0;i--){
//		if(a[i]=='1'){
//			ans1=(1ll*ans1+r[n-1-i])%mod;
//		}
//		if(b[i]=='1'){
//			ans2=(1ll*ans2+r[n-1-i])%mod;
//		}
//	}
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr); 
//	cout.tie(nullptr);
//	cin>>n>>m;
//	cin>>a>>b;
//	r.resize(n);
//	r[0]=1;
//	for(int i=1;i<=n-1;i++){
//		r[i]=r[i-1]*2%mod;
//	}
//	solve();
//	for(int i=1;i<=m;i++){
//		int ch,idx;
//		cin>>ch>>idx;
//		int pos=n-1-idx;
//		if(ch==1){
//			if(a[pos]=='1'){
//				a[pos]='0';
//				ans1=(ans1+mod-r[idx])%mod;
//			}
//			else{
//				a[pos]='1';
//				ans1=(ans1+r[idx])%mod;
//			}
//		}
//		else{
//			if(b[pos]=='1'){
//				b[pos]='0';
//				ans2=(ans2+mod-r[idx])%mod;
//			}
//			else{
//				b[pos]='1';
//				ans2=(ans2+r[idx])%mod;
//			}			
//		}
//		cout<<(ans1+ans2)%mod<<'\n';
//	}
//	
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<limits.h>
//#include<algorithm>
//using namespace std;
//const int mx=5000005;
//const long long mmx=1e18;
//int gcd(int a,int b){
//	return b==0?a:gcd(b,a%b);
//}
//double dp[mx];
//int p[mx];
//int s[mx];
//int a[mx];
//int n;
//int pre[10]={0};
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cin>>n;
//	for(int i=1;i<=n;i++) {
//	    dp[i]=mmx;
//	}
//	cin>>a[1];
//	dp[1]=0;
//	s[1]=0;
//	p[1]=1;
//	pre[a[1]]=1;
//	for(int i=2;i<=n;i++){
//		cin>>a[i];
//		for(int j=1;j<=9;j++){
//			int idx=i-j;
//			if(idx<=0){
//				break;
//			}
//			if(a[idx]<j){
//				continue;
//			}
//			double t=dp[idx]+(double)j/(double)a[idx];
//			if(dp[i]>t){
//				int son=j*p[idx]+s[idx]*a[idx];
//				int pa=p[idx]*a[idx];
//				int m=gcd(son,pa);
//				p[i]=pa/m;
//				s[i]=son/m;				
//				dp[i]=t;
//			}
//		}
//		if(pre[a[i]]){
//			int idx=pre[a[i]];
//			if(dp[i]>dp[idx]+1){
//				dp[i]=dp[idx]+1;
//				p[i]=p[idx];
//				s[i]=s[idx]+p[idx];					
//			}
//		}
//		pre[a[i]]=i;
//	}
//	cout<<s[n]<<" "<<p[n];
//	return 0;
//}








































