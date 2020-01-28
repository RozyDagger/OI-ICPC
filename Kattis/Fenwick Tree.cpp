#include <stdio.h>
#define LL long long
#define MAXN 5000001
inline void readint(int &x){
    char c=getchar_unlocked();
    x=0;
    for(;c<48||c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
}
inline void readll(LL &x){
    char c=getchar_unlocked();
    x=0;
    bool ng=0;
    for(;(c<48||c>57)&&c!='-';c=getchar_unlocked());
    if(c=='-'){
        ng=1;
        c=getchar_unlocked();
    }
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
    if(ng) x=-x;
}
inline void write(LL x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    if(x<0){
        putchar_unlocked('-');
        x=~x+1;
    }
    LL n=x, t=n;
    int cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
int main(){
    int n, q, x;
    char c;
    LL t;
    LL V[MAXN]={0};
    readint(n);
    for(readint(q);q--;putchar_unlocked('\n')){
        c=getchar_unlocked();
        if(c!='+'&&c!='?') c=getchar_unlocked();
        if(c=='+'){
            readint(x);
            readll(t);
            for(++x;x<=n;x+=x&-x) V[x]+=t;
        }else{
            readint(x);
            if(!x) putchar_unlocked('0');
            else{
                t=0;
                for(;x;x-=x&-x) t+=V[x];
                write(t);
            }
        }
    }
}
