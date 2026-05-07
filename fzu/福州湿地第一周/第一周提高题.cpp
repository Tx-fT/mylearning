#include<iostream>
using namespace std;
int main(){
//	int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    int arr[10];
	cout<<"ÇëÊäÈë10¸öÊı"<<endl;
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
