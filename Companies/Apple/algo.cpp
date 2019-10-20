#include <bits/stdc++.h>
using namespace std;


int maxDistToClosest(vector<int>& v) {
  int n=v.size(), l=0, rst=0;
  for (int i=0;i<n;++i) {
    if(v[i]-1) continue;
    if(!l) rst=max(rst, i-l);
    else rst=max(rst, (i-l+1)/2);
    l=i+1;
  }
  rst=max(rst, n-l);
  return rst;
}

class ExamRoom {
public:
  ExamRoom(int N) { n=N; }
  int seat() {
    int l=0, mx=0, ind=0;
    for(int i:st){
      if(!l)
        if(mx<i-l){
          mx=i-l;
          ind=0;
        }
      else if(mx<(i-l+1)/2){
        mx=(i-l+1)/2;
        ind=l+mx-1;
      }
      l=i+1;
    }
    if(l>0&&mx<n-l){
      mx=n-l;
      ind=n-1;
    }
    st.insert(ind);
    return ind;
  }
  void leave(int p) { st.erase(p); }
  int n;
  set<int> st;
};

vector<string> string_split(string s, char c){
  vector<string rst;
    int ind=0;
    for(int i=0;i<s.size();++i)
      if(s[i]==c){
        string t=s.substr(ind, i-ind);
        if(t.size()) rst.push_back(t);
        t=””;
        ind=i+1;
      }
    if(s[s.size()-1]!=c&&ind!=s.size()-1){
      string t=s.substr(ind, s.size()-ind);
      rst.push_back(t);
    }
    return rst;
}

ool isAnagram(string a, string b) {
  if(a.size()-b.size()) return 0;
  int mp[26]={0}; //mp[128] if there are uppercase chars
  for(int i=0;i<a.size();++mp[a[i++]-'a']);
  for(int i=0;i<b.size();++i)
  if(!mp[b[i]-'a']) return 0;
  else --mp[b[i]-'a'];
  return 1;
}

bool wordBreak(string s, vector<string>& v) {
  unordered_set<string> st(v.begin(), v.end());
  bool dp[s.size()+1]={0};
  dp[0]=1;
  for(int i=1;i<=s.size();++i)
  for(int j=i-1;j>=0;--j)
  if(dp[j]&&st.find(s.substr(j, i-j))!=st.end()){
    dp[i]=1;
    break;
  }
  return dp[s.size()];
}

vector<int> spiralOrder(vector<vector<int>>& G) {
  if(!G.size()||!G[0].size()) return {};
  vector<int> rst(G.size()*G[0].size());
  for(int k=0, l=0, m=G.size(), n=G[0].size(), c=0;k<m&&l<n;){
    for(int i=l;i<n;rst[c++]=G[k][i++]);
    ++k;
    for(int i=k;i<m;rst[c++]=G[i++][n-1]);
    --n;
    if(k<m){
      for(int i=n-1;i>=l;rst[c++]=G[m-1][i--]);
      --m;
    }
    if(l<n){
      for(int i=m-1;i>=k;rst[c++]=G[i--][l]);
      ++l;
    }
  }
  return rst;
}

vector<int> productExceptSelf(vector<int>& V) {
  int n=V.size();
  if(!n) return {};
  if(n==1) return {V[0]};
  vector<int> rst(n), l(n), r(n);
  l[0]=V[0];
  r[n-1]=V[n-1];
  for(int i=1;i<n;++i) l[i]=l[i-1]*V[i];
  for(int i=n-2;i>=0;--i) r[i]=r[i+1]*V[i];
  rst[0]=r[1];
  rst[n-1]=l[n-2];
  for(int i=1;i<n-1;++i) rst[i]=l[i-1]*r[i+1];
  return rst;
}

vector<int> productExceptSelf(vector<int>& V) {
  int n=V.size(), l=1, r=1;
  vector<int> rst(n, 1);
  for(int i=0;i<n;++i){
    rst[i]*=l;
    l*=V[i];
    rst[n-i-1]*=r;
    r*=V[n-i-1];
  }
  return rst;
}

int trap(vector<int>& V) {
  if(!V.size()||V.size()==1) return 0;
  int n=V.size(), l[n]={0}, r[n]={0}, rst=0;
  l[0]=V[0], r[n-1]=V[n-1];
  for(int i=1;i<n;++i) l[i]=max(l[i-1], V[i]);
  for(int i=n-2;i>=0;--i) r[i]=max(r[i+1], V[i]);
  for(int i=0;i<n;++i) rst+=min(l[i], r[i])-V[i];
  return rst;
}

void rotateImage(vector<vector<int>>& G) {
  if(!G.size()||!G[0].size()||G.size()!=G[0].size()) return;
  int n=G.size();
  for(int i=0;i<n/2;++i)
    for(int j=i;j<n-i-1;++j){
      int t=G[i][j];
      G[i][j]=G[n-1-j][i];
      G[n-1-j][i]=G[n-1-i][n-1-j];
      G[n-1-i][n-1-j]=G[j][n-1-i];
      G[j][n-1-i]=t;
    }
}

int compareVersion(string a, string b) {
  int ia=0, ib=0, i=0, j=0;
  while(i<a.length()||j<b.length()){
    for(;i<a.length()&&a[i]!='.';++i) ia=ia*10+(a[i]-'0');
    for(;j<b.length()&&b[j]!='.';++j) ib=ib*10+(b[j]-'0');
    if(ia>ib) return 1;
    else if(ia<ib) return -1;
    ++i, ++j;
    ia=ib=0;
  }
  return 0;
} 

#define vi vector<int>
struct Node{ int data; Node *l, *r; };
Node *recur(int rt, vi arr, vi p, vi lc, vi rc){
  if(rt==-1) return NULL;
  Node *t=new Node;
  t->data=arr[rt];
  t->l=recur(lc[rt], arr, p, lc, rc);
  t->r=recur(rc[rt], arr, p, lc, rc);
  return t;
}
Node *build(vi arr){
  int n=arr.size(), rt=0, t;
  vi p(n, -1), lc(n, -1), rc(n, -1);
  for(int i=1;i<n;++i){
  t=i-1;
  rc[i]=-1;
  for(;arr[t]<=arr[i]&&t!=rt;t=p[t]);
    if(arr[t]<=arr[i]){
      p[rt]=i;
      lc[i]=rt;
      rt=i;
    }else if(rc[t]==-1){
      p[i]=t;
      lc[i]=-1;
      rc[t]=i;
    }else{
      p[rc[t]]=i;
      lc[i]=rc[t];
      rc[t]=i;
      p[i]=t;
    }
  }
  p[rt]=-1;
  return recur(rt, arr, p, lc, rc);
}

class MinStack {
public:
  MinStack() {
    mn=INT_MAX;
  }
  void push(int x) {
    if(x<=mn){
      stk.push(mn);
      mn=x;
    }
    stk.push(x);
  }
  void pop() {
    int t=stk.top(); stk.pop();
    if(mn==t){ mn=stk.top(); stk.pop(); }
  }
  int top() { return stk.top(); }
  int getMin() { return mn; }
  int mn;
  stack<int> stk;
};
