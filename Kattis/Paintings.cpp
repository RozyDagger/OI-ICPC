#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
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
int n, cnt, ind[MAXN], loc[MAXN], icnt=0, lcnt=0;
bool vs[13], G[13][13];
char VS[12][21], s1[21], s2[21];
void dfs(){
    if(lcnt==n){
        if(!icnt) for(int i=0;i<lcnt;++i) ind[icnt++]=loc[i];
        ++cnt;
        return;
    }
    for(int i=0;i<n;++i)
        if(!vs[i]){
            if(lcnt&&!G[loc[lcnt-1]][i]) continue;
            vs[i]=1;
            loc[lcnt++]=i;
            dfs();
            vs[i]=0;
            --lcnt;
        }
}
int main(){
    int T, t;
    for(readint(T);T--;cnt=icnt=lcnt=0){
        readint(n);
        memset(vs, 0, sizeof vs);
        memset(VS, 0, sizeof VS);
        memset(G, 1, sizeof G);
        unordered_map<string, int> mp;
        for(int i=0;i<n;++i){
            scanf("%s", s1);
            mp[string(s1)]=i;
            memcpy(VS[i], s1, 21);
        }
        readint(t);
        for(int i=0;i<t;++i){
            memset(s1, 0, 21);
            memset(s2, 0, 21);
            scanf("%s %s", s1, s2);
            string ss1=string(s1), ss2=string(s2);
            G[mp[ss1]][mp[ss2]]=G[mp[ss2]][mp[ss1]]=0;
        }
        dfs();
        writeint(cnt);
        putchar_unlocked('\n');
        for(int i=0;i<icnt;++i) printf("%s ", VS[ind[i]]);
        putchar_unlocked('\n');
    }
}
