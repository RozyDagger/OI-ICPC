#include <stdio.h>
#define MAXN 2005
#define INTMAX(a, b) ((b)-(((b)-(a))&((b)-(a))>>31))
inline int readint(){
    int x=0;
    char c=getchar_unlocked();
    for(;c<48||c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
    return x;
}
inline void writeint(int x){
    int n=x, t=n, cnt=0;
    if(!n){
        putchar_unlocked('0');
        return;
    }
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
int main(){
    int n, i, j, dp1[MAXN], dp2[MAXN], V[MAXN], rst=0;
    n=readint();
    for(i=0;i<n;++i) V[i]=readint();
    for(i=n-1;i>=0;--i){
        dp1[i]=dp2[i]=1;
        for(j=n-1;j>i;--j){
            if(V[i]<V[j]) dp1[i]=INTMAX(dp1[i], dp1[j]+1);
            if(V[i]>V[j]) dp2[i]=INTMAX(dp2[i], dp2[j]+1);
        }
        rst=INTMAX(rst, dp1[i]+dp2[i]-1);
    }
    writeint(rst);
    putchar_unlocked('\n');
}
