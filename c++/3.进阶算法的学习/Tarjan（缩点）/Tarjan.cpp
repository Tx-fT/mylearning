#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
vector<vector<int>> g;     // 邻接表，存引爆关系 u->v 代表点燃u可引爆v
int n;                     // 炸弹总数量
int dfn[N];                // 节点首次遍历时间戳            我是第几个被访问的（时间戳，只增不减）
int low[N];                // 节点能回溯到的最小时间戳       我能绕回最早的那个点
int time1;                 // 时间戳计数器
int cnt;                   // 强连通分量编号
int id[N];                 // 记录每个节点所属连通块编号

stack<int> stk;            // tarjan算法栈
                           // 存当前这条 DFS 搜索路径上，还没确定归属、还没划分好连通块的所有节点
                           //入栈：遍历到节点就放进去
                           //出栈：找到分量根节点，统一弹出批量分配编号

//炸弹结构体
struct node { int p, l, r; };
vector<node> t;            // 存储所有炸弹位置与爆炸范围

bool st[N];                // 标记节点是否在栈中

int in_deg[N];             // 缩点后每个连通块的入度

void tarjan(int u)
{
    dfn[u] = low[u] = ++time1;//更新时间戳，从我自己开始，可回溯的起点当然也是我自己

    stk.push(u);
    st[u] = true;//标记是否入栈

    // 遍历当前炸弹能直接引爆的所有炸弹
    for (int v : g[u])
    {
        if (!dfn[v])//还没有被访问，加入强连通分量
        {
            tarjan(v);//dfs

            low[u] = min(low[u], low[v]);//儿子若找到祖先说明儿子已经变了，直接用low
        }
		
		//****：首先dfs说明一条单向路，然后儿子找到祖先说明儿子的长辈顺着儿子也能找到祖先，最后找到最老资历
		
        // 遇到栈内节点，更新回溯最小值
        else if (st[v])
            low[u] = min(low[u], dfn[v]);//找到祖先了，变为祖先时间dfn
    }

    // 找到连通块根节点，完成缩点分组
    if (dfn[u] == low[u])//这个点，再也回不到更早的点了。
                         //它就是这个环 / 连通块的 “起点” → 根节点！
     {
         cnt++;//强连通块编号/数目+1
         
         //DFS沿路节点入栈，更新low筛出根，出栈统一分配连通块编号。
         while (true)
         {
            int y = stk.top();
            stk.pop();
            st[y] = false;
            id[y] = cnt;//#****关键
            if (y == u) break;
         }
     }
     //遍历一个连通块，所有可达点，更新时间戳dfn、追溯值low，最后赋予连通块编号id
}

int main()
{
    cin >> n;
    g.resize(n);//初始化邻接表容量

    // 录入所有炸弹信息
    for (int i = 0; i < n; i++)
    {
        int p, l, r;
        cin >> p >> l >> r;
        t.push_back({p, l, r});
    }


    // 按位置排序，方便批量查找可引爆炸弹，假定为一维线性分布
    sort(t.begin(), t.end(), [&](auto &a, auto &b)
    {
        return a.p < b.p;
    });

    // 建立引爆关系图
    for (int i = 0; i < n; i++)
    {
        int L = t[i].p - t[i].l;
        int R = t[i].p + t[i].r;


        // 只要坐标在引爆范围内都可以定义为邻居，加入邻接表
        // 注意是线性的
        // 1，2 （不行），3    如果2不在1的爆炸范围内，在将1加入邻接表后，循环结束
 
        // 左边
        for (int j = i - 1; j >= 0 && t[j].p >= L; j--)
            g[i].push_back(j);
        // 右边
        for (int j = i + 1; j < n && t[j].p <= R; j++)
            g[i].push_back(j);
    }

    // 遍历所有节点，求出全部强连通分量,标记dfn,low,    id(*关键)
    for (int i = 0; i < n; i++)//分块
        if (!dfn[i]) tarjan(i);//比如有1~7
                               //第一次，1，2，3，4，5分为一块，id标记=1
                               //第二次，6分为一块           ，id标记=2
                               //第三次，7分为一块           ，id标记=3


    // 统计不同连通块之间的入度
    for (int u = 0; u < n; u++)//每个炸弹
    {
        for (int v : g[u])//考虑邻居（可以顺带引爆的）
        {
            if (id[u] != id[v])
                in_deg[id[v]]++;
                /*
                举例7个炸弹场景：
                连通块1：1、2、3、4、5 互相引爆，双向互通
                连通块2：6 自身独立
                连通块3：7 自身独立
                特殊关系：6爆炸范围大，可以单向引爆2；但2范围小，无法反向引爆6
                缩点后id[6]≠id[2]，遍历边6→2时，满足id不同
                连通块1入度+1，代表连通块1可以被连通块6引爆，并非完全独立
                */
        }
    }

    // 核心思路：入度为0的连通块无法被其他炸弹引爆，必须手动点燃
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (in_deg[i] == 0)
            ans++;
    }
    cout << ans;
    return 0;
}
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
