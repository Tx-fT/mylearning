#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 100;
vector <pair <int, int>> g[N];  // 邻接表：{邻接顶点, 边索引}
int val[N];                     // 每个顶点的值

vector <int> ans;               // 存储每条边的答案
map <int, int> cnt1, cnt2;      // 两个子树中各值的出现次数
set <int> mad1, mad2;           // 两个子树中重复出现的值（MAD候选）
                                 // cnt1/mad1 维护第一棵子树的状态
                                 // cnt2/mad2 维护第二棵子树的状态
                                 // 初始时，cnt2 包含所有顶点，mad2 包含所有重复值

vector <int> path, path_ind;    // path: 路径上的顶点; path_ind: 路径上的边索引
bool used[N];                   // DFS访问标记


// 找到两个出现最大值的位置之间的路径，并记录路径上的顶点和边的索引
bool dfs(int v, int tar) {
    used[v] = true;
    path.push_back(v);           // 记录路径上的顶点
    if (v == tar) {
        return true;
    }
    for (auto [i, ind] : g[v]) {
        if (!used[i]) {
            path_ind.push_back(ind);  // 记录路径上的边索引
            if (dfs(i, tar)) {
                return true;
            }
            path_ind.pop_back();
        }
    }
    path.pop_back();
    return false;
}


// 返回两个子树中最大的重复值
int mad() {
    int mx = 0;
    if (!mad1.empty()) {
        mx = max(mx, *mad1.rbegin());
    }
    if (!mad2.empty()) {
        mx = max(mx, *mad2.rbegin());
    }
    return mx;
}


// 将顶点 v 及其整个子树从树2移动到树1，并更新两个集合
// ban1: 禁止前往的顶点（已在树1中），ban2: 禁止前往的顶点（保留在树2中作为分界）
void recalc(int v, int ban1, int ban2) {
    // 将顶点 v 从树2移动到树1
    cnt1[val[v]]++;
    if (cnt1[val[v]] == 2) {    // 出现次数达到2，成为重复值
        mad1.insert(val[v]);
    }
    
    cnt2[val[v]]--;
    if (cnt2[val[v]] == 1) {    // 从2降到1，不再是重复值
        mad2.erase(val[v]);
    }
    
    // 递归移动子节点（除了被ban的节点）
    for (auto [i, _] : g[v]) {
        if (i != ban1 && i != ban2) {
            recalc(i, v, -1);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    // ind: 统计每个值出现的顶点列表
    map <int, vector <int>> ind;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        ind[val[i]].push_back(i);
        cnt2[val[i]]++;          // 初始时树2包含所有顶点
        if (cnt2[val[i]] == 2) { // 出现次数达到2，加入mad2
            mad2.insert(val[i]);
        }
    }

    // 从最大值开始，逐个删除只出现一次的值，直到找到第一个出现≥2次的值（即全局MAD）
    // ind.rbegin() 指向当前最大的值（因为map按key升序排列）
    // 如果当前最大值只出现1次，它不可能是MAD，删除它继续找下一个
    while (!ind.empty() && ind.rbegin()->second.size() == 1) {
        ind.erase(prev(ind.end()));  // prev(ind.end()) 指向最后一个有效元素
    }
    
    // 情况1：没有值出现≥2次 → 全局MAD = 0，所有边答案都是0
    if (ind.empty()) {
        for (int i = 0; i < n - 1; i++) {
            cout << "0\n";
        }
        return 0;
    } 
    // 情况2：全局MAD出现≥3次 → 根据鸽巢原理，任何分割都至少有一棵树含≥2个MAD
    else if (ind.rbegin()->second.size() > 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << ind.rbegin() -> first << "\n";
        }
        return 0;
    }

    // 情况3：全局MAD恰好出现2次
    // 取出这两个出现位置
    int a = ind.rbegin()->second[0], b = ind.rbegin()->second[1];
    dfs(a, b);  // 找到a到b的路径

    // 关键观察：
    // - 如果删除的边不在 a-b 路径上 → a和b在同一子树中，该子树MAD = 全局MAD
    // - 如果删除的边在 a-b 路径上 → 需要逐步计算
    
    ans.assign(n - 1, ind.rbegin() -> first);  // 默认所有边答案为全局MAD
    
    // 处理路径上的第一条边：将 path[0] 从树2移动到树1
    recalc(path[0], path[1], -1);
    ans[path_ind[0]] = mad();   // 计算删除第一条边后的MAD
    
    // 逐步移动路径上的顶点，每次处理一条边
    // recalc(path[i], path[i-1], path[i+1]) 的含义：
    //   当前顶点是 path[i]
    //   禁止回到 path[i-1]（已在树1中）
    //   禁止前进到 path[i+1]（保留在树2中，作为分界）
    //   只移动 path[i] 的其余子树部分
    for (int i = 1; i + 1 < path.size(); i++) {
        recalc(path[i], path[i - 1], path[i + 1]);
        ans[path_ind[i]] = mad();  // 计算删除当前边后的MAD
    }

    // 按输入顺序输出每条边的答案
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}