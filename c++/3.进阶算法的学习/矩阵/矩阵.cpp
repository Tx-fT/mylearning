//矩阵加快速幂，因为矩阵可以求一般公式叠加
#include<iostream>
#include<cstring>
#define int long long
using namespace std;
const int mod=1000000007;

class matrix{
public:
    int a[3][3];
    matrix(){
        memset(a,0,sizeof(a));
    }
    
    matrix operator *(const matrix& b) const{
        matrix c;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
    }
}ans,q;

void init(){
    ans.a[1][1] = 1;
    ans.a[1][2] = 1;
    
    q.a[1][1] = 1;
    q.a[1][2] = 1;
    q.a[2][1] = 1;
    q.a[2][2] = 0;
}

void qpow(int n){
    while(n){
        if(n & 1){
            ans = ans * q;
        }
        q = q * q;
        n >>= 1;
    }
}

signed main(){
    int n;
    cin>>n;
    
    if(n <= 2){
        cout << 1 << endl;
    }
    else{
        init();
        qpow(n-2);
        cout << ans.a[1][1] % mod << endl;
    }
    return 0;
}
