//完全背包：重复利用
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int w[105],v[105];
//int dp[105]={0};
//int main(){
//    int n,b;
//    cin>>b>>n;
//    for(int i=1;i<=n;i++){
//        cin>>w[i]>>v[i];
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=b;j++){
//            if(j>=w[i]){
//                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
//            }
//        }
//    }
//    cout<<dp[b];
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int dp[11][11][11][11];
//int n;
//int A[11][11];
//int main(){
//	cin>>n;	
//	while(1){
//		int x,y,z;
//		cin>>x>>y>>z;
//		
//		if(x==0&&y==0&&z==0){
//			break;	
//		}
//		else{
//			A[x][y]=z;
//		}
//	}
//	for(int a=1;a<=n;a++)
//	 for(int b=1;b<=n;b++)
//	  for(int c=1;c<=n;c++)
//	   for(int d=1;d<=n;d++){
//	   		dp[a][b][c][d]=max(max(dp[a-1][b][c-1][d],dp[a-1][b][c][d-1]),max(dp[a][b-1][c][d-1],dp[a][b-1][c-1][d]))+A[a][b]+A[c][d];
//			if(a==c&&b==d){
//		   		dp[a][b][c][d]-=A[a][b];	   	
//   			}
//	   }
//	cout<<dp[n][n][n][n];   		
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//const int x=20005;
//
//int n;
//int a[1005];
//int dp[1005][40010];
//long long ans=0;
//
//
//int main(){
//	memset(dp,0,sizeof(dp));
//	
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	
//	for(int i=1;i<=n;i++){
//	 	for(int j=i-1;j;j--){
//	 		dp[i][a[i]-a[j]+x]+=dp[j][a[i]-a[j]+x]+1;
//	 		ans+=dp[j][a[i]-a[j]+x]+1;
//	 		ans%=998244353;
//	 	}		
//	}
//	ans+=n;
//	cout<<ans;
//	
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[1005][1005];
//int main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cin>>a[i][j];
//		}
//	}
//	for(int i=n;i>1;i--){
//		for(int j=2;j<=i;j++){
//			a[i-1][j-1]=max(a[i-1][j-1]+a[i][j-1],a[i-1][j-1]+a[i][j]);
//		}	
//	}
//	cout<<a[1][1];
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int sum=0;
//    int ans=-11111;
//    for(int i=1;i<=n;i++){
//        int t;
//        cin>>t;
//        sum+=t;
//        if(sum<0){
//            sum=0;
//        }
//        else if(sum>ans){
//            ans=sum;
//        }
//    }
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int lcs(string& s1,string& s2) {
//    int m= s1.length(),n=s2.length();
//    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//    
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            if(s1[i-1]==s2[j-1]){
//                dp[i][j]=dp[i-1][j-1]+1;
//            }
//			else{
//                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//            }
//        }
//    }
//    return dp[m][n];
//}
//
//int main(){
//	string s1,s2;
//    while(cin>>s1>>s2){
//        cout<<lcs(s1,s2)<<endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string s1,s2;
//	while(cin>>s1>>s2){
//		
//		vector<int> pos[256];
//		for(int i=0;i<s1.length();i++){
//			pos[s1[i]].push_back(i);
//		}
//		
//		vector<int> q;
//		
//		for(char ch:s2){
//			if(pos[ch].empty()){
//				continue;
//			}
//			else{
//				if(q.empty()){
//					q.push_back(pos[ch][0]);
//					continue;
//				}
//				int t=q.back();
//				for(int i=0;i<pos[ch].size();i++){
//					auto p1=lower_bound(q.begin(),q.end(),pos[ch][i]);
//					if(p1==q.end()){
//						for(int j=i;j<pos[ch].size();j++){
//							if(pos[ch][j]<=t) continue;
//							else{
//								q.push_back(pos[ch][j]);
//								break;
//							}
//						}
//						break;
//					}
//					else{
//						*p1=pos[ch][i];
//					}					
//				}	
//			}
//		}
//		cout<<q.size()<<endl;	
//	}
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXV = 2000005;
//const int MAXN = 500005;
//
//int ac, dr, n, m;
//int a[MAXN], d[MAXN], x[MAXN];
//
//int bit[MAXV];
//
//int lowbit(int x) {
//    return x & -x;
//}
//
//void add(int idx, int delta) {
//    idx++; 
//    while (idx < MAXV) {
//        bit[idx] += delta;
//        idx += lowbit(idx);
//    }
//}
//
//int query(int idx) {
//    idx++;
//    int res = 0;
//    while (idx > 0) {
//        res += bit[idx];
//        idx -= lowbit(idx);
//    }
//    return res;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    cin >> ac >> dr;
//    
//    cin >> n;
//    
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    
//    for (int i = 1; i <= n; i++) {
//        cin >> d[i];
//    }
//    
//    memset(bit, 0, sizeof(bit));
//    for (int i = 1; i <= n; i++) {
//        x[i] = max(0, a[i] - ac) + max(0, d[i] - dr);
//        add(x[i], 1);
//    }
//    
//    cin >> m;
//    
//    while (m--) {
//        int k, na, nd;
//        cin >> k >> na >> nd;
//        
//        add(x[k], -1);
//        
//        a[k] = na;
//        d[k] = nd;
//        
//        x[k] = max(0, a[k] - ac) + max(0, d[k] - dr);
//        add(x[k], 1);
//        
//        int num=0;
//        int cnum=query(num);
//        while(cnum>num){
//			num=cnum;
//			cnum=query(num);
//		}
//		cout<<cnum<<endl;
//    }
//    
//    return 0;
//}

//线段树
//#include<iostream>
//using namespace std;
//int n,m;
//int a[4*100005];
//int h[100005];
//int lzy[4*100005];
//
//
//void pushup(int idx){
//	a[idx]=a[2*idx]+a[2*idx+1];
//}
//
//void build(int l,int r,int idx){
//	if(l==r){
//		a[idx]=h[l];
//		return;
//	}
//	int m=(l+r)/2;
//	build(l,m,2*idx);
//	build(m+1,r,2*idx+1);
//	pushup(idx);
//}
//
////int query(int p,int l,int r,int idx){
////	if(l==r){
////		return a[idx];
////	}
////	int m=(l+r)/2;
////	if(m>=p){
////		return query(p,l,m,2*idx);
////	}
////	else{
////		return query(p,m+1,r,2*idx+1);
////	}
////}
//
////void update(int p,int x,int l,int r,int idx){
////	if(l==r){
////		a[idx]=x;
////		return;
////	}
////	int m=(l+r)/2;
////	if(m>=p){
////		update(p,x,l,m,2*idx);
////	}
////	else{
////		update(p,x,m+1,r,2*idx+1);
////	}
////	pushup(idx);	
////}
//
//bool inrange(int l1,int r1,int l,int r){
//	if(l1<=l&&r1>=r){
//		return true;
//	}
//	return false;
//}
//
//bool outrange(int l1,int r1,int l,int r){
//	return r<l1||l>r1;
//}
//
////int query1(int l1,int r1,int l,int r,int idx){
////	if(inrange(l1,r1,l,r)){
////		return a[idx];
////	}
////	else{
////		if(!outrange(l1,r1,l,r)){
////			int m=(l+r)/2;
////			return query1(l1,r1,l,m,2*idx)+query1(l1,r1,m+1,r,2*idx+1);
////		}
////	}
////	return 0;
////}
//
//void maketag(int idx,int len,int x){
//	lzy[idx]+=x;
//	a[idx]+=len*x;
//}
//
//void pushdown(int idx,int l,int r){
//	int m=(l+r)/2;
//	int len1=m-l+1;
//	int len2=r-m;
//	maketag(2*idx,len1,lzy[idx]);
//	maketag(2*idx+1,len2,lzy[idx]);
//	lzy[idx]=0;
//}
//
//int query2(int l1,int r1,int l,int r,int idx){
//	if(inrange(l1,r1,l,r)){
//		return a[idx];
//	}
//	else if(!outrange(l1,r1,l,r)){
//		int m=(l+r)/2;
//		pushdown(idx,l,r);
//		return query2(l1,r1,l,m,2*idx)+query2(l1,r1,m+1,r,2*idx+1);
//	}
//	else return 0;
//}
//
//void update1(int l1,int r1,int l,int r,int x,int idx){
//	if(inrange(l1,r1,l,r)){
//		maketag(idx,r-l+1,x);
//		return;
//	}
//	else if(!outrange(l1,r1,l,r)){
//		int m=(l+r)/2;
//		pushdown(idx,l,r);
//		update1(l1,r1,l,m,x,2*idx);
//		update1(l1,r1,m+1,r,x,2*idx+1);
//		pushup(idx);
//	}
//	else return;	
//}
//
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>h[i];
//	}
//	build(1,n,1);
//	int ch;
//	cin>>ch;
//	while(m--){
//		if(ch==1){
//			int l1,r1,num;
//			cin>>l1>>r1>>num;
//			update1(l1,r1,1,n,num,1);
//		}
//		else{
//			int l1,r1;
//			cin>>l1>>r1;
//			cout<<query2(l1,r1,1,n,1)<<endl;
//		}
//		cin>>ch;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//typedef long long LL;  // 定义 LL 为 long long
//
//int n,m;
//LL a[4*100005];      // 线段树数组
//LL h[100005];        // 原始数组
//LL lzy[4*100005];    // 懒标记数组
//
//void pushup(int idx){
//    a[idx]=a[2*idx]+a[2*idx+1];
//}
//
//void build(int l,int r,int idx){
//    if(l==r){
//        a[idx]=h[l];
//        return;
//    }
//    int m=(l+r)/2;
//    build(l,m,2*idx);
//    build(m+1,r,2*idx+1);
//    pushup(idx);
//}
//
//bool inrange(int l1,int r1,int l,int r){
//    if(l1<=l&&r1>=r){
//        return true;
//    }
//    return false;
//}
//
//bool outrange(int l1,int r1,int l,int r){
//    return r<l1||l>r1;
//}
//
//void maketag(int idx,int len,LL x){  // x 改为 LL 类型
//    lzy[idx]+=x;
//    a[idx]+=len*x;
//}
//
//void pushdown(int idx,int l,int r){
//    if(lzy[idx] != 0){ 
//        int m=(l+r)/2;
//        int len1=m-l+1;
//        int len2=r-m;
//        maketag(2*idx,len1,lzy[idx]);
//        maketag(2*idx+1,len2,lzy[idx]);
//        lzy[idx]=0;
//    }
//}
//
//LL query2(int l1,int r1,int l,int r,int idx){  // 返回类型改为 LL
//    if(inrange(l1,r1,l,r)){
//        return a[idx];
//    }
//    else if(!outrange(l1,r1,l,r)){
//        int m=(l+r)/2;
//        pushdown(idx,l,r);
//        return query2(l1,r1,l,m,2*idx)+query2(l1,r1,m+1,r,2*idx+1);
//    }
//    else return 0;
//}
//
//void update1(int l1,int r1,int l,int r,LL x,int idx){  // x 改为 LL 类型
//    if(inrange(l1,r1,l,r)){
//        maketag(idx,r-l+1,x);
//        return;
//    }
//    else if(!outrange(l1,r1,l,r)){
//        int m=(l+r)/2;
//        pushdown(idx,l,r);
//        update1(l1,r1,l,m,x,2*idx);
//        update1(l1,r1,m+1,r,x,2*idx+1);
//        pushup(idx);
//    }
//    else return;    
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>h[i];
//    }
//    build(1,n,1);
//    
//    int ch;
//    for(int i=0;i<m;i++){
//        cin>>ch;
//        if(ch==1){
//            int l1,r1;
//            LL num;           // num 改为 LL 类型
//            cin>>l1>>r1>>num;
//            update1(l1,r1,1,n,num,1);
//        }
//        else{
//            int l1,r1;
//            cin>>l1>>r1;
//            cout<<query2(l1,r1,1,n,1)<<endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int h[100010];
//int n,m;
//
//bool solve(int x){
//	int sum=0;
//	for(int i=1;i<=n;i++){
//		sum+=h[i]/x;
//	 	if(sum>=m){
//			return true; 	
//		}	
//	}
//	return false;
//}
//
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>h[i];
//	}
//	int l=0,r=1e8;
//	while(l<r){
//		int mid=(l+r+1)/2;
//		if(solve(mid)){
//			l=mid;
//		}
//		else{
//			r=mid-1;
//		}
//	}	
//	cout<<l;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//struct c{
//	int n,s;
//};
//c city[200010];
//vector<int> q;
//bool cmp(c a,c b){
//	return a.n<b.n;
//}
//int main(){
//	int m;
//	cin>>m;
//	for(int i=1;i<=m;i++){
//		cin>>city[i].n>>city[i].s;
//	}
//	
//	sort(city+1,city+m+1,cmp);
//	
//	for(int i=1;i<=m;i++){
//		auto idx=upper_bound(q.begin(),q.end(),city[i].s);
//		if(idx==q.end()){
//			q.push_back(city[i].s);
//		}
//		else{
//			*idx=city[i].s;
//		}
//	}
//	
//	cout<<q.size();
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//int T;
//int a[105];
//
//int main(){
//	cin>>T;
//	while(T--){
//		int n;
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//		}
//		sort(a+1,a+n+1);
//		
//		bool t[a[n]+1]={false};
//		
//		t[0]=true;
//		
//		int ans=n;
//		for(int i=1;i<=n;i++){
//			if(t[a[i]]){
//				ans--;
//			}
//			for(int j=a[i];j<=a[n];j++){
//				t[j]=t[j]|t[j-a[i]];	
//			}	
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//int n,m;
//int a[4*100010];
//void pushup(int idx){
//	a[idx]=a[2*idx]+a[2*idx+1];
//}
//void creat(int l,int r,int idx){
//	if(l==r){
//		a[idx]=0;
//		return;
//	}
//	int m=(l+r)/2;
//	creat(l,m,2*idx);
//	creat(m+1,r,2*idx+1);
//	pushup(idx);
//}
//bool sw[4*100010];
//bool inrange(int l1,int r1,int l,int r){
//	return l<=l1&&r>=r1;
//}
//bool outrange(int l1,int r1,int l,int r){
//	return r<l1||l>r1;
//}
//void maketag(int l1,int r1,int idx){
//	a[idx]=(r1-l1+1)-a[idx];
//	sw[idx]=!sw[idx];
//}
//void pushdown(int l1,int r1,int idx){
//	if(sw[idx]){
//		int m=(l1+r1)/2;
//		maketag(l1,m,2*idx);
//		maketag(m+1,r1,2*idx+1);
//		sw[idx]=false;
//	}
//}
//
//void update(int l1,int r1,int l,int r,int idx){
//	if(inrange(l1,r1,l,r)){
//		maketag(l1,r1,idx);
//		return;
//	}
//	int m=(l1+r1)/2;
//	if(!outrange(l1,r1,l,r)){
//		pushdown(l1,r1,idx);
//		update(l1,m,l,r,idx*2);
//		update(m+1,r1,l,r,idx*2+1);
//		pushup(idx);
//	}
//}
//int check(int l1,int r1,int l,int r,int idx){
//	if(inrange(l1,r1,l,r)){
//		return a[idx];
//	}
//	if(!outrange(l1,r1,l,r)){
//		int m=(l1+r1)/2;
//		pushdown(l1,r1,idx);
//		return check(l1,m,l,r,idx*2)+check(m+1,r1,l,r,idx*2+1);
//	}
//	return 0;
//}
//
//int main(){
//	cin>>n>>m;
//	creat(1,n,1);
//	memset(sw,false,sizeof(sw));
//	
//	while(m--){
//		int t;
//		cin>>t;
//		int l,r;
//		cin>>l>>r;
//		if(t==0){
//			update(1,n,l,r,1);
//		}
//		else{
//			cout<<check(1,n,l,r,1)<<endl;		
//		}
//	}		
//	return 0;
//#include<iostream>
//using namespace std;
//int n,m,k;
//int ans=0;
//char a[105][105];
//int sx[2]={0,1},sy[2]={1,0};
//void dfs(int s,int x,int y,int cnt){
//	if(cnt>k){
//		ans++;
//		return;
//	}
//	if(x>n||y>m||a[x][y]=='#'){
//		return;
//	}
//	dfs(s,x+sx[s],y+sy[s],cnt+1);
//}
//
//int main(){
//	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin>>a[i][j];
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(a[i][j]=='.'){
//				for(int u=0;u<2;u++){
//					dfs(u,i,j,1);
//				}
//			}
//		}
//	}
//	if(k==1){
//		ans/=2;
//	}		
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//string a,b;
//
//int main(){
//	cin>>a>>b;
//	int len1=a.size();
//	int len2=b.size();
//	
//	int len=max(len1,len2);
//	while(len1<len) len1++,a='0'+a;
//	while(len2<len) len2++,b='0'+b;
//	
//	string ans;
//	int pre=0;
//	for(int i=len-1;i>=0;i--){
//		int t1=a[i]-'0',t2=b[i]-'0';
//		int sum=t1+t2+pre;
//		pre=sum/10;
//		char num=sum%10+'0';
//		ans=num+ans;
//	}
//	if(pre==1){
//		ans='1'+ans;
//	}
//	cout<<ans;
//	return 0;
//}
#include<iostream>
#include<string>
//#include<cstring>
//using namespace std;
//string a,b;
//int a1[2005],b1[2005];
//int c[4005];
//int main(){
//	cin>>a>>b;
//	if(a=="0"||b=="0"){
//		cout<<"0";
//	}
//	else{
//	int len1=a.size(),len2=b.size();
//	for(int i=1;i<=len1;i++) a1[i]=a[len1-i]-'0';
//	for(int i=1;i<=len2;i++) b1[i]=b[len2-i]-'0';
//	memset(c,0,sizeof(c));
//	for(int i=1;i<=len1;i++){
//		for(int j=1;j<=len2;j++){
//			c[i+j-1]+=a1[i]*b1[j];
//		}
//	}
//	for(int i=1;i<=len1+len2;i++){
//		c[i+1]+=c[i]/10;
//		c[i]%=10;
//	}
//	int len;
//	if(c[len1+len2]){
//		len=len1+len2;
//	}
//	else{
//		len=len1+len2-1;
//	}
//	for(int i=len;i>=1;i--){
//		cout<<c[i];
//	}
//	}
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct p{
//	int l,r;
//	int v;
//};
//int n;
//p a[1005];
//
//bool cmp(p a,p b){
//	return a.v<b.v;
//}
//
//int main(){
//	cin>>n;
//	cin>>a[0].l>>a[0].r;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].l>>a[i].r;
//		a[i].v=(long long)a[i].l*a[i].r;
//	}
//	sort(a+1,a+n+1,cmp);
//	long long sum=a[0].l,ans=0;
//	
//	for(int i=1;i<=n;i++){
//		if(sum/a[i].r>ans) ans=sum/a[i].r;
//		sum*=a[i].l;	
//	}
//	
//	cout<<ans;
//	return 0;
//}
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//const int MAXN=1010;
//
//struct bign{
//    const int BASE=1e4;
//    int a[MAXN<<2],len;
//    bign(int len=0){
//        this->len=len;
//    }
//    bign operator=(int rhs){
//        len=0;
//        if(rhs==0){
//            len=1;
//            return *this;
//        }
//        while(rhs){
//            a[++len]=rhs%BASE;
//            rhs/=BASE;
//        }
//        return *this;
//    }
//    bign operator=(const bign rhs){
//        memcpy(a,rhs.a,sizeof(rhs.a));
//        len=rhs.len;
//        return *this;
//    }
//    void operator*=(const int rhs){
//        for(int i=1;i<=len;i++)
//            a[i]*=rhs;
//        for(int i=1;i<=len;i++){
//            a[i+1]+=a[i]/BASE;
//            a[i]%=BASE;
//            if(i+1>len&&a[i+1])
//                len++;
//        }
//        while(len&&a[len]==0)
//            len--;
//    }
//    bign operator/(const int rhs){
//        bign c;c=*this;
//        while(c.len&&c.a[c.len]==0)
//            c.len--;
//        for(int i=c.len;i;i--){
//            c.a[i-1]+=(c.a[i]%rhs)*BASE;
//            c.a[i]/=rhs;
//        }
//        while(c.len&&c.a[c.len]==0)
//            c.len--;
//        return c;
//    }
//    void print(){
//        while(len&&a[len]==0)
//            len--;
//        if(len==0){
//            putchar('0');
//            return;
//        }
//        printf("%d",a[len]);
//        for(int i=len-1;i;i--)
//            printf("%04d",a[i]);
//    }
//    bool operator>(const bign &rhs)const{
//        if(len!=rhs.len)
//            return len>rhs.len;
//        for(int i=len;i;i--)
//            if(a[i]!=rhs.a[i])
//                return a[i]>rhs.a[i];
//        return 0;
//    }
//}mul,ans;
//
//struct node{
//    int a,b;
//    bool operator<(const node &rhs)const{
//        return a*b<rhs.a*rhs.b||(a*b==rhs.a*rhs.b&&a<rhs.a);
//    }
//}p[MAXN];
//
//int main(){
//    int n;scanf("%d",&n);
//    for(int i=0;i<=n;i++)
//        scanf("%d%d",&p[i].a,&p[i].b);
//    std::sort(p+1,p+n+1);
//    mul=p[0].a;
//    for(int i=1;i<=n;i++){
//        bign tmp=mul/p[i].b;
//        if(tmp>ans)
//            ans=tmp;
//        mul*=p[i].a;
//    }
//    ans.print();
//    return 0;
//}
//#include<iostream>
//#include<math.h>
//#include<limits.h>
//using namespace std;
//int a[15],b[15];
//int n;
//int ans=INT_MAX;
//bool v[15]={false};
//void dfs(int s,int k,int now,bool f){
//	if(f){
//		if(abs(s-k)<ans){
//			ans=abs(s-k);
//		}
//	}
//	if(now==n){
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!v[i]){
//			v[i]=true;
//			dfs(s*a[i],k+b[i],i,true);
//			v[i]=false;
//		}
//	}
//}
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i]>>b[i];
//	}
//	dfs(1,0,0,false);
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<vector>
//using namespace std;
//
//int n, m;
//char a[305][305];
//queue<pair<int, int>> q;
//vector<pair<int, int>> portals[26];
//int dist[305][305];
//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {1, 0, -1, 0};
//bool v[305][305] = {false};
//int ans;
//
//void bfs() {
//    while (!q.empty()) {
//        int x1 = q.front().first;
//        int y1 = q.front().second;
//        q.pop();
//
//        if (a[x1][y1] == '=') {
//            ans = dist[x1][y1];
//            break;
//        }
//        
//        for (int i = 0; i < 4; i++) {
//            int x2 = x1 + dx[i];
//            int y2 = y1 + dy[i];
//            
//            if (x2 < 1 || x2 > n || y2 < 1 || y2 > m || v[x2][y2] || a[x2][y2] == '#') {
//                continue;
//            }
//            
//            v[x2][y2] = true;
//            
//            if (a[x2][y2] >= 'A' && a[x2][y2] <= 'Z') {
//                int idx = a[x2][y2] - 'A';
//                    pair<int, int> target;
//                    if (portals[idx][0].first == x2 && portals[idx][0].second == y2) {
//                        target = portals[idx][1];
//                    } else {
//                        target = portals[idx][0];
//                    }
//                    if(!v[x2][y2]) v[x2][y2] = true;
//                    if (!v[target.first][target.second]) {
//                        v[target.first][target.second] = true;
//                        dist[target.first][target.second] = dist[x1][y1] + 1;
//                        q.push(target);
//            		}
//            }
//            else {
//                dist[x2][y2] = dist[x1][y1] + 1;
//                q.push({x2, y2});
//            }
//        }
//    }
//    cout << ans;
//}
//
//int main() {
//	cin >> n >> m;
//	memset(dist, 0, sizeof(dist));
//	
//	for (int i = 1; i <= n; i++) {
//	    string s;
//	    cin >> s;
//	    for (int j = 1; j <= m; j++) {
//	        a[i][j] = s[j-1];
//	        if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
//	            portals[a[i][j]-'A'].push_back({i,j});
//	        } else if (a[i][j] == '@') {
//	            q.push({i,j});
//	            v[i][j] = true;
//	        }
//	    }
//	}
//    
//    bfs();
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int a[31][61];
//bool v[31][61]={false};
//int dx[4] = {1, -1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//int ans = -1;
//int sum = 0;
//
//void dfs(int x1, int y1) {
//    v[x1][y1] = true;
//    sum++;
//    
//    for(int i = 0; i < 4; i++) {
//        int x2 = x1 + dx[i];
//        int y2 = y1 + dy[i];
//        
//        if(x2 < 1 || x2 > 30 || y2 < 1 || y2 > 60 || a[x2][y2] == 0 || v[x2][y2]) {
//            continue;
//        }    
//        dfs(x2, y2);
//    }
//}
//
//int main() {
//    char ch;
//    for(int i = 1; i <= 30; i++) {
//        for(int j = 1; j <= 60; j++) {
//            cin >> ch;           // 读入字符
//            a[i][j] = ch - '0';  // 将字符 '0'/'1' 转换为数字 0/1
//        }
//    }
//    
//    for(int i = 1; i <= 30; i++) {
//        for(int j = 1; j <= 60; j++) {
//            if(!v[i][j] && a[i][j] == 1) {
//                sum = 0;
//                dfs(i, j);
//                if(sum > ans) {
//                    ans = sum;
//                }
//            }
//        }
//    }
//    
//    cout << ans;
//    return 0;
//}
//A*做法，从小到大列深度
//#include<iostream>
//#include<string>
//#include<map>
//#include<cmath>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//#include<cstdio>
//using namespace std;
//typedef long long lt;
//
//int read()
//{
//    int f=1,x=0;
//    char ss=getchar();
//    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
//    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
//    return f*x;
//}
//
//char ss[15];
//int ans[4][4]=
//{{0,0,0,0},
// {0,1,2,3},
// {0,8,0,4},
// {0,7,6,5}};
//int a[5][5],k,judge;
//int nxtx[]={0,1,-1,0};
//int nxty[]={1,0,0,-1};
//
//int check()
//{
//    for(int i=1;i<=3;++i)
//    for(int j=1;j<=3;++j)
//    if(ans[i][j]!=a[i][j])return 0;
//    return 1;
//}
//
//int test(int step)
//{
//    int cnt=0;
//    for(int i=1;i<=3;++i)
//    for(int j=1;j<=3;++j)
//    if(ans[i][j]!=a[i][j]){ if(++cnt+step>k) return 0;}
//    return 1;
//}
//
//void A_star(int step,int x,int y,int pre)
//{
//    if(step==k){ if(check())judge=1; return;}
//    if(judge) return;
//    for(int i=0;i<4;++i)
//    {
//        int nx=x+nxtx[i],ny=y+nxty[i];
//        if(nx<1||nx>3||ny<1||ny>3||pre+i==3) continue;
//        swap(a[x][y],a[nx][ny]);
//        if(test(step)) A_star(step+1,nx,ny,i);
//        swap(a[x][y],a[nx][ny]);
//    }
//}
//int main()
//{
//    int x,y;
//    scanf("%s",&ss);
//    for(int i=0;i<9;++i)
//    {
//        a[i/3+1][i%3+1]=ss[i]-'0';
//        if(ss[i]-'0'==0)x=i/3+1,y=i%3+1;
//    }
//    if(check()){printf("0");return 0;}
//    while(++k)
//    {
//        A_star(0,x,y,-1);
//        if(judge){printf("%d",k);break;}
//    }
//    return 0;
//}
//KMP算法*****
//#include<iostream>
//using namespace std;
//string s1,s2;
//int b[1000010];
//int main(){
//	cin>>s1>>s2;
//	int l1=s1.size(),l2=s2.size();
//	int j=0;
//	for(int i=1;i<l2;++i){
//		while(j&&s2[i]!=s2[j]){
//			j=b[j-1];
//		}
//		if(s2[i]==s2[j]){
//			j++;
//		}
//		b[i]=j;
//	}
//	j=0;
//	for(int i=0;i<l1;++i){
//		while(j&&s1[i]!=s2[j]){
//			j=b[j-1];
//		}
//		if(s1[i]==s2[j]){
//			j++;
//		}
//		if(j==l2){
//			cout<<i+2-j<<endl;
//			j=b[j-1];
//		}
//	}
//	for(int i=0;i<l2;i++){
//		if(i){
//			cout<<" ";
//		}
//		cout<<b[i];
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int L;
//int n1,n2;
//int a[10000010];
//bool solve(int c){
//	int sum=0;
//	int now=a[1];
//	for(int i=2;i<=n1;i++){
//		if(a[i]-now>c){
//			sum+=(a[i]-now)/c;
//		}
//
//		if(sum>n2){
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(){
//	cin>>L>>n1>>n2;
//	
//	for(int i=1;i<=n1;i++){
//		cin>>a[i];
//	}
//		
//	int l=0,r=L;
//	while(l<r){
//		int m=l+(r-l)/2;
//		if(solve(m)){
//			r=m;
//		}
//		else{
//			l=m+1;
//		}
//	}
//	
//	cout<<r;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<string>
//typedef unsigned long long ull;
//const int prime=23317;
//const ull mod=212370440130137957ll;
//using namespace std;
//int n;
//ull a[100010];
//ull hash1(string t){
//	ull sum=0;
//	int l=t.size();
//	for(int i=0;i<=l;i++){
//		sum+=(sum*131+t[i])%mod+prime;
//	}
//	return sum;
//}
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		string t;
//		cin>>t;
//		a[i]=hash1(t);
//	}
//	sort(a+1,a+n+1);
//	int ans=0;
//	for(int i=1;i<=n;i++)
//	{
//	 	if(a[i]!=a[i+1])
//	 	ans++;
//	}
//	 printf("%d",ans); 
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int a[205];
//int n,f1,f2;
//int ans=1e4;
//int dis[205];
//void dfs(int f,int ste){
//	dis[f]=ste;
//	int t=f+a[f];
//	if(t<=n&&ste+1<dis[t]){
//		dfs(t,ste+1);
//	}
//	t=f-a[f];
//	if(t>=1&&ste+1<dis[t]){
//		dfs(t,ste+1);
//	}	
//}
//
//int main(){
//	cin>>n>>f1>>f2;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	memset(dis,0x3f3f3f3f,sizeof(dis));
//
//	dfs(f1,0);
//	
//	cout<<(dis[f2]==0x3f?-1:dis[f2]);
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int dp[55][55];
//
//int main(){
//	string s;
//	cin>>s;
//	int len=s.size();
//	memset(dp,0x3f,sizeof(dp));
//	for(int i=0;i<len;i++){
//		dp[i][i]=1;
//	}
//	for(int k=2;k<=len;k++){
//		for(int i=0;i+k<=len;i++){
//			int r=i+k-1;
//			if(s[i]==s[r]){
//				dp[i][r]=min(dp[i+1][r],dp[i][r-1]);
//			}
//			else{
//				for(int j=i;j<r;j++){
//					dp[i][r]=min(dp[i][r],dp[i][j]+dp[j+1][r]);
//				}
//			}
//		}
//	}
//	cout<<dp[0][len-1];	
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//int main(){
//    int k;
//    cin>>k;
//    cin.ignore();
//    string s1;
//    getline(cin,s1);
//    int len=s1.size();
//    int idx=1;
//    string ss[50];
//    int cn=1; 
//    for(int i=0;i<len;++i,++cn){
//        ss[idx]+=s1[i];
//        if(cn==4){
//            cn=0;
//            ++idx;
//        }
//    }
//    int l1=ss[idx].size();
//    for(int i=l1;i<=k;i++){
//        ss[idx]+=' ';
//    }
//    for(int i=0;i<k;i++){
//        for(int j=idx;j>=1;j--){
//            cout<<ss[j][i];
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int n;
//int b[1000010]={0};
//int main(){
//	string a;
//	cin>>n;
//	cin.ignore();
//	cin>>a;
//	int j=0;
//	for(int i=1;i<n;i++){
//		while(j&&a[i]!=a[j]){
//			j=b[j-1];
//		}
//		if(a[j]==a[i]){
//			++j;
//		}
//		b[i]=j;
//	}
//	cout<<n-b[n-1];
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int a,b,n;
//int x[4]={0,1,0,-1};
//int y[4]={-1,0,1,0};
//int sx,sy,ex,ey;
//int sum=0;
//bool v[10][10]={false};
//void dfs(int x1,int y1){
//	if(x1==ex&&y1==ey){
//		sum++;
//		return;
//	}
//	for(int i=0;i<=3;i++){
//		int nx=x1+x[i];
//		int ny=y1+y[i];
//		if(nx<1||nx>a||ny<1||ny>b||v[nx][ny]){
//			continue;
//		}
//		v[nx][ny]=true;
//		dfs(nx,ny);
//		v[nx][ny]=false;	
//	}
//}
//int main(){
//	cin>>a>>b>>n;
//	cin>>sx>>sy>>ex>>ey;
//	for(int i=1;i<=n;i++){
//		int tx,ty;
//		cin>>tx>>ty;
//		v[tx][ty]=true;
//	}
//	v[sx][sy]=true;
//	dfs(sx,sy);
//	cout<<sum;
//	return 0;
//}
//#include<iostream>
//#define maxn 2000*75+5
//using namespace std;
//int a[maxn][26];
//int tot=0;
//int word[maxn]={0};
//int ans=0;
//
//void insert(string t){
//	int l;
//	int r=0;
//	int sum=0;
//	l=t.size();
//	for(int i=0;i<l;i++){
//		int x=t[i]-'a';
//		if(a[r][x]==0){
//			a[r][x]=++tot;
//		}
//		r=a[r][x];
//		sum+=word[r];
//	}
//	word[r]=1;
//	if(sum+1>ans){
//		ans=sum+1;
//	}	
//}
//int main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		string t;
//		cin>>t;
//		insert(t);
//	}
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int f[41][41][41][41];
//int n,m;
//int r[400];
//int b[5];
//int main(){
//	ios::sync_with_stdio(false);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>r[i];
//	}
//	for(int i=1;i<=m;i++){
//		int t;
//		cin>>t;
//		b[t]++;
//	}
//	f[0][0][0][0]=r[1];
//	for(int i1=0;i1<=b[1];++i1){
//		for(int i2=0;i2<=b[2];++i2){
//			for(int i3=0;i3<=b[3];++i3){
//				for(int i4=0;i4<=b[4];++i4){
//					int r1=1+i1+2*i2+3*i3+4*i4;
//					if(i1) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1-1][i2][i3][i4]+r[r1]);
//					if(i2) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2-1][i3][i4]+r[r1]);
//					if(i3) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3-1][i4]+r[r1]);
//					if(i4) f[i1][i2][i3][i4]=max(f[i1][i2][i3][i4],f[i1][i2][i3][i4-1]+r[r1]);
//				}
//			}
//		}
//	}
//	cout<<f[b[1]][b[2]][b[3]][b[4]];		
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#define mx 10000*50+10
//using namespace std;
//int sx[mx][26];
//int tot=0;
//int n,m;
//bool f[mx]={false};
//bool cnt[mx]={false};
//void insert(string t){
//	int r=0;
//	int l=t.size();
//	int nex;
//	for(int i=0;i<l;i++){
//		nex=t[i]-'a';
//		if(sx[r][nex]==0){
//			sx[r][nex]=++tot;
//		}
//		r=sx[r][nex];
//	}
//	f[r]=true;
//}
//void check(string t){
//	int r=0;
//	int l=t.size();
//	int nex;
//	for(int i=0;i<l;i++){
//		nex=t[i]-'a';
//		if(!sx[r][nex]){
//			cout<<"WRONG"<<endl;
//			return;
//		}
//		r=sx[r][nex];
//	}
//	if(!cnt[r]&&f[r]){
//		cout<<"OK"<<endl;
//		cnt[r]=true;
//	}
//	else if(cnt[r]){
//		cout<<"REPEAT"<<endl;
//	}
//	else{
//		cout<<"WRONG"<<endl;
//	}	
//}
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		string t;
//		cin>>t;
//		insert(t);
//	}
//	cin>>m;
//	for(int i=1;i<=m;i++){
//		string t;
//		cin>>t;
//		check(t);
//	}	
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int dp[1005][1005][2];
//int n;
//int q[1005];
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		dp[i][i][0]=1;
//	}
//	for(int i=1;i<=n;i++){
//		cin>>q[i];
//	}
//	for(int k=1;k<n;k++){
//		for(int i=1,j=i+k;i<=n-k;i++,j++){
//				if(q[i+1]>q[i]){
//					dp[i][j][0]+=dp[i+1][j][0];
//				}
//				if(q[j]>q[i]){
//					dp[i][j][0]+=dp[i+1][j][1];
//				}
//				if(q[j-1]<q[j]){
//					dp[i][j][1]+=dp[i][j-1][1];
//				}
//				if(q[i]<q[j]){
//					dp[i][j][1]+=dp[i][j-1][0];
//				}
//				dp[i][j][0]%=19650827;
//				dp[i][j][1]%=19650827;	
//		}
//	}
//	cout<<(dp[1][n][0]+dp[1][n][1])%19650827;	
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#define mx 31*100000+5
//
//using namespace std;
//struct node{
//	int idx,w;
//};
//vector<node> q[100010];
//bool v[100010]={false};
//int n;
//int tot=0;
//int trie[mx][2];
//int cnt=0;
//int s[100010];
//void build(int num){
//	int r=0;
//    for(int i=31; i>=0; i--){
//        int bit = (num >> i) & 1;
//        if(!trie[r][bit]){
//            trie[r][bit]=++tot;
//        }
//        r=trie[r][bit];
//    }    
//}
//void build_trie(int f,int sum){
//	s[++cnt]=sum;
//	build(sum);
//	for(auto i:q[f]){
//		int nx=i.idx;
//		if(!v[nx]){
//			v[nx]=true;
//			int ne=sum^i.w;
//			build_trie(nx,ne);			
//		}
//	}
//}
//int find(int n){
//	int sum=0;
//	int r=0;
//	for(int i=31;~i;i--){
//		int a=(n>>i)&1;
//		if(trie[r][!a]){
//			sum+=(1<<i);
//			r=trie[r][!a];
//		}
//		else{
//			r=trie[r][a];
//		}
//	}
//	return sum;
//}
//
//int main(){
//	cin>>n;
//	for(int i=1;i<n;i++){
//		int fr,nx,wt;
//		cin>>fr>>nx>>wt;
//		q[fr].push_back({nx,wt});
//		q[nx].push_back({fr,wt});
//	}
//	v[1]=true;
//	build_trie(1,0);
//	int ans=0;
//	for(int i=1;i<=cnt;i++){
//		ans=max(ans,find(s[i]));
//	}
//	cout<<ans;		
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<stack>
//using namespace std;
//int dp[25][25];
//int n;
//int pre[25][25];
//int main(){
//	cin>>n;
//	memset(dp,0,sizeof(dp));
//	memset(pre,-1,sizeof(pre));
//	for(int i=1;i<=n;i++){
//		cin>>dp[i][i];
//	}
//	for(int i=1;i<=n-1;i++){
//		for(int j=i+1;j<=n;j++){
//			cin>>dp[i][j];
//			if(dp[i][j]){
//				dp[i][j]=dp[i][i]+dp[j][j];
//				pre[i][j]=i;
//			}
//		}
//	}
//	for(int k=2;k<=n-1;k++){
//		for(int i=1;i<k;i++){
//			for(int j=k+1;j<=n;j++){
//				if(dp[i][k]&&dp[k][j]){
//					if(dp[i][k]+dp[k][j]-dp[k][k]>dp[i][j]){
//						dp[i][j]=dp[i][k]+dp[k][j]-dp[k][k];
//						pre[i][j]=k;
//					}
//				}
//			}
//		}
//	}
//	int ans=0;
//	int idxs,idxe;
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(dp[i][j]>ans){
//				idxs=i;
//				idxe=j;
//				ans=dp[i][j];	
//			}
//		}
//	}
//	int cnt=1;
//	stack<int> st;
//	st.push(idxe);
//	for(int i=pre[idxs][idxe];i!=-1;i=pre[idxs][i]){
//		st.push(i);
//		cnt++;
//	}
//	for(int i=1;i<=cnt;i++){
//		if(i!=1){
//			cout<<" ";
//		}
//		cout<<st.top();
//		st.pop();
//	}
//	cout<<endl<<ans;		
//	return 0;
//}
//#include <cstdio>
//#include <algorithm>
//#define M 200010
//
//using namespace std;
//
//int node_cnt, n, m;
//int sum[M<<5], rt[M], lc[M<<5], rc[M<<5];
//int a[M], b[M];
//int p;
//
//void build(int &t, int l, int r)
//{
//    t = ++node_cnt;
//    if(l == r)
//        return;
//    int mid = (l + r) >> 1;
//    build(lc[t], l, mid);
//    build(rc[t], mid+1, r);
//}
//
//int modify(int o, int l, int r)
//{
//    int oo = ++node_cnt;
//    lc[oo] = lc[o]; rc[oo] = rc[o]; sum[oo] = sum[o] + 1;
//    if(l == r)
//        return oo;
//    int mid = (l + r) >> 1;
//    if(p <= mid) lc[oo] = modify(lc[oo], l, mid);
//    else rc[oo] = modify(rc[oo], mid+1, r);
//    return oo;
//}
//
//int query(int u, int v, int l, int r, int k)
//{
//    int ans, mid = ((l + r) >> 1), x = sum[lc[v]] - sum[lc[u]];
//    if(l == r)
//        return l;
//    if(x >= k) ans = query(lc[u], lc[v], l, mid, k);
//    else ans = query(rc[u], rc[v], mid+1, r, k-x);
//    return ans;
//}
//
//int main()
//{
//    int l, r, k, q, ans;
//    scanf("%d%d", &n, &m);
//    for(register int i = 1; i <= n; i += 1)
//        scanf("%d", &a[i]), b[i] = a[i];
//    sort(b+1, b+n+1);
//    q = unique(b+1, b+n+1) - b - 1;
//    build(rt[0], 1, q);
//    for(register int i = 1; i <= n; i += 1)
//    {
//        p = lower_bound(b+1, b+q+1, a[i])-b;
//        rt[i] = modify(rt[i-1], 1, q);
//    }
//    while(m--)
//    {
//        scanf("%d%d%d", &l, &r, &k);
//        ans = query(rt[l-1], rt[r], 1, q, k);
//        printf("%d\n", b[ans]);
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#define mx 200005
//
//using namespace std;
//int rt[mx];
//int cnt=0;
//int sum[mx<<5];
//int lc[mx<<5],rc[mx<<5];
//int n,m;
//int oq[mx];
//int nq[mx];
//int p;
//
//void build(int k,int l,int r){
//	if(l==r){
//		return;
//	}
//	lc[k]=++cnt;
//	rc[k]=++cnt;
//	int m=(l+r)>>1;
//	build(lc[k],l,m);
//	build(rc[k],m+1,r);
//}
//
//int insert(int u,int l,int r){
//	int nc=++cnt;
//	sum[nc]=sum[u]+1;
//	if(l==r){
//		return nc;
//	}	
//	lc[nc]=lc[u],rc[nc]=rc[u];
//	int m=(l+r)>>1;
//	if(p<=m){
//		lc[nc]=insert(lc[u],l,m);
//	}
//	else{
//		rc[nc]=insert(rc[u],m+1,r);
//	}
//	return nc;
//}
//int find(int l,int r,int u,int v,int k){
//	int x=sum[lc[u]]-sum[lc[v]];
//	int m=(l+r)>>1;
//	if(l==r){
//		return l;
//	}
//	if(x>=k){
//		return find(l,m,lc[u],lc[v],k);
//	}
//	else{
//		return find(m+1,r,rc[u],rc[v],k-x);
//	}
//}
//
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>oq[i];
//		nq[i]=oq[i];
//	}
//	sort(nq+1,nq+n+1);
//	int len=unique(nq+1,nq+n+1)-nq-1;
//	build(rt[0],1,len);
//	for(int i=1;i<=n;i++){
//		p=lower_bound(nq+1,nq+len+1,oq[i])-nq;
//		rt[i]=insert(rt[i-1],1,len);
//	}
//	for(int i=1;i<=m;i++){
//		int l,r,k;
//		cin>>l>>r>>k;
//		int idx=find(1,len,rt[r],rt[l-1],k);
//		cout<<nq[idx]<<endl;
//	}	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int v[6][6]={	
//	{0,0,0,0,0,0},
//	{0,5,-1,-2,-1,-3},
// 	{0,-1,5,-3,-2,-4},
// 	{0,-2,-3,5,-2,-2},
//	{0,-1,-2,-2,5,-1},
// 	{0,-3,-4,-2,-1,0}
//};
//int a[105],b[105];
//int f[105][105];
//int l1,l2;
//int main()
//{
//	cin>>l1;
//	for(int i=1;i<=l1;i++)
//	{
//		char t;
//		cin>>t;
//		switch(t)
//		{
//		case'A':
//			a[i]=1;break;
//		case'C':
//			a[i]=2;break;
//		case'G':
//			a[i]=3;break;
//		case'T':
//			a[i]=4;break;
//		}
//	}
//	cin>>l2;
//	for(int i=1;i<=l2;i++)
//	{
//		char t;
//		cin>>t;
//		switch(t)
//		{
//		case'A':
//			b[i]=1;break;
//		case'C':
//			b[i]=2;break;
//		case'G':
//			b[i]=3;break;
//		case'T':
//			b[i]=4;break;
//		}
//	}
//	f[0][0]=0;
//	for(int i=1;i<=l1;i++)
//		f[i][0]=f[i-1][0]+v[a[i]][5];
//	for(int i=1;i<=l2;i++)
//		f[0][i]=f[0][i-1]+v[5][b[i]];
//	for(int i=1;i<=l1;i++)
//		for(int j=1;j<=l2;j++)
//			f[i][j]=max(f[i-1][j-1]+v[a[i]][b[j]],max(f[i-1][j]+v[a[i]][5],f[i][j-1]+v[5][b[j]]));
//	 
//	cout<<f[l1][l2]<<endl;
//	
//	return 0;
//}
//#include<iostream>
//#define mod 1000007 
//using namespace std;
//int dp[105][105]={0};
//int a[105];
//int main(){
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		dp[i][0]=1;
//	}
//	dp[0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(j<=a[i]){
//				for(int u=j;u>=0;u--){
//					dp[i][j]+=dp[i-1][j-u];
//				}
//			}
//			else if(j>a[i]){
//				for(int u=a[i];u>=0;u--){
//					dp[i][j]+=dp[i-1][j-u];
//				}
//			}
//			dp[i][j]%=mod;
//		}
//	}
//	cout<<dp[n][m];	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int n;
//int sum=0;
//int dp[20][20];
//int main(){
//	cin>>n;
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			if(!i) dp[i][j]=1;
//			else if(!j) dp[i][j]=dp[i-1][j+1];
//			else dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
//		}
//	}
//	cout<<dp[n][0];
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n;
//int dp[1000000];
//int sum[1000000];
//int main(){
//	memset(dp,0,sizeof(dp));
//	memset(sum,0,sizeof(sum));
//	dp[0]=1;
//	dp[1]=1;
//	dp[2]=2;
//	sum[0]=1;
//	sum[1]=2;
//	sum[2]=4;
//	cin>>n;
//	for(int i=3;i<=n;i++){
//		dp[i]=dp[i-1]+dp[i-2];
//		dp[i]=(dp[i]+2*sum[i-3])%10000;
//		sum[i]=(sum[i-1]+dp[i])%10000;
//	}
//	cout<<dp[n];
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#define maxn 4010
//using namespace std;
//class hp{
//public:
//    int a[maxn];
//    hp(){memset(a,0,sizeof(a));}
//    void clear(){memset(a,0,sizeof(a));}
//    hp(int x){
//        clear();
//        while(x){
//            a[++a[0]]=x%10;
//            x/=10;
//        }
//        while(a[a[0]]==0&&a[0])a[0]--;
//    }
//    hp& operator=(int x){
//        clear();
//        while(x){
//            a[++a[0]]=x%10;
//            x/=10;
//        }
//        while(a[a[0]]==0&&a[0])a[0]--;
//        return *this;
//    }
//
//    short cmp(const hp& x){
//        if(a[0]>x.a[0])return 1;
//        if(a[0]<x.a[0])return -1;
//        for(register int i=a[0];i>=1;i--){
//            if(a[i]>x.a[i])return 1;
//            if(a[i]<x.a[i])return -1;
//        }
//        return 0;
//    }
//    bool operator>(const hp& x){
//        return cmp(x)==1;
//    }
//    bool operator==(const hp& x){
//        return cmp(x)==0;
//    }
//    bool operator<(const hp& x){
//        return cmp(x)==-1;
//    }
//    bool operator>=(const hp& x){
//        return !(*this<x);
//    }
//    bool operator<=(const hp& x){
//        return !(*this>x);
//    }
//    
//    hp operator-(const hp& x){
//        hp a=*this,c;
//        c.a[0]=a.a[0]>x.a[0]?a.a[0]:x.a[0];
//        for(register int i=1;i<=c.a[0];i++) {
//            c.a[i]+=a.a[i]-x.a[i];
//            if(c.a[i]<0){c.a[i]+=10;a.a[i+1]--;}
//        }
//        while(c.a[c.a[0]]==0&&c.a[0])c.a[0]--;
//        return c;
//    }
//    hp operator*(const hp& x){
//        hp c;
//        for(register int i=1;i<=a[0];i++){
//            for(register int j=1;j<=x.a[0];j++){ 
//                c.a[i+j-1]+=a[i]*x.a[j];
//            }
//        }
//        c.a[0]=a[0]+x.a[0];
//        for(register int i=1;i<=c.a[0];i++){
//            if(c.a[i]>=10){
//                c.a[i+1]+=c.a[i]/10;
//                c.a[i]%=10;
//            }
//        }
//        while (c.a[c.a[0]]==0&&c.a[0]>0)c.a[0]--;
//        return c;
//    }
//    hp operator/(const int& x){
//        hp c;
//        int t=0,s=0;
//        bool flag=1;
//        for(register int i=a[0];i>=1;i--){
//            t=s*10+a[i];
//            if(t/x>0||t==0){
//                c.a[++c.a[0]]=t/x;
//                s=t%x;
//                flag=0;
//            }
//            else{
//                s=t;
//                if(!flag)c.a[++c.a[0]]=0;
//            }
//        }
//        reverse(c.a+1,c.a+c.a[0]+1);
//        return c;
//    }
//};
//int main(){
//	
//	return 0;
//}
//高精度
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#define mx 4010
//
//using namespace std;
//struct p{
//	int l,r;
//	int v;
//};
//int n;
//p a[1005];
//
//bool cmp(p a,p b){
//	return a.v<b.v;
//}
//class hp{
//public:
//	int a[mx];
//	hp(){
//		memset(a,0,sizeof(a));
//	}
//	hp(int num){
//		memset(a,0,sizeof(a));
//		while(num){
//			a[++a[0]]=num%10;
//			num/=10;		
//		}
//	}
//	hp operator*(const int& num){
//		hp c,b(num);
//		for(int i=1;i<=a[0];i++){
//			for(int j=1;j<=b.a[0];j++){
//				c.a[i+j-1]+=a[i]*b.a[j];
//			}
//		}
//		c.a[0]=a[0]+b.a[0]-1;
//		for(int i=1;i<=c.a[0];i++){
//			if(c.a[i]>=10){
//				c.a[i+1]+=c.a[i]/10;
//				c.a[i]%=10;
//			}
//		}
//		while(c.a[c.a[0]+1]){
//			c.a[0]++;			
//		}
//		return c;
//	}
//	hp operator/(const int& num){
//		hp c,b(num);
//		int u=0,t=0;
//		bool f=false;
//		for(int i=a[0];i>=1;i--){
//			t=u*10+a[i];
//			if(t/num>0||t==0){
//				c.a[++c.a[0]]=t/num;
//				u=t%num;
//				f=true;
//			}
//			else{
//				if(f){
//					c.a[++c.a[0]]=0;
//				}
//				u=t;
//			}
//		}
//		reverse(c.a+1,c.a+1+c.a[0]);
//		return c;
//	}
//	bool operator>(const hp& b){
//		if(a[0]>b.a[0]){
//			return true;
//		}
//		else if(a[0]<b.a[0]){
//			return false;
//		}
//		else{
//			for(int i=a[0];i>=1;i--){
//				if(a[i]>b.a[i]){
//					return true;
//				}
//			}
//			return false;
//		}
//	}
//};
//int main(){
//	cin>>n;
//	cin>>a[0].l>>a[0].r;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].l>>a[i].r;
//		a[i].v=(long long)a[i].l*a[i].r;
//	}
//	sort(a+1,a+n+1,cmp);
//	hp sum=a[0].l,ans;
//	
//	for(int i=1;i<=n;i++){
//		if(sum/a[i].r>ans) ans=sum/a[i].r;
//		sum=sum*a[i].l;	
//	}
//	if(ans.a[0]==0){
//		cout<<"0";
//	}
//	else{
//		for(int i=ans.a[0];i>=1;i--){
//			cout<<ans.a[i];
//		}		
//	}
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//int n,m;
//int a[105][105];
//int dist[105][105]={0};
//int ste[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
//int ans=0;
//int dfs(int x,int y){
//	if (dist[x][y]) return dist[x][y];
//	if(!dist[x][y]){
//		dist[x][y]=1;
//	}
//	for(int i=0;i<4;i++){
//		int tx=x+ste[i][0];
//		int ty=y+ste[i][1];
//		if(tx<1||ty<1||tx>n||ty>n){
//			continue;
//		}
//		if(a[x][y]>a[tx][ty]){
//			dist[x][y]=max(dist[x][y],dfs(tx,ty)+1);				
//		}
//	}
//	ans=max(dist[x][y],ans);
//	return dist[x][y];
//}
//int main(){
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin>>a[i][j];
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			if(!dist[i][j]){
//				dfs(i,j);
//			}
//		}
//	}
//	cout<<ans;			
//	return 0;
//}

































