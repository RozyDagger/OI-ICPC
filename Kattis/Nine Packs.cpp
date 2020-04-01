#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
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
#define MAXN 100001
#define INF 0x3f3f3f3f
#define INTMIN(a, b) ((a)+(((b)-(a))&((b)-(a))>>31))
int main() {
    int n, i, j, t;
    vector<int> vh(MAXN, INF), vb(MAXN, INF);
    vh[0]=vb[0]=0;
    readint(n);
    for(i=0;i<n;++i){
        readint(t);
        for(j=MAXN-t-1;j>=0;--j) if(vh[j]<vh[j+t]) vh[j+t]=vh[j]+1;
    }
    readint(n);
    for(i=0;i<n;++i){
        readint(t);
        for(j=MAXN-t-1;j>=0;--j) if(vb[j]<vb[j+t]) vb[j+t]=vb[j]+1;
    }
    n=INF;
    for(i=1;i<MAXN;++i) n=INTMIN(vh[i]+vb[i], n);
    if(n>=INF>>1) printf("impossible");
    else writeint(n);
}
