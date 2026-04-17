//浮舟湿地
//第一周
//提高题
#include<iostream>
using namespace std;
int main(){
//	int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    int arr[10];
	cout<<"请输入10个数"<<endl;
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
//	cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9>>a10;
//	int arr[10]={a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
	for(int a=10;a>1;a--){
		for(int i=0;i<a;i++){
			if(arr[i]>=arr[i+1]){
				int c=0;
				c=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=c;		
			}
		}
	}
	for(int i=0;i<10;i++){
					cout<<arr[i]<<endl;
					}
	system("pause");
	return 0;
}
//第二周 指针 结构体 类&对象
//存储 格子每个8个 一个格子是字节byte int用4个byte
//指针 存储的是地址
//#include <iostream>
//using namespace std;
//int main(){
//	int num=20;
//	int &ref=num;//&ref c++中存储地址变量 指针写作int* a 但有意义需要a=&b
//	cout<<&ref<<endl;//\n换成endl
//	system("pause");
//	return 0;
//}
//用法1
//#include<iostream>
//using namespace std;
//int main(){	
//    int a=10;
//	int &b=a;
//	b=11;
//	cout<<b<<endl;//可以利用指针改变变量
//	cout<<&b<<endl;
//	system("pause");
//	return 0;
	
//}

//用法2
//#include<iostream>
//using namespace std;
//int main(){
//	int* p1=new int;//提前占用内存1个4byte
//	int* p2=new int[3];//提前占用3个4byte
//	delete p1;
//	delete[] p2;//全部清空
	
//}
//结构体struct打包成统一的数据集合方便管理 
