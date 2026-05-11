#include<iostream>
#include<algorithm>
#define mx 200005

using namespace std;
int rt[mx];
int cnt=0;
int sum[mx<<5];
int lc[mx<<5],rc[mx<<5];
int n,m;
int oq[mx];
int nq[mx];
int p;

void build(int k,int l,int r){
	if(l==r){
		return;
	}
	lc[k]=++cnt;
	rc[k]=++cnt;
	int m=(l+r)>>1;
	build(lc[k],l,m);
	build(rc[k],m+1,r);
}

int insert(int u,int l,int r){
	int nc=++cnt;
	sum[nc]=sum[u]+1;
	if(l==r){
		return nc;
	}	
	lc[nc]=lc[u],rc[nc]=rc[u];
	int m=(l+r)>>1;
	if(p<=m){
		lc[nc]=insert(lc[u],l,m);
	}
	else{
		rc[nc]=insert(rc[u],m+1,r);
	}
	return nc;
}
int find(int l,int r,int u,int v,int k){
	int x=sum[lc[u]]-sum[lc[v]];
	int m=(l+r)>>1;
	if(l==r){
		return l;
	}
	if(x>=k){
		return find(l,m,lc[u],lc[v],k);
	}
	else{
		return find(m+1,r,rc[u],rc[v],k-x);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>oq[i];
		nq[i]=oq[i];
	}
	sort(nq+1,nq+n+1);
	int len=unique(nq+1,nq+n+1)-nq-1;
	build(rt[0],1,len);
	for(int i=1;i<=n;i++){
		p=lower_bound(nq+1,nq+len+1,oq[i])-nq;
		rt[i]=insert(rt[i-1],1,len);
	}
	for(int i=1;i<=m;i++){
		int l,r,k;
		cin>>l>>r>>k;
		int idx=find(1,len,rt[r],rt[l-1],k);
		cout<<nq[idx]<<endl;
	}	
	return 0;
}
