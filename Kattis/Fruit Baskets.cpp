#include <stdlib.h>
#include <stdio.h>
#define M10(a) (((a)<<3)+((a)<<1))
#define INTMAX(a, b) ((b)&(((a)-(b))>>31)|(a)&~(((a)-(b))>>31))
#define LL long long
#define MAXN 41
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
LL LV[MAXN], rst, t;
int n, V[MAXN], i, j, k;
int main(){
    LV[0]=1;
    for(i=1;i<=40;++i) LV[i]=LV[i-1]<<1;
    readint(n);
    for(i=0;i<n;++i){
        readint(V[i]);
        rst+=V[i]*LV[n-1];
    }
    for(i=0;i<n;++i){
        t=V[i];
        if(t<200) rst-=t;
        for(j=i+1;j<n;++j){
            t=V[i]+V[j];
            if(t<200) rst-=t;
            for(k=j+1;k<n;++k){
                t=V[i]+V[j]+V[k];
                if(t<200) rst-=t;
            }
        }
    }
    printf("%lld\n", rst);
}
