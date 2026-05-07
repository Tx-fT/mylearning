#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long dp[35][35];
int p[35][35];
void dfs(int l,int r){
	if(l>r){
		return;
	}
	int root=p[l][r];
	cout<<root<<" ";
	dfs(l,root-1);
	dfs(root+1,r);
}
int main(){
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dp[i][i];
		p[i][i]=i;
	}
	for(int k=2;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			int l=i,r=i+k-1;
			for(int j=l;j<=r;j++){
				if(j==l){
					dp[l][r]=dp[l][l]+dp[l+1][r];
					p[l][r]=j;
				}
				else if(j==r){
					if(dp[l][r]<dp[r][r]+dp[l][r-1]){
						dp[l][r]=dp[r][r]+dp[l][r-1];
						p[l][r]=j;
					}			
				}
				else{
					if(dp[l][r]<dp[l][j-1]*dp[j+1][r]+dp[j][j]){
						dp[l][r]=dp[l][j-1]*dp[j+1][r]+dp[j][j];
						p[l][r]=j;
					}					
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	dfs(1,n);
	return 0;
}
