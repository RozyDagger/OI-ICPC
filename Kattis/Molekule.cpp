#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
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
int main(){
    int n, de, t, i=0, rst[MAXN], se[MAXN];
    vector<int> G[MAXN];
    queue<int> Q({1});
    memset(rst, -1, sizeof rst);
    for(readint(n);i<n-1;++i){
        readint(se[i]);
        readint(de);
        G[se[i]].push_back(de);
        G[de].push_back(se[i]);
    }
    for(rst[1]=0;!Q.empty();Q.pop()){
        t=Q.front();
        for(i=0;i<G[t].size();++i){
            if(rst[G[t][i]]!=-1) continue;
            rst[G[t][i]]=1-rst[t];
            Q.push(G[t][i]);
        }
    }
    for(i=0;i<n-1;++i){
        writeint(rst[se[i]]);
        putchar_unlocked('\n');
    }
}
