#include<bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w, idx; };

int par[200010];
int find(int x){ return par[x]==x ? x : par[x]=find(par[x]); }
bool unite(int a, int b){
    a=find(a); b=find(b);
    if(a==b) return false;
    par[a]=b; return true;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].idx = i+1;
    }

    // 1. Kruskal 求原图 MST
    sort(edges.begin(), edges.end(), [](auto&a,auto&b){return a.w<b.w;});
    for(int i=1;i<=n;i++) par[i]=i;

    vector<Edge> mst;
    long long ans = 0;
    for(auto& e : edges){
        if(unite(e.u, e.v)){
            mst.push_back(e);
            ans += e.w;
            if((int)mst.size()==n-1) break;
        }
    }

    // 2. MST边按边权从大到小，贪心标记要替换的边（权>1且k够）
    sort(mst.begin(), mst.end(), [](auto&a,auto&b){return a.w>b.w;});

    vector<bool> removed(mst.size(), false);
    int replaceCount = 0;
    for(int i=0;i<(int)mst.size() && k>0;i++){
        if(mst[i].w > 1){
            removed[i] = true;
            ans -= mst[i].w;
            k--;
            replaceCount++;
        } else {
            break; // 降序排列，后面都<=1，不用替换
        }
    }

    // 3. 重建并查集（只含保留的MST边）
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=0;i<(int)mst.size();i++){
        if(!removed[i]) unite(mst[i].u, mst[i].v);
    }

    // 4. 顺序扫 i, i+1，不连通就加边，最多加 replaceCount 条
    vector<Edge> newEdges;
    int newIdx = m;
    for(int i=1; i<n && replaceCount>0; i++){
        if(unite(i, i+1)){
            newIdx++;
            newEdges.push_back({i, i+1, 1, newIdx});
            ans += 1;
            replaceCount--;
        }
    }

    // 5. 输出新加边数量及内容
    cout << newEdges.size() << "\n";
    for(auto& e : newEdges) cout << e.u << " " << e.v << "\n";

    // 6. 输出 MST 总权
    cout << ans << "\n";

    // 7. 输出 n-1 条MST边编号（保留的原MST边 + 新加边）
    vector<int> result;
    for(int i=0;i<(int)mst.size();i++){
        if(!removed[i]) result.push_back(mst[i].idx);
    }
    for(auto& e : newEdges) result.push_back(e.idx);

    for(int i=0;i<(int)result.size();i++){
        if(i) cout << " ";
        cout << result[i];
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
