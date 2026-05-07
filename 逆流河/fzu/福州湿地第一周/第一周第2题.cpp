#include<iostream>
using namespace std;
int main(){
	int a,b,c=0;
	cin>>a>>b>>c;
	int count=0;
	for(int x=0;a*x<=c;x++){
		if((c-a*x)%b==0){
			count++;
		}
	}
	cout<<count<<endl;
	system("pause");
	return 0;

}
