#include <string.h>
#include <stdio.h>
#define LL long long
#define MAXN 2001
#define INF 0x3f3f3f3f
#define M10(a) (((a)<<3)+((a)<<1))
#define INTEMAX(a, b) ((a)^((a)^(b))&-((a)<(b)))
#define INTEMIN(a, b) ((b)^((a)^(b))&-((a)<(b)))
inline void readint(int &x){
    int c=getchar_unlocked();
    x=0;
    bool ng=0;
    for(;(c<48||c>57)&&c!='-';c=getchar_unlocked());
    if(c=='-'){
        ng=1;
        c=getchar_unlocked();
    }
    for(;c>47&&c<58;c=getchar_unlocked()) x=M10(x)+c-48;
    if(ng) x=-x;
}
inline int R(int a){
    int t=a%10;
    return t>=5?a-t+10:a-t;
}
int main(){
    int i, j, n, d, V[MAXN], dp[MAXN][21], rst=INF, l, r;
    readint(n);
    readint(d);
    for(i=0;i<n;++i) readint(V[i]);
    memset(dp, INF, sizeof dp);
    for(i=0;i<=d;++i) dp[0][i]=0;
    for(i=1;i<=n;++i) dp[i][0]=dp[i-1][0]+V[i-1];
    for(i=1;i<=n;++i)
        for(j=d;j;--j){
            l=dp[i-1][j]+V[i-1];
            r=R(dp[i-1][j-1]+V[i-1]);
            dp[i][j]=INTEMIN(l, r);
        }
    for(i=0;i<=d;++i){
        r=R(dp[n][i]);
        rst=INTEMIN(rst, r);
    }
    printf("%d\n", rst);//just 1 number, too lazy to use writeint()
}
