#include <stdio.h>
#define INTEMAX(a, b) ((a)^((a)^(b))&-((a)<(b)))
#define INTEMIN(a, b) ((b)^((a)^(b))&-((a)<(b)))
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
int main(){
    int T, m, n, l, r, t, tl, tr;
    for(readint(T);T--;printf("%d %d\n", l, r)){
        readint(m);
        readint(n);
        for(l=r=0;n--;){
            readint(t);
            tl=INTEMIN(t, m-t);
            tr=INTEMAX(t, m-t);
            l=INTEMAX(l, tl);
            r=INTEMAX(r, tr);
        }
    }
}
