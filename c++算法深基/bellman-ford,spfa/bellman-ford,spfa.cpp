//bellman-ford解决可以有负权边但不能有负环（保证最短路存在）的图，单源最短路算法
//过程：
//1.每一轮考察每条边，每条边都尝试（无法确定入队点局部最优不是全局最优）进行松弛操作（假设以此更新），那么若干点后会变小
//2.当某一轮发现不再有松弛操作时停止->无法变得更小了
//顺序无所谓，*遍历边*
//O(n*m)->小图
//判断从某个点出发有没有到达负环（正常情况下最大n-1轮）
//SPFA优化
//每一轮考察所有边没必要
//策略：用队列维护新更新的点，然后松弛重复直至没有松弛
//用途：小图，负边（无负环），判断负环：及一个数组记录每个点松弛的次数1.全图：虚拟源点（s连向所有点权值为0）2.指定点，并行计算（多线程），费用流
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2010;
const int MAXM=6010;
int n,m;
int upcnt[MAXN];
int head[MAXN];
int nx[MAXM];
int to[MAXM];
int wt[MAXM];
bool v[MAXN];
int dist[MAXN];
int cnt=0;
queue<int> q;
bool judge(){
    while(!q.empty()){
        int idx=q.front();
        v[idx]=false;
        q.pop();
        for(int e=head[idx];e;e=nx[e]){
            int p=to[e];
            if(dist[idx]+wt[e]<dist[p]){
                dist[p]=dist[idx]+wt[e];
                if(!v[p]){
                    if(++upcnt[p]>=n) return false;
                    q.push(p);
                    v[p]=true;
                }
            }
        }
    }
    return true;
}
void solve(){
    cnt=0;
    cin>>n>>m;
    fill(dist+1,dist+n+1,0x3f3f3f3f);
    fill(head+1,head+n+1,0);
    fill(v+1,v+n+1,false);
    fill(upcnt+1,upcnt+n+1,0);
    dist[1]=0;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        nx[++cnt]=head[a];
        head[a]=cnt;
        to[cnt]=b;
        wt[cnt]=w;
        if(w>=0){
            nx[++cnt]=head[b];
            head[b]=cnt;
            to[cnt]=a;
            wt[cnt]=w;
        }
    }
    q=queue<int>();
    q.push(1);
    v[1]=true;
    judge()?cout<<"NO"<<endl:cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
