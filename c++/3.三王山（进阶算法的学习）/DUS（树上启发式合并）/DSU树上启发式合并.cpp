#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXC = 2e5 + 5;

int n;
vector<int> g[MAXN];
int color[MAXN];        // C[i]
int sz[MAXN], son[MAXN];
int cntColor[MAXC];     // 每种颜色的出现次数
int cntTimes[MAXN];     // cntTimes[x] = 出现次数为 x 的颜色数量
int maxCnt = 0;         // 当前子树中最大的出现次数
int totalColor = 0;     // 当前子树中不同颜色的数量
int ans = 0;

// 第一次 DFS：求子树大小和重儿子
void dfsSize(int u) {
    sz[u] = 1;
    son[u] = 0;
    int maxSon = 0;
    for (int v : g[u]) {
        dfsSize(v);
        sz[u] += sz[v];
        if (sz[v] > maxSon) {
            maxSon = sz[v];
            son[u] = v;
        }
    }
}

// 添加节点 u 的颜色到统计中
void add(int u) {
    int c = color[u];
    // 旧出现次数
    int oldCnt = cntColor[c];
    if (oldCnt > 0) {
        cntTimes[oldCnt]--;
    }
    cntColor[c]++;
    int newCnt = cntColor[c];
    cntTimes[newCnt]++;
    
    if (newCnt > maxCnt) maxCnt = newCnt;
    if (oldCnt == 0) totalColor++;  // 新颜色出现
}

// 删除节点 u 的颜色（只用于清空轻儿子时）
void del(int u) {
    int c = color[u];
    int oldCnt = cntColor[c];
    cntTimes[oldCnt]--;
    cntColor[c]--;
    int newCnt = cntColor[c];
    if (newCnt > 0) {
        cntTimes[newCnt]++;
    }
    if (oldCnt == maxCnt && cntTimes[oldCnt] == 0) maxCnt--;
    if (oldCnt == 1) totalColor--;
}

// 递归添加或删除一棵子树
void operateSubtree(int u, bool isAdd) {
    if (isAdd) add(u);
    else del(u);
    for (int v : g[u]) {
        operateSubtree(v, isAdd);
    }
}

// DSU on tree
void dfs(int u, bool keep) {
    // 先处理轻儿子
    for (int v : g[u]) {
        if (v == son[u]) continue;
        dfs(v, false);
    }
    // 处理重儿子（保留数据）
    if (son[u]) {
        dfs(son[u], true);
    }
    // 加入当前节点 u 和所有轻儿子
    add(u);
    for (int v : g[u]) {
        if (v == son[u]) continue;
        operateSubtree(v, true);   // 加入轻儿子子树
    }
    
    // 判断以 u 为根的子树是否颜色平衡
    if (maxCnt * totalColor == sz[u]) {
        ans++;
    }
    
    // 如果不保留（keep==false），则清空当前子树信息
    if (!keep) {
        operateSubtree(u, false);
        maxCnt = 0;
        totalColor = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int fa;
        cin >> color[i] >> fa;
        if (fa != 0) {
            g[fa].push_back(i);
        }
    }
    
    dfsSize(1);
    dfs(1, true);
    cout << ans << endl;
    
    return 0;
}
