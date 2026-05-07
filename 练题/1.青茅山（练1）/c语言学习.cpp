//c语言学习
//gets(inStr);gets函数得到字符串 getchanr()函数得到字符

//outStr[j] = '\0'; // 3. 补充：在有效字符末尾添加字符串结束标志，确保printf正确识别

//strlen 是 C 语言标准库 <string.h> 中提供的一个核心函数，用于计算一个字符串的长度
//size_t strlen(const char *str);
//参数：str 是一个指向以 null 字符 (\0) 结尾的字符串的指针。
//返回值：返回字符串中字符的数量，不包括末尾的 null 结束符 \0。返回类型是 size_t，这是一个无符号整数类型（通常是 unsigned int 或 unsigned long），专门用于表示对象的大小或数组的索引。

//strcpy
//strcpy 是 C 语言标准库 <string.h> 中用于字符串复制的核心函数。它会将一个字符串（源字符串）的内容完整地复制到另一个字符串（目标字符串）中，包括末尾的 null 结束符 \0。
//char *strcpy(char *dest, const char *src);
//参数：
//dest：目标字符串的指针，复制后的内容会存放在这里。
//src：源字符串的指针，要被复制的内容。
//返回值：返回指向目标字符串 dest 的指针。

//递归//重复逻辑的活先把前面干了再干后面
//表象：函数调用函数自身
//阶乘
//#include<iostream>
//using namespace std;
//int fact(int n){
//	if(n==1){ 
//	return 1;
//	}
//	return fact(n-1)*n;
//}
//int main(){
//	cout<<fact(3);
//	return 0;
//}
//斐波那契数列
//#include<stdio.h>
//#include<vector.h>
//vector<int> saved(n,-1);
//int fib(int n){
//	if(n<=2) return 1;
//	if(saved[n]==-1){
//		saved[n]=fib(n-1)+fib(n-2);
//	}
//	return saved[n];
//}
//int main(){
//	printf("%d",fib(7));
//	return 0;
//}
//汉诺塔
//#include<stdio.h>
//void hanoi(int n,char a,char b,char c){
//	if(n==1){
//		printf("move %d from %c to %c\n",n,a,c);
//		return;
//	}
//	hanoi(n-1,a,c,b);
//	printf("move %d from %c to %c\n",n,a,c);
//	hanoi(n-1,b,a,c);
//}
//int main(){
//	char a='a';
//	char b='b';
//	char c='c';
//	hanoi(2,a,b,c);
//	return 0;
//}
//#include<stdio.h>
//int main(){
//    int n;
//    scanf("%d",&n);
//    int arr[n];
//    for(int i=0;i<n;i++){
//        scanf("%d",&arr[i]);
//    }
//    printf("%d",arr[0]);
//    return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    cout << "请输入杨辉三角的行数：";
//    cin >> n;
//
//    // 创建二维向量存储杨辉三角，初始化每行元素为1
//    vector<vector<int>> yanghui(n);//二维向量数组yanghui中每个元素都是向量 
//    for (int i = 0; i < n; i++) {
//        yanghui[i].resize(i + 1, 1);  // 第i行有i+1个元素，默认值为1，给yanghui中每个元素定义长度
//    }
//
//    // 填充杨辉三角（从第2行开始，因为前两行已初始化）
//    for (int i = 2; i < n; i++) {//也是从0开始
//        // 第i行的第j个元素 = 上一行的第j-1个元素 + 上一行的第j个元素
//        for (int j = 1; j < i; j++) {
//            yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
//        }
//    }
//
//    // 打印杨辉三角（居中对齐，更美观）
//    for (int i = 0; i < n; i++) {
//        // 前置空格实现居中：总行数 - 当前行数 - 1 个空格
//        for (int k = 0; k < n - i - 1; k++) {
//            cout << " ";
//        }
//        // 打印当前行的元素
//        for (int j = 0; j <= i; j++) {
//            cout << yanghui[i][j] << " ";
//        }
//        cout << endl;  // 换行
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main(){
// //   char arr[80];
//   // scanf("%s",arr);
//	int i=141;
//	printf("\\%d",i);   
//    return 0;
//}
//运行
//char *fgets(char *str, int num, FILE *stream);
//参数说明
//char *str: 这是一个字符指针，指向一个用于存储读取到的数据的字符数组（缓冲区）。
//int num: 这是要读取的最大字符数。fgets 会读取最多 num - 1 个字符，然后在末尾自动添加一个 null 字符 (\0) 来构成一个有效的 C 字符串。
//FILE *stream: 这是一个指向 FILE 对象的指针，该对象标识了要从中读取数据的文件流。常见的流有 stdin (标准输入)、stdout (标准输出)、stderr (标准错误输出)，以及通过 fopen 函数打开的文件。
//返回值
//成功时：函数返回指向缓冲区 str 的指针。
//到达文件末尾 (EOF)：函数返回 NULL 指针。
//发生错误时：函数也返回 NULL 指针。
//注意：当 fgets 返回 NULL 时，你无法仅通过返回值区分是到达了文件末尾还是发生了错误。为了准确判断，你需要使用 feof() 和 ferror() 函数。
//工作机制
//fgets 从 stream 中逐个读取字符，并将它们存储到 str 指向的缓冲区中。
//它会一直读取，直到遇到以下三种情况之一：
//读取到了换行符 (\n)。换行符会被包含在读取的字符串中。
//已经读取了 num - 1 个字符。
//到达了文件末尾 (EOF)。
//无论因为哪种情况停止，fgets 都会在读取的字符序列末尾添加一个 null 字符 (\0)，以确保结果是一个正确的 C 字符串。

//#include<stdio.h>
//#include<string.h>
//int main(){
//    char arr[81],result[81];
//    fgets(arr,81,stdin);
//    int visit[256]={0};
//    int len=strlen(arr);
//    if(len>0&&arr[len-1]=='\n'){
//        arr[len-1]='\0';
//        len--;
//    }
//    int k=0;
//    for(int i=0;i<len;i++){
//        if(!visit[(int)arr[i]]){
//            visit[(int)arr[i]]=1;
//            result[k++]=arr[i];
//        }
//    }
//    result[k]='\0';
//    for(int i=0;i<k-1;i++){
//        for(int j=0;j<k-i-1;j++){
//            if(result[j]>result[j+1]){
//                char temp=result[j];
//                result[j]=result[j+1];
//                result[j+1]=temp;
//            }
//        }
//    }
//    printf("%s",result);
//    return 0;
//}

//strtok(input, ",") 以 "," 为分隔符，从 input 字符串的起始位置开始分割，找到第一个分隔符 "," 后，将分隔符替换为字符串结束符 '\0'，并返回分隔符之前的子串指针（即密文字符串的起始地址）。
//例如输入为 "ccAAbB,AAyyZz"，这一步会返回指向 "ccAAbB" 的指针，input 字符串被修改为 "ccAAbB\0AAyyZz"。
//第二行：
//strtok(NULL, ",") 中第一个参数为 NULL，表示继续分割上一次未处理完的字符串（即 input 中 "\0" 之后的部分）。
//这一步会从 "\0" 之后的位置开始，找到下一个分隔符（此处无更多分隔符，直接到字符串末尾），返回指向 "AAyyZz" 的指针。

//递归函数应该直接返回值，而不是给自己赋值。
//
//修正后的代码：
//float fun(int n) {
//    if (n == 1) 
//        return 1;
//    return 1.0 / (1 + fun(n - 1));
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	long long a;
//	for(int i=0;i<n;i++){
//		int m=0;
//		cin>>a;
//		if(a%4==0){
//			cout<<"Yes"<<endl;
//			continue;
//		}
//		int arr[19];
//		int count=0;
//		while(a/10!=0||a%10!=0){
//			arr[count++]=a%10;
//			a/=10;	
//		}
//		if(count==1){
//			cout<<"NO"<<endl;
//			continue;
//		}
//		m=0;
//		for(int i=0;i<count-1;i++){
//			if((arr[i]+arr[i+1]*10)%4==0){
//				cout<<"Yes"<<endl;
//				m=1;
//				continue;
//			}
//		}
//		if(m){
//			continue;
//		}
//		m=0;
//		for(int i=2;i<count;i++){
//			if((arr[0]+arr[i]*10)%4==0){
//				cout<<"Yes"<<endl;
//				m=1;
//				continue;
//			}
//		}
//		if(m){
//			continue;
//		}
//		cout<<"No"<<endl;
//	}
//	system("pause");
//	return 0;
//}

//for (int j = 0; j < n; j++) {
//            total += *(*(scores + i) + j);  // 相当于 scores[i][j]
//        }























