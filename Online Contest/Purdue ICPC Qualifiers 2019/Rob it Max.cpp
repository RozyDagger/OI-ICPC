#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;cin>>v[i++]);
    int a=v[0], b=0;
    for(int i=1;i<n;++i){
        int t=a>b?a:b;
        a=b+v[i];
        b=t;
    }
    cout<<max(a, b);
}
