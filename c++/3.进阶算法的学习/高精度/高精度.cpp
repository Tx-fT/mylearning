#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 4010
using namespace std;
class hp{
public:
    int a[maxn];
    hp(){memset(a,0,sizeof(a));}
    void clear(){memset(a,0,sizeof(a));}
    hp(int x){
        clear();
        while(x){
            a[++a[0]]=x%10;
            x/=10;
        }
        while(a[a[0]]==0&&a[0])a[0]--;
    }
    hp& operator=(int x){
        clear();
        while(x){
            a[++a[0]]=x%10;
            x/=10;
        }
        while(a[a[0]]==0&&a[0])a[0]--;
        return *this;
    }

    short cmp(const hp& x){
        if(a[0]>x.a[0])return 1;
        if(a[0]<x.a[0])return -1;
        for(register int i=a[0];i>=1;i--){
            if(a[i]>x.a[i])return 1;
            if(a[i]<x.a[i])return -1;
        }
        return 0;
    }
    bool operator>(const hp& x){
        return cmp(x)==1;
    }
    bool operator==(const hp& x){
        return cmp(x)==0;
    }
    bool operator<(const hp& x){
        return cmp(x)==-1;
    }
    bool operator>=(const hp& x){
        return !(*this<x);
    }
    bool operator<=(const hp& x){
        return !(*this>x);
    }
    
    hp operator-(const hp& x){
        hp a=*this,c;
        c.a[0]=a.a[0]>x.a[0]?a.a[0]:x.a[0];
        for(register int i=1;i<=c.a[0];i++) {
            c.a[i]+=a.a[i]-x.a[i];
            if(c.a[i]<0){c.a[i]+=10;a.a[i+1]--;}
        }
        while(c.a[c.a[0]]==0&&c.a[0])c.a[0]--;
        return c;
    }
    hp operator*(const hp& x){
        hp c;
        for(register int i=1;i<=a[0];i++){
            for(register int j=1;j<=x.a[0];j++){ 
                c.a[i+j-1]+=a[i]*x.a[j];
            }
        }
        c.a[0]=a[0]+x.a[0];
        for(register int i=1;i<=c.a[0];i++){
            if(c.a[i]>=10){
                c.a[i+1]+=c.a[i]/10;
                c.a[i]%=10;
            }
        }
        while (c.a[c.a[0]]==0&&c.a[0]>0)c.a[0]--;
        return c;
    }
    hp operator/(const int& x){
        hp c;
        int t=0,s=0;
        bool flag=1;
        for(register int i=a[0];i>=1;i--){
            t=s*10+a[i];
            if(t/x>0||t==0){
                c.a[++c.a[0]]=t/x;
                s=t%x;
                flag=0;
            }
            else{
                s=t;
                if(!flag)c.a[++c.a[0]]=0;
            }
        }
        reverse(c.a+1,c.a+c.a[0]+1);
        return c;
    }
};
struct node{
    int a,b;
};
node a[1001];
bool cmp(node x,node y){
    return x.a*x.b<y.a*y.b;
}
void checkmax(hp& x,hp y){
	if(x<y) x=y;
}
int main(){
    int n;scanf("%d",&n);
    for(register int i=0;i<=n;i++){
        scanf("%d%d",&a[i].a,&a[i].b);
    }
    sort(a+1,a+n+1,cmp);
    hp ans=0,ji=a[0].a;
    for(register int i=1;i<=n;i++){
        checkmax(ans,ji/a[i].b);
        ji=ji*a[i].a;
	}
	if(ans.a[0]==0) putchar('0');
	else for(register int i=ans.a[0];i>=1;i--)
		putchar(ans.a[i]+'0');
	return 0;
}
