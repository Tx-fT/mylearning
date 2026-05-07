#include<iostream>
using namespace std;
string s1,s2;
int b[1000010];
int main(){
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size();
	int j=0;
	for(int i=1;i<l2;++i){
		while(j&&s2[i]!=s2[j]){
			j=b[j-1];
		}
		if(s2[i]==s2[j]){
			j++;
		}
		b[i]=j;
	}
	j=0;
	for(int i=0;i<l1;++i){
		while(j&&s1[i]!=s2[j]){
			j=b[j-1];
		}
		if(s1[i]==s2[j]){
			j++;
		}
		if(j==l2){
			cout<<i+2-j<<endl;
			j=b[j-1];
		}
	}
	for(int i=0;i<l2;i++){
		if(i){
			cout<<" ";
		}
		cout<<b[i];
	}
	return 0;
}
