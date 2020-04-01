#include <bits/stdc++.h>
using namespace std;
#define M10(a) (((a)<<3)+((a)<<1))
inline int readint(){
    char c=getchar_unlocked();
    int x=0;
    for(;c<48||c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=M10(x)+c-48;
    return x;
}
inline void writeint(int x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    if(x<0){
        putchar_unlocked('-');
        x=~x+1;
    }
    int n=x, t=n, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
#define MAXN 10001
#define ABS(a) (((a)+((a)>>31))^((a)>>31))
struct node{
    int cnt;
    vector<int> V;
};
node T[MAXN];
int rst, vs[MAXN];
inline int dfs(int i){
    int cnt=0, j=0;
    for(vs[i]=1;j<T[i].V.size();++j)
        if(!vs[T[i].V[j]]){
            cnt+=dfs(T[i].V[j]);
            T[i].cnt+=T[T[i].V[j]].cnt;
        }
    rst+=ABS(T[i].cnt-cnt-1);
    return cnt+1;
}
int main() {
    int n, v, m, d, vtx, i, j;
    for(;n=readint();putchar_unlocked('\n')){
        memset(vs, 0, sizeof vs);
        for(i=1;i<=n;++i) T[i].V.clear();
        for(i=1;i<=n;++i){
            v=readint();
            m=readint();
            d=readint();
            for(T[v].cnt=m;d--;){
                vtx=readint();
                T[v].V.push_back(vtx);
                T[vtx].V.push_back(v);
            }
        }
        rst=0;
        dfs(1);
        writeint(rst);
    }
}
