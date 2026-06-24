#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

// fast pow
long long qpow(long long a,long long b){
    long long r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return r;
}

void solve(){
    int n,d;
    cin>>n>>d;

    // d=1: any subset works, answer = 2^(2n)
    if(d==1){
        cout<<qpow(2,2ll*n)<<'\n';
        return;
    }

    // number of states: 2d-1
    // state encoding:
    //   0: empty (no black cell in last d-1 cols)
    //   1..d-1: row-0 black at position (s-1), meaning column cur-(s-1)-1 = cur-s
    //   d..2d-2: row-1 black at position (s-d)
    int S=2*d-1;
    vector<long long> dp(S,0);
    dp[0]=1;  // before first column: empty window

    int fullMask=(1<<(d-1))-1;      // mask for d-1 bits
    int crossMask=(1<<max(0,d-2))-1; // mask for cross-row check (d-2 bits)

    for(int col=0;col<n;col++){
        vector<long long> ndp(S,0);
        for(int s=0;s<S;s++){
            long long cur=dp[s];
            if(!cur) continue;

            // decode state into two bitmasks
            int m0=0,m1=0;
            if(s!=0){
                if(s<d) m0=1<<(s-1);
                else    m1=1<<(s-d);
            }

            // try 3 column configs: 0=empty, 1=row0 black, 2=row1 black
            for(int c=0;c<3;c++){
                // ---- validity checks ----
                if(c==1){  // place black in row 0
                    if(m0) continue;                    // same-row too close
                    if(m1 & crossMask) continue;        // cross-row too close
                }
                if(c==2){  // place black in row 1
                    if(m1) continue;
                    if(m0 & crossMask) continue;
                }

                // ---- compute new masks ----
                int nm0=((m0<<1)|(c==1)) & fullMask;
                int nm1=((m1<<1)|(c==2)) & fullMask;

                // ---- encode new state ----
                int ns;
                if(nm0==0 && nm1==0) ns=0;
                else if(nm1==0)       ns=__builtin_ctz(nm0)+1;
                else                  ns=__builtin_ctz(nm1)+d;

                ndp[ns]=(ndp[ns]+cur)%MOD;
            }
        }
        dp.swap(ndp);
    }

    long long ans=0;
    for(long long x:dp) ans=(ans+x)%MOD;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
}