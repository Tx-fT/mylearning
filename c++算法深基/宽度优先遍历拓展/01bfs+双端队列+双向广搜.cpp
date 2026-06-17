//为了更好解决，边权重只有0 1的图问题，有01bfs
//引入了双端队列 其实就是dijkstra实时更新
//不同的是，用双端队列，若权重为0则从头进，若为1则从尾进（前提新更新的dist变小），每次头弹出

// ============ deque（双端队列）用法总结 ============
// 头文件: #include <deque>
// 底层: 分段连续内存, 头尾插入/删除 O(1), 随机访问 O(1), 中间操作 O(n)
//
// 创建:
//   deque<int> dq;
//   deque<int> dq(5, 10);            // 5个元素，值都是10
//   deque<int> dq = {1, 2, 3, 4};
//
// 访问:
//   dq[0]       dq.at(0)             // at()会检查越界
//   dq.front()  dq.back()            // 首/尾元素
//
// 添加:
//   dq.push_back(x)   dq.emplace_back(x)   // 尾部
//   dq.push_front(x)  dq.emplace_front(x)  // 头部
//   dq.insert(it, x)  dq.emplace(it, x)    // 中间
//
// 删除:
//   dq.pop_back()   dq.pop_front()    // 尾/头弹出
//   dq.erase(it)                      // 删除指定位置
//   dq.clear()                        // 清空
//
// 大小:
//   dq.size()   dq.empty()   dq.resize(n)
//
// 遍历:
//   for (int x : dq) 或 for (size_t i = 0; i < dq.size(); i++)


// ============ 01-BFS 模板 ============
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// const int INF = 0x3f3f3f3f;

// vector<pair<int, int>> g[N];  // g[u] = {v, w}, w 只能是 0 或 1
// int dist[N];
// bool vis[N];

// void zero_one_bfs(int s) {
//     memset(dist, 0x3f, sizeof(dist));
//     dist[s] = 0;
//     deque<int> dq;
//     dq.push_back(s);

//     while (!dq.empty()) {
//         int u = dq.front();
//         dq.pop_front();
//         if (vis[u]) continue;
//         vis[u] = true;

//         for (auto [v, w] : g[u]) {
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 if (w == 0)
//                     dq.push_front(v);  // 边权0 → 插头部, 优先处理
//                 else
//                     dq.push_back(v);   // 边权1 → 插尾部
//             }
//         }
//     }
// }

// // 例题: 有向图, 边权0或1, 求 s 到各点最短路
// void solve() {
//     int n, m, s;
//     cin >> n >> m >> s;
//     for (int i = 1; i <= m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});  // 无向图再加 g[v].push_back({u, w});
//     }
//     zero_one_bfs(s);
//     for (int i = 1; i <= n; i++)
//         cout << (dist[i] == INF ? -1 : dist[i]) << " ";
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--) solve();
//     return 0;
// }
//这里的dist只起比较作用，不用其查找不用v【】，队列最大差值为1

// ============ set 用法总结 ============
// 头文件: #include <set>
// 底层: 红黑树, 有序, 元素唯一, 插入/删除/查找 O(log n), 遍历有序

// ===== 1. 创建 =====
// set<int> s;
// set<int> s = {3, 1, 4, 1, 5};          // 去重后: {1, 3, 4, 5}
// set<int, greater<int>> s2;              // 降序
// struct cmp { bool operator()(int a, int b) const { return a > b; } };
// set<int, cmp> s3;                       // 自定义比较器

// // ===== 2. 插入/删除 =====
// s.insert(x);                            // 返回 pair<iterator, bool>
// auto [it, ok] = s.insert(x);            // ok==false 表示已存在
// s.emplace(x);                           // 原地构造
// s.erase(it);                            // 删除迭代器指向元素
// s.erase(x);                             // 删除值为x的元素, 返回删除个数(0或1)
// s.erase(first, last);                   // 删除区间 [first, last)
// s.clear();                              // 清空

// // ===== 3. 查找 =====
// auto it = s.find(x);                    // 找不到返回 s.end()
// if (s.count(x)) { ... }                 // 存在返回1, 否则0
// if (s.contains(x)) { ... }              // C++20, bool返回值

// // ===== 4. 边界查找（二分） =====
// auto it = s.lower_bound(x);             // 第一个 >= x 的元素
// auto it = s.upper_bound(x);             // 第一个 > x  的元素
// // 例: s = {1,3,5,7}, x=3 → lower=指向3, upper=指向5

// // ===== 5. 大小 =====
// s.size()   s.empty()   s.max_size()

// // ===== 6. 遍历 =====
// for (int x : s) { ... }
// for (auto it = s.begin(); it != s.end(); ++it) { *it ... }
// for (auto it = s.rbegin(); it != s.rend(); ++it) { ... }  // 逆序

// // ===== 7. multiset（允许重复） =====
// multiset<int> ms;
// ms.insert(x);                           // 重复插入, 永远成功
// ms.erase(x);                            // 删除所有值为x的元素!
// ms.erase(ms.find(x));                   // 只删除一个
// ms.count(x);                            // 返回个数（O(log n + k)）

// // ===== 8. unordered_set（哈希, 无序） =====
// #include <unordered_set>
// unordered_set<int> us;
// // 插入/删除/查找 平均 O(1), 最坏 O(n), 无序遍历

// // ===== 常见写法 =====
// // 取集合中最大值/最小值:
// int mn = *s.begin();
// int mx = *s.rbegin();

// // 区间查询 [L, R]:
// auto l = s.lower_bound(L);
// auto r = s.upper_bound(R);
// for (auto it = l; it != r; ++it) { ... }

// // 删除区间:
// s.erase(s.lower_bound(L), s.upper_bound(R));

//双向bfs
//用途：
//1.小优化：bfs剪枝策略，分两侧展开分枝，哪侧数量少就从哪侧展开
//2.*用于解决特征很明显的一类问题，特征：全量样本不允许递归完全展开，但是半量样本可以完全展开，过程：把数据拆成两份，每部分各自展开计算结果，然后设计两部分结果的整合逻辑
//   左右同时bfs每次扩展小的直至相遇，中间swap
#include<bits/stdc++.h>
using namespace std;
map<string,bool> a;
int solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        a[t]=true;
    }
    string st,ed;
    cin>>st>>ed;
    if(st==ed){
        return 1;
    }
    set<string> sm;
    set<string> bg;
    set<string> nx;
    sm.insert(st);
    bg.insert(ed);
    for(int len=2;!sm.empty();len++){
        for(string i:sm){
            for(int j=0;j<i.size();j++){
                char od=i[j];
                for(char ne='a';ne<='z';ne++){
                    if(ne==od) continue;
                    string tep=i;
                    tep[j]=ne;
                    if(bg.find(tep)!=bg.end()){
                        return len;
                    }
                    if(!a[tep]) continue;
                    a[tep]=false;
                    nx.insert(tep);
                }
            }
        }
        if(nx.size()<=bg.size()){
            swap(nx,sm);
        }else{
            swap(bg,nx);
            swap(nx,sm);
        }
        nx.clear();
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        int ans=solve();
        cout<<ans;
    }
    return 0;
}












