//#include<iostream>
//using namespace std;
//int a[1005][1005];
//int r[1005],c[1005];
//int main(){
//	int n,m;
//	cin>>n>>m;
//	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cin>>a[i][j];
//		}
//	}
//	
//	for(int i=1;i<=n;i++){r[i]=i,c[i]=i;}
//	while(m--){
//		int f;
//		cin>>f;
//		int r1,r2;
//		cin>>r1>>r2;
//		if(f){
//			int temp=r[r1];
//			r[r1]=r[r2];
//			r[r2]=temp;
//		}
//		else{
//			int temp=c[r1];
//			c[r1]=c[r2];
//			c[r2]=temp;			
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(j!=1) cout<<" ";
//			cout<<a[r[i]][c[j]];
//		}
//		cout<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<string>
//#include<math>
//using namespace std;
//stack<int> num;
//stack<char> ch;
//
//int main(){
//		
//	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	while(n--){
//		char a,b,c;
//		cin>>a>>b>>c;
//		if(a!='Y'&&a!='y'){ cout<<"NO"<<endl; continue;}
//		if(b!='E'&&b!='e'){ cout<<"NO"<<endl; continue;}
//		if(c!='S'&&c!='s'){ cout<<"NO"<<endl; continue;}
//		cout<<"YES"<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    while(n--){
//        string a;
//        cin>>a;
//        int x=a.back()-'0';
//        if(x%2==0){
//			cout<<"odd"<<endl;
//		}
//		else{
//			cout<<"even"<<endl;
//		}
//    }
//    return 0;
//}
//#include<iostream>
//#include<queue>
//using namespace std;
//priority_queue<int> q;
//int main(){
//	string a;
//	cin>>a;
//	while(a!="end"){
//		if(a=="insert"){
//			int t;
//			cin>>t;
//			q.push(t);
//		}
//		else{
//			int t=q.top();
//			q.pop();
//			cout<<t<<endl;
//		}
//		cin>>a;
//	}
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	while(n--){
//		int n1,m;
//		cin>>n1>>m;
//		int al[7];
//		memset(al,0,sizeof(al));
//		string a;
//		cin>>a;
//		for(char i:a){
//			al[i-'A']++;
//		}
//		int ans=0;
//		while(m--){
//			for(int i=0;i<7;i++){
//				if(al[i]<=0){ans++;}
//				else al[i]--;
//			}
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//	int n,d,t;
//	cin>>n>>d>>t;
//	int cnt=0;
//	int n1=n;
//	if(n%2==1) n1++;
//	int d1=d;
//	while(d1--){
//		int num=0;
//		for(int i=0;i<n;i++){
//			int r;
//			cin>>r;
//			if(r==t) num++;
//		}
//		if(num>=n1/2) cnt++;
//	}
//	if(d%2==1) d++;
//	if(cnt>=d/2) cout<<"YES";
//	else cout<<"NO";
//	return 0;
//}
//#include<iostream>
//#include<stack>
//using namespace std;
//stack<int> s;
//int main(){
//	int n;
//	cin>>n;
//	n=n%10000;
//	s.push(n);
//	char ch;
//	while(scanf("%c",&ch)&&ch!='\n'){
//		cin>>n;
//		if(ch=='*'){
//			int t=s.top();
//			t=t*n%10000;
//			s.pop();
//			s.push(t);
//		}
//		else{
//			s.push(n);
//		}
//	}
//	int ans=0;
//	while(!s.empty()){
//		int a=s.top();
//		s.pop();
//		ans=ans+a%10000;
//	}
//	cout<<ans;
//	return 0;
//}
//½»»¥Ìâ
//#include<iostream>
//using namespace std;
//
//int main(){
//	int n,m;
//	cin>>n>>m;
//	
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> a;
//int main(){
//    int n,m;
//    cin>>n>>m;
//    for(int i=0;i<n;i++){
//		int t;
//		cin>>t;
//		a.push_back(t);
//	}
//	while(m--){
//		int q;
//		cin>>q;
//		int idx=lower_bound(a.begin(),a.end(),q)-a.begin();
//		if(idx==n||a[idx]!=q){
//			cout<<"-1 ";
//		}
//		else cout<<idx+1<<" ";
//	}
//    
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[200010];
//
//int main(){
//    int n,c;
//    cin>>n>>c;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    sort(a+1,a+n+1);
//	long long ans=0;
//    int idx=1;
//    while(idx!=n+1){
//		int idx1=lower_bound(a+1,a+n+1,a[idx]+c)-a;
//		if(idx1==n+1){
//			break;
//		}
//		int cnt1=0,cnt2=0;
//		while(a[idx+cnt1]==a[idx]) cnt1++;
//		if(a[idx1]-c==a[idx]){
//			while(idx1+cnt2<=n&&a[idx1+cnt2]==a[idx1]) cnt2++;
//			ans+=(long long)cnt1*cnt2;	
//		}
//		idx+=cnt1;
//	}
//	cout<<ans;
//    return 0;
//}
//#include<iostream>
//#include<queue>
//using namespace std;
//queue<int> q1;
//queue<int> q2[305];
//int main(){
//	int n,m;
//	cin>>n>>m;
//	int g[n];
//	int v[n]={0};
//	for(int i=0;i<n;i++){
//		cin>>g[i];
//	}
//	int q;
//	cin>>q;
//	
//	while(q--){
//		string s;
//		cin>>s;
//		if(s=="push"){
//			int t;
//			cin>>t;
//			if(!v[g[t]]){
//				q1.push(g[t]);
//			}
//			v[g[t]]++;
//			q2[g[t]].push(t);
//		}
//		else{
//			int idx=q1.front();
//			v[idx]--;
//			if(!v[idx]){
//				q1.pop();
//			}
//			int t=q2[idx].front();
//			q2[idx].pop();
//			cout<<t<<endl;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//#include<queue>
//#include<math.h>
//using namespace std;
//priority_queue<int> q1;
//priority_queue<int,vector<int>,greater<int> > q2;
//
//int main(){
//	int n;
//	cin>>n;
//	int t;
//	cin>>t;
//	cout<<t<<endl;
//	q1.push(t);
//	for(int i=2;i<=n;i++){
//		cin>>t;
//		if(t>q1.top()){
//			q2.push(t);
//			if(i%2==1){
//				cout<<q2.top()<<endl;
//			}
//		}
//		else{
//			q1.push(t);
//			if(i%2==1){
//				cout<<q1.top()<<endl;
//			}
//		}
//		if( abs( (int)q1.size()-(int)q2.size() ) > 1){
//			if(q1.size()>q2.size()){
//				q2.push(q1.top());
//				q1.pop();
//			}			
//			else{
//				q1.push(q2.top());
//				q2.pop();
//			}
//		}
//	}	
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int a[100010];
//int h,q;
//bool check(int d,int q,int t[]){
//	int f=1;
//	q*=2;
//	while(q--){
//		for(int i=d;i<h;i+=d){
//			int s=0;
//			while(!t[i-s]&&s!=d) s++;
//			if(s==d){
//				f=0;
//				break;
//			}
//			else{
//				t[i-s]--;
//				i=i-s;
//			}
//		}		
//		if(!f){
//			break;
//		}		
//	}
//	return f?true:false;
//}
//int main(){
//	cin>>h>>q;
//	for(int i=1;i<h;i++){
//		cin>>a[i];
//	}
//	int l=1,r=h;
//	while(l<r){
//	    int t[100010];
//	    memcpy(t,a,sizeof(a));
//		int m=(l+r)/2;
//		if(check(m,q,t)){
//			r=m;				
//		}
//		else{
//			l=m+1;
//		}
//	}
//	cout<<r;	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int a[100010];
//int w,q;
//bool check(int q,int s){
//	q*=2;
//	int f=1;
//	for(int i=s;i<w;i++){
//		if(a[i]-a[i-s]<q){
//			f=0;
//			break;
//		}	
//	}
//	return f?true:false;
//}
//int main(){
//	
//	cin>>w>>q;
//	for(int i=1;i<w;i++){
//		int t;
//		cin>>t;
//		a[i]=t+a[i-1];
//	}
//	a[0]=0;
//	int l=1,r=w;
//	while(l<r){
//		int m=(l+r)/2;
//		if(check(q,m)){
//			r=m;
//		}
//		else{
//			l=m+1;
//		}
//	}
//	cout<<r;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int n;
//bool a1[27]={false},a2[25]={false},a3[14]={false};
//int ans=0;
//int t[14];
//void dfs(int cnt){
//	if(cnt==n){
//		ans++;
//		if(ans<=3){
//			for(int i=1;i<=n;i++){
//				if(i!=1) cout<<" ";
//				cout<<t[i];
//			}
//			cout<<endl;
//		}
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!a1[cnt+1+i]&&!a2[cnt+1-i+n]&&!a3[i]){
//			a2[(cnt+1)-i+n]=true;
//			a1[cnt+1+i]=true;
//			a3[i]=true;
//			t[cnt+1]=i;
//			dfs(cnt+1);
//			a3[i]=false;
//			a1[cnt+1+i]=false;
//			a2[cnt+1-i+n]=false;		
//		}
//	}
//}
//int main(){
//	cin>>n;
//	dfs(0);	
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//int n;
//long long h[1005][1005];
//bool v[1005][1005];
//bool f_r=false,f_v=false;
//int cnt_r=0,cnt_v=0;
//int sx[8]={-1,-1,-1,0,0,1,1,1};
//int sy[8]={-1,0,1,1,-1,-1,0,1};
//struct node{
//	int x,y; 
//};
//
//queue<node> q;
//
//void bfs(int x,int y){
//	q.push({x,y});
//	v[x][y]=true;
//	long long H=h[x][y];
//	
//	while(!q.empty()){
//		int ox=q.front().x;
//		int oy=q.front().y;
//		
//		q.pop();
//		for(int i=0;i<8;i++){
//			int nx=ox+sx[i];
//			int ny=oy+sy[i];
//			if(nx>n||nx<1||ny<1||ny>n) continue;
//				if(!v[nx][ny]&&h[nx][ny]==H){
//					q.push({nx,ny});
//					v[nx][ny]=true;
//				}
//				if(h[nx][ny]>H){
//					f_r=true;
//				}
//				else if(h[nx][ny]<H){
//					f_v=true;
//				} 
//		}
//	}
//	if(!f_r) cnt_r++;
//	if(!f_v) cnt_v++;	
//}
//
//int main(){
//	
//	cin>>n;
//	
//	memset(v,false,sizeof(v));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cin>>h[i][j];
//		}
//	}
//	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(!v[i][j]){
//				f_r=false,f_v=false;
//				bfs(i,j);
//			}
//		}
//	}
//	cout<<cnt_r<<" "<<cnt_v;
//	
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct node{
//	int index;
//	int data;
//};
//bool cmp(node a,node b){
//	return a.data<b.data;
//}
//int main()
//{
//	int n;
//	cin>>n;
//	node a[1005];
//	for(int i=1;i<=n;i++){
//		cin>>a[i].data;
//		a[i].index=i;
//	}
//	double sum=0;
//	double ans=0;
//	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		
//		cout<<a[i].index;
//		if(i!=n){
//			cout<<" ";
//			sum+=a[i].data;
//			ans+=sum;	
//		} 
//	}
//	cout<<endl;
//	printf("%.2lf",ans/n);
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main(){
//	int w;
//	int n;
//	cin>>w>>n;
//	int Min=0,Max=0;
//	for(int i=1;i<=n;i++){
//		int l;
//		cin>>l;
//		int r=w-l;
//		int t1=l>r?l-1:r;
//		int t2=l<r?l-1:r;
//		Min=max(Min,t2);
//		Max=max(Max,t1);
//	}
//	if(!n){
//		cout<<"0 0";
//	}
//	else{
//		cout<<Min+1<<" "<<Max+1;	
//	}
//	return 0;
//}
//#include<iostream>
//#include<math.h>
//#include<cstring>
//#include<iomanip>
//
//using namespace std;
//int n,x[16],y[16];
//double dp[1<<15][16];
//double ans=100000000.00;
//bool v[16];
//double dist[16][16];
//double cal(int a, int b) {
//    double dx = x[a] - x[b];
//    double dy = y[a] - y[b];
//    return sqrt(dx*dx + dy*dy); 
//}
//
//void dfs(int cnt,int pre,int p,double sum){
//	if(sum>ans){
//		return;
//	}
//	if(cnt==n){
//		ans=min(ans,sum);
//		return;	
//	} 
//	for(int i=1;i<=n;i++){
//		if(!v[i]){
//			int p1=p|(1<<(i-1));
//			double sum1=sum+dist[pre][i];
//			if(dp[p1][i]&&sum1>dp[p1][i]){
//				continue;
//			}
//			dp[p1][i]=sum1;
//			v[i]=true;
//			dfs(cnt+1,i,p1,sum1);
//			v[i]=false;
//		}
//	}
//}
//int main(){
//	cin>>n;
//	memset(v,false,sizeof(v));
//	memset(dp,0,sizeof(dp));
//	for(int i=1;i<=n;i++){
//		cin>>x[i]>>y[i];
//	}
//	x[0]=y[0]=0;
//	for(int i=0;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			dist[i][j]=dist[j][i]=cal(i,j);
//		}
//	}
//	dfs(0,0,0,0.0);	
//	printf("%.2lf",ans);
//	return 0;
//}
//#include<iostream>
//#include<math.h>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n;
//double s[20][20];
//double x[20],y[20];
//double dp[1<<16][20];
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>x[i]>>y[i];
//	}
//	x[0]=y[0]=0;
//	for(int i=0;i<=n;i++)
//	 for(int j=0;j<=n;j++)
//	  s[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
//	
//	memset(dp,100,sizeof(dp));
//	for(int i=1;i<=n;i++){
//		dp[(1<<(n+1))-1][i]=0;
//	}
//	for(int i=(1<<(n+1))-2;~i;--i){
//		for(int j=0;j<=n;j++){
//			if(((1<<j)&i)){
//				for(int h=0;h<=n;h++){
//					if(!((1<<h)&i)){
//						dp[i][j]=min(dp[i][j],dp[i|(1<<h)][h]+s[j][h]);	
//					}
//				}
//			}
//		}
//	}
//	printf("%.2lf",dp[1][0]);
//	return 0;	
//}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//int n=0;
//int h[100010];
//vector<int> q1;
//vector<int> q2;
//
//int cnt=0;
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	
//	while(cin>>t){
//		h[++n]=t;
//	}
//	for(int i=1;i<=n;i++){
//		auto p1=lower_bound(q1.begin(),q1.end(),h[i]);
//		auto p2=lower_bound(q2.begin(),q2.end(),h[i],greater<int>() );
//		if(p1==q1.end()){
//			q1.push_back(h[i]);
//		}
//		else{
//			*p1=h[i];
//		}
//		if(p2==q2.end()){
//			q2.push_back(h[i]);
//		}
//		else{
//			*p2=h[i];
//		}
//	}
//	cout<<q2.size()<<endl<<q1.size();	
//	return 0;
//}






























