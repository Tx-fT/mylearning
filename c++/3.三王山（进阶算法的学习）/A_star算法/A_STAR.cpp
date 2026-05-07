#include<iostream>
using namespace std;
//f(x)=g(x)+h(x)  新代价=原点到现在+现在到目标
//取f(x)最小，若对其他点有更优g(x)则更新否则不更
//h(x)启发函数原则：***可低估但不可高估***<=真实的最短距离,找最优乐观估计直至目的出队（都乐观了还比不过现实）

//例：luogoP1379八数码难题IDA*枚举

int tm[4][4]={
	{0,0,0,0},
	{0,1,2,3},
	{0,8,0,4},
	{0,7,6,5}
};
int a[4][4];
int bx,by;
int sx[4]={-1,0,0,1};
int sy[4]={0,1,-1,0};
int hx(){
	int sum=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]!=tm[i][j]){
				sum++;
			}
		}
	}
	return sum;
}
bool j=false;
void solve(int k,int stp,int x,int y,int pre){
	if(j==true) return;
	if(stp==k){
		if(hx()==0){
		   j=true;
		   return;	
		}
		else return;
	}
	for(int i=0;i<4;i++){
		if(pre+i==3){
			continue;
		}
		int nx=x+sx[i];
		int ny=y+sy[i];
		if(nx<1 || nx>3 || ny<1 || ny>3) continue;
		swap(a[x][y],a[nx][ny]);
		if(hx()+stp<=k){
			solve(k,stp+1,nx,ny,i);
		}	
		swap(a[x][y],a[nx][ny]);
	}	
}
int main(){
	string n;
	cin>>n;
	for(int i=0;i<9;i++){
		int t=n[i]-'0';
		a[i/3+1][i%3+1]=t;
		if(t==0){
			bx=i/3+1;
			by=i%3+1;
		}	
	}
	int k=0;
	if(hx()==0){
		cout<<"0";
		return 0;
	}
	while(++k){
		solve(k,0,bx,by,-1);
		if(j){
			cout<<k;
			break;
		}
	}		
	return 0;
}











