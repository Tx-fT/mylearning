//一维
//丑数：后=前*2||*3||*5
//思路1：优先队列：弹出的入三（*2*3*5）
//思路2：2，3，5各一个指针指向下一回乘它的dp【i】，插入进去则++
#include<iostream>
#include<algorithm>
using namespace std;
int dp[100010];
int main(){
    dp[1]=1;
    int n;
    cin>>n;
    for(int i=2,i2=1,i3=1,i5=1;i<=n;i++){
        int a=dp[i2]*2;
        int b=dp[i3]*3;
        int c=dp[i5]*5;
        int mi=min(a,min(b,c));
        //三个都可以插入
        if(mi==a){
            i2++;
        }
        if(mi==b){
            i3++;
        }
        if(mi==c){
            i5++;
        }
        dp[i]=mi;
    }
    cout<<dp[n];
    return 0;
}