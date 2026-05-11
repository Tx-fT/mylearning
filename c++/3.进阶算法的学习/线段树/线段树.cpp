#include<iostream>
using namespace std;
typedef long long LL;  

int n,m;
LL a[4*100005];      
LL h[100005];    
LL lzy[4*100005];  

void pushup(int idx){
    a[idx]=a[2*idx]+a[2*idx+1];
}

void build(int l,int r,int idx){
    if(l==r){
        a[idx]=h[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*idx);
    build(m+1,r,2*idx+1);
    pushup(idx);
}

bool inrange(int l1,int r1,int l,int r){
    if(l1<=l&&r1>=r){
        return true;
    }
    return false;
}

bool outrange(int l1,int r1,int l,int r){
    return r<l1||l>r1;
}

void maketag(int idx,int len,LL x){
    lzy[idx]+=x;
    a[idx]+=len*x;
}

void pushdown(int idx,int l,int r){
    if(lzy[idx] != 0){ 
        int m=(l+r)/2;
        int len1=m-l+1;
        int len2=r-m;
        maketag(2*idx,len1,lzy[idx]);
        maketag(2*idx+1,len2,lzy[idx]);
        lzy[idx]=0;
    }
}

LL query2(int l1,int r1,int l,int r,int idx){
    if(inrange(l1,r1,l,r)){
        return a[idx];
    }
    else if(!outrange(l1,r1,l,r)){
        int m=(l+r)/2;
        pushdown(idx,l,r);
        return query2(l1,r1,l,m,2*idx)+query2(l1,r1,m+1,r,2*idx+1);
    }
    else return 0;
}

void update1(int l1,int r1,int l,int r,LL x,int idx){ 
    if(inrange(l1,r1,l,r)){
        maketag(idx,r-l+1,x);
        return;
    }
    else if(!outrange(l1,r1,l,r)){
        int m=(l+r)/2;
        pushdown(idx,l,r);
        update1(l1,r1,l,m,x,2*idx);
        update1(l1,r1,m+1,r,x,2*idx+1);
        pushup(idx);
    }
    else return;    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    build(1,n,1);
    
    int ch;
    for(int i=0;i<m;i++){
        cin>>ch;
        if(ch==1){
            int l1,r1;
            LL num;           
            cin>>l1>>r1>>num;
            update1(l1,r1,1,n,num,1);
        }
        else{
            int l1,r1;
            cin>>l1>>r1;
            cout<<query2(l1,r1,1,n,1)<<endl;
        }
    }
    return 0;
}
