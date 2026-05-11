//LCA倍增法

//朴素超时
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//vector<int> g[100010];
//int n,m;
//int b[100010];
//int p[100010];
//int d[100010];
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


#include<bits/stdc++.h>
using namespace std;
const int N =1e6+10;
vector<int> g[N<<1];
int sum[N],a[N],dep[N],fa[N][20],n,m;
inline int read(){
  	int x=0,w=1;char ch=0;
  	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
  	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
  	return x*w;
}

inline void write(int x){
  	static int sta[35];int top=0;
  	do{sta[top++]=x%10,x/=10;}while (x);
  	while(top)putchar(sta[--top]+48);
}
void dfs(int u,int fath)
{
	dep[u]=dep[fath]+1;
	fa[u][0]=fath;
	for(int i=1;(1<<i)<=dep[u];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];//上2^i-1在上2^i-1
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fath)
			continue;
		sum[v]=sum[u]+a[v];
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=0;i<=log2(n);i++)
		if((1<<i)&d)
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=log2(n);i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
signed main()
{
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)
		a[i]=g[i].size(),sum[i]=g[i].size();
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		cout<<sum[u]+sum[v]-2*sum[lca(u,v)]+a[lca(u,v)]<<endl;
	}
	return 0;
}


