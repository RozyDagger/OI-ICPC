#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000000
#define MAXS 10000
short v[MAXN]={0};
int d=1, n, i, k;
vector<int> t;
int main(){
    cin>>i>>k;
    for(int c=0;c<MAXS;i+=d){
        ++c;
        if(i<MAXN) v[i]=1;
        for(int i=0;i<n;++i) if(i-t[i]<MAXN) v[i-t[i]]=1;
        if(v[k]) break;
        t.push_back(i);
        for(++n;v[d];++d);
    }
    cout<<c-1<<endl;
}
