//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n;
//long long dp[35][35];
//int p[35][35];
//void dfs(int l,int r){
//	if(l>r){
//		return;
//	}
//	int root=p[l][r];
//	cout<<root<<" ";
//	dfs(l,root-1);
//	dfs(root+1,r);
//}
//int main(){
//	memset(dp,0,sizeof(dp));
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>dp[i][i];
//		p[i][i]=i;
//	}
//	for(int k=2;k<=n;k++){
//		for(int i=1;i<=n-k+1;i++){
//			int l=i,r=i+k-1;
//			for(int j=l;j<=r;j++){
//				if(j==l){
//					dp[l][r]=dp[l][l]+dp[l+1][r];
//					p[l][r]=j;
//				}
//				else if(j==r){
//					if(dp[l][r]<dp[r][r]+dp[l][r-1]){
//						dp[l][r]=dp[r][r]+dp[l][r-1];
//						p[l][r]=j;
//					}			
//				}
//				else{
//					if(dp[l][r]<dp[l][j-1]*dp[j+1][r]+dp[j][j]){
//						dp[l][r]=dp[l][j-1]*dp[j+1][r]+dp[j][j];
//						p[l][r]=j;
//					}					
//				}
//			}
//		}
//	}
//	cout<<dp[1][n]<<endl;
//	dfs(1,n);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int mx=300010;
vector<int> g[mx];
long long dp[mx][3];
int qpow(long long d,long long m){
	d=d%mod;
	long long res=1;
	while(m){
		if(m&1){
			res=1ll*res*d%mod;
		}
		d=1ll*d*d%mod;
		m>>=1;
	}
	return res;
}
long long inv(long long x){
	return qpow(x,mod-2);
}
void dfs(int x,int r){
	dp[x][0]=1;
	dp[x][2]=1;
	dp[x][1]=0;
	int res1=1;
	for(auto i:g[x]){
		if(i==r) continue;
		dfs(i,x);
		dp[x][0]=dp[i][2]*dp[x][0]%mod;
		dp[x][2]=(dp[i][1]+dp[i][2])*dp[x][2]%mod;//类似于递加元素，再从头往前加
		res1=res1*(dp[i][1]+dp[i][2])%mod;
	}
	int res2=1;
	for(auto i:g[x]){
		if(i==r) continue;
		res1=res1*inv(dp[i][1]+dp[i][2])%mod;
		dp[x][1]=(dp[x][1]+(dp[i][0]*res1%mod*res2%mod))%mod;
		res2=res2*(dp[i][1]+dp[i][2])%mod;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,-1);
	cout<<(dp[1][0]+dp[1][1]+dp[1][2]-1+mod)%mod;
	return 0;
}
