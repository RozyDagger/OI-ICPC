//Shortest distance between a pair of x and y in a 2D array.
#include <bits/stdc++.h>
using namespace std;
int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
uct node{
    int x, y;
    node(int a, int b):x(a), y(b){}
};
int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}}, n, m, d;
bool f;
queue<node> q;
int BFS(vector<vector<int>>& G) {
    if(!G.size()||!G[0].size()) return 0;
    n=G.size(), m=G[0].size();
    for(int i=0;i<n&&!f;++i) 
        for(int j=0;j<m&&!f;++j) 
            if(G[i][j]){
                dfs(G, i, j);
                f=1;
            }
    for(;!q.empty();++d){
        for(int i=q.size();i--;){
            node tn=q.front(); q.pop();
            for(int j=0;j<4;++j){
                int ti=tn.x+dr[j][0], tj=tn.y+dr[j][1];
                if(ti<0||ti>=n||tj<0||tj>=m||G[ti][tj]==2) continue;
                if(G[ti][tj]==1) return d;
                G[ti][tj]=2;
                q.push(node(ti, tj));
            }
        }
    }
    return -1;
}
void dfs(vector<vector<int>> &G, int i, int j){
    G[i][j]=2;
    q.push(node(i, j));
    for(int k=0;k<4;++k){
        int ti=i+dr[k][0], tj=j+dr[k][1];
        if(ti>=0&&ti<n&&tj>=0&&tj<m&&G[ti][tj]==1) dfs(G, ti, tj);
    }
}
int main(){
    vector<vector<char>> G;
    G.push_back({'x','x','0','0','0'});
    G.push_back({'x','x','0','0','0'});
    G.push_back({'0','0','0','y','y'});
    //cout<<BFS(G);
}
