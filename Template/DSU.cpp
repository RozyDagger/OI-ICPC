#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
int P[MAXN], R[MAXN];   //parent, rank
void init(){
  for(int i=0;i<MAXN;++i) P[i]=-(R[i]=1);
}
int find(int a){
  int p=a, t;
  for(;P[p]!=p;p=P[p]);
  for(a!=p;a=t) t=P[a], P[a]=p;
  return a;
}
void union(int a, int b){
  a=find(a), b=find(b);
  if(a==b) return;
  if(R[a]>R[b]) P[b]=a;
  else{
    P[a]=b;
    if(R[a]==R[b]) ++R[b];
  }
}
