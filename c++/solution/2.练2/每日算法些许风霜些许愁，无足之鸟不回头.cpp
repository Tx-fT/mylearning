//1
//#include<stdio.h>
//#include<math.h>
//bool isprime(int n){
//	if(n<=1) return 0;
//	if(n==2) return 1;
//	for(int i=2;i<n;i++){
//		if(n%i==0){
//			return 0;
//		}
//	}
//	return 1;
//}
//int main(){
//	double n;
//	scanf("%lf",&n);
//	for(int i=2;i<(int)sqrt(n);i++)
//	if(isprime(i)){
//		if((int)n%i==0){
//			printf("%d",(int)n/i);
//			return 0;
//		};
//	}
//	else{
//		continue;
//	}
////	printf("%.2f",sqrt(n));//sqrt不能用int
//	return 0;
//}
//2
//sort(a+1,a+n+1,cmp);  // 对a[1]~a[n]按cmp规则排序（权重高的任务在前）
//sort 函数的参数：a+1 是排序起始地址，a+n+1 是排序结束地址（左闭右开），cmp 是自定义排序规则
//cmp 函数的核心要求：接收两个同类型的参数 a 和 b，返回一个布尔值：
//返回 true：表示 a 应该排在 b 的前面；
//返回 false：表示 a 应该排在 b 的后面。
//#include<bits/stdc++.h>
//using namespace std;
//struct game{
//    int r;
//    int t;
//}a[511];
//int num,f[511]={0};
//int n;
//bool cmp(const game& a, const game& b){
//    return a.r>b.r;
//}
//int main(){
//    cin>>n;
//    for(int i=1;i<=n;i++)cin>>a[i].t;
//    for(int i=1;i<=n;i++)cin>>a[i].r;
//    sort(a+1,a+n+1,cmp);
//    for(int i=1;i<=n;i++){
//        for(int j=a[i].t;j>0;j--){
//            if(!f[j]){
//                f[j]=1;
//                num+=a[i].r;
//                break;
//            }
//        }
//    }
//    cout<<num;
//    return 0;
//}
// 增强型 for 循环
//for(int e : b) {
//    // 处理 e
//}
//
//// 相当于传统循环
//for(int i = 0; i < b.length; i++) {  // Java 数组
//    int e = b[i];
//    // 处理 e
//}
//for(int& e : b) {  // C++ 引用
//    e *= 2;  // 修改原数组
//}
//3
//        // 将整数转换为字符串
//        sprintf(nums[i], "%d", num);
//    // 使用自定义规则排序
//    qsort(nums, n, sizeof(nums[0]), compare);
//4过河卒
//#include<bits/stdc++.h>
//using namespace std;
//long long f[30][30]={0},xb,yb,xh,yh;//pand能不能走f步数
//bool pand[30][30]={false};
//int main(){
//	const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
//	const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//	//input
//	cin>>xb>>yb>>xh>>yh;
//	xb+=2;yb+=2;xh+=2;yh+=2;
//	//边界赋值
//	for(int i=2;i<30;i++){
//		f[2][i]=1;
//		f[i][2]=1;
//	}
//	//马对应的特殊点进行赋值
//	for(int i=0;i<9;i++){
//		pand[xh+fx[i]][yh+fy[i]]=true;
//	}
//	//递推的计算f（x，y）
//	f[1][2]=1;
//	for(int i=2;i<=xb;i++){
//		for(int j=2;j<=yb;j++){
//			if(pand[i][j]){
//				f[i][j]=0;
//				continue;
//			}
//			f[i][j]=f[i-1][j]+f[i][j-1];
//		}
//	}
//	//输出
//	cout<<f[xb][yb];
//	return 0;
//}
//5
//#include<iostream>
//#include <algorithm> 
//using namespace std;
//bool cmp(int a,int b){
//    return a<b;
//}
//int main(){
//    int n,qn;
//    cin>>n>>qn;
//    int arr[n]={0};
//    for(int i=0;i<n;i++){
//        cin>>arr[i];
//    }
//    for(int i=0;i<qn;i++){
//        int left,right;
//        cin>>left>>right;
//        sort(&arr[left-1],&arr[right],cmp);
//        int num=0,index=1;
//        int temp=index;
//        for(int j=left-1;j<right;j++){
//            num+=arr[j]*index;
//            temp++;
//            if(j!=right-1&&arr[j]<arr[j+1]){
//                index=temp;
//            }
//        }
//        cout<<num<<endl;
//    }
//}
//6(*success)
//#include<bits/stdc++.h>
//using namespace std;
//struct pack{
//    int m,v;
//    double av;
//};
//bool cmp(pack a,pack b){
//    return a.av>b.av;
//}
//int main(){
//    int stack,bag;
//    cin>>stack>>bag;
//    pack arr[stack];
//    for(int i=0;i<stack;i++){
//        cin>>arr[i].m;
//        cin>>arr[i].v;
//        arr[i].av=(double)arr[i].v/(double)arr[i].m;
//    }
//    sort(arr,arr+stack,cmp);
//    double ans=0.0;
//    int i=0;
//    while(1){
//        if(bag>=arr[i].m){
//            ans+=arr[i].v;
//            bag-=arr[i].m;
//        }
//        else{
//            ans+=bag*arr[i].av;
//            break;
//        }
//        if(++i==stack){
//            break;
//        }
//    }
//    printf("%.2lf",ans);
//    return 0;
//}
//7
//#include<stdio.h>
//#include<string.h>
//int main(){
//    int n;
//    scanf("%d",&n);
//    char arr[n][100];
//    for(int i=0;i<n;i++){
//		scanf("%s",arr[i]);
//	}
//    for(int i=0;i<n;i++){
//        int len=strlen(arr[i]);
//        int arr1[26]={0};
//        int max=0;
//        for(int j=0;j<len;j++){
//            arr1[(int)arr[i][j]-97]++;
//            if(arr1[(int)arr[i][j]-97]>max){
//                max=arr1[(int)arr[i][j]-97];
//            }
//        }
//        printf("%d\n",len-max);
//    }
//    return 0;
//}
//8
// 字符串操作
//strcpy(dest, src)      // 字符串复制
//strncpy(dest, src, n)  // 安全字符串复制
//strcat(dest, src)      // 字符串拼接
//strncat(dest, src, n)  // 安全字符串拼接
//
//// 字符串比较
//strcmp(s1, s2)         // 字符串比较
//strncmp(s1, s2, n)     // 前n字符比较
//
//// 字符串查找
//strchr(str, ch)        // 查找字符
//strstr(haystack, needle) // 查找子串
//
//// 内存操作（也用于字符串）
//memset(ptr, value, n)  // 内存设置
//memcpy(dest, src, n)   // 内存复制
//memmove(dest, src, n)  // 安全内存复制
//memcmp(p1, p2, n)      // 内存比较
//
//// 字符串长度
//strlen(str)            // 字符串长度
// 输入输出
//printf()    // 格式化输出
//scanf()     // 格式化输入
//
//// 文件操作
//fopen(), fclose()
//fprintf(), fscanf()
//
//// 字符输入输出
//getchar(), putchar()
//gets(), puts()  // C++中不建议使用gets()
//
//// 其他
//sprintf()   // 字符串格式化
//sscanf()    // 从字符串读取
//整体考虑不是单次最优
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int arr[n][n];
//    for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			arr[i][j]=0;
//		}
//	}
//    while(1){
//        int x,y,num;
//        cin>>x>>y>>num;
//        arr[x-1][y-1]=num;
//        if(x==0&&y==0&&num==0){
//            break;
//        }
//    }
//    int m_final=0;
//    for(int u=0;u<2;u++){
//	    int totler=0,totled=0,right=0,down=0,ans=0;
//	    while(right!=n-1||down!=n-1){
//	        ans+=arr[down][right];
//	        arr[down][right]=0;
//	        for(int x1=down;x1<n;x1++){
//	            for(int y1=right+1;y1<n;y1++){
//	                totler+=arr[x1][y1];
//	            }
//	        }
//	        for(int x2=down+1;x2<n;x2++){
//	            for(int y2=right;y2<n;y2++){
//	                totled+=arr[x2][y2];
//	            }
//	        }
//	        if(totler>totled){
//	            right++;
//	        }
//	        else if(totled>totler){
//	            down++;
//	        }
//	        else{
//	            if(right<n-1){
//	                right++;
//	            }
//	            else{
//	                down++;
//	            }
//	        }
//	        totled=0;
//	        totler=0;
//	    }
//	    m_final+=ans;
//    }
//    cout<<m_final+arr[n-1][n-1]<<endl;
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int grid[15][15];
//int dp[30][15][15];  // dp[步数][第一条的行][第二条的行]
//
//int main() {
//    int n;
//    cin >> n;
//    
//    // 输入数据
//    while(true) {
//        int x, y, val;
//        cin >> x >> y >> val;
//        if(x == 0 && y == 0 && val == 0) break;
//        grid[x][y] = val;
//    }
//    
//    // 动态规划
//    // 步数从2开始（第一步在起点）
//    for(int step = 2; step <= 2 * n; step++) {
//        for(int i = 1; i <= n; i++) {
//            for(int k = 1; k <= n; k++) {
//                int j = step - i;  // 第一条的列
//                int l = step - k;  // 第二条的列
//                
//                // 检查是否越界
//                if(j < 1 || j > n || l < 1 || l > n) continue;
//                
//                // 四种可能的来源
//                int max_val = max({
//                    dp[step-1][i][k],       // 都向右
//                    dp[step-1][i-1][k-1],   // 都向下
//                    dp[step-1][i-1][k],     // 第一条向下，第二条向右
//                    dp[step-1][i][k-1]      // 第一条向右，第二条向下
//                });
//                
//                // 加上当前格子的值
//                if(i == k) {  // 走到同一行，因为step相同，所以列也相同
//                    dp[step][i][k] = max_val + grid[i][j];
//                } else {
//                    dp[step][i][k] = max_val + grid[i][j] + grid[k][l];
//                }
//            }
//        }
//    }
//    
//    // 输出结果
//    cout << dp[2*n][n][n] << endl;
//    
//    return 0;
//}
//9这么做是对的但要学dp
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int x,y;
//    cin>>x>>y;
//    int arr[x][y];
//    for(int i=0;i<x;i++){
//        for(int j=0;j<y;j++){
//            cin>>arr[i][j];
//        }
//    }
//    int arr1[x][y];
//    for(int i=0;i<x;i++){
//	    for(int j=0;j<y;j++){
//           arr1[i][j]=1;
//       }
//	}
//    int ans=0;
//    for(int u=1;u<=y;u++){
//        int temp=0;
//        for(int i=0;i<x;i++){
//            int left=0,right=y-1;
//            while(!arr1[i][left]){
//                left++;
//            }
//            while(!arr1[i][right]){
//                right--;
//            }
//            if(arr[i][left]<=arr[i][right]){
//                arr1[i][left]=0;
//                temp+=arr[i][left];
//            }
//            else{
//                arr1[i][right]=0;
//                temp+=arr[i][right];
//            }
//        }
//        ans+=temp*pow(2,u);
//    }
//    cout<<ans<<endl;
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//typedef struct person* p;
//struct person{
//    char name[6];
//    p son;
//    p bro;
//};
//p creat(){
//    p temp=new person;
//    cin>>temp->name;
//    temp->son=temp->bro=NULL;
//    return temp;
//}
//p check(char cmp[],p root){
//    if(root==NULL) return NULL;
//    if(strcmp(cmp,root->name)==0){
//        return root;
//    }
//    p result = check(cmp, root->bro);
//    if (result != NULL) {
//        return result;
//    }
//    result = check(cmp, root->son);
//    if (result != NULL) {
//        return result;
//    }
//    return NULL;
//}
//int main(){
//    p arr[11];
//    for(int i=0;i<11;i++){
//		arr[i]=NULL;
//	}
//    char single;
//    cin>>single;
//    int index=0;
//    while(single!='$'){
//        if(single=='#'){
//            bool is=1;
//            p root=creat();
//            p temp=root;
//            for(int i=0;i<index;i++){
//                temp=check(root->name,arr[i]);
//                if(temp!=NULL){
//                    is=0;
//                    break;
//                }
//            }
//            if(is){
//                arr[index++]=root;
//            }
//            cin>>single;
//        }
//        if(single=='+'){
//            p temp=creat();
//            if(arr[index-1]==NULL){
//                arr[index-1]->son=temp;
//            }
//            else{
//                p tep=arr[index]->son;
//                while(tep){
//                    tep=tep->bro;
//                }
//                tep->bro=temp;
//            }
//            cin>>single;
//        }
//        if(single=='?'){
//            p find=creat();
//            for(int i=0;i<index;i++){
//                p temp=NULL;
//                temp=check(find->name,arr[i]);
//                if(temp!=NULL){
//                    printf("%s %s\n",find->name,arr[i]->name);
//                }
//            }
//            cin>>single;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//    int T;
//    cin >> T;
//    
//    while(T--){
//        int n, k;
//        cin >> n >> k;
//        vector<long long> a(n);
//        
//        long long max_a = 0;
//        for(int i = 0; i < n; i++){
//            cin >> a[i];
//            if(a[i] > max_a) max_a = a[i];
//        }
//        
//        // 计算 diff_i = (max_a - a_i) mod (2k)
//        vector<int> diff(n);
//        for(int i = 0; i < n; i++){
//            diff[i] = (max_a - a[i]) % (2*k);
//        }
//        
//        // 尝试 x = 0 到 2k-1
//        int ans_x = -1;
//        for(int x = 0; x < 2*k; x++){
//            bool valid = true;
//            for(int i = 0; i < n; i++){
//                if((x + diff[i]) % (2*k) >= k){
//                    valid = false;
//                    break;
//                }
//            }
//            if(valid){
//                ans_x = x;
//                break;
//            }
//        }
//        
//        if(ans_x == -1){
//            cout << -1 << endl;
//        } else {
//            cout << max_a + ans_x << endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct p{
//    int index;
//    int weight;
//};
//bool cmp(p a,p b){
//	if(a.weight!=b.weight)
//    return a.weight>b.weight;
//    else return a.index<b.index;
//}
//int main(){
//    int n,k;
//    cin>>n>>k;
//    int arr[n];
//    for(int i=0;i<n;i++){
//		arr[i]=0;
//	}
//    p d[n];
//    for(int i=0;i<10;i++){
//        cin>>arr[i];
//    }
//    for(int i=0;i<n;i++){
//        d[i].index=i+1;
//        cin>>d[i].weight;
//    }
//    sort(d,d+n,cmp);
//    for(int i=0;i<n;i++){
//        d[i].weight+=arr[i%10];
//    }
//    sort(d,d+n,cmp);
//    for(int i=0;i<k;i++){
//        if(i!=0){
//            putchar(' ');
//        }
//        cout<<d[i].index;
//    }
//    return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    int T;
//    cin >> T;
//    while (T--) {
//        string s;
//        cin >> s;
//        int len = s.size();
//        bool flag = false;
//        if(s[0]-'0'==4||s[0]-'0'==8||s[len-1]-'0'==4||s[len-1]-'0'==8){
//            cout<<"Yes"<<endl;
//            continue;
//        }
//        for (int i = 0; i < len-1; i++) {
//            int digit = (s[i] - '0')*10+(s[i+1]-'0');
//            if (digit % 4 == 0) {
//                cout<<"Yes"<<endl;
//                flag=true;
//                break;
//            }
//        }
//        if(flag){
//            continue;
//        }
//        for (int i = 0; i < len - 1; i++) {
//            int two = (s[i] - '0') * 10 + (s[len-1]-'0');
//            if (two % 4 == 0) {
//                cout<<"Yes"<<endl;
//                flag=true;
//                break;
//            }
//        }
//        if(flag){
//            continue;
//        }
//        cout << "No" << endl;
//    }
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//typedef struct{
//    int v,e;
//    int g[1005][1005];
//}gnode;
//typedef gnode* mgraph;
//int vnum,edgenum;
//mgraph creat(){
//    mgraph g;
//    g=new gnode;
//    g->v=vnum;
//    g->e=0;
//    for(int i=0;i<vnum;i++){
//        for(int j=0;j<vnum;j++){
//            g->g[i][j]=0;
//        }
//    }
//    return g;
//}
//void inserte(mgraph g,int v1,int v2){
//    g->g[v1][v2]=1;
//    g->g[v2][v1]=1;
//    g->e++;
//}
//bool *visit;
//int cnt[1005]={0};
//int sum=0;
//void dfs(mgraph g,int st,int end){
//    int v=st;
//    if(v==end){
//        sum++;
//        for(int i=0;i<vnum;i++){
//        	if(visit[i]==true){
//				cnt[i]++;
//			}
//		}
//        return;
//    }
//    visit[v]=true;
//    for(int w=0;w<g->v;w++){
//        if(g->g[v][w]&&!visit[w]){
//            visit[w]=true;
//            dfs(g,w,end);
//            visit[w]=false;
//        }
//    }
//}
//int main(){
//    mgraph g;
//    cin>>vnum>>edgenum;
//    g=creat();
//    for(int i=0;i<edgenum;i++){
//        int v1,v2;
//        cin>>v1>>v2;
//        inserte(g,v1,v2);
//    }
//    int st,end;
//    cin>>st>>end;
//    visit = new bool[vnum];
//	for (int i = 0; i < vnum; i++) {
//        visit[i] = false;
//    }
//    dfs(g,st,end);
//    int ans=0;
//    for(int i=0;i<vnum;i++){
//        if(sum==cnt[i]){
//            ans++;
//        }
//    }
//    cout<<ans-2;
//    return 0;
//}
//#include<bits/stdc++.h>
//#define LL long long
//#define made return
//#define in 0
//#define China ;
//using namespace std;
//LL n,m,u,v,ans,cnt[1010],sum;
//bool bj[1010],a[1010][1010];
//void dfs(LL now){
//	if(now==v){//如果走到终点了， 
//		sum++;//路径总数加一。 
//		for(int i=1;i<=n;i++)
//			if(bj[i]==1)cnt[i]++;//每个被走过的点，被走总次数加一 
//	}
//	else{
//		for(int i=1;i<=n;i++)
//			if(a[now][i]==1&&bj[i]==0){//如果两点连通且下一步要走到的点未被走过， 
//				bj[i]=1;//标记。
//				dfs(i);
//				bj[i]=0;//回溯一步。 
//			}
//	}
//}
//int main(){
//	scanf("%lld%lld",&n,&m);
//	while(m--){
//		scanf("%lld%lld",&u,&v);
//		a[u][v]=a[v][u]=1;//输入邻接矩阵。因为是无向的，所以u到v和v到u都要设为1。 
//	}
//	scanf("%lld%lld",&u,&v);
//	dfs(u);
//	if(sum>0){//dfs求解
//		for(int i=1;i<=n;i++)
//			if(cnt[i]==sum)ans++;//如果这个点被走过的总次数与路径总数相等，那么删去这个点起点与终点间一定不连通。 
//		printf("%lld",ans-1);//因为起点也被算在内，所以总危险系数要减去终点的1。 
//	}
//	else printf("-1");//如果询问的两点无路径连通则输出'-1'。
//	made in China 
//}
////made in China. 中国制造。
//#include<iostream>
//using namespace std;
//int square(int c){ 
//    if(c==1) return 1;
//    return 4*square(c-1)+1;
//}
//int main(){
//    int a,b;
//    cin>>a>>b;
//    int c=a<b?a:b;
//    int n=a>b?a:b;
//    int d=(a+1)*(b+1)*a*b/4-square(c)*(n-1);
//    cout<<d<<" "<<square(c)*(n-1);
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int path[10]={0};
//void dfs(int arr[][10],int &num,int d,int left,int index){
//	if(index>9){
//		return;
//	}
//    int new_left = left - d;  // ? 修正：不直接修改left，用临时变量存储剩余值，天然回溯
//    path[index] = d;          // 将当前选择的数字存入路径
//    // 递归终止条件（你的原代码，完全正确，保留）
//    if (new_left == 0 && index == 9) {
//        for (int i = 0; i < 10; i++) {
//            arr[num][i] = path[i];
//        }
//        num++;
//        return;
//    }
//    if(index==9&&new_left>0){
//        return;
//    }
//    if(index<9&&new_left<=0){
//        return;
//    }
//    // 递归遍历下一个位置的3种选择：1、2、3
//    dfs(arr,num,1,new_left,index+1);
//    dfs(arr,num,2,new_left,index+1);
//    dfs(arr,num,3,new_left,index+1);
//}
//int main(){
//    int arr[10000][10]={0};  // 存储所有结果，1000足够存所有组合
//    int num=0;              // 合法组合的数量
//    int left;               // 需要凑的目标总和
//    cin>>left;
//    
//           // ? 修复：将path提到循环外定义，全局使用一块内存，避免数据污染
//    for(int i=1;i<=3;i++){
//        dfs(arr,num,i,left,0);
//    }
//	cout<<num<<endl;
//    for(int i=0;i<num;i++){
//        for(int j=0;j<10;j++){
//            if(j>0) cout<<" ";
//            cout<<arr[i][j];
//        }
//        if(i<num-1) cout<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int n, cnt = 0;
//bool col[15] = {false};
//bool diag1[30] = {false};
//bool diag2[30] = {false};
//int arr[100000][14];
//int solution[15]; 
//void dfs(int row) {
//    if (row == n) {
//	        for (int i = 0; i < n; i++) {
//	            arr[cnt][i] = solution[i] + 1;
//	        }
//	        cnt++;
//	        return;
//	    }
//    for (int c = 0; c < n; c++) {
//        if (!col[c] && !diag1[row - c + n] && !diag2[row + c]) {
//            solution[row] = c;
//            col[c] = diag1[row - c + n] = diag2[row + c] = true;
//            dfs(row + 1);
//            col[c] = diag1[row - c + n] = diag2[row + c] = false;
//            
//        }
//    }
//}
//int main() {
//    cin >> n;
//    dfs(0);
//    for(int i=0;i<cnt&&i<3;i++){
//        for(int j=0;j<n;j++){
//            if(j!=0) cout<<" ";
//            cout<<arr[i][j];
//        }
//        cout<<endl;
//    }
//    cout << cnt ;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int q_num[4];
//int a[4][21]={0};
//int cnt=0;
//long long ans=0;
//bool cmp(int a,int b){
//    return a>b;
//}
//void dfs(int cnt){
//    if(cnt==4){
//        return;
//    }
//    if(a[cnt][1]==0){
//        ans+=a[cnt][0];
//        dfs(cnt+1);
//        return;
//    }
//    a[cnt][0]--;
//    a[cnt][1]--;
//    ans++;
//    sort(a[cnt],a[cnt]+q_num[cnt],cmp);
//    dfs(cnt);
//}
//int main(){
//    for(int i=0;i<4;i++){
//        cin>>q_num[i];
//    }
//    for(int i=0;i<4;i++){
//        for(int j=0;j<q_num[i];j++){
//            cin>>a[i][j];
//        }
//        sort(a[i],a[i]+q_num[i],cmp);
//    }
//    dfs(0);
//    cout<<ans;
//}
//#include<iostream>
//#include<queue>
//#include<cstdio>
//#include<cstring>
//#define maxn 310
//using namespace std;
//struct cord{
//    int x,y;
//};
//int n,m,x,y;
//queue<cord> q;
//int ans[maxn][maxn];
//int walk[8][2]={{2,1},{-2,-1},{1,2},{-1,-2},{-1,2},{1,-2},{-2,1},{2,-1}};
//int main(){
//    cin>>n>>m>>x>>y;
//    cord st={x,y};
//    q.push(st);
//    memset(ans,-1,sizeof(ans));
//    ans[x][y]=0;
//    while(!q.empty()){
//        cord temp=q.front();
//        q.pop();
//        int ux=temp.x;int uy=temp.y;
//        int step=ans[ux][uy];
//        for(int i=0;i<8;i++){
//            int x=ux+walk[i][0];
//            int y=uy+walk[i][1];
//            if(ans[x][y]==-1&&x<=n&&x>=1&&y<=m&&y>=1){
//                ans[x][y]=step+1;
//                cord temp={x,y};
//                q.push(temp);
//            }
//        }
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            if(j!=1) cout<<" ";
//            cout<<ans[i][j];
//        }
//        if(i!=n) cout<<endl;
//    }
//    return 0;
//}
//记忆化搜索把子问题的答案存起来没必要重复计算
//暴力dfs-->记忆化搜索-->递推dp；
//大问题拆成小问题       自下而上到顶
//自上而下再回来         
//记忆化搜索：递归（dfs）+记录答案；
//递推公式：dfs向下递归公式
//#include<iostream>
//using namespace std;
////long long mem[50]={0};
////int dfs(int n){
////    if(mem[n]){
////        return mem[n];
////    }
////    int sum=0;
////    if(n==1) sum=1;
////    else if(n==2) sum=2;
////    else sum=dfs(n-1)+dfs(n-2);
////    mem[n]=sum;
////    return sum;
////}
////高精度
//int main(){
//    int n;
//    cin>>n;
////    long long ans=dfs(n);
//	int ans=0;
//	int a1=1;
//	int a2=2;
//	for(int i=3;i<=n;i++){
//		ans=a1+a2;
//		a1=a2;
//		a2=ans;
//	}
//	//优化空间
//    cout<<ans;
//    return 0;
//}
//#include<stdio.h>
//#define max(a, b)  a>b?a:b
//#define N 100010
//
//int f[N];
//int main()
//{
//    int t;
//    scanf("%d", &t);
//    while(t --)
//    {
//        int n;
//        scanf("%d", &n);
//
//        int w;
//        scanf("%d", &w);
//        f[1] = w;
//        for(int i = 2; i <= n; i ++)
//        {
//            scanf("%d", &w);
//            f[i] = max(f[i - 1], f[i - 2] + w);
//        }
//
//        printf("%d\n", f[n]);
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int arr[n][n];
//    for(int i=0;i<n;i++){
//        for(int j=0;j<=i;j++){
//            cin>>arr[i][j];
//        }
//    }
//    for(int i=n-2;i>=0;i--){
//        for(int j=0;j<=i;j++){
//            arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
//        }
//    }
//    cout<<arr[0][0];
//    return 0;
//}
//#include<iostream>
//using namespace std;
//int a[10];
//int a1,b,c;
//bool visit[10]={false};
//bool is=false;
//void dfs(int cnt){
//    if(cnt==9){
//        int x=a[1]*100+a[2]*10+a[3];
//        int y=a[4]*100+a[5]*10+a[6];
//        int z=a[7]*100+a[8]*10+a[9];
//        if(x*b==y*a1&&x*c==z*a1){
//            cout<<x<<" "<<y<<" "<<z<<endl;
//            is=true;
//        }
//        return;
//    }
//    for(int i=1;i<=9;i++){
//        if(!visit[i]){
//            visit[i]=true;
//            a[cnt+1]=i;
//            dfs(cnt+1);
//            visit[i]=false;
//        }
//    }
//}
//int main(){
//    cin>>a1>>b>>c;
//    dfs(0);
//    if(!is){
//        cout<<"No!!!";
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//#define maxn 1000010
//#define INF 1e9
//long long a[maxn],n,m;
//bool ok(int s){
//	int last;
//    last=-INF;
//    int cnt=0;
//    for(int i=1;i<=n;i++){
//        if(a[i]-last>=s){
//            cnt++;
//            last=a[i];
//        }
//    }
//    return cnt>=m;
//}
//int main(){
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    sort(a+1,a+n+1);
//    int l=0,r=(a[n]-a[1])/(m-1)+1;
//    long long mid,ans;
//    while(l<=r){
//        mid=l+r>>1;
//        if(ok(mid)){
//            l=mid+1;
//            ans=mid;
//        }
//        else{
//            r=mid-1;
//        }
//    }
//    cout<<ans;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//struct o{
//    int index;
//    o* next;
//};
//o* creat1(int i){
//    o* tem=new o;
//    tem->index=i;
//    tem->next=NULL;
//    return tem;
//}
//o* buildo(int n){
//    o* root=creat1(0);
//    o* tem=root;
//    for(int i=1;i<=n;i++,tem=tem->next){
//        o* temp=creat1(i);
//        tem->next=temp;
//    }
//    tem->next=root->next;
//    return root;
//}
//void solve(o* r,int s){
//    while(r->next!=r){
//        for(int i=0;i<s-1;i++,r=r->next);
//        cout<<r->next->index<<" ";
//        r->next=r->next->next;
//    }
//    cout<<r->index;
//}
//int main(){
//    int n;
//    int s;
//    cin>>n>>s;
//    o* g=buildo(n);
//    solve(g,s);
//    return 0;
//}
//#include<string>
//#include<cstring>
//#include<iostream>
//#include<cstdio>
//using namespace std;
//string pre,in;
//void solve(string pre,string in){
//    if(pre.empty()){
//        return;
//    }
//    char root=pre[0];
//    int k=in.find(root);
//    pre.erase(pre.begin());
//    string lp=pre.substr(0,k);//在逗号后代表数量
//    string lin=in.substr(0,k);
//    string rp=pre.substr(k);//k--index
//    string rin=in.substr(k+1);
//    solve(lp,lin);
//    solve(rp,rin);
//    cout<<root;
//}
//int main(){
//    cin>>pre>>in;
//    solve(pre,in);
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//class Graph {
//private:
//    int V;  // 顶点数
//    vector<vector<int>> adj;  // 邻接表****
//    
//public:
//    Graph(int vnum) : V(vnum) {
//        adj.resize(V);
//    }
//    
//    void addEdge(int a, int b) {
//        a--; b--;  // 转换为0-based
//        adj[a].push_back(b);
//    }
//    
//    // 从start出发能到达的最大顶点
//    int findMaxReachable(int start) {
//        vector<bool> visited(V, false);
//        queue<int> q;
//        int maxNode = start;
//        
//        visited[start] = true;
//        q.push(start);
//        
//        while(!q.empty()) {
//            int cur = q.front();
//            q.pop();
//            
//            // 更新最大顶点
//            if(cur > maxNode) {
//                maxNode = cur;
//            }
//            
//            // 遍历邻居
//            for(int neighbor : adj[cur]) {
//                if(!visited[neighbor]) {
//                    visited[neighbor] = true;
//                    q.push(neighbor);
//                }
//            }
//        }
//        
//        return maxNode + 1;  // 转换回1-based
//    }
//};
//
//int main() {
//    int V, E;
//    cin >> V >> E;
//    
//    Graph g(V);
//    
//    // 读取边
//    for(int i = 0; i < E; i++) {
//        int a, b;
//        cin >> a >> b;
//        g.addEdge(a, b);
//    }
//    
//    // 对每个顶点找最大可达顶点
//    for(int i = 0; i < V; i++) {
//        if(i != 0) cout << " ";
//        cout << g.findMaxReachable(i);
//    }
//    cout << endl;
//    
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int V, E;
//    cin >> V >> E;
//    
//    vector<vector<int>> adj(V);
//    vector<int> indegree(V, 0);
//    
//    // 构建图和入度
//    for(int i = 0; i < E; i++) {
//        int a, b;
//        cin >> a >> b;
//        a--; b--;
//        adj[a].push_back(b);
//        indegree[b]++;
//    }
//    
//    // 拓扑排序
//    queue<int> q;
//    vector<int> maxReachable(V);
//    
//    // 初始化
//    for(int i = 0; i < V; i++) {
//        maxReachable[i] = i;
//        if(indegree[i] == 0) {
//            q.push(i);
//        }
//    }
//    
//    // 拓扑排序处理
//    while(!q.empty()) {
//        int cur = q.front();
//        q.pop();
//        
//        for(int neighbor : adj[cur]) {
//            // 更新邻居的最大可达顶点
//            maxReachable[neighbor] = max(maxReachable[neighbor], maxReachable[cur]);
//            indegree[neighbor]--;
//            if(indegree[neighbor] == 0) {
//                q.push(neighbor);
//            }
//        }
//    }
//    
//    // 输出结果
//    for(int i = 0; i < V; i++) {
//        if(i != 0) cout << " ";
//        cout << maxReachable[i] + 1;  // 转回1-based
//    }
//    cout << endl;
//    
//    return 0;
//}
//反向建边
//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//#define MAXL 100010
//
//int N, M, A[MAXL];
//vector<int> G[MAXL]; //vector存图 
//
//void dfs(int x, int d) {
//	if(A[x]) return; //访问过 
//	A[x] = d;
//	for(int i=0; i<G[x].size(); i++)
//		dfs(G[x][i], d);
//}
//
//int main() {
//	int u, v;
//	scanf("%d%d", &N, &M);
//	for(int i=1; i<=M; i++) {
//		scanf("%d%d", &u, &v);
//		G[v].push_back(u); //反向建边 
//	}
//	for(int i=N; i; i--) dfs(i, i); 
//	for(int i=1; i<=N; i++) printf("%d ", A[i]);
//	printf("\n");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//struct enemy{
//    int win;
//    int fail;
//    int num;
//};
//int n;
//enemy a[1005];
//bool v[1005]={false};
//int max1=0;
//void dfs(int m,int num,int deep){
//    if(deep==n){
//        if(num>max1){
//            max1=num;
//        }
//        return;
//    }
//    for(int i=1;i<=n;i++){
//    	int num1=num,m1=m;
//        if(!v[i]){
//            if(m>=a[i].num){
//            num1+=a[i].win;
//            m1-=a[i].num;
//            }
//            else{
//                m1-=a[i].num;
//                num1+=a[i].fail;
//            }
//            v[i]=true;
//            dfs(m1,num1,deep+1);
//            v[i]=false;
//        }
//    }
//}
//int main(){
//    int m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>a[i].fail>>a[i].win>>a[i].num;
//    }
//    dfs(m,0,0);
//    cout<<max1*5;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int a[505]={0},b[505]={0},c[505]={0};
//int main(){
//    string a1,a2;
//    cin>>a1>>a2;
//    for(int i=a1.length()-1,j=0;i>=0;i--,j++){
//        a[j]=a1[i]-'0';
//    }
//    for(int i=a2.length()-1,j=0;i>=0;i--,j++){
//        b[j]=a2[i]-'0';
//    }
//    int v=max(a1.length()-1,a2.length()-1);
//    for(int i=0;i<=v;i++){
//        c[i]+=a[i]+b[i];
//        if(c[i]>=10){
//            c[i+1]=c[i]/10;
//            c[i]=c[i]%10;
//        }
//    }
//    if(c[v+1]){
//        v+=1;
//    }
//    for(int i=v;i>=0;i--){
//        cout<<c[i];
//    }
//    return 0;
//}
//而我们此处介绍的，即是最常见的一种哈希：进制哈希。进制哈希的核心便是给出一个固定进制base，将一个串的每一个元素看做一个进制位上的数字，
//所以这个串就可以看做一个base进制的数，那么这个数就是这个串的哈希值；则我们通过比对每个串的的哈希值，即可判断两个串是否相同
//#include<iostream>
//#include<cstring> 
//using namespace std;
//int find_root(int a,int arr[]){
//    if(arr[a]<0){
//        return a;
//    }
//    return arr[a]=find_root(arr[a],arr);
//}
//void link(int a,int b,int arr[]){
//    int root1=find_root(a,arr);
//    int root2=find_root(b,arr);
//    if(root1==root2){
//		return;
//	}
//	else{
//		if(root1<root2){
//		    arr[root2]=root1;
//		    arr[root1]--;
//	    }
//	    else{
//	        arr[root1]=root2;
//	        arr[root2]--;
//	    }
//	}
//}
//int main(){
//    while(1){
//        int vn,sn;
//        cin>>vn;
//        if(vn==0){
//            break;
//        }
//        cin>>sn;
//        int arr[1005];
//        memset(arr, -1, sizeof(arr));
//        for(int i=1;i<=sn;i++){
//            int a,b;
//            cin>>a>>b;
//            link(a,b,arr);
//        }
//        int ans=-1;
//        for(int i=1;i<=vn;i++){
//            if(arr[i]<0){
//                ans++;
//            }
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int dp[105][1005]={0};
//int w[105],v[105];
//int main(){
//    int n,b;
//    cin>>b>>n;
//    for(int i=1;i<=n;i++){
//        cin>>w[i]>>v[i];
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<=b;j++){
//            if(j>=w[i]){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//            }
//            else{
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }
//    cout<<dp[n][b];
//    return 0;
//}
//完全背包允许重复
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int w[105],v[105];
//int dp[1005]={0};
//int main(){
//    int n,b;
//    cin>>b>>n;
//    for(int i=1;i<=n;i++){
//        cin>>w[i]>>v[i];
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=w[i];j<=b;j++){
//            if(j>=w[i]){
//                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
//            }
//        }
//    }
//    cout<<dp[b];
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main(){
//	int size,n;
//    cin>>size>>n;
//    vector<int> w(n+1, 0), v(n+1, 0);
//    for(int i=1;i<=n;i++){
//        cin>>w[i]>>v[i];
//    }
//	vector<vector<int>> dp(n+1, vector<int>(size+1, 0));
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=size;j++){
//            if(w[i]<=j){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]*w[i]);
//            }
//            else{
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }
//    cout<<dp[n][size];
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int dp[35][20005]={0};
//int w[35]={0};
//int main(){
//    int v,n;
//    cin>>v>>n;
//    for(int i=1;i<=n;i++){
//        cin>>w[i];
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=v;j++){
//            if(w[i]<=j){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
//            }
//            else{
//				dp[i][j]=dp[i-1][j];
//			}
//        }
//    }
//    cout<<v-dp[n][v];
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int dp[4005];//不能直接全赋值应改memset
//int main(){
//	dp[0]=1;
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++){
//        for(int j=i;j<=n;j++){
//            dp[j]=(dp[j]+dp[j-i])%2147483648;        
//        }
//    }
//    cout<<dp[n]-1;
//    return 0;
//}
//#include<iostream>
//#include<cmath>
//using namespace std;
//int a[25];
//int n,num;
//int cnt=0;
//long long sum=0;
//inline bool isprime(int x) { // 判断一个数是否是素数
//	if (x == 1) return false; // 注意这步特判是必需的
//	for (int i = 2; i * i <= x; ++i)
//		if (x % i == 0)
//			return false;
//	return true;
//}
//void dfs(int deep,int pre,int sum){
//    if(deep==num){
//        if(isprime(sum)){
//            cnt++;
//        }
//        return;
//    }
//    int i;
//    for(i=pre+1;i<=n;i++){
//        dfs(deep+1,i,sum+a[i]);
//    }
//}
//int main(){
//    cin>>n>>num;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    dfs(0,0,0);
//    cout<<cnt;
//    return 0
//};
//双指针：映射思想
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int main(){
//	int a[10010];
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
//	int check[n+1];
//	memset(check,0,sizeof(check));
//	int path[n+1];
//	memset(path,0,sizeof(path));
//	int ans=0;
//	int i=0;
//	int num=0;
//	int x=0;
//	for(;i<n;i++){
//		int t=a[i];
//		++check[t];
//		if(check[t]!=2){
//			path[t]=num++;
//		}
//		else{
//			i=i-(num-path[t])+1;
//			if(num>ans){
//				ans=num;
//			}
//			num=0;
//			memset(check,0,sizeof(check));
//			memset(path,0,sizeof(path));
//		}
//	}	
//	cout<<max(ans,num);
//	return 0;
//}
//线段树
//#include<iostream>
//using namespace std;
//int a[50005],t[50005],ans=0;
//void msort(int s,int e){
//    if(s==e){
//        return;
//    }
//    int mid=(s+e)/2;
//    int i=s;
//    int j=mid+1;
//    int index=i-1;
//    msort(s,mid);
//    msort(mid+1,e);
//    while(i<=mid&&j<=e){
//        if(a[i]<a[j]) t[++index]=a[i++];
//        else{
//            t[++index]=a[j++];
//            ans+=mid+1-i;
//        } 
//    }
//    while(i<=mid){
//        t[++index]=a[i++];
//    }
//    while(j<=e){
//        t[++index]=a[j++];
//    }
//    for(int i=s;i<=e;i++){
//        a[i]=t[i];
//    }
//}
//int main(){
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//    }
//    msort(0,n-1);
//    cout<<ans;
//    return 0;
//}
//线段树
//#include <bits/stdc++.h>
//#include <algorithm>
//#define LL long long
//#define the return
//#define lop(x,l,r,c) for(LL x=(l); (r)-x+(c); x+=(c))
//using namespace std;
//const LL N=1e5+5;
//LL n,m,ans,a[N],mod;
//struct CCTV{
//	LL l,r;//维护 [l,r] 区间
//	LL sum; 
//} t[N<<2];//线段树一般都要开 4*N 范围
//void up(LL u){
//	t[u].sum=min(t[u<<1].sum , t[u<<1|1].sum);
//	//计算区间 l--r 的最小值
//    //u<<1 左子树 , u<<1|1 为 u*2+1 右子树
//}
//void build(LL u,LL l,LL r){//给节点 u 建树,范围为 l<-->r 
//	if(l==r){//叶子节点 
//		t[u]={l,r,a[l]};// a[l] 为权值 
////验树	cout<<u<<" "<<t[u].l<<" "<<t[u].r<<" "<<t[u].sum<<"\n"; 
//		the ;
//	} 
//	t[u]={l,r,0};//建树但 sum 后求
//	LL mid=l+r>>1;//五五分
//	build(u<<1,l,mid);//建 left 子树 
//	build(u<<1|1,mid+1,r);//right:  
//	up(u);//计算答案 sum
//}
//LL query(LL u,LL ql,LL qr){//query
//	//ql 为询问的 l
//	if(t[u].l >= ql && t[u].r <= qr){
//		//包含了查询范围 
//		the t[u].sum;//ans
//	} 
//	LL mid=t[u].l+t[u].r>>1;//取中
//	if(qr <= mid) the query(u<<1,ql,qr);//偏于left
//	if(ql > mid) the query(u<<1|1,ql,qr); //right
//    the min(query(u<<1,ql,mid),query(u<<1|1,mid+1,qr));//劈一半 
//}
//int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
//	cin>>n>>m;
//	lop(i,1,n,1) cin>>a[i];
//	build(1,1,n);//根节点建树
//	while(m--){ 
//        LL l,r; cin>>l>>r;//询问
//		cout<<query(1,l,r)<<" ";
//		// 	   1, l ,r
//	}
//	return 0;
//}
//滑动窗口
//#include<iostream>
//#include<limits.h>
//using namespace std;
//int a[100010];
//int v[2005];
//int sum=0;
//int s=INT_MAX,l,r;
//int main(){
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    for(int i=1,j=1;i<=n;i++){
//        v[a[i]]++;
//        if(v[a[i]]==1) sum++;
//        while(sum==m){
//            v[a[j]]--;
//            if(v[a[j]]==0){
//                sum--;
//                if(i-j<s){
//                    s=i-j;
//                    l=j,r=i;
//                }
//            }
//            j++;
//        }
//    }
//    cout<<l<<" "<<r;
//    return 0;
//}
//单调栈
//#include<iostream>
//#include<stack>
//using namespace std;
//int n,h;
//stack<int> a;
//long long ans;
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>h;
//		while(!a.empty()&&h>=a.top()){
//			a.pop();
//		}
//		ans+=a.size();
//		a.push(h);
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<stack>
//
//using namespace std;
//char ch[1005][1005];
//int h[1005];
//stack<int> a;
//int r[1005],l[1005];
//long long ans=0;
//
//int main(){
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cin>>ch[i][j];
//		}
//	}
//	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			ch[i][j]=='*'?h[j]=0:h[j]+=1;
//		for(int j=1;j<=m;j++){
//			while(!a.empty()&&h[j]<h[a.top()]){
//				r[a.top()]=j;
//				a.pop();
//			}
//			a.push(j);
//		}
//		while(!a.empty()){
//			r[a.top()]=m+1;
//			a.pop();
//		}
//		
//		for(int j=m;j>=1;j--){
//			while(!a.empty()&&h[j]<=h[a.top()]){
//				l[a.top()]=j;
//				a.pop();
//			}
//			a.push(j);
//		}
//		while(!a.empty()){
//			l[a.top()]=0;
//			a.pop();
//		}
//		
//		for(int j=1;j<=m;j++){
//			ans+=(j-l[j])*(r[j]-j)*h[j];
//		}
//	}
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int a[200005];
//int main(){
//    int n,k;
//    cin>>n>>k;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//    }
//    int q[200005]={0};
//    int front=0,rear=0;
//    for(int i=1;i<=n;i++){
//        while(front!=rear&&i-q[front]>k){
//            front++;
//        }
//        while(front!=rear&&a[q[rear]]<a[i]){
//            rear--;
//        }
//        q[++rear]=i;
//        if(i>=k){
//            cout<<a[q[front+1]]<<endl;
//        }
//    }
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<climits>
//#include<cstring>
//#include<cmath>
//using namespace std;
//int w[200005],num[200005],v[200005]={0},v1[200005];
//int x,y=INT_MIN;//二分
//long long sum=0;
//long long ans;
//int main(){
//	int n,m;
//	cin>>n>>m;
//	long long s;
//	cin>>s;
//	ans=s;
//	for(int i=1;i<=n;i++){
//		cin>>w[i]>>v[i];
//		if(y<w[i]){
//			y=w[i];
//		}
//	}
//	int l[m+1],r[m+1];
//	for(int i=1;i<=m;i++){
//		cin>>l[i]>>r[i];
//	}
//	
//	x=1;
//	y+=2;
//	while(x<y){
//		sum=0;
//		memset(v1,0,sizeof(v1));
//		memset(num,0,sizeof(num));
//		int mid=(x+y)>>1;
//		for(int i=1;i<=n;i++){
//			// 先继承前一个位置的前缀和
//			v1[i] = v1[i-1];
//			num[i] = num[i-1];
//			
//			// 如果满足条件，再加上当前值
//			if(w[i] >= mid){
//			    v1[i] += v[i];
//			    num[i] += 1;
//			}	
//		}
//		for(int i=1;i<=m;i++){
//			sum+=(v1[r[i]]-v1[l[i]-1])*(num[r[i]]-num[l[i]-1]);
//		}
//		if(sum==s){
//			ans=0;
//			break;
//		}
//		else{
//			ans=min(ans,abs(sum-s));
//			if(sum>s){
//				x=mid+1;
//			}
//			else{
//				y=mid;
//			}
//		}
//	}
//	
//	cout<<ans;	
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int a[5000005]={0},b[5000005];
//int main(){
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//        b[i]=a[i]-a[i-1];
//    }
//    for(int i=0;i<m;i++){
//        int s,e,num;
//        cin>>s>>e>>num;
//        b[s]+=num;
//        b[e+1]-=num;
//    }
//    int min=a[1];
//    for(int i=1;i<=n;i++){
//        a[i]=b[i]+a[i-1];
//        if(a[i]<min){
//            min=a[i];
//        }
//    }
//    cout<<min;
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int a[1005][1005];
//int b[1000005];
//int main(){
//    memset(a,0,sizeof(a));
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=m;i++){
//        int x1,y1,x2,y2;
//        cin>>x1>>y1>>x2>>y2;
//        for(int i=x1;i<=x2;i++){
//            b[(i-1)*n+y1]+=1;
//            b[(i-1)*n+y2+1]-=1;
//        }
//    }
//    int sum=0;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//        	if(j!=1){
//				cout<<" ";
//			}
//            sum+=b[(i-1)*n+j];
//            cout<<sum;
//        }
//        cout<<endl;
//    }
//    return 0;
//}
//二维差分+前缀和
//#include <bits/stdc++.h>
//using namespace std;
//template<typename T>inline void read(T&x){
//	x=0;char c;int sign=1;
//	do{c=getchar_unlocked();if(c=='-') sign=-1;} while(!isdigit(c));
//	do{x=x*10+c-'0';c=getchar_unlocked();}while(isdigit(c));
//	x*=sign;
//}
//int n,m;
//int c[5050][5050];
//int x,y,z,s;
//long long ans;
//int main(){
//    read(n),read(m);
//    for(int i=1;i<=m;i++){
//        read(x),read(y),read(z),read(s);
//        c[x][y]++;
//        c[x][s+1]--;
//        c[z+1][y]--;
//        c[z+1][s+1]++;
//        //差分处理
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//        	c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+c[i][j];//前缀和处理
//        	ans+=(i+j)^c[i][j];//计算答案
//		}
//    }
//    cout<<ans;
//    return 0;
//}
//#include<iostream>
//#include<string.h>
//using namespace std;
//long long ans=0;
//int a[5005][5005];
//int main(){
//    
//    memset(a,0,sizeof(a));
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=m;i++){
//        int x1,y1,x2,y2;
//        cin>>x1>>y1>>x2>>y2;
//        a[x1][y1]+=1;
//        a[x1][y2+1]-=1;
//        a[x2+1][y1]-=1;
//        a[x2+1][y2+1]+=1;
//    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
//            ans+=a[i][j]^(i+j);
//        }
//    }
//    cout<<ans;
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int a[10005],b[10005];
//int c[20010],d[20010];
//bool e[20010];
//long long ans=0;
//int location(int l,int r,int n){
//	while(l!=r){
//		int mid=(l+r)>>1;
//		if(d[mid]<n) l=mid+1;
//		else if(d[mid]>n) r=mid-1;
//		else return mid;
//	}
//	return r;
//}
//int main(){
//	int n;
//	int index=0;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		scanf("%d %d",&a[i],&b[i]);
//		c[++index]=a[i];
//		c[++index]=b[i];
//	}
//	sort(c+1,c+index+1);
//	int index1=0;
//	for(int i=1;i<=index;i++)
//		if(i==1||c[i]!=c[i-1]){
//			d[++index1]=c[i];
//		}
//	for(int i=1;i<=n;i++){
//		int x=location(1,index1,a[i]);
//		int y=location(1,index1,b[i]);
//		for(int j=x;j<y;j++){
//			e[j]=true;
//		}
//	}
//	for(int i=1;i<=index1;i++){
//		if(e[i]){
//			ans+=d[i+1]-d[i];
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<map>
//using namespace std;
//int a[1005][4];
//int b[4020];
//int c[4020];
//int f[4020][4020];
//int topb=0;
//int topc=0;
//map<int,int> m;
//int main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=3;j++){
//			cin>>a[i][j];
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=3;j++){
//			b[++topb]=a[i][j];
//		}
//	}
//	sort(b+1,b+topb+1);
//	b[0]=-100007;
//	for(int i=1;i<=topb;i++){
//		if(b[i-1]!=b[i]){
//			c[++topc]=b[i];
//			m[b[i]]=topc;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=3;j++){
//			a[i][j]=m[a[i][j]];
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=a[i][0];j<a[i][2];j++){
//			f[j][a[i][1]]--;
//			f[j][a[i][3]]++;
//		}
//	}
//	for(int i=1;i<=topc;i++){
//		for(int j=1;j<=topc;j++){
//			f[i][j]+=f[i][j-1];
//		}
//	}
//	long long ans=0;
//	for(int i=1;i<=topc;i++){
//		for(int j=1;j<=topc;j++){
//			if(f[i][j]){
//				ans+=(long long)(c[i+1]-c[i])*(c[j+1]-c[j]);
//			}
//		}
//	}
//	cout<<ans;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n;
//const long long mod=1e9+7;
//int a[5010];
//int top=0;
//long long ans=0;
//int b[2];
//int cnt[5010];
//void dfs(int st,int deep){
//    if(deep==2){
//        int tem=b[0]+b[1];
//        if(cnt[tem]>=2){
//       		int sum;
//    		if(b[0]==b[1]){
//				sum=cnt[tem]*(cnt[tem]-1)/2*(cnt[b[0]]+1)*(cnt[b[1]]+2)/2;
//			}
//			else{
//				sum=cnt[tem]*(cnt[tem]-1)/2*(cnt[b[0]]+1)*(cnt[b[1]]+1);
//			}
//			ans=(ans+sum)%mod;
//	    }
//        return;
//    }
//    for(int i=st;i<=top;i++){
//    	if(cnt[a[i]]){
//			b[deep]=a[i];
//			cnt[a[i]]--;
//			dfs(i,deep+1);
//			cnt[a[i]]++;
//		}
//    }
//}
//int main(){
//	memset(cnt,0,sizeof(cnt));
//    cin>>n;
//    for(int i=1;i<=n;i++){
//    	int temp;
//        cin>>temp;
//        if(!cnt[temp]){
//			a[++top]=temp;
//		}
//        cnt[temp]++;
//    }
//    dfs(1,0);
//    cout<<ans;
//    return 0;
//}
//状态压缩dp
//#include<iostream>
//#include<cmath>
//#include<limits.h>
//using namespace std;
//int n;
//double x[20],y[20];
//double ans=INT_MAX;
//bool visit[20];
//double dp[42000][20];
//void dfs(int num,double sum,int pre,int p){
//	if(num==n){
//		if(sum<ans){
//			ans=sum;
//		}
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!visit[i]){
//            double tem;
//            tem=sqrt(pow(x[i]-x[pre],2.0)+pow(y[i]-y[pre],2.0));
//            int k=p|(1<<(i-1));
//            if((dp[k][i]!=0&&sum+tem>dp[k][i])||sum+tem>ans) continue;
//            dp[k][i]=sum+tem;
//			visit[i]=true;
//			dfs(num+1,sum+tem,i,k);
//			visit[i]=false;
//		}
//	}
//}
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>x[i]>>y[i];
//	}
//	x[0]=0.00;
//	y[0]=0.00;
//	dfs(0,0.00,0,0);		
//	printf("%.2lf",ans);
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#define maxn 80112002
//using namespace std;
//long long ans=0,sum=0;
//bool v[5010];
//int m[5010];
//typedef struct node* p1;
//typedef struct gnode* lgraph;   
//struct node{
//	int index;
//	p1 next;
//};
//typedef struct adjlist{
//	p1 firstedge;
//}p[5050];
//struct gnode{
//	int v;
//	int e;
//	p g;
//};
//lgraph creat(int vnum){
//	lgraph tem=new gnode;
//	tem->v=vnum;
//	tem->e=0;
//	for(int i=1;i<=vnum;i++){
//		tem->g[i].firstedge=NULL;
//	}
//	return tem;
//}
//void build(lgraph graph,int num){
//	graph->e=num;
//	for(int i=1;i<=num;i++){
//		int st,en;
//		cin>>st>>en;
//		v[en]=true;
//		p1 tem=new node;
//		tem->index=en;
//		tem->next=graph->g[st].firstedge;
//		graph->g[st].firstedge=tem;
//	}
//}
//long long dfs(lgraph g,int index){
//	if(m[index] != -1) {
//	    return m[index];
//	}
//	if(g->g[index].firstedge==NULL){
//		m[index]=1;
//		return m[index];
//	}
//	long long t=0;
//	for(p1 tem=g->g[index].firstedge;tem;tem=tem->next){
//		t+=dfs(g,tem->index);
//	}
//	m[index]=t;
//	return t;
//}
//int main(){
//	int vnum,ed;
//	cin>>vnum>>ed;
//    lgraph g=creat(vnum);
//    build(g,ed);
//    memset(m,-1,sizeof(m));
//    for(int i=1;i<=vnum;i++){
//		if(!v[i]){
//			ans=(ans+dfs(g,i))%maxn;
//		}
//	}
//	cout<<ans;
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<limits.h>
//using namespace std;
//
//int n, m;
//int g[5005][5005];
//int dist[5005];
//bool visited[5005];
//int ans = 0;
//
//void solve(int st) {
//    for(int i = 1; i <= n; i++) {
//        dist[i] = INT_MAX;
//    }
//    dist[st] = 0;
//    
//    for(int i = 1; i <= n; i++) {
//        int u = -1;
//        int minDist = INT_MAX;
//        for(int j = 1; j <= n; j++) {
//            if(!visited[j] && dist[j] < minDist) {
//                minDist = dist[j];
//                u = j;
//            }
//        }
//        if(u == -1) return;
//        visited[u] = true;
//        ans += dist[u];
//        
//        for(int v = 1; v <= n; v++) {
//            if(g[u][v] && !visited[v] && g[u][v] < dist[v]) {
//                dist[v] = g[u][v];
//            }
//        }
//    }
//}
//
//int main() {
//    memset(g, 0, sizeof(g));
//    memset(visited, false, sizeof(visited));
//    
//    cin >> n >> m;
//
//    for(int i = 1; i <= m; i++) {
//        int a, b, w;
//        cin >> a >> b >> w;
//        if(g[a][b] == 0) {
//            g[a][b] = w;
//            g[b][a] = w;
//        } else {
//            g[a][b] = min(g[a][b], w);
//            g[b][a] = g[a][b];
//        }
//    }
//    solve(1);
//    
//    bool isConnected = true;
//    for(int i = 1; i <= n; i++) {
//        if(!visited[i]) {
//            isConnected = false;
//            break;
//        }
//    }
//    
//    if(!isConnected) {
//        cout << "orz";
//    } else {
//        cout << ans;
//    }
//    
//    return 0;
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int v[100010];
//int w[100010];
//bool cmp(int a,int b){
//	return a>b;
//}
//
//
//int main(){
//	int ans=0;
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>v[i];
//	}
//	sort(v+1,v+n+1);
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	sort(w+1,w+m+1,cmp);
//	
//	int i=0,j=0;
//	while(1){
//		int sum=0;
//		while(sum+1<=w[i+1]) i++,sum++,ans+=v[j+1];
//		j++;
//		if(i==m||j==n){
//			break;
//		}
//	}
//	if(i==m){
//		cout<<ans;
//	}
//	else cout<<"-1";
//	
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<vector>
//#include<math.h>
//const long long mod=1e9+7;
//using namespace std;
//char ch[10005];
//long num[20010];
//int i1=0,i2=0;
//
//void insert(int a[],int n){
//	int num1=0;
//	int i=0;
//	while(i<n){
//		num1+=a[++i]*pow(10,--n);
//	}
//	num[++i1]=num1;
//}
//
//int calculate(){
//	int a[10005];
//	char ch1[10005];
//	int index=0,index1=0;
//	int n=1;
//	for(int i=1;i<=i2;i++){
//		n*=num[i];
//		n%=mod;
//		if(!ch[i]){
//			continue;
//		}
//		else a[++index]=n,n=1,ch1[++index1]=ch[i];
//	}
//	int ans=a[1];
//	for(int i=1;i<=index1;i++){
//		if(ch[i]=='+'){
//			ans+=a[i+1];
//		}
//		else{
//			ans-=a[i+1];
//		}
//	}
//	ans%=mod;
//	return ans;
//} 
//
//int main(){
//
//	vector<char> arr;
//	scanf("%s",arr);
//	int len=arr.size();
//	int k=0;
//	
//	while(1){
//		int tem[11];
//		int index=0;
//		
//		for(;k<len;k++){
//			
//			if(arr[k]=='*'){
//				break;
//			}
//			tem[++index]=arr[k]-'0';
//		}
//		insert(tem,index);
//		i2++;
//		if(k==len) break;
//	}
//	int q;
//	cin>>q;
//	cout<<calculate();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//long long a[10010];
//int n;
//long long ans=0;
//void percdown(int idx){
//	int p=idx;
//	int c;
//	int top=a[idx];
//	for(;2*p<=n;p=c){
//		c=2*p;
//		if(c+1<=n&&a[c]>a[c+1]){
//			c++;
//		}
//		if(a[c]<top){
//			a[p]=a[c];
//		}
//		else break;
//	}
//	a[p]=top;
//}
//int gettop(){
//	int tem=a[1];
//	a[1]=a[n--];
//	percdown(1);
//	return tem;
//}
//int combine(){
//	int a=gettop();
//	int b=gettop();
//	ans=ans+a+b;
//	return a+b;
//}
//void insert(){
//	int tem=combine();
//	a[++n]=tem;
//	int i=n;
//	for(;i/2>=1;i/=2){
//		if(a[i/2]>tem){
//			a[i]=a[i/2];
//		}
//		else break;
//	}
//	a[i]=tem;
//}
//int main(){
//	cin>>n;
//	int cnt=n-1;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	int in;
//	in=n/2;
//	for(;in>=1;in--){
//		percdown(in);
//	}
//	for(int i=1;i<=cnt;i++){
//		insert();
//	}
//	cout<<ans;
//	return 0;
//}
//优先队列，真为下沉less<T>(默认最大堆(new)a<(old)b),加上priority_queue<int,vector<int>,greater<int> >（最小堆，真为下沉a>b）;
//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//typedef long long ll;
//struct node{
//	ll w,l;
//};
//
//bool operator<(node a,node b){
//	if(a.w!=b.w){
//		return a.w>b.w;
//	}
//	return a.l>b.l;//为了使树更均衡	
//}
//priority_queue<node> q;
//
//int main(){
//	int n,k;
//	cin>>n>>k;
//	for(int i=1;i<=n;i++){
//		ll w;
//		cin>>w;
//		q.push(node {w,0});
//	}
//	if((n-1)%(k-1)){
//		for(int i=1;i<=k-1-(n-1)%(k-1);i++){//要想最后哈夫曼树只剩根
//			q.push(node {0,0});
//		}
//	}
//	ll ans=0;
//	while(q.size()!=1){
//		ll sum=0,maxn=0;
//		for(int i=1;i<=k;i++){
//			node tem=q.top();
//			sum+=tem.w;
//			q.pop();
//			maxn=max(maxn,tem.l);
//		}
//		q.push(node {sum,maxn+1});
//		ans+=sum;
//	}
//	cout<<ans<<endl;
//	cout<<q.top().l<<endl;	
//	return 0;
//}
//差分加树状数组
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n,m;
//int t[500010];
//int c[500010];
//int lowbit(int n1){return n1&(-n1);}
//void add(int p,int n1){
//	for(int i=p;i<=n;i+=lowbit(i)){c[i]+=n1;}
//}
//int solve(int a){
//	int sum1=0;
//	for(int i=a;i;i-=lowbit(i)){sum1+=c[i];}
//	return sum1;
//}
//int main(){
//	memset(c,0,sizeof(c));
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		int tem;
//		cin>>tem;
//		t[i]=tem;
//		add(i,tem-t[i-1]);
//	}
//	for(int i=1;i<=m;i++){
//		int f;
//		cin>>f;
//		if(f==1){
//			int a,b,k;
//			cin>>a>>b>>k;
//			add(a,k);
//			add(b+1,-k);
//		}
//		else{
//			int index;
//			cin>>index;
//			cout<<solve(index)<<endl;
//		}
//	}
//	return 0;	
//}
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main(){
//    int t;
//    cin>>t;
//    while(t--){
//        int ans=0;
//        int n,m;
//        cin>>n>>m;
//        long long a[10010];
//        int index=0;
//        int cnt[10010];
//        memset(cnt,0,sizeof(cnt));
//        for(int i=0;i<n;i++){
//            long long tem;
//            cin>>tem;
//            int f=1;
//            for(int j=0;j<index;j++){
//                if(a[j]==tem){ cnt[j]++; f=0; break;}
//            }
//            if(f){ a[index]=tem; cnt[index++]++;}
//        }
//        if(index>m){
//            cout<<"0"<<endl;
//            continue;
//        }
//        int min=10000;
//        int idx;
//        for(int i=0;i<index;i++){
//            if(cnt[i]<min){
//                min=cnt[i];
//                idx=i;
//            }
//        }
//        bool v[10000]={false};
//        for(int i=1;i<=min;i++){
//            if(min%i!=0) continue;
//            int flag=0;
//            for(int j=0;j<index;j++){
//                if(cnt[j]%i!=0){
//					flag=1;
//					break;
//				}
//            }
//            if(!flag){
//            	int j=n/i;
//				for(int num=j,x=1;num<=m;num=x*j,x++) v[num]=true;
//			}
//        }
//        for(int i=index;i<=m;i++){
//			if(v[i]) ans++;
//		}
//        cout<<ans<<endl;
//    }
//    return 0;
//}
//#include<iostream>
//#include<cstring>
//#include<map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main(){
//    int t;
//    cin>>t;
//    while(t--){
//        int n, m;
//        cin>>n>>m;
//        
//        map<long long, int> count_map;
//        for(int i=0;i<n;i++){
//            long long tem;
//            cin>>tem;
//            count_map[tem]++;
//        }
//        
//        int index = count_map.size();
//        if(index > m){
//            cout<<"0"<<endl;
//            continue;
//        }
//        
//        vector<int> cnt;
//        int min_cnt = n;
//        for(auto& p : count_map){
//            cnt.push_back(p.second);
//            min_cnt = min(min_cnt, p.second);
//        }
//        
//        vector<bool> possible(m+1, false);
//        
//        // 遍历所有可能的每组中每个数字的出现次数
//        for(int x = 1; x <= min_cnt; x++){
//            bool valid = true;
//            for(int c : cnt){
//                if(c % x != 0){
//                    valid = false;
//                    break;
//                }
//            }
//            if(valid){
//                int groups = n / x;
//                if(groups >= index && groups <= m){
//                    possible[groups] = true;
//                }
//            }
//        }
//        
//        int ans = 0;
//        for(int i=index;i<=m;i++){
//            if(possible[i]) ans++;
//        }
//        cout<<ans<<endl;
//    }
//    return 0;
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
//#include<cstring>
//using namespace std;
//char a[100010];
//int main(){
//	int n;
//	cin>>n;
//	cin>>a;
//	a[n]='\0';
//	int q;
//	cin>>q;
//	while(q--){
//		char t,t1;
//		cin>>t>>t1;
//		char* p=a;
//		while((p=strchr(p,t))!=NULL){
//			*p=t1;		
//			p++;
//		}
//	}
//	cout<<a<<endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main(){
//	int n,q;
//	string a;
//	cin>>n>>a>>q;
//	char al[26];
//	for(int i=0;i<26;i++){
//		al[i]=i+'a';
//	}
//	while(q--){
//		char t1,t2;
//		cin>>t1>>t2;
//		for(int i=0;i<26;i++){
//			if(al[i]==t1){
//				al[i]=t2;
//			}
//		}
//		
//	}
//	for(int i=0;i<n;i++){
//		cout<<al[a[i]-'a'];
//	}
//}
//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool cmp(int a,int b){
//	return a>b;
//}
//int main(){
//	int q;
//	cin>>q;
//	while(q--){
//		int n;
//		cin>>n;
//		int a[n+1];
//		int b[n+1];
//		for(int i=0;i<n;i++){
//			cin>>a[i];
//		}
//		for(int i=0;i<n;i++){
//			cin>>b[i];
//		}
//		sort(a,a+n,cmp);
//		int cnt_i=0,cnt_k=0;
//		long long max=0;
//		for(int i=0;i<n;i++){
//			if(cnt_i+b[i]<=n){
//				cnt_i+=b[i];
//				cnt_k++;
//				long long t=(long long)cnt_k*a[cnt_i-1];
//				if(t>max){
//					max=t;
//				}
//			}
//			else{
//				break;
//			}
//		}
//		cout<<max<<endl;	
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int a[50005];
//int L,n,m;
//
//bool check(int d){
//	int c=0,cnt=0;
//	for(int i=1;i<=n;i++){
//		if(a[i]-c<d){
//			cnt++;
//		}
//		else{
//			c=a[i];
//		}
//		if(cnt>m){
//			break;
//		}
//	}
//	if(cnt>m){
//		return false;
//	}
//	else{
//		return true;
//	}
//}
//int main(){
//	cin>>L>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	a[++n]=L;
//	int l=a[0];
//	int r=L;
//	while(l<r){
//		int mid=(l+r+1)/2;
//		if(check(mid)){
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
//using namespace std;
//int a[1000010];
//int main(){
//	int d,m;
//	cin>>d>>m;
//	int last=0;
//	for(int i=1;i<=d;i++){
//		int t;
//		cin>>t;
//		a[i]=t-last;
//		last=t;
//	}
//	int num[m+5],d1[m+5],d2[m+5];
//	for(int i=1;i<=m;i++){
//		cin>>num[i]>>d1[i]>>d2[i];
//	}
//	int l=1;
//	int r=m;
//	bool flag=true;
//	while(l<r){
//		int mid=(l+r)/2;
//		if(flag){
//			for(int i=l;i<=mid;i++){
//				a[d1[i]]-=num[i];
//				a[d2[i]+1]+=num[i];
//			}
//		}
//		else{
//			for(int i=mid+1;i<=r;i++){
//				a[d1[i]]+=num[i];
//				a[d2[i]+1]-=num[i];
//			}
//		}
//		bool f=true;
//		long long sum=0;
//		for(int i=1;i<=d;i++)
//		{
//			sum+=a[i];
//			if(sum<0){
//		    	f=false;
//		    	break;
//			}
//		}
//		if(f){
//			l=mid+1;
//			flag=true;
//		}
//		else{
//			r=mid;
//			flag=false;
//		}		
//	}
//	if(l==m){
//		cout<<"0";
//	}	
//	else{
//		cout<<"-1"<<endl<<r;
//	}
//	return 0;
//}

































