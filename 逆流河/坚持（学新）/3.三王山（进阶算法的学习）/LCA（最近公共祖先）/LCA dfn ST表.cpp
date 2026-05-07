//#include<iostream>
//#include<vector>
//using namespace std;
////树状图最近公共祖先LCA算法
////dfn算法
////_lg()返回 x 的二进制表示中最高位 1 所在的位置（从 0 开始计数）
//
////ST 表（Sparse Table，稀疏表） 是一种用于解决可重复贡献问题（如区间最小值、区间最大值、区间最大公约数等）的数据结构，支持 O(1) 查询，但不支持修改。
////预处理 + 倍增：预处理所有长度为2^k的区间的最值，查询时用两个重叠的区间覆盖目标区间。
////st[0][i] = arr[i]  // 长度为 2^0 = 1 的区间
////st[k][i] = merge(st[k-1][i], st[k-1][i + 2^(k-1)])
//
//constexpr int N = 5e5 + 5;
//int n, m, R, dn, dfn[N], mi[19][N];
//vector<int> e[N];
//int get(int x, int y) {return dfn[x] < dfn[y] ? x : y;}
//void dfs(int id, int f) {
//	mi[0][dfn[id] = ++dn] = f;//dn即为dfs序
//	for(int it : e[id]) if(it != f) dfs(it, id); 
//}
//int lca(int u, int v) {
//	if(u == v) return u;
//	if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
//	int d = __lg(v - u++);
//	return get(mi[d][u], mi[d][v - (1 << d) + 1]);
//}
//int main(){
//	  scanf("%d %d %d", &n, &m, &R);
//	  for(int i = 2, u, v; i <= n; i++) {
//	    scanf("%d %d", &u, &v);
//	    e[u].push_back(v), e[v].push_back(u);
//	  }
//	  dfs(R, 0);
//	  for(int i = 1; i <= __lg(n); i++)
//	    for(int j = 1; j + (1 << i) - 1 <= n; j++)
//	      mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
//	  for(int i = 1, u, v; i <= m; i++) scanf("%d %d", &u, &v), printf("%d\n", lca(u, v));
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
int n,q,r;
vector<int> g[mx];
//建ST表
int stg[19][mx];
int dfn[mx];
int cnt=0;
void dfs(int now,int fa){
	stg[0][dfn[now]=++cnt]=fa;	
	for(int i:g[now]){
		if(i==fa) continue;
		dfs(i,now);
	}
}
int merge_num(int x,int y){return dfn[x]<dfn[y]?x:y;}
void merge_stg(){
	for(int d=1;d<=__lg(n);d++){
		for(int i=1;i<=n-(1<<d)+1;i++){
			stg[d][i]=merge_num(stg[d-1][i],stg[d-1][i+(1<<(d-1))]);//因为记录的是父节点，因为公共祖先是a,b的父节点
		}
	}
}
void solve(int a,int b){
	if(a==b){
		cout<<a<<endl;
		return;
	}
	if((a=dfn[a])>(b=dfn[b])) swap(a,b);
	int d=__lg(b-a++);
	cout<<merge_num(stg[d][a],stg[d][b-(1<<d)+1])<<endl;
	return;
}
int main(){
  	cin>>n>>q>>r;
  	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);	  	
	}
	dfs(r,0);
//完善stg
	merge_stg();
	while(q--){
		int a,b;
		cin>>a>>b;
		solve(a,b);
	}
	return 0;
}















































