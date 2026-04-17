//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int k=0;
//	cin>>k;
//	int n=1;
//	double num=0.0;//分数用double关于其的任何表示用小数
//	while(1){
//		num+=1.0/n;
//		n++;
//		if(num>k){
//			cout<<n-1<<endl;//n已经自增
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main(){
//    int a,b,c;
//    scanf("%d/02%d/02%d",&a,&b,&c);
//    char arr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
//    int month_num=0;
//    for(int i=0;i<b-1;i++){
//        month_num+=arr[i];
//    }
//    int num=0;
//    num=c+month_num;
//    if((a%4==0&&a%100!=0)||a%400==0){
//        printf("%d",num+1);
//    }
//    else{
//        printf("%d",num);
//    }
//    return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main(){
//    int x1,y1,x2,y2,x3,y3;
//    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
//    double l1,l2,l3;
//    l1=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
//    l2=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
//    l3=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
//    if(l1+l2>l3&&l1+l3>l2&&l3+l2>l1){
//        double p;
//        p=(l1+l2+l3)/2.00;
//        double s;
//        s=sqrt(p*(p-l1)*(p-l2)*(p-l3));
//        printf("L = %.2f, A = %.2f",p*2,s);
//    }
//    else{
//        printf("Impossible");
//    }
//    return 0;
//}
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main() {
//    int A, B;
//    cin >> A >> B;
//    
//    int sum = 0;
//    int count = 0;  // 用于计数，控制每行输出5个数字
//    
//    for (int i = A; i <= B; i++) {
//        // 每个数字占5个字符宽度，右对齐
//        cout << setw(5) << i;
//        sum += i;
//        count++;
//        
//        // 每5个数字换行（最后一行不足5个也不额外换行）
//        if (count % 5 == 0) {
//            cout << endl;
//        }
//    }
//    
//    // 如果最后一行不足5个数字，需要手动换行
//    if (count % 5 != 0) {
//        cout << endl;
//    }
//    
//    // 输出总和
//    cout << "Sum = " << sum << endl;
//    
//    return 0;
//}
//#include<iostream>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//int a1,a2,a3,a4;
//bool zf(double i){
//    if(a1*pow(i,3)+a2*pow(i,2)+a3*i+a4>0){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//int main(){
//    cin>>a1>>a2>>a3>>a4;
//    double r1,r2;
//    cin>>r1>>r2;
//    double r;
//    const double epsilon = 1e-10;
//    while(1){
//        r=(r1+r2)/2;
//        if(a1*pow(r,3)+a2*pow(r,2)+a3*r+a4==0){
//            break;
//        }
//        else if(abs(a1*pow(r,3)+a2*pow(r,2)+a3*r+a4)<epsilon){
//            break;
//        }
//        if(zf(r1)^zf(r)){
//            r2=r;
//        }
//        else{
//            r1=r;
//        }
//    }
//    cout<<fixed<<setprecision(2)<<r<<endl;
//    return 0;
//}
//#include<stdio.h>
//int main(void)
//{  
//      int  m, n;
//
//      printf("Enter m,n;");   
//      scanf("%d%d", &m,&n);
//      while (m != n)
//      {   while (m > n)       m = m - n;
//          while (n > m)       n = n - m;    
//      }
//      printf("m=%d\n",m);    
//
//      return 0;
//}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int data;
    char pre[6];
    char next[6];
}node;

int main(){
    int num;
    char p[6];
    scanf("%s %d",p,&num);
    
    node arr[num];
    for(int i=0;i<num;i++){
        scanf("%s %d %s",arr[i].pre,&arr[i].data,arr[i].next);
    }
    
    int visited[10001] = {0};  // 标记绝对值是否出现过
    int remain[num], rem_cnt = 0;   // 保留的结点索引
    int removed[num], del_cnt = 0;  // 删除的结点索引
    
    // 遍历链表
    while(strcmp(p, "-1") != 0){
        // 查找当前结点
        int found = -1;
        for(int i=0;i<num;i++){
            if(strcmp(p, arr[i].pre) == 0){
                found = i;
                break;
            }
        }
        
        if(found == -1) break;  // 结点不存在
        
        node* cur = &arr[found];
        int abs_val = cur->data;
        if(abs_val < 0) abs_val = -abs_val;
        
        if(!visited[abs_val]){
            // 第一次出现，保留
            visited[abs_val] = 1;
            remain[rem_cnt++] = found;
        }else{
            // 重复出现，删除
            removed[del_cnt++] = found;
        }
        
        // 移动到下一个结点
        strcpy(p, cur->next);
    }
    
    // 重新连接保留链表并输出
    for(int i=0;i<rem_cnt;i++){
        int idx = remain[i];
        if(i < rem_cnt - 1){
            int next_idx = remain[i+1];
            strcpy(arr[idx].next, arr[next_idx].pre);
            printf("%s %d %s\n", arr[idx].pre, arr[idx].data, arr[idx].next);
        }else{
            strcpy(arr[idx].next, "-1");
            printf("%s %d %s\n", arr[idx].pre, arr[idx].data, arr[idx].next);
        }
    }
    
    // 重新连接删除链表并输出
    for(int i=0;i<del_cnt;i++){
        int idx = removed[i];
        if(i < del_cnt - 1){
            int next_idx = removed[i+1];
            strcpy(arr[idx].next, arr[next_idx].pre);
            printf("%s %d %s\n", arr[idx].pre, arr[idx].data, arr[idx].next);
        }else{
            strcpy(arr[idx].next, "-1");
            printf("%s %d %s\n", arr[idx].pre, arr[idx].data, arr[idx].next);
        }
    }
    
    return 0;
}



































