#include <stdio.h>
#include <string.h>
inline void readint(int &x){
    int c=getchar_unlocked();
    x=0;
    for(;c<48|c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
}
inline void writeint(int x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    int n=x, t=n, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
#define INF 0x3f3f3f3f
#define MAXN 10000
int main(){
    int T, n, t, i, j, V[101], dp[MAXN];
    for(readint(T);T--;){
        readint(t);
        readint(n);
        for(i=0;i<n;++i) readint(V[i]);
        memset(dp, INF, MAXN*sizeof(int));
        for(i=dp[0]=0;i<n;++i) for(j=MAXN-1;j>=0;--j) if((j-V[i]>=0)&&(dp[j-V[i]]+1<dp[j])) dp[j]=dp[j-V[i]]+1;
        for(i=t;dp[i]==INF;++i);
        writeint(i);
        putchar_unlocked(' ');
        writeint(dp[i]);
        putchar_unlocked('\n');
    }
}
