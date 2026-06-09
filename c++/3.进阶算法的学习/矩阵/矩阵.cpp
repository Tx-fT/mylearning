////矩阵加快速幂，因为矩阵可以求一般公式叠加
//#include<iostream>
//#include<cstring>
//#define int long long
//using namespace std;
//const int mod=1000000007;
//
//class matrix{
//public:
//    int a[3][3];
//    matrix(){
//        memset(a,0,sizeof(a));
//    }
//    
//    matrix operator *(const matrix& b) const{
//        matrix c;
//        for(int i=1;i<=2;i++){
//            for(int j=1;j<=2;j++){
//                for(int k=1;k<=2;k++){
//                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
//                }
//            }
//        }
//        return c;
//    }
//}ans,q;
//
//void init(){
//    ans.a[1][1] = 1;
//    ans.a[1][2] = 1;
//    
//    q.a[1][1] = 1;
//    q.a[1][2] = 1;
//    q.a[2][1] = 1;
//    q.a[2][2] = 0;
//}
//
//void qpow(int n){
//    while(n){
//        if(n & 1){
//            ans = ans * q;
//        }
//        q = q * q;
//        n >>= 1;
//    }
//}
//signed main(){
//    int n;
//    cin>>n;
//    
//    if(n <= 2){
//        cout << 1 << endl;
//    }
//    else{
//        init();
//        qpow(n-2);
//        cout << ans.a[1][1] % mod << endl;
//    }
//    return 0;
//}
//指数取模(mod-1)
#include <iostream>
#include<cstring>
using namespace std;
const long long mod=998244353;
const long long M=mod-1;
class matrix{
public:
  long long m[3][3];
  matrix(){
    memset(m,0,sizeof(m));
  }
};
matrix operator*(const matrix &a,const matrix &b){
	matrix c;
	for(int i=1;i<=2;i++){
	  for(int j=1;j<=2;j++){
	    for(int k=1;k<=2;k++){
	      c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%M;
	    }
	  }
	}
	return c;
} 
matrix w,v;
void init(){
    v.m[1][2] = 0;
    v.m[2][2] = 1;
    w.m[1][1] = 0;
    w.m[1][2] = 1;
    w.m[2][1] = 1;
    w.m[2][2] = 1;
}
void qpow(long long x){
  while(x){
    if(x&1){
      v=w*v;
    }
    w=w*w;
    x>>=1;
  } 
}
long long qpow1(long long x,int b){
  long long res=1;
  while(x){
    if(x&1){
      res=(res*b)%mod;
    }
    b=(b*b)%mod;
    x>>=1;
  }
  return res;
}
int main()
{/*
2
3
2 3
2 3 3
2 2 3 3 3
2 2 2 3 3 3 3 3 
*/
  long long n;
  cin>>n;
  if (n == 1) {
      cout << 2 << endl;
      return 0;
  }
  init();
  qpow(n);
  cout<<(qpow1(v.m[1][2],2)*qpow1(v.m[2][2]-1,3))%mod;
  return 0;
}
