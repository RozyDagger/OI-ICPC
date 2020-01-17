#include <stdio.h>
#define M10(a) (((a)<<3)+((a)<<1))
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
inline void readstr(char *x){
    char c=getchar_unlocked();
    short i=0;
    for(;c<97||c>122;c=getchar_unlocked());
    for(;c>96&&c<123;c=getchar_unlocked()) x[i++]=c;
}
inline void writeint(int x){
    int n=x, t=n, cnt=0;
    if(!n){
        putchar_unlocked('0');
        return;
    }
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=M10(t)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
