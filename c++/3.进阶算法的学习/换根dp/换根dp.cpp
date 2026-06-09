#include <bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;

const int N=500010;
int n,res;
int a[N],s[N]; // a[公司]：该公司连通块大小；s[u]：子树大小
vector<PII> g[N];//邻接表存树


// 第一次 DFS：计算每个节点的子树大小
void dfs1(int u,int fa)
{
  s[u]=1;// 自身算一个节点
  for(auto [v,w]:g[u])
  {
    if(v!=fa)
    {
      dfs1(v,u);
      s[u]+=s[v];// 累加子树大小
    }
  }
}


// 第二次 DFS：换根 DP，动态维护每个公司的连通块大小
void dfs2(int u,int fa)
{
  for(auto [v,w]:g[u])
  {
    if(v!=fa)
    {
      int t=a[w];// 暂存原来公司 w 的大小
      a[w]=s[v];// 以 v 为根的子树属于公司 w
      dfs2(v,u);
      res-=a[w]*(a[w]-1);// 减去非法点对（同一公司内部）
      a[w]=t-s[v];// 恢复为另一部分连通块
    }
  }
}

signed main()
{
  cin >> n;
  res=n*n*(n-1);// 初始化为所有可能的点对数量

  for(int i=1;i<=n;i++) a[i]=n;

  for(int i=1;i<n;i++)
  {
    int u,v,w;cin >> u >> v >> w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }

  dfs1(1,0);// 计算子树大小
  dfs2(1,0);// 换根 DP
  for(int i=1;i<=n;i++)
  {
    res-=a[i]*(a[i]-1);
  }
  cout << res << endl;
  return 0;
}
//深度和
//void dp1(int u,int fa)
//{
//	sz[u]=1;
//	for(int i=Head[u];i;i=Edge[i].next)
//	{
//		int v=Edge[i].to;
//		if(v==fa)continue;
//		dep[v]=dep[u]+1;//深度
//		dp1(v,u);
//		sz[u]+=sz[v];//子树大小
//	}
//}
//void dp2(int u,int fa)
//{
//	for(int i=Head[u];i;i=Edge[i].next)
//	{
//		int v=Edge[i].to;
//		if(v==fa)continue;
//		f[v]=f[u]-2*sz[v]+sz[1];//转移方程
//		dp2(v,u);
//	}
//}
//in main:
//dp1(1,0);
//for(int i=1;i<=n;i++)f[1]+=dep[i];//计算1号节点的答案
//dp2(1,0);
//int ans=-19260817,id=0;
//for(int i=1;i<=n;i++)
//	if(ans<f[i])ans=f[i],id=i;//统计最终的答案
