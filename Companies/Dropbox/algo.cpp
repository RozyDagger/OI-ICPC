#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 256
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define LEFT(a) ((a)*2+1)
#define RIGHT(a) ((a)*2+2)
#define PARENT(a) (((a)-1)/2)

typedef struct Point{ int x, y; Point(int a, int b):x(a), y(b){} }Point;    //For Number_of_Islands_II
typedef struct Node{ int st, en; Node(int a, int b):st(a), en(b){} }Node;    //For Download_File
struct cmpN{ bool operator()(Node a, Node b) const { return a.st<b.st; } };  //For Download_File priority queue
struct cmpV{ bool operator()(vector<int> a, vector<int> b) const { return a[0]<b[0]; } };    //For Download_File red black tree
bool cmp(Node a, Node b){ return (a.st<b.st); }    //For Download_File Vector

int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1}, dir[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Algo{
public:
    //Highest Sharpness; 2d Array Path; Sharpness Values
    //Time: O(m*n); Space: O(m*n)
    int Sharpness_2D_Array(vector<vector<int>> G){
        vector<vector<int>> dp(G);
        for(int j=1;j<G[0].size();++j)
            for(int i=0;i<G.size();++i){
                int t=dp[i][j-1];
                if(i>0) t=MAX(t, dp[i-1][j-1]);
                if(i<G[0].size()-1) t=MAX(t, dp[i+1][j-1]);
                dp[i][j]=MIN(t, dp[i][j]);
            }
        int rst=-INF;
        for(int i=0;i<dp[0].size();++i) rst=MAX(rst, dp[i][dp.size()-1]);
        return rst;
    }
    
    //Buy Soda; Unbounded Knapsack
    //Time: O(k*n); Space: O(k)
    int Coin_Change_DP(int k, vector<int> V){
        vector<int> dp(k+1, k+1);
        dp[0]=0;
        for(int i=1;i<=k;++i)
            for(int j=0;j<V.size();++j)
                if(i>=V[j]) dp[i]=MIN(dp[i], dp[i-V[j]]+1);
        return dp[k]>k?-1:dp[k];
    }
    //Time: O(k^n); Space: O(n)
    int Coin_Change_DFS(int k, vector<int> V){
        vector<int> mem(k+1, INF);
        mem[0]=0;
        return ccd_dfs(V, k, mem);
    }
    int ccd_dfs(vector<int> &V, int k, vector<int> &mem){
        if(k<0) return -1;
        if(mem[k]!=INF) return mem[k];
        for(int i=0;i<V.size();++i){
            int t=ccd_dfs(V, k-V[i], mem);
            if(t>=0) mem[k]=MIN(mem[k], t+1);
        }
        return mem[k]=(mem[k]==INF)?-1:mem[k];
    }
    
    //Game of Life
    //Time: O(n*m); Space: O(m*n)
    void Game_of_Life_Omn(vector<vector<int>>& G) {
        int m=G.size(), n=G[0].size();
        vector<vector<int>> rst(m, vector<int>(n, 0));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                int cnt=0;
                for(int k=0;k<8;++k){
                    int x=i+dx[k], y=j+dy[k];
                    if(x>=0&&x<m&&y>=0&&y<n&&G[x][y]) ++cnt;
                }
                if(G[i][j]&&(cnt==2||cnt==3)) rst[i][j]=1;
                if(!G[i][j]&&cnt==3) rst[i][j]=1;
            }
        G=rst;
    }
    //Time: O(n*m); Space: O(1)
    void Game_of_Life_O1(vector<vector<int>>& G) {
        int m=G.size(), n=G[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
                int st=0;
                for(int y=MAX(i-1, 0);y<=MIN(i+1, m-1);++y)
                    for(int x=MAX(j-1, 0);x<=MIN(j+1, n-1);++x) st+=G[y][x]&1;
                if(st==3||st-G[i][j]==3) G[i][j]|=2;
            }
        for(int i=0;i<m;++i) for(int j=0;j<n;G[i][j++]>>=1);
    }

    //Word Pattern
    //Time: O(n); Space: O(n)
    bool Word_Pattern_with_Space(string p, string s){
        unordered_map<char, int> ci;
        unordered_map<string, int> si;
        stringstream ss(s);
        int cnt=0;
        for(string t;ss>>t;++cnt){
            if(cnt==p.size()||ci[p[cnt]]!=si[t]) return 0;
            ci[p[cnt]]=si[t]=cnt+1; //Note that +1 is to avoid c++ umap default 0 value.
        }
        return cnt==p.size();
    }
    
    //Word Pattern II; Word Pattern no Space
    //Time: O(n); Space: O(n)
    bool Word_Pattern_no_Space(string p, string s){
        unordered_map<char, string> mp;
        set<string> st;
        return wdns_dfs(p, 0, s, 0, mp, st);
    }
    bool wdns_dfs(string p, int i, string s, int j, unordered_map<char, string> &mp, set<string> &st){
        if(i==p.size()&&j==s.size()) return 1;
        if(i==p.size()||j==s.size()) return 0;
        char c=p[i];
        for(int k=j;k<s.size();++k){
            string ts=s.substr(j, k-j+1);
            if(mp.find(c)!=mp.end()&&mp[c]==ts){ if(wdns_dfs(p, i+1, s, k+1, mp, st)) return 1; }
            else if(mp.find(c)==mp.end()){
                if(st.find(ts)!=st.end()) continue;
                mp[c]=ts;
                st.insert(ts);
                if(wdns_dfs(p, i+1, s, k+1, mp, st)) return 1;
                mp.erase(c);
                st.erase(ts);
            }
        }
        return 0;
    }
        
    //Phone Number with Dictionary; Letter Combination of Phone Number
    //Time: O(4^n); Space: O(dict.size()+n)
    string pndk[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> Phone_Number_Dict(string s, unordered_set<string> st){
        if(!s.size()) return {};
        vector<string> rst;
        string buf="";
        pnd_dfs(rst, buf, s, 0, st);
        return rst;
    }
    void pnd_dfs(vector<string> &rst, string buf, string &s, int i, unordered_set<string> &st){
        if(i==s.size()&&st.find(buf)!=st.end()){
            rst.push_back(buf);
            return;
        }
        for(int j=0;j<pndk[s[i]-'0'].size();++j) pnd_dfs(rst, buf+pndk[s[i]-'0'][j], s, i+1, st);
    }
    //Time: O(4^n); Space: O(trie.size()+n)
    //TODO: Traverse the trie during the search to prun unncessary search.
    vector<string> Phone_Number_Trie(string s, unordered_set<string> st){
        return {};
    }
    
    //Word Break
    //Time: O(n^2+k); Space: O(n+k*dict_word.size()); n: s.size(), k: v.size()
    bool Word_Break(string s, vector<string> v){
        unordered_set<string> st(v.begin(), v.end());
        int n=s.size();
        bool dp[n+1]={0};
        dp[0]=1;
        for(int i=0;i<=n;++i)
            for(int j=0;j<i;++j)
                if(dp[j]&&st.find(s.substr(j, i-j))!=st.end()){
                    dp[i]=1;
                    break;
                }
        return dp[n];
    }
    
    //Word Break II
    //Time: O(n^2+k); Space: O(n^2+k*dict_word.size())
    unordered_map<string, vector<string>> wbiimp;
    vector<string> Word_Break_II(string s, vector<string> &v){
        if(wbiimp.find(s)!=wbiimp.end()) return wbiimp[s];
        if(!s.size()) return {""};
        vector<string> rst;
        for(string ts:v){
            if(s.substr(0, ts.size())!=ts) continue;
            vector<string> t=Word_Break_II(s.substr(ts.size()), v);
            for(string tts:t) rst.push_back(ts+(tts.size()?" ":"")+tts);
        }
        return wbiimp[s]=rst;
    }
    
    //Number of Islands
    //Time: O(n*m); Space: O(1)
    int Number_of_Islands(vector<vector<char>>& G) {
        int rst=0, n, m;
        if(!G.size()||!G[0].size()) return 0;
        n=G.size(), m=G[0].size();
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(G[i][j]=='1') nof_dfs(i, j, G, n, m), ++rst;
        return rst;
    }
    void nof_dfs(int i, int j, vector<vector<char>> &G, int &n, int &m){
        if(i<0||j<0||i>=n||j>=m||G[i][j]-'1') return;
        G[i][j]='@';
        for(int k=0;k<4;++k) nof_dfs(i+dx[k], j+dy[k], G, n, m);
    }
    
    //Number of Islands II
    //Time: O(V.size()); Space: O(n*m)
    int noisii_find(int x, vector<int> &f){
        if(f[x]==x) return x;
        return f[x]=noisii_find(f[x], f);
    }
    bool noisii_merge(int x, int y, vector<int> &f){
        if(f[x]==-1||y==-1) return 0;
        x=noisii_find(x, f), y=noisii_find(y, f);
        if(x!=y){
            f[x]=y;
            return 1;
        }else return 0;
    }
    bool noisii_val(int &x, int &y, int &n, int &m){ return (x>=0&&y>=0&&x<n&&y<m); }
    vector<int> Number_of_Islands_II(int n, int m, vector<Point> &V){
        int cnt=0;
        vector<int> rst, f(100000, -1);
        for(int i=0;i<V.size();++i){
            int id=V[i].x*m+V[i].y;
            if(f[id]==-1){
                ++cnt;
                f[id]=id;
            }
            for(int j=0;j<4;++j){
                int x=V[i].x+dir[j][0], y=V[i].y+dir[j][1];
                if(noisii_val(x, y, n, m)&&noisii_merge(x*m+y, id, f)) --cnt; 
            }
            rst.push_back(cnt);
        }
        return rst;
    }
    
    //Folder Access; Folders and Cows
    //Time: O(logn*Q.size()); Space: O(tree.size()); Note: Q: queries, tree: folder tree
    //TODO: Backtracking in the tree, from requested node up to closest parent folder.
    //Time: O(Q.size()); Space: O(tree.size())
    //TODO: Hash the tree and store nodes in a map, if there is a folder with access permission, no need to hash its sub-tree.
    //unordered_map<node*, bool> mp; /*{name:-permission}*/
    //bool query(node *a){ return (mp.find(a)==mp.end()?1:mp[a]); }
    
    //Count and Say; Look and Say
    //Time: O(n*rst.size()); Space: O(rst.size())
    string Count_and_Say(int n){
        if(n==1) return "1";
        if(n==2) return "11";
        string rst="11";
        for(int i=2;i<n;++i){
            rst+='$';
            int l=rst.size(), cnt=1;
            string t="";
            for(int j=1;j<l;++j){
                if(rst[j]!=rst[j-1]){
                    t+=(cnt+'0');
                    t+=rst[j-1];
                    cnt=1;
                }else ++cnt;
            }
            rst=t;
        }
        return rst;
    }
    
    //Grid Illumination
    //Time: O(Q.size()); Space: O(G.size()); Note: Q: queries, G: graph
    unordered_map<int, int> gimx, gimy, gimd1, gimd2;
    unordered_set<unsigned long> st;
    vector<int> Grid_Illumination(int N, vector<vector<int>> &G, vector<vector<int>> Q){
        for(vector<int> v:G){
            ++gimx[v[0]], ++gimy[v[1]], ++gimd1[v[0]+v[1]], ++gimd2[v[0]-v[1]];
            st.insert(((unsigned long)v[0]<<32)|v[1]);
        }
        vector<int> rst;
        for(vector<int> q:Q) rst.push_back(gi_check(q[0], q[0]));
        return rst;
    }
    int gi_check(int x, int y){
        bool flag=gimx[x]||gimy[y]||gimd1[x+y]||gimd2[x-y];
        for(int i=-1;i<2;++i)
            for(int j=-1;j<2;++j){
                unsigned long id=((unsigned long)(x+i)<<32)|(y+j);
                if(st.find(id)!=st.end()){
                    --gimx[x+i], --gimy[y+j], --gimd1[x+i+y+j], --gimd2[x+i-y-j];
                    st.erase(id);
                }
            }
        return flag;
    }
};

int main(){
    //Test-Algo
    /*
    Algo algo;
    */
    //Sharpness
    /*
    vector<vector<int>> G={{5, 7, 2}, {7, 5, 8}, {9, 1, 5}};
    cout<<algo.Sharpness(G);
    */
    //Phone Number with Dictionary
    /*
    unordered_set<string> st;
    st.insert("abc");
    st.insert("aaa");
    vector<string> pnd_tv=algo.Phone_Number_Dict("222", st);
    for(auto tc:pnd_tv) cout<<tc<<endl;
    */
    
    //Test-Allocators
    /*
    Allocator_ST t1(10);  //Subsitute ST to Q & BS
    for(int i=0;i<10;++i) cout<<t1.allocate()<<endl;  //0-9
    cout<<(t1.del(0)?"del":"fail")<<endl;    //del
    cout<<(t1.del(12)?"del":"fail")<<endl;   //fail
    cout<<(t1.del(7)?"del":"fail")<<endl;    //del
    for(int i=0;i<8;++i) cout<<t1.allocate()<<endl;   //2 valid IDs, and there are 6 "-1"
    */
    
    //Test-Download_File
    /*Download_File a(5);
    cout<<(a.check_V({Node(0, 1)})?"true":"fail")<<endl; //fail
    cout<<(a.check_Q()?"true":"fail")<<endl; //fail
    cout<<(a.check_BS()?"true":"fail")<<endl; //fail
    cout<<(a.check_V({Node(0, 5)})?"true":"fail")<<endl; //true
    Node done(0, 5);
    a.add_Q(done);
    cout<<(a.check_Q()?"true":"fail")<<endl; //true
    a.add_BS(done);
    cout<<(a.check_BS()?"true":"fail")<<endl; //true
    cout<<a.bs;
    a.add_RBT(1);
    auto t=a.get_RBT();
    for(auto e:t) cout<<e.st<<" "<<e.en<<endl;
    cout<<"---------------"<<endl;
    a.add_RBT(3);
    t=a.get_RBT();
    for(auto e:t) cout<<e.st<<" "<<e.en<<endl;
    cout<<"---------------"<<endl;
    a.add_RBT(7);
    t=a.get_RBT();
    for(auto e:t) cout<<e.st<<" "<<e.en<<endl;
    cout<<"---------------"<<endl;
    a.add_RBT(2);
    t=a.get_RBT();
    for(auto e:t) cout<<e.st<<" "<<e.en<<endl;
    cout<<"---------------"<<endl;
    a.add_RBT(6);
    t=a.get_RBT();
    for(auto e:t) cout<<e.st<<" "<<e.en<<endl;
    cout<<"---------------"<<endl;
    */
}
