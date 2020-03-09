/*
    Many things can be improved:
        * calculation process can be optimzed in getP()
        * no need for cnt
        * fast io
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int n, cnt=1, A, P, dr[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> G;
inline int getP(int x, int y){
    int rst=0;
    rst+=((!x)||(x>0&&G[x-1][y]=='.'));
    rst+=((x==n-1)||(x<n-1&&G[x+1][y]=='.'));
    rst+=((!y)||(y>0&&G[x][y-1]=='.'));
    rst+=((y==n-1)||(y<n-1&&G[x][y+1]=='.'));
    return rst;
}
void dfs(vector<string> &G, int x, int y, int idx){
    if(x<0||y<0||x>=n||y>=n||G[x][y]!='#') return;
    ++A;
    P+=getP(x, y);
    G[x][y]=idx;
    for(int i=0;i<4;++i) dfs(G, x+dr[i][0], y+dr[i][1], idx);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int rst=0, buf=INF;
    cin>>n;
    G.resize(n);
    for(int i=0;i<n;cin>>G[i++]);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(G[i][j]=='#'){
                A=P=0;
                dfs(G, i, j, cnt);
                if(rst<A){
                    rst=A;
                    buf=P;
                }else if((rst==A)&(buf>P)) buf=P;
                ++cnt;
            }
    cout<<rst<<" "<<buf;
}
