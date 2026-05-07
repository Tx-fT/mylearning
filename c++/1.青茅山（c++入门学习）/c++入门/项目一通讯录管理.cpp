//c++项目1 通讯录管理系统
#include<iostream>
#include<string>
using namespace std;
void showMenu(){//menu
	string s=R"(**************************
*****  1.添加联系人  *****
*****  2.显示联系人  *****
*****  3.删除联系人  *****  //函数也可以作为变量在于返回值return 0成功/return -1失败有bool的功效
*****  4.查找联系人  *****
*****  5.修改联系人  *****
*****  6.清空联系人  *****
*****  0.退出通讯录  *****
**************************
	)";  
	cout<<s;
}
struct relation{
	string name;
	string sex;
	int num;
	string adr;
};
int main(){
	relation em={"","",0,""};
	relation g[10];//永远存在10个位置--静态数组   relation*g=new relation[]动态数组
	int i=0;
	string name1;
	string name2;
	string name3;
	bool a=false;
	while(1){
	showMenu();//显示menu
	int a=0;
	cin>>a;
	switch (a) {
		case 0:
			cout<<"欢迎下次使用"<<endl;
			system("pause");
			return 0;
			break;
		case 1:
			cout<<"姓名"<<endl;
			cin>>g[i].name;
			while(1){
			cout<<"性别（1为男 2为女）"<<endl;
			int s=0;
			cin>>s;
			if(s==1){
			    g[i].sex="男";
			    break;
			}
			else if(s==2){
				g[i].sex="女";
				break;//可以巧用三目运算符
			}
			else{
				cout<<"请重新输入"<<endl;
				continue;
			}
			}
			cout<<"电话"<<endl;
			cin>>g[i].num;
			cout<<"地址"<<endl;
			cin>>g[i].adr;
			cout<<"保存成功"<<endl;
			i++;
			break;
		case 2:
			for(int u=0;u<i;u++){
				cout<<g[u].name<<"   "<<g[u].sex<<"   "<<g[u].num<<"   "<<g[u].adr<<endl;
			}
			break;
		case 3:
			cout<<"请输入你想删除的联系人"<<endl;
			cin>>name1;
			for(int u=0;u<i;u++){
				if(name1==g[u].name){
					int b=u;
                    for(int u;u<9;u++){
						g[u]=g[u+1];
					}
					i--;
					break;
				}
			}
			cout<<"删除完成"<<endl;
			break;
		case 4:
			cout<<"请输入你想查找的联系人"<<endl;
			cin>>name2;
			for(int u=0;u<i;u++){
				if(name2==g[u].name){
				    cout<<g[u].name<<"   "<<g[u].sex<<"   "<<g[u].num<<"   "<<g[u].adr<<endl;
				    a=true;
				    break;
				}
			}
			if(a==true){
				break;
			}
			else{
				cout<<"查无此人"<<endl;
			}
			break;
		case 5:
			cout<<"请输入你想修改的联系人"<<endl;
			cin>>name3;
			for(int u=0;u<i;u++){
				if(name3==g[u].name){
					cout<<"姓名"<<endl;
					cin>>g[u].name;
					while(1){
					cout<<"性别（1为男 2为女）"<<endl;
					int s=0;
					cin>>s;
					if(s==1){
					    g[u].sex="男";
					    break;
					}
					else if(s==2){
					    g[u].sex="女";
					    break;
					}
					else{
						cout<<"请重新输入"<<endl;
						continue;
					}
								}
					cout<<"电话"<<endl;
					cin>>g[u].num;
					cout<<"地址"<<endl;
					cin>>g[u].adr;
					cout<<"保存成功"<<endl;			    
				}
			}		
			break;
		case 6:
            for(int u=0;u<i;u++){
				g[u]=em;
			i=0;
			}
			break;
		default:
			cout<<"重新输入"<<endl;
			break;
	}
	}
	system("pause");
	return 0;
}
