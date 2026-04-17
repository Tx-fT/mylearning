//C语言
//#include<stdio.h>

//int main()
//{
//	printf("hello world!\n");
	
//	return 0;
//}

//#include<stdio.h>

//int main()
//{
//	printf("12+1=%d",12+1);%d指代
//	return 0;
	
//}

//#include<stdio.h>
//int main()
//{
//	int price=0;
//	int change=100;or  const int AMOUNT=100   不可改；强调全大写
//	printf("你交了多少钱\n");
//	scanf("%d",&price);互动 &指明位置
//	change=100-price;
//	printf("找您%d\n",change);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a=0;
//	int b=0;
//	printf("请输入两个整数\n");
//	scanf("%d %d",&a,&b);//空格；\n在输入里一定要换行＋占位  前后一致性前＋c输入也要＋c
//	printf("a+b=%d\n",a+b);
//	return 0;
//}

//c++
//数据类型 给变量分配一个合适的内存空间
//整形short int long longlong//sizeof(short)
//浮点型float单精度7位（默认double要加3.14f） double双精度更准15到16位全部 科学计数法float a=3e2//3*10^2 3e-2(3*0.1^2)
//字符型char char word='a';要用单引号括起来 只占1个字节 并不是本身存储换成ASCII编码想看可以（int）word
//转义字符\\输出\ \t同行占8个位置
//字符串c：char str[]="" c++:string str=""(要加头文件#include<string>)
//布尔数据类型1真0假bool a=ture;输出为1 非0即真
//#include<iostream>
//using namespace std;

//int main(){
//	int price=0;
//	cout<<"请输入价格"<<endl;
//	cin>>price;//scanf换成cin不用%d代替
//	int change=100-price;
//	cout<<"找您"<<change;
//	system("pause");
//	return 0;
//}

//算数运算符
//前置递增减++a让变量+1操作，先＋-后运行
//后置递增减b++同上，先运行后＋—
//区别
//#include<iostream>
//using namespace std;
//int main(){
//	int a=10;
//	int b;
//	b=a++*10;
//	cout<<b<<endl;
//	system("pause");
//	return 0;
//} 
//赋值运算符
//#include<iostream>
//using namespace std;
//int main(){
//	int a=10;
//	a+=2;//a=a+2 同理-= *= /= %=
//	cout<<a<<endl;
	
//	system("pause");
//	return 0;
//}
//比较运算符（结果0 1）
//==相等于 !=不等于 > < >= <=  ()内可以优先级运算
//逻辑运算符
//！非 !a如果a为真则!a为假 取反操作
//&&与 a&&b如果a和b都为真，则结果为真，否则为假。
//||或 a或b有一个真则为真否则为假
//在c++中非0为真
//#include<iostream>
//using namespace std;
//int main(){
//	int a=10;
//	cout<<!a<<endl;//假为真，真为假
//	int a1=10;
//	int b=0;
//	cout<<(a1&&b)<<endl;//同真才真因为要一起看＋()
//	cout<<(a1||b)<<endl;//同假才假  条件（1or0）
//	system("pause");
//	return 0;
//}
//程序流程结构
//顺序结构
//#include<iostream>
//using namespace std;
//int main(){
//	int a=0;
//	cout<<"请输入分数"<<endl;
//	cin>>a;
//	if(a>=600){//if后不加分号要不然后面代码直接执行
//		cout<<"恭喜"<<endl;
		//TODO
//	}
//	else{
//		cout<<"菜就多练"<<endl;//else if(){}多条件
//	}
//	system("pause");
//	return 0;
//}//if里再if叫做嵌套if语句
//选择结构
//if语句 if(条件){执行代码}
//三目运算符
//#include<iostream>
//using namespace std;
//int main(){
//	int a=10;
//	int b=11;
//	int c=0;
//	c=(a>b?a:b);//缩写（if）a>b则执行（剩）第一个否则第二个，因为三个连着加括号；剩下的量可以继续赋值
//	cout<<c<<endl;
//	system("pause");
//	return 0;
//}switch语句（使多条件更简洁）
//#include<iostream>
//using namespace std;
//int main(){
//	int a=0;
//	cin>>a;
//	switch(a){//switch只能放整数或字符型，优点结构清晰效率高
//		case 10:
//		case 9://;表段联系：表如此的话
//		 cout<<"666"<<endl;
//		 break;
//		default://充当else用
//		 cout<<"00"<<endl;
//		 break;//终止
//	}
//	system("pause");
//	return 0;
//}

//
//循环结构
//while(条件){为真执行代码}//无限循环直至不满足条件
//#include<iostream>
//#include<ctime>
//using namespace std;
//int main(){
//	srand((unsigned int)time(NULL));
//	int i=rand()%100+1;//生成一个随机1-100的数 因为计算机的第一位为0 %为区间范围 但前面要加头文件代码
	
//	cout<<"请输入你猜测的数字"<<endl;
	
//	while(1){//一直真无限循环
//	    int a=0;
//	    cin>>a;
//		if(a>i){
//			cout<<"大了"<<endl;
//		}
//		else if(a<i){
//			cout<<"小了"<<endl;
//		}
//		else{
//			cout<<"恭喜"<<endl;
//			break;
//	    }
//		}
//	system("pause");
//	return 0;
//}
//dowhile循环语句
//do{循环代码}while（循环条件）
//先运行一次再做判断
//#include<iostream>
//using namespace std;
//int main(){
//	int i=0;
//	do{
//		cout<<i<<endl;
//		i=++i;
//	}
//	while(i<10);
//	system("pause");
//	return 0;
	
//}
//案例水仙花数
//#include<iostream>
//using namespace std;
//int main(){
//	int i=100;
//	do{
//		int a=0;
//		int b=0;
//		int c=0;
//		a=i/100;
//		b=(i/10)%10;
//		c=i%10;
//		if(i==a*a*a+b*b*b+c*c*c){//=是赋值==是相等条件c++不支持幂运算
//			cout<<i<<endl;
//		}
//		i++;
//		}
//	while(i<=999);
//	system("pause");
//	return 0;
//}
//for循环语句
//满足循环条件，执行循环语句for(起始表达式；条件表达式；循环体)for(i=01;i<102;i++3){代码4}for逻辑顺序1243243243......先于循环体执行代码
//案例敲桌子
//#include<iostream>
//using namespace std;
//int main(){
//	int i=1;
//	for(;i<=100;++i){//因为i++放在最后所以与++1此时没区别
//		int a=0;
//		int b=0;
//		a=i/10;
//		b=i%10;
//		if(a||b==7;i%7==0){
//			cout<<"敲桌子"<<i<<endl;
//		}
//		else{
//			cout<<i<<endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
//嵌套循环
//#include<iostream>
//using namespace std;
//int main(){
//	for(int u=0;u<=9;u++){//c++一定要考虑0
//		for(int i=0;i<=9;i++){//此时i做循环次数
//				cout<<"* ";
//			}
//			cout<<endl;
//	}
//	system("pause");
//	return 0;
	
//}
//#include<iostream>
//using namespace std;
//int main(){
//	for(int x=1;x<=9;x++){
//		for(int y=1;y<=9;y++){//直接可以y<=x就不用if
//			cout<<x<<"*"<<y<<"="<<x*y<<"  ";
//			if(x==y){
//				cout<<endl;//指令要在break前
//				break;
//			
//			}
//		}
//	}
//}
//break跳转语句，退出循环   可以筛选条件用bool可以跳出双重循环
//出现在switch中终止case并跳出switch
//嵌套循环中跳出就近循环
//跳转语句continue，直接执行下一次循环
//#include<iostream>
//using namespace std;
//int main(){
//	for(int i=1;i<=100;i++){
//		if(i%2==0){
//			continue;
//		}
//		cout<<i<<endl;
//	}
//	system("pause");
//	return 0;
//}
//跳转语句goto后习惯大写（标记）  任意门的形式 
//goto FLAG;
//FLAG:****

//数组
//三种定义方式
//数组类型 数组名[数组长度];  int score[10];
//数据类型 数组名[数组长度]={值1，值2...};
//数组的特点 放在一块连续的内存空间中 数组中每个元素都是相同数据类型——呈集合形式 从0开始a[0]通过下标访问
//int a[5];//0 1 2 3 4
//int a[5]={10,20,30,40,50}
//a[0]=1;
//cout<<a[0]<<endl;
//利用循环的方式输出
//#include<iostream>
//using namespace std;
//int main(){
//	int a[5]={1,2,3,4,5};//如果输出未有数据0填补
//	for(int i=0;i<=4;i++){//从0开始索引
//		cout<<a[i]<<endl;
//	}
//	system("pause");
//	return 0;
//}
//案例5小猪称体重  访问数组中各个元素打擂台法
//#include<iostream>
//using namespace std;
//int main(){
//	int max=0;
//	int arr[5]={300,350,200,400,250};
//	for(int i=0;i<=4;i++){
//		if(max<=arr[i]){
//			max=arr[i];
//		}	
//	}
//	cout<<max<<endl;
	
	
//	int a[2]={1,2};
//	cout<<"数组占用内存空间： "<<sizeof(a)<<endl;
//	cout<<"each"<<sizeof(a[0])<<endl;
//	cout<<"geshu"<<sizeof(a)/sizeof(a[0])<<endl;
//	cout<<(int)a<<endl;
//	cout<<(int)&a[0]<<endl;//数组为集合有地址&指向其中一个
//	cout<<(int)&a[1]<<endl;

//	system("pause");
//	return 0;
//}
//案例数组元素逆置
//倒序方法1
//#include<iostream>
//using namespace std;
//int main(){
//	int arr[5]={1,2,3,4,5};
//	for(int i=0;i<=4;i++){
//		cout<<arr[4-i]<<"  ";
//	}
//	system("pause");
//	return 0;
//}
//方法2
//int main(){
//	int arr[5]={1,2,3,4,5,};
//	for(int i=0;i<5;i++){
//		cout<<arr[i]<<endl;
//	}
//	int a=0;
//	int b=sizeof(arr)/sizeof(arr[0])-1;;
//	while(a<b){
//		int c=arr[a];//c的作用为保存要不然a被b代替了
//		arr[a]=arr[b];
//		arr[b]=c;//错的arrb赋给arra已经没了arrc也变了
//		a++;
//		b--;
//	}
//	for(int i=0;i<5;i++){
//			cout<<arr[i]<<endl;
//	}
//	system("pause");
//	return 0;
//}
//冒泡排序
//#include<iostream>
//using namespace std;
//int main(){
//	int arr[8]={2,3,1,4,7,9,5,8};
//	for(int a=0;a<8;a++){
//		for(int i=0;i<8-a-1;i++){
//			if(arr[i]>=arr[i+1]){
//				int c=0;
//				c=arr[i];
//				arr[i]=arr[i+1];
//				arr[i+1]=c;		
//			}
//		}
//	}
//	for(int i=0;i<8;i++){
//					cout<<arr[i]<<endl;
//					}
//    system("pause");
//	return 0;
//}
//二维数组
//4种定义方式
//1.数据类型 数组名[行数][列数]
//2.数据类型 数组名[行数][列数]={
//                              {数据1，数据2}，
//                              {数据3，数据4}
//                                           };最好
//3.数据类型 数组名[行数][列数]={数据1，数据2，数据3，数据4};
//4.数据类型 数组名[][列数]={数据1，数据2，数据3，数据4};
//方法：外侧循环行数，内侧循环列数
//二维数组名称 看内存 看首地址
//第一行arr[0]
///一个arr[0][0]
//列数sizeof（第一行）/（一个）//&只指向1个元素
//案例考试成绩的统计
//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	string c[3]={"张三","李四","王五"};字符串与数组相似但字符串要前提文件且＋“”
//	int a[3][3]={
//		{100,100,100},
//		{70,80,20},
//		{80,70,90}
//	};
//	
//	for(int i=0;i<3;i++){
//		int b=0;//子程序赋值不能管上程序，需要上程序赋值0
///		for(int u=0;u<3;u++){
//		    b+=a[i][u];//中间不要赋值
//			
//		}
//		cout<<c[i]<<"的成绩为"<<b<<endl;
//	}
//	system("pause");
//	return 0;
//}
//函数  定义以后可以直接用 定义在int main（）之前
//步骤 1.返回值类型2.函数名3.参数表列（使用该函数传入的数据）4.函数体语句（函数内需要执行的语句）5.return表达式（和返回值挂钩，函数执行完后，返回相应的数据）
//返回值类型 函数名（参数列表（形参））调用时实参传递给形参
//{
//	函数体语句
//	return表达式
//}
//函数的调用
//#include<iostream>
//using namespace std;
//int add(int num1,int num2){
//	int sum=num1+num2;
//	return sum;
//}
//int main(){
//	int a=1;
//	int b=2;
//	int c=add(a,b);//形参与实参对应
//	cout<<c<<endl;
//	system("pause");
//	return 0;
//}
//值传递
//定义函数，实现两个函数进行交换 如果函数不需要返回值，声明的时候可以写void
//void swap(int num1,int num2){
//	int c=num1;
//	num1=num2;
//	num2=c;
	//(return)
//}
//int main(){
//	int a=1;
//	int b=2;
//	swap(a,b);
//	cout<<a<<b<<endl;//a b不会交换值传递中形参发生改变不会影响实参  相当于a b实参不变只是把数据给到形参去执行
//	system("pause");
//	return 0;
//}
//返回值赋值后刷新
//#include<iostream>
//using namespace std;
//函数的常见样式
//1.无参无返
//void test01(){
//	cout<<"111"<<endl;
//}
//2.有参无返(一般适用于指令例如交换，与赋值无关，来无回，形参赋值后固定)
//
//3.无参有返
//int test03(){
//	return 1000;
//你写的 test03() 是 “调用 test03 这个函数” 的语法，执行后会得到函数返回的 1000（一个 int 类型的数值），它本身不存储数据，也不能被赋值，因此不是变量
//只是操作时表现一下并非存储
//}
//4.有参有返(zuizhong)
//int test04(int a){
//	cout<<a<<endl;
//	return 0;//a是a test04(int a)是个整体return 0最后表现为0
//}
//int main(){
//	test01();//要加括号
//    int num1=test03();
//    int num1=test04(10000);
//    for(int i=0;i<2;i++){
    
//    cout<<num1<<endl;
//}
//	system("pause");
//	return 0;
//}
//函数的声明
//声明只要返回值类型 函数名称 形参列表//声明可以写多次但定义只能一次
//函数的分文件编写
//步骤1.创建后缀名为.h的头文件
//    2.创建后缀名为.cpp的源文件
//    3.在头文件中写函数声明
//    4.在源文件中写函数的定义
//#include<iostream>
//using namespace std;
//void swap(int a,int b){
//	int c=a;
//	a=b;
//	b=c;
//}
//指针！！！ 可以通过指针间接访问内存（可以通过指针=地址，来保存地址）
//*有两意思  1.在定义时表指针 2.解引用附身地址，变换其中内容
//定义一个指针
//数据类型*指针变量名；int* p；
//#include<iostream>
//using namespace std;
//int main(){
//	int a=100;
//	int *p;//定义指针必须有*
//	p=&a;//有*方能使p存储地址 P是地址*P附身此地址的值
//	cout<<p<<endl;
//	*p=1000;
//	cout<<a<<endl;
//	cout<<*p<<endl;//解引用*p可直接修改原变量
//	system("pause");
//	return 0;
//}
//空指针 空指针用于给指针变量初始化 int* p=NULL；不可进行访问0-255内存是系统占用 
//野指针 指针 int* p=（int* ）0*1100//指针变量p指向地址编号为  的空间
//const修饰修饰指针  const是永恒的意思 在指针中p为坐标即指向*p为常量（所以const加在谁前谁不可更改）
//1.const修饰指针--常量指针const int* p=&a； *p=20错误 p=&b正确  值不可更改但指向坐标可跟你改改
//2.const修饰常量--指针常量int* const p=&a； 值可以更改但指针坐标不能更改
//3.const既修饰指针又修饰常量 const int* const p=&a；都不可更改
//const修饰指针--常量指针--指针可以改--const int* p=&a；
//const修饰常量--指针常量（以能更改的命名）--常量可以改--int* const p=&a；
//利用指针访问数组中的元素
//#include<iostream>
//using namespace std;
//int main(){
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int *p=arr;//arr本身就代表数组坐标
//	for(int i=0;i<10;i++){
//		cout<<*p<<endl;
//		p++;/*表示跳过四个字节访问数组下一个值*/
//	}
//    system("pause");
//  return 0;
//}
//指针与函数
//地址传递（值传递不能改变实参本身）//实参之所以实正是因为他一直存储在内存中某个地址，形参只能复制他不能改变他//而地址传递直接对地址中的值动手
//#include<iostream>
//using namespace std;
//void swap(int* p1,int* p2){//定义时*为说明指针（坐标）  此后p就为坐标
//	int c=*p1;
//	*p1=*p2;//用时＋*解引用附身
//	*p2=c;
//}
//int main(){
//	int a=10;
//	int b=20;
//	swap(&a,&b);//输入坐标
//	cout<<a<<"  "<<b<<endl;
//	system("pause");
//	return 0;
//}
//要改实参用地址传递 函数参数列表用地址，不改实参用值传递，函数参数列表用值
//案例：封装一个函数，利用冒泡排序，实现对整形数组的升序排列
//#include<iostream>
//using namespace std;
//void bubblesort(int* arr,int len){//虽然数组名本身就是指针但是在括号内形参就是个形式，需要表明类型和是不是指针
//	for(int i=0;i<len-1;i++){
//		for(int u=0;u<len-1-i;u++){
//			if(arr[u]>arr[u+1]){
//				int c=arr[u];
//				arr[u]=arr[u+1];
//				arr[u+1]=c;
//			}
//		}
//	}
//}
//void print(int *arr,int len){//数组用函数因为太大需要用指针表示
//	for(int i=0;i<len;i++){
//		cout<<arr[i]<<endl;
//	}
//}
///int main(){
//	int arr[10]={1,3,6,7,9,2,4,5,10,8};
//	int len=sizeof(arr)/sizeof(arr[0]);
//	bubblesort(arr,len);//数组名称本来就是指针
//	print(arr,len);
//	system("pause");
//	return 0;
//}
//结构体！！！

//1.c++中要很多cout才支持换行操作/或用字符串s=R"(不用换行)"//但第一行输出要注意
//2.#include<bits/stdc++.h>包含c++中所有头文件
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//    int a=0;
//    int b=0;
//    cin>>a;
//    cin>>b;
//    cout<<a+b<<endl;
//    system("pause");
//    return 0;
//}

//结构体 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
//语法：
//struct 结构体名称{结构体成员列表};
//3种：
//1.自定意数据类型，一些类型集合组成的一个类型//算做一个整体的数据类型
//#include<iostream>
//#include<string>
//using namespace std;
//struct student{
//	string name;
//	int age;
//	int score;};//定义结构体 //attention;
//int main(){
//	//创建方式1
//	struct student stu1={"111",22,33};//创建结构体，结构体把各种“类型”组成集合，再具体调用类型“.”来访问具体成员 创建结构体名称struct可以省略 
//	stu1.name="111";
//	cout<<stu1.name<<endl;
//	student stu2={"李四",18,100};//创建方式2
//	cout<<stu2.age<<endl;
//	system("pause");
//	return 0;

//创建结构体数组
//    student stu[3]={
//		{"111",18,100},
//		{"222",17,90},
//		{"333",19,80}
//	};
//	for(int i=0;i<3;i++){
//		cout<<stu[i].name<<endl;//具体用.访问
//	}

//用指针访问结构体
//    student *p=&stu1;
//    p->name="222";
//    cout<<p->name<<endl;//这里用坐标且不能用.访问,指针访问结构体只能用->
//    int a=10;
//    int *p1=&a;
//    *p1=1;//平常＋*为解引用附身而在结构体中p->为解引用附身
//    cout<<a<<endl;
//	system("pause");
//	return 0;
//}
//结构体嵌套结构体
//#include<iostream>
//#include<string>
//using namespace std;
//struct student{
//	string name;
//	int age;
//	int score;
//};
//void print(const student *a){//a只是代量  将函数形参改为指针可以减少内存空间
//	a->age=100;
//	cout<<a->name<<a->age<<a->score<<endl;
//}
////struct teacher{
////	int id;
////	string name;
////	int age;
////	struct student stu;
////};
//int main(){
////	teacher t={1,"11",};
////	t.stu.name="22";
////	t.stu.age=11;
////	t.stu.score=100;
////	cout<<"学生姓名"<<t.stu.name<<"老师姓名"<<t.name<<endl;
//
////结构体做函数参数
////const操作情景：数据太大要用指针，但不能改变实参，加入const一旦有修改就会报错，可以防止误操作
//    student s={"张三",18,100};
//    print(&s);
//	system("pause");
//	return 0;
//}
//结构体案例1：
//#include<iostream>
//#include<string>
//using namespace std;
//struct student{
//	string name;
//	int score;
//};
//struct teacher{
//	string name;
//	student stu[5];
//};
//void a(teacher b[3]){//student stu[5]){   stu下属于teacher不用作为形参  ＋指针的情况1.做地址交换2.后面要用的数据太大用指针节省内存（用const防止地址交换）
//	for(int i=0;i<3;i++){
//		cout<<b[i].name<<endl;
//		for(int j=0;j<5;j++){
//			cout<<b[i].stu[j].name<<b[i].stu[j].score<<endl;
//		}
//	}	
//}
//int main(){
//	teacher t[3];
//	for(int i=0;i<3;i++){
//		    cout<<"输入老师姓名"<<endl;
//			cin>>t[i].name;
//			student stu[5];
//				cout<<"输该各老师的5名学生姓名"<<endl;
//				for(int j=0;j<5;j++){
//					cin>>t[i].stu[j].name;
//				}
//				cout<<"输入该老师的5名学生的成绩"<<endl;
//				for(int j=0;j<5;j++){
//				    cin>>t[i].stu[j].score;
//				}
//		}
//	a(t);
//	system("pause");
//	return 0;
//	
//}
//结构体案例2
//#include<iostream>
//#include<string>
//using namespace std;
//struct hero{
//	string name;
//    int age;
//	string sex;	
//};
//void bubblesort(hero arr[]){//说明清楚为数组
//	for(int i=0;i<5;i++){
//		for(int j=0;j<5-i-1;j++){
//			if(arr[j].age>arr[j+1].age){
//				hero temp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=temp;//不能只交换age要整体都换//右边给左边赋值
//			}
//		}
//	}
//	for(int i=0;i<5;i++){
//		cout<<arr[i].name<<"  "<<arr[i].age<<"  "<<arr[i].sex<<endl;
//	}
//}
//int main(){
//	hero arr[5]={
//		{"1",1,"1"},
//		{"2",2,"0"},
//		{"3",5,"0"},
//		{"4",3,"1"},
//		{"5",4,"1"}
//	};
//	bubblesort(arr);//【5】不算做数组名称
//	system("pause");
//	return 0;
//}
















