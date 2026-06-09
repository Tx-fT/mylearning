//st表子数组最大值最小值
#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[19][100010];
void mergest(){
	for(int j=1;j<=__lg(n);j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);	
		}
	}
}
int query(int l,int r){
	int len=r-l+1;
	int x=__lg(len);
	int m1=st[x][l];
	int m2=st[x][r-(1<<x)+1];
	return m1>m2?m1:m2;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st[0][i];
	}
	mergest();
	while(m--){
		int l,r;
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
	return 0;
}




































