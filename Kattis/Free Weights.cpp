#include <stdio.h>
inline int readint(){
    int c=getchar_unlocked(), x=0;
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
#define INTMAX(a, b) ((b)-(((b)-(a))&((b)-(a))>>31))
#define MAXN 1000005
#define INF 0x3f3f3f3f
int n, w1[MAXN], w2[MAXN], s[MAXN];
inline bool run(int m){
    int sz=0, i;
    for(i=0;i<n;++i)
        if(w1[i]>m){
            if(!sz) s[sz++]=w1[i];
            else if(sz&&s[sz-1]==w1[i]) --sz;
            else return 0;
        }
    if(sz) return 0;
    for(i=0;i<n;++i)
        if(w2[i]>m){
            if(!sz) s[sz++]=w2[i];
            else if(sz&&s[sz-1]==w2[i]) --sz;
            else return 0;
        }
    return !sz;
}
int main(){
    n=readint();
    int maxn=0, l=0, r, rst=INF, m;
    for(int i=0;i<n;++i){
        w1[i]=readint();
        maxn=INTMAX(maxn, w1[i]);
    }
    for(int i=0;i<n;++i){
        w2[i]=readint();
        maxn=INTMAX(maxn, w2[i]);
    }
    r=maxn;
    for(m=l+r>>1;l<=r;m=l+r>>1)
        if(run(m)){
            rst=m;
            r=m-1;
        }else l=m+1;
    writeint(rst);
    putchar_unlocked('\n');
}
