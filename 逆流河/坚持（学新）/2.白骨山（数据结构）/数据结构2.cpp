//树习题
//一直前序遍历，中序遍历求后序遍历
//分而治之
//#include<iostream>
//using namespace std;
//int pre[6]={1,2,3,4,5,6};
//int in[6]={3,2,4,1,6,5};
//int post[6];
//void solve(int prel,int inl,int postl,int n){
//	if(n==0) return;
//	if(n==1){
//		post[postl]=pre[prel];
//		return;
//	}
//	int l,r;
//	int root=pre[prel];
//	post[postl+n-1]=root;
//	for(int i=0;i<n;i++){
//		if(in[inl+i]==root){
//			l=i;
//			r=n-l-1;
//			break;
//		}
//	}
//	solve(prel+1,inl,postl,l);
//	solve(prel+1+l,inl+l+1,postl+l,r);
//}
//int main(){
//	solve(0,0,0,6);
//	for(int i=0;i<6;i++){
//		cout<<post[i];
//	}
//	return 0;
//}
//完全二叉搜索树
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#define maxsize 30
//using namespace std;
//int arr[maxsize];
//bool cmp(int a,int b){
//	return a<b;
//}
//int getl(int num){
//	int n=0;
//	double i;
//	for(i=0;n+pow(2.00,i)<num;i++){
//		n+=pow(2.00,i);
//	}
//	int left=num-n;
//	if(left<pow(2.00,i)/2){
//		return left+(n-1)/2;
//	}
//	return (n-1)/2+pow(2.00,i)/2;
//}
//void solve(int al,int ar){//随深度变化的量
//	int n;
//	n=ar-al+1;
//	if(n<=0){
//		return;
//	}
//	int num1=getl(n);
//	cout<<arr[num1+al]<<endl;
//	solve(al,al+num1-1);
//	solve(al+num1+1,ar);
//}
//int main(){
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>arr[i];
//	}
//	sort(arr,arr+n,cmp);
//	solve(0,n-1);
//	return 0;
//}
//二分查找
//#include<iostream>
//using namespace std;
//void erfen(int l,int r,int arr[],int d){
//	if(l>r){
//		cout<<"no";
//		return;
//	}
//	int mid=l+(r-l)/2;
//	if(arr[mid]==d){
//		cout<<"yes";
//		return;
//	}
//	if(arr[mid]<d){
//		erfen(mid+1,r,arr,d);
//	}
//	if(arr[mid]>d){
//		erfen(l,mid-1,arr,d);
//	}
//}
//int main(){
//	int arr[10]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
//	erfen(0,9,arr,17);
//	return 0;
//}
//判断是否是最优编码
//huffman codes特点
//1.最优编码--总长度wpl最小
//2.无歧义的解码--前缀码：数据仅存到叶子节点
//没有度（一个节点的孩子数）为一的节点--满足一二则必有三
//算法实现
//Huffman编码自己实现一次！！
//#include<iostream>
//using namespace std;
//struct heapnode{
//  int capacity;
//	int size;
//	int* p;
//};
//typedef struct heapnode* minheap;
//minheap creatheap(){
//	
//} 
//int main(){
//	//1.计算最优编码长度
//	//思路：创建huffman tree要建立权重最小堆
//	minheap h=creatheap();
//	
//	return 0;
//}
//最短路径
//按照递增（非递减）的顺序找出各个顶点的最短路径bfs
//bfs算法
//#include<iostream>
//#include<stdlib.h>
//#define vertex int
//#define maxsize 10
//using namespace std;
//typedef struct gnode* mgraph;
//struct gnode{
//	int v;
//	int e;
//	vertex g[maxsize][maxsize];
//};
//mgraph creat(int vnum){
//	mgraph temp;
//	temp=new gnode;
//	temp->e=0;
//	temp->v=vnum;
//	for(int i=0;i<vnum;i++){
//		for(int j=0;j<vnum;j++){
//			temp->g[i][j]=0;
//		}
//	}
//	return temp;
//}
//void insertedge(mgraph g,int v,int w){
//	g->g[v][w]=1;
//	g->g[w][v]=1;
//}
//void bfs(mgraph g,vertex idx,int dist[],int pre[]){
//	int front=0,reer=0;
//	int q[maxsize];
//	q[reer++]=idx;
//	while(front!=reer){
//		int cur=q[front++];
//		for(int i=0;i<g->v;i++){
//			if(g->g[cur][i]&&dist[i]<0){
//				dist[i]=dist[cur]+1;
//				q[reer++]=i;
//				pre[i]=cur;
//		   }
//		}
//	 }
//}
//void find(int st,int en,mgraph g){
//	int dist[g->v];
//	int pre[g->v];
//	for(int i=0;i<g->v;i++){
//		dist[i]=-1;
//		pre[i]=-1;
//	}
//	dist[st]=0;
//	bfs(g,st,dist,pre);
//	cout<<dist[en]<<endl;
//	int top=-1;
//	int stack[g->v];
//	int temp=en;
//	while(temp!=-1){
//		stack[++top]=temp;
//		temp=pre[temp];
//	}
//	for(int i=top;i>=0;i--){
//		if(i!=top){
//			cout<<"->";
//		}
//		cout<<stack[i];
//	}
//}
//int main(){
//	int n;
//	cin>>n;
//	mgraph g=creat(n);
//	int num;
//	cin>>num;
//	g->e=num;
//	for(int i=0;i<num;i++){
//		int v,w;
//		cin>>v>>w;
//		insertedge(g,v,w);
//	}
//	int st,en;
//	cin>>st>>en;
//	find(st,en,g);
//	return 0;
//}
//有权图单源最短路径算法
//Dijkstra算法
/* 邻接矩阵存储 - 有权图的单源最短路径算法 */
//#include <stdio.h>
//#include <limits.h>
//
//// 宏定义与类型别名（根据代码上下文补充必要的基础定义）
//#define MaxVertexNum 100    // 最大顶点数
//#define INFINITY INT_MAX    // 用无穷大表示不存在的边
//#define ERROR -1            // 错误标记
//typedef int Vertex;         // 顶点用下标表示，设为整型
//typedef int WeightType;     // 边的权值设为整型
//
//// 图的邻接矩阵存储结构
//typedef struct GNode *PtrToGNode;
//struct GNode {
//    int Nv;                // 顶点数
//    int Ne;                // 边数
//    WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵
//};
//typedef PtrToGNode MGraph;
//
///* 邻接矩阵存储 - 有权图的单源最短路径算法 */
//Vertex FindMinDist( MGraph Graph, int dist[], int collected[] )
//{ /* 返回未被收录顶点中dist最小者 */
//    Vertex MinV, V;
//    int MinDist = INFINITY;
//
//    for (V=0; V<Graph->Nv; V++) {
//        if ( collected[V]==false && dist[V]<MinDist) {
//            /* 若V未被收录，且dist[V]更小 */
//            MinDist = dist[V]; /* 更新最小距离 */
//            MinV = V; /* 更新对应点 */
//        }
//    }
//
//    if (MinDist < INFINITY) /* 若找到最小dist */
//        return MinV; /* 返回对应的顶点下标 */
//    else return ERROR;   /* 若这样的顶点不存在，返回错误标记 */
//}
//
//bool Dijkstra( MGraph Graph, int dist[], int path[], Vertex S )
//{
//    int collected[MaxVertexNum];
//    Vertex V, W;
//
//    /* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
//    for ( V=0; V<Graph->Nv; V++ ) {
//        dist[V] = Graph->G[S][V];
//        if ( dist[V]<INFINITY )
//            path[V] = S;
//        else
//            path[V] = -1;
//        collected[V] = false;//在外设置全部
//    }
//    /* 先将起点收入集合 */
//    dist[S] = 0;
//    collected[S] = true;
//
//    while (1) {
//        /* V = 未被收录顶点中dist最小者 */
//        V = FindMinDist( Graph, dist, collected );
//        if ( V==ERROR ) /* 若这样的V不存在 */
//            break;      /* 算法结束 */
//        collected[V] = true;  /* 收录V */
//        for( W=0; W<Graph->Nv; W++ ) {
//            /* 若W是V的邻接点并且未被收录 */
//            if ( collected[W]==false && Graph->G[V][W]<INFINITY ) {
//                if ( Graph->G[V][W]<0 ) /* 若有负边 */
//                    return false; /* 不能正确解决，返回错误标记 */
//                /* 若收录V使得dist[W]变小 */
//                if ( dist[V]+Graph->G[V][W] < dist[W] ) {
//                    dist[W] = dist[V]+Graph->G[V][W]; /* 更新dist[W] */
//                    path[W] = V; /* 更新S到W的路径 */
//                }
//            }
//        }
//    } /* while结束*/
//    return true; /* 算法执行完毕，返回正确标记 */
//}
//多源最短路算法
//方法1：直接将单源最短路算法调用n遍（对于稀疏图效果好）
//方法2：floyd算法（稠密图）
/* 邻接矩阵存储 - 多源最短路算法 */

//#include <stdio.h>
//#include <limits.h>  // 引入无穷大常量 INT_MAX
//
//// ===================== 宏定义与结构体定义 【标准固定写法】 =====================
//#define MaxVertexNum 100   // 图的最大顶点数量，可按需修改
//typedef int Vertex;        // 顶点下标，用整型表示，取值范围 0 ~ 顶点数-1
//typedef int WeightType;    // 边的权值类型，支持正权、负权（不支持负权环）
//const WeightType INF = INT_MAX; // 定义【无穷大】：表示两点之间没有边，不可达
//
//// 图的邻接矩阵存储结构
//typedef struct GNode *MGraph;
//struct GNode {
//    int Nv;  // 顶点的总数
//    int Ne;  // 边的总数
//    WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵核心：存储所有边的权值
//};

// ===================== Floyd算法核心函数 【你给的原函数+完整补全+逐行注释】 =====================
/**
 * @brief Floyd算法：求解图中【所有顶点对】的最短路径（多源最短路径）
 * @param Graph 指向邻接矩阵存储的图的指针
 * @param D 输出参数 距离矩阵，D[i][j]存储i到j的最短路径总权值
 * @param path 输出参数 路径矩阵，path[i][j]存储i到j最短路径的【中转顶点】
 * @return bool值：true=无负权环，计算成功；false=存在负权环，最短路径无意义
 */
//bool Floyd( MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum] )
//{
//    Vertex i, j, k;  // k：中转顶点  i：起点顶点  j：终点顶点
//
//    /* ===================== 步骤1：初始化距离矩阵 D 和 路径矩阵 path 【标准答案】 ===================== */
//    for ( i=0; i<Graph->Nv; i++ ){
//        for( j=0; j<Graph->Nv; j++ ) {
//            if (i == j) {
//                D[i][j] = 0;          // ★核心规则1：顶点自己到自己的距离为 0
//            } else {
//            	if(Graph->G[i][j]<INT_MAX){
//					D[i][j] = Graph->G[i][j]; 
//				}
//                else{// ★核心规则2：其余点，用邻接矩阵的权值初始化                       
//					D[i][j]-INT_MAX;
//				}// 这里的Graph->G[i][j] 已经是 无穷大/对应边权
//            }
//            path[i][j] = -1;          // 路径矩阵初始化：path[i][j]=-1 表示 i到j【无中转顶点】
//        }
//    }
//
//    /* ===================== 步骤2：Floyd核心三层循环 - 插点松弛法 【固定顺序：k→i→j 绝对不能换】 ===================== */
//    // 核心思想：依次将每个顶点k作为「中转点」，尝试优化 所有起点i 到 所有终点j 的路径
//    // 松弛条件：如果 i→k→j 的路径长度  <  原i→j的路径长度，则更新路径
//    for( k=0; k<Graph->Nv; k++ ){        // 第一层：枚举 所有中转顶点k
//        for( i=0; i<Graph->Nv; i++ ){    // 第二层：枚举 所有起点顶点i
//            for( j=0; j<Graph->Nv; j++ ){ // 第三层：枚举 所有终点顶点j
//                // ★【必加判断】防止无穷大相加溢出 + 保证i到k、k到j都可达
//                if( D[i][k] != INF && D[k][j] != INF ){
//                    // 松弛操作：中转路径更短，则更新距离和路径
//                    if( D[i][k] + D[k][j] < D[i][j] ) {
//                        D[i][j] = D[i][k] + D[k][j];  // 更新i到j的最短路径权值
//                        path[i][j] = k;               // 记录中转点：i到j的最短路径 必须经过k
//                    }
//                }
//            }
//        }
//    }
//
//    /* ===================== 步骤3：负权环（负值圈）检测 【修复原代码的位置错误，这是正确位置】 ===================== */
//    // 原代码错误：把负权环检测写在松弛的if里面 → 只能检测到「松弛时发现的负环」，会漏检！
//    // 正确逻辑：松弛完成后，遍历所有i==j的情况，只要D[i][i]<0 就说明存在负权环
//    for(i=0; i<Graph->Nv; i++){
//        if(D[i][i] < 0){  // 顶点i 到 自身 的最短路径权值 < 0 → 存在从i出发回到i的负权环
//            return false; // 存在负权环，算法失效，返回false
//        }
//    }
//
//    return true;  // 所有顶点对的最短路径计算完成，无负权环，返回成功标记
//}
//案例：hurry poter's exam;
//#include<iostream>
//#include<limits.h>
//#define maxsize 10
//using namespace std;
////mgraph的一套定义
//typedef struct gnode* mgraph;
//struct gnode{
//	int v;
//	int e;
//	int g[maxsize][maxsize];
//};
//mgraph creatgraph(int vnum){
//	mgraph t=new gnode;
//	t->e=0;
//	t->v=vnum;
//	for(int i=0;i<vnum;i++){
//		for(int j=0;j<vnum;j++){
//			t->g[i][j]=0;
//		}
//	}
//	return t;
//}
//void insertedge(mgraph g,int weight,int v1,int v2){
//	v1--; v2--; 
//	g->g[v1][v2]=weight;
//	g->g[v2][v1]=weight;
//}
//mgraph buildgraph(){
//	int vnum;
//	cin>>vnum;
//	mgraph g;
//	g=creatgraph(vnum);
//	int en;
//	cin>>en;
//	g->e=en;
//	for(int i=0;i<en;i++){
//		int v1,v2,w;
//		cin>>v1>>v2>>w;
//		insertedge(g,w,v1,v2);
//	}
//	return g;
//}
////分析图
////1.找一行中最大值
//void findmax(int arr[],int d[][maxsize],int vnum){
//	for(int i=0;i<vnum;i++){
//		int max=0;
//		for(int j=0;j<vnum;j++){
//			if(d[i][j]>max){
//				max=d[i][j];
//			}
//			arr[i]=max;
//		}
//	}
//}
////2.找最大之中的最小值
//int findmin(int arr[],int vnum){
//	int min=INT_MAX;
//	int ans=0;
//	for(int i=0;i<vnum;i++){
//		if(arr[i]<min){
//			min=arr[i];
//			ans=i;
//		}
//	}
//	return ans;
//}
//void findanimal(mgraph g){
//	//floyd 算法
//	int pre[maxsize][maxsize];
//	int d[maxsize][maxsize];
//	for(int i=0;i<g->v;i++){
//		for(int j=0;j<g->v;j++){
//			if(i==j){
//				d[i][j]=0;
//			}
//			else{
//				if(g->g[i][j]==0){
//					d[i][j]=INT_MAX;
//				}
//				else{
//					d[i][j]=g->g[i][j];
//				}
//			}
//			pre[i][j]=-1;
//		}
//	}
//	for(int k=0;k<g->v;k++){
//		for(int i=0;i<g->v;i++){
//			for(int j=0;j<g->v;j++){
//				if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX){
//					if(d[i][k]+d[k][j]<d[i][j]){
//						d[i][j]=d[i][k]+d[k][j];
//						pre[i][j]=k;
//					}
//				}
//			}
//		}
//	}
//	int arr[g->v];
//	findmax(arr,d,g->v);
//	int index=findmin(arr,g->v)+1;
//	if(index==0){
//		cout<<"图不连通"<<endl;
//	}
//	cout<<index;
//}
//int main(){
//	//读入图
//	mgraph g=buildgraph();
//	//分析图
//	findanimal(g);
//	return 0;
//}

//Prim算法
//最小生成树
//是一棵树
//无回路
//v个顶点一定有v-1条边
//是生成树
//包含全部顶点
//v-1条边都在图里
//向生成树中任加一条边都一定构成回路
//边的权重和最小
//最小生成树存在
//算法：贪心算法
//“贪”：每一步都要最好的
//“好”：权重最小的变
//约束：
//只能用图里有的边
//只能正好用掉v-1边
//不能有回路
//Prim算法--让一颗小树长大--稠密图
//与Dijkstra算法相似
//kruskal算法--将森林合并成树
//prim算法
//#include <stdio.h>
//#include <stdlib.h>
//
///* ===================== 宏定义与常量声明 ===================== */
//// 最大顶点数，可根据需求修改
//#define MaxVertexNum 100
//// 无穷大，代表两点之间无边相连，权值设为极大值
//#define INFINITY 65535
//// 错误标记，FindMinDist找不到顶点/生成树不连通时返回
//#define ERROR -1
//// 顶点下标类型，用int即可
//typedef int Vertex;
//// 边的权值类型，根据需求可改为float
//typedef int WeightType;
//
///* ===================== 数据结构定义 ===================== */
///**
// * 邻接矩阵存储的图结构 (MGraph)
// * Nv: 顶点数  Ne: 边数
// * G: 二维数组，G[i][j]表示顶点i到顶点j的边权值，无边则为INFINITY
// */
//typedef struct GNode *PtrToGNode;
//struct GNode {
//    int Nv;                    // 顶点的数量
//    int Ne;                    // 边的数量
//    WeightType G[MaxVertexNum][MaxVertexNum]; // 邻接矩阵存储边权
//};
//typedef PtrToGNode MGraph;
//
///**
// * 邻接表存储的边节点结构 (ENode)
// * 用于存储最小生成树的边，最终MST为邻接表存储
// */
//typedef struct ENode *PtrToENode;
//struct ENode {
//    Vertex V1, V2;     // 边的两个端点
//    WeightType Weight; // 边的权值
//};
//typedef PtrToENode Edge;
//
///**
// * 邻接表的顶点结构
// */
//typedef struct AdjVNode *PtrToAdjVNode;
//struct AdjVNode {
//    Vertex AdjV;           // 邻接点的下标
//    WeightType Weight;     // 边的权值
//    PtrToAdjVNode Next;    // 指向下一个邻接点的指针
//};
//
///**
// * 邻接表的表头结构
// */
//typedef struct VNode {
//    PtrToAdjVNode FirstEdge; // 指向第一个邻接点
//} AdjList[MaxVertexNum];
//
///**
// * 邻接表存储的图结构 (LGraph)，用于保存最小生成树MST
// */
//typedef struct LGraphNode *PtrToLGraphNode;
//struct LGraphNode {
//    int Nv;            // 顶点数
//    AdjList G;         // 邻接表核心数组
//};
//typedef PtrToLGraphNode LGraph;
//
///* ===================== 工具函数实现 ===================== */
///**
// * 创建空的邻接表图（仅初始化顶点，无边）
// * @param VertexNum 顶点数量
// * @return 邻接表图的指针，用于存储最小生成树
// */
//LGraph CreateGraph(int VertexNum) {
//    Vertex V;
//    LGraph Graph = (LGraph)malloc(sizeof(struct LGraphNode));
//    Graph->Nv = VertexNum;
//    // 初始化每个顶点的邻接表头，无邻接点则置空
//    for (V = 0; V < Graph->Nv; V++) {
//        Graph->G[V].FirstEdge = NULL;
//    }
//    return Graph;
//}
//
///**
// * 向邻接表存储的图中插入一条边
// * @param Graph 邻接表图（最小生成树MST）
// * @param E 待插入的边节点
// */
//void InsertEdge(LGraph Graph, Edge E) {
//    PtrToAdjVNode NewNode;
//    // 插入边 <V1, V2>：为V2创建邻接点，挂载到V1的邻接表
//    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewNode->AdjV = E->V2;
//    NewNode->Weight = E->Weight;
//    NewNode->Next = Graph->G[E->V1].FirstEdge;
//    Graph->G[E->V1].FirstEdge = NewNode;
//
//    // 无向图的边是双向的，需要插入边 <V2, V1>
//    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewNode->AdjV = E->V1;
//    NewNode->Weight = E->Weight;
//    NewNode->Next = Graph->G[E->V2].FirstEdge;
//    Graph->G[E->V2].FirstEdge = NewNode;
//}
//
///**
// * 创建邻接矩阵存储的图（手动输入顶点数、边数、边权）
// * @return 邻接矩阵图的指针
// */
//MGraph CreateMGraph() {
//    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
//    Vertex V, W;
//    Edge E = (Edge)malloc(sizeof(struct ENode));
//
//    printf("请输入顶点数和边数：");
//    scanf("%d %d", &Graph->Nv, &Graph->Ne);
//
//    // 初始化邻接矩阵：所有点之间无边，权值设为无穷大
//    for (V = 0; V < Graph->Nv; V++) {
//        for (W = 0; W < Graph->Nv; W++) {
//            Graph->G[V][W] = INFINITY;
//        }
//    }
//    // 初始化顶点到自身的权值为0
//    for (V = 0; V < Graph->Nv; V++) {
//        Graph->G[V][V] = 0;
//    }
//
//    // 输入每条边的两个端点和权值，填充邻接矩阵
//    for (int i = 0; i < Graph->Ne; i++) {
//        printf("请输入边(V1, V2)及权值：");
//        scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
//        Graph->G[E->V1][E->V2] = E->Weight;
//        Graph->G[E->V2][E->V1] = E->Weight; // 无向图，双向赋值
//    }
//    free(E);
//    return Graph;
//}
//
///* ===================== 核心算法实现 ===================== */
///**
// * 核心辅助函数：返回未被收录顶点中dist数组值最小的顶点下标
// * @param Graph 邻接矩阵存储的原图
// * @param dist  dist数组：dist[W]表示 已收录顶点集 到 未收录顶点W 的最小边权
// * @return 满足条件的顶点下标，无则返回ERROR(-1)
// * 注：dist[V]=0 代表顶点V已经被收录到最小生成树中
// */
//Vertex FindMinDist(MGraph Graph, WeightType dist[])
//{
//    Vertex MinV, V;
//    WeightType MinDist = INFINITY; // 初始化最小权值为无穷大
//
//    // 遍历所有顶点，筛选符合条件的顶点
//    for (V = 0; V < Graph->Nv; V++) {
//        // 条件1：dist[V]!=0 → 顶点V未被收录
//        // 条件2：dist[V]<MinDist → 当前顶点的权值更小，更新最小值
//        if ( dist[V] != 0 && dist[V] < MinDist ) {
//            MinDist = dist[V];  // 更新当前找到的最小权值
//            MinV = V;           // 更新最小权值对应的顶点下标
//        }
//    }
//    // 找到有效顶点则返回下标，否则返回错误标记
//    if (MinDist < INFINITY)
//        return MinV;
//    else return ERROR;
//}
//
///**
// * 邻接矩阵存储 - Prim最小生成树核心算法
// * @param Graph 邻接矩阵存储的无向连通网（原图）
// * @param MST   邻接表存储的最小生成树（输出参数，保存最终的最小生成树）
// * @return 最小生成树的总权值；若原图不连通，返回ERROR(-1)
// * 算法思想：贪心策略，从初始顶点0出发，每次选「已收录集」到「未收录集」的最小边，逐步扩展生成树
// */
//int Prim(MGraph Graph, LGraph MST)
//{
//    WeightType dist[MaxVertexNum];  // dist[W]: 已收录顶点→未收录顶点W的最小边权
//    WeightType TotalWeight;         // 最小生成树的总权值
//    Vertex parent[MaxVertexNum];    // parent[W]: 顶点W在生成树中的父节点，用于确定边的连接关系
//    Vertex V, W;                    // V：本次选中的最小权值顶点；W：遍历所有顶点的临时变量
//    int VCount;                     // 已收录到生成树中的顶点数量
//    Edge E;                         // 临时边节点，用于插入MST
//    
//    /* ========== 1. 初始化dist、parent数组，默认初始顶点为 0 ========== */
//    for (V = 0; V < Graph->Nv; V++) {
//        // dist[V]初始化为：初始顶点0 到 顶点V 的直接边权（无边则为INFINITY）
//        dist[V] = Graph->G[0][V];
//        parent[V] = 0;            // 所有顶点的父节点暂定为初始顶点0
//    }
//    TotalWeight = 0;              // 初始化总权值为0
//    VCount = 0;                   // 初始化已收录顶点数为0
//    MST = CreateGraph(Graph->Nv); // 创建空的邻接表，用于存储生成树（仅顶点，无边）
//    E = (Edge)malloc( sizeof(struct ENode) ); // 申请临时边节点内存
//
//    /* ========== 2. 将初始顶点0收录到最小生成树 ========== */
//    dist[0] = 0;          // dist[V]=0 作为「顶点已收录」的标记
//    VCount ++;            // 已收录顶点数+1
//    parent[0] = -1;       // 根节点0没有父节点，标记为-1
//
//    /* ========== 3. 核心循环：逐步收录顶点，构建最小生成树 ========== */
//    while (1) {
//        // 步骤1：找到未收录顶点中，dist最小的顶点V
//        V = FindMinDist( Graph, dist );
//        if ( V == ERROR )  // 没有找到有效顶点 → 要么所有顶点已收录，要么原图不连通
//            break;
//
//        // 步骤2：将顶点V 及其对应的边 <parent[V], V> 插入到最小生成树MST中
//        E->V1 = parent[V];
//        E->V2 = V;
//        E->Weight = dist[V];
//        InsertEdge( MST, E );         // 向邻接表插入这条边
//        TotalWeight += dist[V];       // 累加当前边的权值到总权值
//        dist[V] = 0;                  // 标记顶点V已被收录
//        VCount ++;                    // 已收录顶点数+1
//
//        // 步骤3：松弛操作：更新所有未收录顶点的dist和parent
//        for( W = 0; W < Graph->Nv; W++ ) {
//            // 条件1：dist[W]!=0 → 顶点W未被收录
//            // 条件2：Graph->G[V][W]<INFINITY → 顶点V和W之间有直接边相连
//            if ( dist[W] != 0 && Graph->G[V][W] < INFINITY ) {
//                // 若通过新收录的顶点V，到达W的边权 比原来的dist[W]更小 → 更新
//                if ( Graph->G[V][W] < dist[W] ) {
//                    dist[W] = Graph->G[V][W];  // 更新最小边权
//                    parent[W] = V;             // 更新W的父节点为V
//                }
//            }
//        }
//    } /* while循环结束 */
//
//    /* ========== 4. 校验生成树的连通性 ========== */
//    // 若已收录的顶点数 < 原图顶点数 → 原图不连通，无法生成完整生成树
//    if ( VCount < Graph->Nv )
//       TotalWeight = ERROR;
//    
//    free(E);  // 释放临时边节点的内存
//    return TotalWeight;  // 返回总权值 或 错误标记
//}
//
///* ===================== 测试函数：打印最小生成树 ===================== */
//void PrintMST(LGraph MST) {
//    Vertex V;
//    PtrToAdjVNode p;
//    printf("\n最小生成树的边及权值：\n");
//    for (V = 0; V < MST->Nv; V++) {
//        p = MST->G[V].FirstEdge;
//        while (p) {
//            // 避免重复打印无向边（只打印 V < AdjV 的情况）
//            if (V < p->AdjV) {
//                printf("(%d, %d) → %d\n", V, p->AdjV, p->Weight);
//            }
//            p = p->Next;
//        }
//    }
//}
//
///* ===================== 主函数：测试Prim算法 ===================== */
//int main() {
//    MGraph Graph = CreateMGraph();
//    LGraph MST;
//    int total = Prim(Graph, MST);
//    if (total == ERROR) {
//        printf("\n原图不连通，无法生成最小生成树！\n");
//    } else {
//        printf("\n最小生成树的总权值为：%d\n", total);
//        PrintMST(MST);
//    }
//    return 0;
//}
//kruskal算法
//直截了当贪心
//把最小边收进来，不能成回路
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
///* -------------------------- 基础类型定义 -------------------------- */
//// 顶点类型（用非负整数表示）
//typedef int Vertex;
//// 边的权值类型
//typedef int WeightType;
//
//// 邻接表的边结点结构
//typedef struct AdjVNode *PtrToAdjVNode;
//struct AdjVNode {
//    Vertex AdjV;          // 邻接点的索引
//    WeightType Weight;    // 边的权值
//    PtrToAdjVNode Next;   // 指向下一个边结点
//};
//
//// 邻接表的顶点结构
//typedef struct VNode {
//    PtrToAdjVNode FirstEdge;  // 指向第一个边结点
//} VNode;
//
//// 邻接表表示的图结构
//typedef struct GNode *LGraph;
//struct GNode {
//    int Nv;  // 顶点数
//    int Ne;  // 边数
//    VNode G[100];  // 顶点数组（假设最大顶点数为100，可修改）
//};
//
//// 边的结构（用于最小堆/边数组）
//typedef struct ENode *Edge;
//struct ENode {
//    Vertex V1;        // 边的起点
//    Vertex V2;        // 边的终点
//    WeightType Weight;// 边的权值
//};
//
///* -------------------------- 顶点并查集定义 -------------------------- */
//typedef Vertex ElementType;  // 并查集元素类型（对应顶点）
//typedef Vertex SetName;      // 集合名称（用根结点下标表示）
//#define MaxVertexNum 100     // 最大顶点数（与图的顶点数组对应）
//typedef ElementType SetType[MaxVertexNum];
//
//// 初始化并查集：每个顶点自成一个集合（值为-1）
//void InitializeVSet(SetType S, int N) {
//    ElementType X;
//    for (X = 0; X < N; X++)
//        S[X] = -1;
//}
//
//// 合并两个集合（按大小合并，小集合并入大集合）
//void Union(SetType S, SetName Root1, SetName Root2) {
//    // 保证Root1和Root2是不同集合的根
//    if (S[Root2] < S[Root1]) {  // 集合2的规模更大
//        S[Root2] += S[Root1];   // 集合1的规模合并到集合2
//        S[Root1] = Root2;       // 集合1的根指向集合2的根
//    } else {                    // 集合1的规模更大
//        S[Root1] += S[Root2];   // 集合2的规模合并到集合1
//        S[Root2] = Root1;       // 集合2的根指向集合1的根
//    }
//}
//
//// 查找元素X的根（带路径压缩）
//SetName Find(SetType S, ElementType X) {
//    if (S[X] < 0)  // X是根结点
//        return X;
//    else
//        return S[X] = Find(S, S[X]);  // 路径压缩：将X的父结点直接指向根
//}
//
//// 检查边(V1,V2)是否会构成回路：
//// 若V1和V2已连通则返回false（不能加入）；否则合并集合并返回true（可以加入）
//bool CheckCycle(SetType VSet, Vertex V1, Vertex V2) {
//    Vertex Root1 = Find(VSet, V1);
//    Vertex Root2 = Find(VSet, V2);
//    if (Root1 == Root2)
//        return false;  // 已连通，构成回路
//    else {
//        Union(VSet, Root1, Root2);  // 合并集合
//        return true;                // 未构成回路
//    }
//}
//
///* -------------------------- 边的最小堆定义 -------------------------- */
//// 下滤调整：将以ESet[p]为根的子堆调整为最小堆（按Weight排序）
//void PercDown(Edge ESet, int p, int N) {
//    int Parent, Child;
//    struct ENode X = ESet[p];  // 取出根结点的值
//    for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
//        Child = Parent * 2 + 1;  // 左孩子
//        // 选择左右孩子中权值较小的那个
//        if ((Child != N - 1) && (ESet[Child].Weight > ESet[Child + 1].Weight))
//            Child++;
//        if (X.Weight <= ESet[Child].Weight)
//            break;  // 找到合适位置，停止下滤
//        else
//            ESet[Parent] = ESet[Child];  // 下滤：子结点上移
//    }
//    ESet[Parent] = X;  // 将根结点放入最终位置
//}
//
//// 交换两个边的内容
//void Swap(Edge a, Edge b) {
//    struct ENode temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 将图的边存入数组ESet，并初始化为最小堆
//void InitializeESet(LGraph Graph, Edge ESet) {
//    Vertex V;
//    PtrToAdjVNode W;
//    int ECount = 0;
//    // 遍历图的邻接表，收集所有边（无向图只存V1<V2的边，避免重复）
//    for (V = 0; V < Graph->Nv; V++) {
//        for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
//            if (V < W->AdjV) {  // 只存V1 < V2的边（无向图）
//                ESet[ECount].V1 = V;
//                ESet[ECount].V2 = W->AdjV;
//                ESet[ECount++].Weight = W->Weight;
//            }
//        }
//    }
//    // 构建最小堆：从最后一个非叶结点开始下滤********用现有数据群建堆
//    for (ECount = Graph->Ne / 2; ECount >= 0; ECount--)
//        PercDown(ESet, ECount, Graph->Ne);
//}
//
//// 弹出最小堆的堆顶（权值最小的边），并调整堆
//// 返回值：最小边在ESet中的位置
//int GetEdge(Edge ESet, int CurrentSize) {
//    Swap(&ESet[0], &ESet[CurrentSize - 1]);  // 堆顶与最后一个元素交换
//    PercDown(ESet, 0, CurrentSize - 1);      // 调整剩余元素为最小堆
//    return CurrentSize - 1;                  // 返回最小边的位置
//}
//
///* -------------------------- 图的基础操作 -------------------------- */
//// 创建空图（邻接表）
//LGraph CreateGraph(int Nv) {
//    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
//    Graph->Nv = Nv;
//    Graph->Ne = 0;
//    for (int i = 0; i < Nv; i++)
//        Graph->G[i].FirstEdge = NULL;
//    return Graph;
//}
//
//// 向图中插入一条边（邻接表）
//void InsertEdge(LGraph Graph, Edge E) {
//    // 插入V1->V2的边
//    PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewNode->AdjV = E->V2;
//    NewNode->Weight = E->Weight;
//    NewNode->Next = Graph->G[E->V1].FirstEdge;
//    Graph->G[E->V1].FirstEdge = NewNode;
//
//    // 无向图，还需插入V2->V1的边
//    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
//    NewNode->AdjV = E->V1;
//    NewNode->Weight = E->Weight;
//    NewNode->Next = Graph->G[E->V2].FirstEdge;
//    Graph->G[E->V2].FirstEdge = NewNode;
//
//    Graph->Ne++;
//}
//
///* -------------------------- Kruskal算法核心 -------------------------- */
//// 输入：邻接表表示的图Graph
//// 输出：最小生成树MST（邻接表），返回最小权值和；若无法生成树则返回-1
//int Kruskal(LGraph Graph, LGraph *MST) {
//    WeightType TotalWeight;
//    int ECount, NextEdge;
//    SetType VSet;  // 顶点并查集
//    Edge ESet;     // 边的最小堆数组
//
//    // 初始化顶点并查集
//    InitializeVSet(VSet, Graph->Nv);
//
//    // 初始化边的最小堆
//    ESet = (Edge)malloc(sizeof(struct ENode) * Graph->Ne);
//    InitializeESet(Graph, ESet);
//
//    // 创建空的最小生成树（包含所有顶点，无边）
//    *MST = CreateGraph(Graph->Nv);
//    TotalWeight = 0;  // 初始化权值和
//    ECount = 0;       // 已收录的边数
//
//    NextEdge = Graph->Ne;  // 初始边集规模
//    // 最小生成树需要Nv-1条边
//    while (ECount < Graph->Nv - 1) {
//        // 取出当前权值最小的边
//        NextEdge = GetEdge(ESet, NextEdge);
//        if (NextEdge < 0)  // 边集已空，无法生成树
//            break;
//
//        // 检查该边是否构成回路
//        if (CheckCycle(VSet, ESet[NextEdge].V1, ESet[NextEdge].V2)) {
//            // 将边插入最小生成树MST
//            InsertEdge(*MST, &ESet[NextEdge]);
//            TotalWeight += ESet[NextEdge].Weight;  // 累计权值
//            ECount++;  // 边数+1
//        }
//    }
//
//    free(ESet);  // 释放边数组
//
//    // 若边数不足Nv-1，说明无法生成树
//    if (ECount < Graph->Nv - 1) {
//        TotalWeight = -1;
//        // 释放无效的MST
//        // （可选：这里简化处理，实际需补充MST的销毁函数）
//    }
//    return TotalWeight;
//}
//拓扑排序
//AOV(activity on vertex)网络
//顶点间有向边表示两个顶点间的先后顺序
//拓扑序：如果如果图中从v到w有一条有向路径，则v一定排在w之前。满足此条件的顶点序列称为一个拓扑序
//获得一个拓扑序的过程就是拓扑排序
//AOV如果有合理的拓扑序，则必定是有向无环图（DAG）
//若有环：v必须在开始前结束
//输出没有前驱顶点的节点
//#include<iostream>
//using namespace std;
//
//// ====================== 1. 全局常量定义 ======================
//// 最大顶点数，可根据工程工序规模调整
//const int MaxVertexNum = 100;
//// 边的权值/活动时间的无穷大定义（用于关键路径的最晚发生时间初始化）
//const int INF = 0x3f3f3f3f;
//// 顶点下标类型定义，顶点编号从0开始
//typedef int Vertex;
//// 边的权值类型定义，代表工序的持续时间/活动耗时
//typedef int WeightType;
//
//// ====================== 2. 邻接表的边节点结构体定义 ======================
//// 邻接表中，每个顶点的邻接边链表节点
//typedef struct AdjVNode {
//    Vertex AdjV;            // 该边指向的 邻接点的顶点下标
//    WeightType weight;      // 该边的权值，AOE网中代表【活动持续时间】
//    struct AdjVNode *Next;  // 指向下一个邻接边节点的指针
//} *PtrToAdjVNode;
//
//// ====================== 3. 邻接表的顶点结构体定义 ======================
//typedef struct VNode {
//    PtrToAdjVNode FirstEdge; // 指向该顶点的第一条邻接边
//} AdjList[MaxVertexNum];
//
//// ====================== 4. 完整的图(邻接表)结构体定义 ======================
//typedef struct {
//    AdjList G;       // 邻接表的核心数组，存储所有顶点的边链表
//    int Nv;          // 图的顶点数 (Number of Vertex)
//    int Ne;          // 图的边数 (Number of Edge)
//} gnode;            // LGraph = Linked Graph 邻接表存储的图
//typedef gnode* LGraph;
//// ====================== 5. 队列的结构体定义(拓扑排序专用) ======================
//// 拓扑排序的核心思想是用队列存储【入度为0】的顶点，这里实现顺序队列
//typedef struct QNode {
//    Vertex Data[MaxVertexNum]; // 存储顶点下标
//    int front;                 // 队头指针
//    int rear;                  // 队尾指针
//} *Queue;
//
//// ====================== 6. 队列的基础操作函数 ======================
///**
// * 创建空队列
// * @param maxSize 队列最大容量，传入顶点数即可
// * @return 初始化后的队列指针
// */
//Queue CreateQueue(int maxSize) {
//    Queue Q = new QNode;
//    Q->front = 0;
//    Q->rear = 0;
//    return Q;
//}
//
///**
// * 判断队列是否为空
// * @param Q 队列指针
// * @return 空返回true，非空返回false
// */
//bool IsEmpty(Queue Q) {
//    return (Q->front == Q->rear);
//}
//
///**
// * 入队操作：将顶点v加入队列尾部
// * @param Q 队列指针
// * @param v 待入队的顶点下标
// * @return 入队成功返回true
// */
//bool AddQ(Queue Q, Vertex v) {
//    // 顺序队列简单判满，顶点数不超过MaxVertexNum则不会满
//    if ((Q->rear + 1) % MaxVertexNum == Q->front) {
//        cout << "队列已满！" << endl;
//        return false;
//    }
//    Q->Data[Q->rear] = v;
//    Q->rear = (Q->rear + 1) % MaxVertexNum;
//    return true;
//}

/**
 * 出队操作：从队头取出一个顶点
 * @param Q 队列指针
 * @return 队头的顶点下标
 */
//Vertex DeleteQ(Queue Q) {
//    if (IsEmpty(Q)) {
//        cout << "队列为空！" << endl;
//        return -1; // 返回无效顶点下标
//    }
//    Vertex v = Q->Data[Q->front];
//    Q->front = (Q->front + 1) % MaxVertexNum;
//    return v;
//}
//
//// ====================== 7. 你提供的核心：拓扑排序算法【补全+逐行注释】 ======================
///**
// * 对邻接表存储的有向无环图(DAG)进行拓扑排序
// * @param Graph 邻接表存储的图（AOE网必须是DAG，否则有环无法安排工序）
// * @param TopOrder 输出型数组，顺序存储排序后的顶点下标，存储拓扑序列
// * @return 拓扑排序成功返回true；若返回false，说明图中有回路，无拓扑序列，工程不可行
// */
//bool TopSort( LGraph Graph, Vertex TopOrder[] )
//{ 
//    int Indegree[MaxVertexNum], cnt; // Indegree[]:存储每个顶点的入度  cnt:统计拓扑序列的顶点个数
//    Vertex V;                        // 遍历用的顶点下标
//    PtrToAdjVNode W;                 // 遍历邻接边的指针
//    Queue Q = CreateQueue( Graph->Nv ); // 创建队列，容量为顶点数
//
//    /* 初始化所有顶点的入度为0 */
//    for (V=0; V<Graph->Nv; V++)
//        Indegree[V] = 0;
//        
//    /* 遍历整张图，统计每个顶点的入度 */
//    for (V=0; V<Graph->Nv; V++)      // 遍历每个顶点
//        for (W=Graph->G[V].FirstEdge; W; W=W->Next) // 遍历当前顶点的所有邻接边
//            Indegree[W->AdjV]++;     // 对有向边<V, W->AdjV>，终点的入度+1
//            
//    /* 拓扑排序前置：将所有入度为0的顶点入队 */
//    for (V=0; V<Graph->Nv; V++)
//        if ( Indegree[V]==0 )       // 入度为0的顶点：无前置工序，可最先执行
//            AddQ(Q, V);
//            
//    /* 拓扑排序核心循环 */ 
//    cnt = 0; // 初始化拓扑序列的顶点计数
//    while( !IsEmpty(Q) ){
//        V = DeleteQ(Q); // 取出队首的【入度为0】顶点
//        TopOrder[cnt++] = V; // 将该顶点存入拓扑序列，计数+1
//
//        /* 遍历当前顶点V的所有邻接边，消除V的出边对邻接点的影响 */
//        for ( W=Graph->G[V].FirstEdge; W; W=W->Next ){
//            // 邻接点的入度-1：代表V这个前置工序已完成
//            if ( --Indegree[W->AdjV] == 0 ){
//                AddQ(Q, W->AdjV); // 入度变为0 → 无前置工序，入队等待处理
//            }
//        }
//    } /* while结束*/
//    
//    // 核心判断：拓扑序列的顶点数 == 图的总顶点数？
//    if ( cnt != Graph->Nv )
//        return false; // 不相等 → 图中有回路，拓扑排序失败，工程有循环依赖，不可行
//    else
//        return true;  // 相等 → 拓扑排序成功，得到合法的工序执行顺序
//}
//
//// ====================== 8. 关键路径求解核心算法【AOE网核心，必补！】 ======================
///**
// * 基于拓扑排序求解AOE网的关键路径（工程最短完成时间+关键工序）
// * AOE网核心概念：
// * 1. 事件：顶点代表事件，是某几个活动完成的标志
// * 2. 活动：边代表活动，是具体的工序，有权值代表耗时
// * 3. 关键路径：从源点(起点)到汇点(终点)的最长路径，路径长度=工程最短完成时间
// * 4. 关键活动：关键路径上的所有活动，延误该活动会导致整个工程延期
// * @param Graph 邻接表存储的AOE网
// */
//void CriticalPath(LGraph Graph) {
//    Vertex TopOrder[MaxVertexNum]; // 存储拓扑序列
//    // 第一步：先做拓扑排序，失败则直接退出（有回路，无关键路径）
//    if ( !TopSort(Graph, TopOrder) ) {
//        cout << "AOE网中存在回路，无法求解关键路径！" << endl;
//        return;
//    }
//
//    int Ve[MaxVertexNum]; // Ve[i]：事件i的【最早发生时间】，源点Ve[0]=0
//    int Vl[MaxVertexNum]; // Vl[i]：事件i的【最晚发生时间】，汇点Vl[最后]=Ve[最后]
//    Vertex i, V, W;
//    PtrToAdjVNode p;
//
//    // ========= 步骤1：求所有事件的 最早发生时间 Ve[] =========
//    for (i=0; i<Graph->Nv; i++) Ve[i] = 0; // 源点最早发生时间初始化0
//    for (i=0; i<Graph->Nv; i++) {          // 按拓扑序列的顺序遍历事件
//        V = TopOrder[i];                   // 当前处理的事件V
//        for (p=Graph->G[V].FirstEdge; p; p=p->Next) {
//            W = p->AdjV;                   // V的邻接点W，代表后续事件
//            // 事件W的最早发生时间 = max(当前Ve[W], Ve[V]+活动<V,W>的耗时)
//            // 含义：事件W必须等所有前置活动完成后，才能发生
//            if ( Ve[V] + p->weight > Ve[W] ) {
//                Ve[W] = Ve[V] + p->weight;
//            }
//        }
//    }
//
//    // ========= 步骤2：求所有事件的 最晚发生时间 Vl[] =========*****
//    for (i=0; i<Graph->Nv; i++) Vl[i] = Ve[Graph->Nv-1]; // 汇点的最晚=最早，其余初始化为汇点Ve值
//    for (i=Graph->Nv-2; i>=0; i--) {       // 按拓扑序列的【逆序】遍历事件
//        V = TopOrder[i];                   // 当前处理的事件V
//        for (p=Graph->G[V].FirstEdge; p; p=p->Next) {
//            W = p->AdjV;                   // V的邻接点W
//            // 事件V的最晚发生时间 = min(当前Vl[V], Vl[W]-活动<V,W>的耗时)
//            // 含义：事件V不能影响后续事件W的最晚完成时间
//            if ( Vl[W] - p->weight < Vl[V] ) {
//                Vl[V] = Vl[W] - p->weight;
//            }
//        }
//    }
//
//    // ========= 步骤3：遍历所有边，求解关键活动 =========
//    cout << "===== AOE网关键路径信息 =====" << endl;
//    cout << "工程最短完成时间：" << Ve[Graph->Nv-1] << endl;
//    cout << "关键活动(起点->终点)：" << endl;
//    for (V=0; V<Graph->Nv; V++) {          // 遍历每个顶点(事件)
//        for (p=Graph->G[V].FirstEdge; p; p=p->Next) {
//            W = p->AdjV;                   // 遍历当前顶点的所有出边(活动)
//            // 核心公式：活动<V,W>的 最早开始时间e = Ve[V]
//            // 活动<V,W>的 最晚开始时间l = Vl[W] - p->weight
//            int e = Ve[V];
//            int l = Vl[W] - p->weight;
//            // 关键活动判定条件：e == l
//            // 含义：该活动的最早开始时间 = 最晚开始时间，无缓冲时间，延误则工程延期a->b,a->c,若b时间长c要等b
//            if (e == l) {
//                cout << V << " -> " << W << " (耗时：" << p->weight << ")" << endl;
//            }
//        }
//    }
//}
//
//// ====================== 9. 创建邻接表图的工具函数【测试用】 ======================
//LGraph CreateGraph(int n) {
//    LGraph graph = new gnode;
//    graph->Nv = n;
//    graph->Ne = 0;
//    for (int i=0; i<n; i++) {
//        graph->G[i].FirstEdge = nullptr;
//    }
//    return graph;
//}
//
//void AddEdge(LGraph graph, Vertex v1, Vertex v2, WeightType w) {
//    PtrToAdjVNode edge = new AdjVNode;
//    edge->AdjV = v2;
//    edge->weight = w;
//    edge->Next = graph->G[v1].FirstEdge;
//    graph->G[v1].FirstEdge = edge;
//    graph->Ne++;
//}
//
//// ====================== 10. 测试主函数 ======================
//int main() {
//    // 构建一个测试AOE网：顶点数6，边数8 (经典案例)
//    LGraph graph = CreateGraph(6);
//    AddEdge(graph, 0, 1, 3);
//    AddEdge(graph, 0, 2, 2);
//    AddEdge(graph, 1, 3, 2);
//    AddEdge(graph, 1, 4, 3);
//    AddEdge(graph, 2, 3, 4);
//    AddEdge(graph, 2, 5, 3);
//    AddEdge(graph, 3, 5, 2);
//    AddEdge(graph, 4, 5, 1);
//
//    // 求解关键路径
//    CriticalPath(graph);
//
//    return 0;
//}
//dijkstra算法（拓展）
//路径长度+成本
//#include<iostream>
//#include<limits.h>
//#define maxsize 30
//using namespace std;
//typedef struct lnode{
//	int adj;
//	int cost;
//	int s;
//	lnode* next;
//}*p[maxsize],*p1; 
//typedef struct lgraph_{
//	int nv;
//	int ne;
//	p list;
//}*lgraph;
//lgraph creatgraph(int v){
//	lgraph g;
//	g=new lgraph_;
//	g->nv=v;
//	g->ne=0;
//	for(int i=0;i<v;i++){
//		g->list[i]=nullptr;
//	}
//	return g;
//}
//struct edge{
//	int v1;
//	int v2;
//	int cost;
//	int s;
//};
//void insert(edge t,lgraph g){
//	p1 newg=new lnode;
//	newg->cost=t.cost;
//	newg->s=t.s;
//	newg->adj=t.v2;
//	newg->next=g->list[t.v1];
//	g->list[t.v1]=newg;
//	newg=new lnode;
//	newg->cost=t.cost;
//	newg->s=t.s;
//	newg->adj=t.v1;
//	newg->next=g->list[t.v2];
//	g->list[t.v2]=newg;
//}
//void build(lgraph g){
//	edge t;
//	int ne;
//	cin>>ne;
//	g->ne=ne;
//	for(int i=0;i<ne;i++){
//		int v1,v2;
//		cin>>v1>>v2>>t.s>>t.cost;
//		t.v1=v1;
//		t.v2=v2;
//		insert(t,g);
//	}
//}
//int findmin(bool collect[],int dist[],lgraph g){
//	int min=INT_MAX;
//	int min_index;
//	for(int i=0;i<g->nv;i++){
//		if(dist[i]<INT_MAX&&!collect[i]&&dist[i]<min){
//			min_index=i;
//			min=dist[i];
//		}
//	}
//	if(min<INT_MAX){
//		return min_index;
//	}
//	return -1;
//}
//void dijkstra(lgraph g,int dist[],int cost[],bool collect[],int parent[]){
//	while(1){
//		int v=findmin(collect,dist,g);
//		if(v==-1){
//			break;
//		}
//		collect[v]=true;
//		for(p1 temp=g->list[v];temp;temp=temp->next){
//			int w=temp->adj;
//			if(!collect[w]&&dist[w]>temp->s+dist[v]){
//				dist[w]=temp->s+dist[v];
//				cost[w]=temp->cost+cost[v];
//				parent[w]=v;
//			}
//			else if(!collect[w]&&dist[w]==temp->s+dist[v]){
//				if(cost[w]>temp->cost+cost[v]){
//					dist[w]=temp->s+dist[v];
//					cost[w]=temp->cost+cost[v];
//					parent[w]=v;
//				}
//			}
//		}
//	}
//}
//void find(lgraph g,int v1,int v2){
//	int dist[g->nv];
//	int cost[g->nv];
//	for(int i=0;i<g->nv;i++){
//		dist[i]=INT_MAX;
//		cost[i]=INT_MAX;
//	}
//	bool collect[maxsize]={false};
//	int parent[maxsize]={0};
//	dist[v1]=0;
//	cost[v1]=0;
//	parent[v1]=-1;
//	dijkstra(g,dist,cost,collect,parent);
//	cout<<dist[v2]<<endl;
//	cout<<cost[v2]<<endl;
//}
//int main(){
//	int n;
//	cin>>n;
//	lgraph g=creatgraph(n);
//	build(g);
//	int v1,v2;
//	cin>>v1>>v2;
//	find(g,v1,v2);
//	return 0;
//}
//dijkstra算法其他应用
//1.最短路径有多少条
//count[s]=1;
//如果找到更短路：count[w]=count[v];
//如果找到等长路：count[w]+=count[v];
//2.要求边最少的最短路
//count[w]=count[v]+1;

//简单排序
//排序算法效率
//void x_sort(elementtype a[],int n)
//算法使用看数据特征使用语境
//冒泡排序
//插入排序
//#include<iostream>
//using namespace std;
//void bubble_sort(int arr[],int n){
//	int cnt=0;
//	for(int i=0;i<n-1;i++){
//		bool flag=false;
//		for(int j=0;j<n-1-i;j++){
//			if(arr[j]>arr[j+1]){
//				int temp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=temp;
//				flag=true;
//				cnt++;
//			}
//		}
//		if(!flag){
//			break;
//		}
//	}
//	cout<<cnt<<endl;
//}
//void insert_sort(int arr[],int n){
//	int cnt=0;
//	for(int i=1;i<n;i++){
//		int temp=arr[i];
//		int j=i;
//		for(;j>0&&temp<arr[j-1];j--){
//			arr[j]=arr[j-1];
//			cnt++;
//		}
//		arr[j]=temp;
//	}
//	cout<<cnt;
//}
//int main(){
//	int arr[6]={34,8,64,51,32,21};
//	bubble_sort(arr,6);
//	int arr1[6]={34,8,64,51,32,21};
//	insert_sort(arr1,6);
//	return 0;
//}
//时间复杂度下届
//对于下标i<j,如果A[i]>A[j],则称(i,j)是一对逆序对
//{34,8,64,51,32,21}9个逆序对
//两种算法都是交换两个相邻元素正好消去1个逆序对
//插入排序：O(N+I)：如果序列基本有序，则插入排序简单且高效
//定理：任意N个不同元素组成的序列平均具有n(n-1)/4个逆序对
//定理：任意仅以交换相邻两元素的排序算法其平均时间复杂度为Ω(N^2)
//所以要高效->每次小区不止一个逆序对->每次交换相隔较远的两个元素
//希尔排序
//shellsort
//出自插入排序
//#include<iostream>
//using namespace std;
//void shell_sort(int arr[],int n){
//	int cnt=0;
//	for(int d=n/2;d>0;d/=2){
//		//+希尔排序//只不过先隔几个来以此把1换成d
//		for(int i=d;i<n;i++){
//			int temp=arr[d];
//			int j=i;
//			for(;j>0&&temp<arr[j-d];j-=d){
//				arr[d]=arr[j-d];
//				cnt++;
//			}
//			arr[j]=temp;	
//		}
//	}
//	cout<<cnt;
//}
//int main(){
//	int arr[6]={34,8,64,51,32,21};
//	shell_sort(arr,6);
//	return 0;
//}
//相邻增量d互质(效率高)
//选择排序
//堆排序
//#include<iostream>
//#include<limits.h>
//using namespace std;
//int findmin_index(int arr[],int st,int ed){
//	int min=INT_MAX;
//	int index=st;
//	for(int i=st;i<=ed;i++){
//		if(arr[i]<min){
//			index=i;
//			min=arr[i];
//		}
//	}
//	return index;
//}
//void selectio_sort(int arr[],int n){
//	for(int i=0;i<n;i++){
//		int in=findmin_index(arr,i,n-1);
//		if(in==i){
//			continue;
//		}
//		int temp=arr[in];
//		arr[in]=arr[i];
//		arr[i]=temp;
//	}
//}
////选择排序O(n^2)
////关键在于如何搜到最小值下标
////堆排序
////因为堆只知道最小或最大所以要想从小到大排序且不建立新数组要建最大堆再将最大值调整至末尾
//void percdown(int arr[],int root,int n){
//	int p=root;
//	int temp=arr[root];
//	int c;
//	for(;2*p+1<=n-1;p=c){
//		c=2*p+1;
//		if(c+1<=n-1&&arr[c]<arr[c+1]){
//			c++;
//		}
//		if(arr[c]>temp){
//			arr[p]=arr[c];
//		}
//		else{
//			break;
//		}
//	}
//	arr[p]=temp;	
//}
//void heap_sort(int arr[],int n){
//	for(int i=n/2-1;i>=0;i--){
//		percdown(arr,i,n);
//	}
//	for(int i=n-1;i>0;i--){
//		swap(arr[0],arr[i]);
//		percdown(arr,0,i);
//	}	
//}
//int main(){
//	int n;
//	cin>>n;
//	int arr[n];
//	for(int i=0;i<n;i++){
//		cin>>arr[i];
//	}
////	heap_sort(arr,n);
//	selectio_sort(arr,n);
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<"  ";
//	}
//	return 0;
//}
//归并排序
//核心：有序子列的归并
//三个数组，三个index指向数组位置，两个有序子列互相比较index所在数据小者传到目标数组，再将指针移动
//递归算法
//分而治之
//#include<iostream>
//using namespace std;
//void merge(int ls,int re,int rs,int arr[],int tem[]){
//	int i=ls;
//	int le=rs-1;
//	int index=ls-1;
//	while(ls<=le&&rs<=re){
//		if(arr[ls]<arr[rs]) tem[++index]=arr[ls++];
//		else tem[++index]=arr[rs++];
//	}
//	while(ls<=le){
//		tem[++index]=arr[ls++];
//	}
//	while(rs<=re){
//		tem[++index]=arr[rs++];
//	}
//	for(;i<=index;i++){
//		arr[i]=tem[i];
//	}
//}
//void msort(int ls,int re,int arr[],int tem[]){
//	int rs;
//	if(ls<re){
//		rs=(re+ls)/2;
//		msort(ls,rs,arr,tem);
//		msort(rs+1,re,arr,tem);
//		merge(ls,re,rs+1,arr,tem);
//	}
//}
//int main(){
//	int tem[10]={0};
//	int arr[10]={12,14,2,66,43,22,1,7,55,4};
//	msort(0,9,arr,tem);
//	for(int i=0;i<10;i++){
//		cout<<arr[i]<<endl;
//	}
//	return 0;
//}
//快速排序
//分而治之
//选主元，再将左右大小的元素排序
//取头中尾的中位数
//数据规模大可以用，小的话用简单排序
//判断数据大小与阈值的大小关系，来调用不同算法
//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义元素类型，可根据实际需求替换为 int / float 等
//typedef int ElementType;
//
//// 交换两个元素的值
//void Swap(ElementType *a, ElementType *b) {
//    ElementType temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 插入排序（用于元素数量较少时的优化）
//void InsertionSort(ElementType A[], int N) {
//    int i, j;
//    ElementType temp;
//    for (i = 1; i < N; i++) {
//        temp = A[i];
//        for (j = i; j > 0 && A[j-1] > temp; j--) {
//            A[j] = A[j-1];
//        }
//        A[j] = temp;
//    }
//}
//
//// 三数取中选择基准
//ElementType Median3(ElementType A[], int Left, int Right) {
//    int Center = (Left + Right) / 2;
//    if (A[Left] > A[Center])
//        Swap(&A[Left], &A[Center]);
//    if (A[Left] > A[Right])
//        Swap(&A[Left], &A[Right]);
//    if (A[Center] > A[Right])
//        Swap(&A[Center], &A[Right]);
//    // 将基准藏到右边
//    Swap(&A[Center], &A[Right-1]);
//    return A[Right-1];
//}
//
//// 快速排序的核心递归函数
//#define Cutoff 3  // 当元素数量小于等于此值时，使用插入排序
//void Qsort(ElementType A[], int Left, int Right) {
//    int Pivot, Low, High;
//    if (Cutoff <= Right - Left) {
//        Pivot = Median3(A, Left, Right);
//        Low = Left;
//        High = Right - 1;
//        while (1) {
//            while (A[++Low] < Pivot);
//            while (A[--High] > Pivot);
//            if (Low < High)
//                Swap(&A[Low], &A[High]);
//            else
//                break;
//        }
//        // 将基准放到正确的位置
//        Swap(&A[Low], &A[Right-1]);
//        // 递归处理左右子数组
//        Qsort(A, Left, Low - 1);
//        Qsort(A, Low + 1, Right);
//    } else {
//        // 元素太少，用插入排序
//        InsertionSort(A + Left, Right - Left + 1);
//    }
//}
//
//// 统一接口
//void QuickSort(ElementType A[], int N) {
//    Qsort(A, 0, N - 1);
//}
//
//// 测试用例
//int main() {
//    ElementType arr[] = {5, 2, 9, 1, 5, 6, 3, 7, 4, 8};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    printf("排序前：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    QuickSort(arr, n);
//
//    printf("排序后：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//#include<iostream>
//using namespace std;
//char arr[101][101]={'0'};
//int n,m;
//int find_bomb(int x,int y){
//    int ans=0;
//    for(int i=x-1;i<=x+1;i++){
//        if(i<0) continue;
//        if(i>=n) break;
//        for(int j=y-1;j<=y+1;j++){
//            if(j<0||j>=m) continue;
//            if(arr[i][j]=='*'){
//                ans++;
//            }
//        }
//    }
//    return ans;
//}
//int main(){
//    cin>>n>>m;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cin>>arr[i][j];
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            if(arr[i][j]=='*'){
//                cout<<"*";
//                continue;
//            }
//            else{
//                cout<<find_bomb(i,j);
//            }
//        }
//        if(i!=n-1){
//            cout<<endl;
//        }
//    }
//    return 0;
//}
//表排序
//用table[],存arr[]的下标arr[table[i]]输出
//n个数字的排列一定由若干个独立的环组成
//物理排序：
//
//#include<iostream>
//using namespace std;
//int main(){
//	int n;//数据个数
//	int arr[n];
//	int table[n];//正确顺序
//	for(int i=0;i<n;i++){
//		if(table[i]==i){//说明已经在院结构数组中排好序
//			continue;
//		}
//		else{
//			int temp=arr[i];
//			int i1=i;
//			while(i!=table[i1]){
//			    arr[i1]=arr[table[i1]];
//				table[i1]=i1;
//				i1=table[i1];
//			}
//			arr[i1]=temp;
//		}
//	}
//}
//线段树
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<limits.h>
//using namespace std;
//struct node{
//	int data,lazy=0;
//};
////线段树的构建
////每个节点代表一个区间，存储当前区间最大值
////data输入数组tree是线段树rt是当前节点left right当前区间左右边界，当left==right表明已经达到叶子节点，直接赋值
////未到叶节点，算mid递归左右子树，递归返回当前节点的值由左右子树最大值决定
//void build(const vector<int> &data,vector<node> &tree,int rt,int left,int right){
//	if(left==right){
//		tree[rt].data=data[left];//叶子节点
//		return;
//	}
//	int mid=left+(right-left)/2;
//	build(data,tree,2*rt,left,mid);//递归建立左子树
//	build(data,tree,2*rt+1,mid+1,right);//递归建立右子树
//	tree[rt].data=max(tree[2*rt].data,tree[2*rt+1].data);//更新当前节点的值
//}
////pushdown函数处理lazy
//void pushdown(vector<node> &tree,int rt){
//	if(tree[rt].lazy!=0){
//		//更新左子树
//		tree[2*rt].data+=tree[rt].lazy;
//		tree[2*rt].lazy+=tree[rt].lazy;
//		//更新右子树
//		tree[2*rt+1].data+=tree[rt].lazy;
//		tree[2*rt+1].lazy+=tree[rt].lazy;
//		//清空当前节点懒标记
//		tree[rt].lazy=0;
//	}
//}
////查询某个区间最大值
////ql,qr查询区间左右边界  left right为当前节点表示的区间
//int query(vector<node> &tree,int rt,int left,int right,int ql,int qr){
//	if(ql>right|qr<left){
//		return INT_MIN;
//	}//区间无交集返回最小值
//	if(ql<=left&&qr>=right){
//		return tree[rt].data;//当前区间完全包含在查询区间内
//	}
//	int mid=left+(right-left)/2;
//	pushdown(tree,rt);
//	int leftmax=query(tree,2*rt,left,mid,ql,qr);//查询左子树
//	int rightmax=query(tree,2*rt+1,mid+1,right,ql,qr);
//	return max(leftmax,rightmax);
//}
//int main(){
//	
//	return 0;
//}
/* 链式地址哈希表 */
/* 加法哈希 */
//int addHash(string key) {
//    long long hash = 0;
//    const int MODULUS = 1000000007;
//    for (unsigned char c : key) {
//        hash = (hash + (int)c) % MODULUS;
//    }
//    return (int)hash;
//}
//
///* 乘法哈希 */
//int mulHash(string key) {
//    long long hash = 0;
//    const int MODULUS = 1000000007;
//    for (unsigned char c : key) {
//        hash = (31 * hash + (int)c) % MODULUS;
//    }
//    return (int)hash;
//}
//
///* 异或哈希 */
//int xorHash(string key) {
//    int hash = 0;
//    const int MODULUS = 1000000007;
//    for (unsigned char c : key) {
//        hash ^= (int)c;
//    }
//    return hash & MODULUS;
//}
//
///* 旋转哈希 */
//int rotHash(string key) {
//    long long hash = 0;
//    const int MODULUS = 1000000007;
//    for (unsigned char c : key) {
//        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
//    }
//    return (int)hash;
//}



































