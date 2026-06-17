//基于快排
//同样选一个基准数，左右数个数（不用排），看是否命中
#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,k,idx;
int l=0,r=0;
int random(){
    static mt19937 rng(random_device{}());//随机数源+名字（随机数生成器）
    uniform_int_distribution<int> dist(l, r);//伪随机引擎 rng 吐出来的是一个大范围的原始整数（比如 $[0, 2^{32})​$）。dist(rng) 把这个原始值映射到 [l, r] 区间，每个整数被抽到的概率完全相等。
    //标准整数映射
    return dist(rng);
}
void merge(int x){
    for(int i=l,i1=l,i2=r;i<=i2;){
        if(a[i]<a[x]){
            swap(a[i],a[i1]);
            i1++;
            i++;//因为跨过去的一定小于等于a[x]
        }else if(a[i]>a[x]){
            swap(a[i],a[i2]);
            i2--;//i不能动进一步判断
        }else{
            i++;
        }
    }
}
int find(){
    for(l=1,r=n;l<=r;){
        int x=random();
        merge(x);
        if(idx>=l&&idx<=r){
            return a[idx];
        }else if(idx<l){
            r=l-1;
        }else{
            l=r+1;
        }
    } 
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>k;
    // 随机选择基准
    // static mt19937 rng(random_device{}());
    // uniform_int_distribution<int> dist(l, r);
    // int x = a[dist(rng)];//【0-长度-1】
    //c++:更好三选一：mid
    //经典快排，i1，i2，i1开拓看看后面有没有比基准更小的，i2收成左边全是小于等于基准的，每当交换，i++
    //荷兰国旗问题
    //怎么实现基准数相等的多个数一次排完
    //设计两个区域，遇到情况发货就行，i遍历，a左区域，b右区域；

    //随机选择算法求第k大
    //荷兰国旗算法
    idx=n-k+1;
    int ans=find();
    cout<<ans<<endl;
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