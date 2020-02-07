#include <stdio.h>
inline int readint(int &x){
    int c=getchar_unlocked();
    for(x=0;c<48||c>57;c=getchar_unlocked());
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
#define MAXN 5002
#define EPS 1e-6
int main(){
    int a, d, ih, it, i;
    double l, r, m, tt, th, d1, d2, t, V1[MAXN][2], V2[MAXN][2];
    readint(a);
    readint(d);
    for(i=1;i<=a;++i){
        readint(ih);
        readint(it);
        V1[i][0]=ih;
        V1[i][1]=it;
        tt+=it;
        th+=ih;
    }
    for(i=1;i<=d;++i){
        readint(ih);
        readint(it);
        V2[i][0]=ih;
        V2[i][1]=it;
    }
    r=tt;
    l=0;
    while(r-l>=EPS){
        m=l+(r-l)/2;
        d1=0;
        t=m;
        for(i=1;i<=a&&t>=V1[i][1];++i){
            d1+=V1[i][0];
            t-=V1[i][1];
        }
        d1+=(double)t*V1[i][0]/V1[i][1];
        d2=th;
        t=m;
        for(i=1;i<=d&&t>=V2[i][1];++i){
            d2-=V2[i][0];
            t-=V2[i][1];
        }
        d2-=(double)t*V2[i][0]/V2[i][1];
        if(d2-d1>0) l=m;
        else r=m;
    }
    printf("%lf\n", m);
}
