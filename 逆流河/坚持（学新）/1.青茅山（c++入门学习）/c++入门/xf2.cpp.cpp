//#include<iostream>
//#include<string>
//using namespace std;
//
//struct hero{
//    string name;
//    int age;
//    string sex;	
//};
//
//void bubblesort(hero arr[]){
//    for(int i=0; i<5; i++){  // 外层循环控制排序轮次（5个元素最多4轮即可完成）
//        for(int j=0; j<5-i-1; j++){  // 内层循环控制每轮比较次数
//            if(arr[j].age > arr[j+1].age){  // 按年龄升序排序
//                // 正确交换整个结构体
//                hero temp = arr[j];       // 临时保存arr[j]
//                arr[j] = arr[j+1];        // arr[j]接收arr[j+1]的值
//                arr[j+1] = temp;          // arr[j+1]接收临时保存的arr[j]的值
//            }
//        }
//    }
//    // 输出排序结果
//    for(int i=0; i<5; i++){
//        cout << arr[i].name << "  " << arr[i].age << "  " << arr[i].sex << endl;
//    }
//}
//
//int main(){
//    hero arr[5] = {
//        {"1",1,"1"},
//        {"2",2,"0"},
//        {"3",5,"0"},
//        {"4",3,"1"},
//        {"5",4,"1"}
//    };
//    bubblesort(arr);  // 正确传递数组名（数组名本身就是首地址）
//    system("pause");
//    return 0;
//}
#include<iostream>
#include<string>
using namespace std;
struct hero{
	string name;
    int age;
	string sex;	
};
void bubblesort(hero arr[]){//说明清楚为数组
	for(int i=0;i<5;i++){
		for(int j=0;j<5-i-1;j++){
			if(arr[j].age>arr[j+1].age){
				hero temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;//不能只交换age要整体都换//右边给左边赋值
			}
		}
	}
	for(int i=0;i<5;i++){
		cout<<arr[i].name<<"  "<<arr[i].age<<"  "<<arr[i].sex<<endl;
	}
}
int main(){
	hero arr[5]={
		{"1",1,"1"},
		{"2",2,"0"},
		{"3",5,"0"},
		{"4",3,"1"},
		{"5",4,"1"}
	};
	bubblesort(arr);//【5】不算做数组名称
	system("pause");
	return 0;
}
