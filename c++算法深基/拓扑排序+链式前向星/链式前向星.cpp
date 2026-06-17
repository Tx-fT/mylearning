//邻接表动态结构在空间比较严苛的环境下不够
//head[]:idx=点号，data=头边号
//next[]:idx=边号，data=下一条边号
//to[]:idx=边号，data=去往的点
//int cnt=1；边被编为了几号
//就是基于模拟链表的头插法
#include<bits/stdc++.h>
using namespace std;
int head[10010],nx[10010]/*去的边*/,to[10010]/*去的点*/;
void solve(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        ++cnt;
        int a,b;
        cin>>a>>b;
        nx[cnt]=head[a];
        head[a]=cnt;
        to[cnt]=b;
    }
    int t;
    cin>>t;
    int edg=head[t];
    while(edg){
        cout<<to[edg]<<endl;
        edg=nx[edg];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
//拓扑排序
//有向无环
//先遍历数度->再0度入队(删掉)，同时减度->直到所有点都被删除，依次删除的顺序就是拓扑排序的结果
//如果无法把所有的点都删掉，说明有向图有环

















