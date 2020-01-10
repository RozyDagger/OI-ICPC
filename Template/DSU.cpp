#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int P[MAXN], R[MAXN];   //parent, rank(tree height)
void init(){
  for(int i=0;i<MAXN;++i) P[i]=-(R[i]=1);
}
//path compression
int find(int a){
  int p=a, t;
  for(;P[p]!=p;p=P[p]);
  for(;a!=p;a=t) t=P[a], P[a]=p;
  return a;
}
//union by rank
void union(int a, int b){
  a=find(a), b=find(b);
  if(a==b) return;
  if(R[a]>R[b]) P[b]=a;
  else{
    P[a]=b;
    if(R[a]==R[b]) ++R[b];
  }
}
/*
Rank by count of elements in set
int n, p[MAXN], c[MAXN];
int F(int a){
    if(a==p[a]) return a;
    else{
        c[p[a]]+=c[a];
        c[a]=0;
        return p[a]=F(p[a]);
    }
}
void M(int a, int b){
    a=F(a);
    b=F(b);
    if(c[a]>=c[b]) swap(a, b);
    p[a]=b;
    F(a);
}
*/
