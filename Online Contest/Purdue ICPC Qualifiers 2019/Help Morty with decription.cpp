#include <bits/stdc++.h>
using namespace std;
int n, cnt, flag=1;
string s;
int main(){
    cin>>n;
    vector<vector<char>> G(n, vector<char>(n)), rst(n, vector<char>(n, 'Z'));;
    for(int i=0;i<n;++i) for(int j=0;j<n;cin>>G[i][j++]);
    cin>>s;
    for(int rd=0;rd<4;++rd){
        for(int i=0;i<n&&flag;++i)
            for(int j=0;j<n&&flag;++j)
                if(G[i][j]=='.'){
                    if(cnt<n*n&&rst[i][j]=='Z') rst[i][j]=s[cnt++];
                    else flag=0;
                }
        vector<vector<char>> T(n, vector<char>(n));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                T[j][n-1-i]=G[i][j];
        G=T;
    }
    for(int i=0;i<n&&flag;++i) for(int j=0;j<n&&flag;++j) flag=(rst[i][j]!='Z');
    if(!flag) cout<<"invalid grille";
    else for(int i=0;i<n;++i) for(int j=0;j<n;cout<<rst[i][j++]);
}
