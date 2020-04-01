#include <bits/stdc++.h> //data is small, cin/cout used -_-||
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, t=2, i, n, tmp=1;
    string s;
    cin>>h>>s;
    for(i=0;i<h;++i) t<<=1;
    --t;
    n=s.size();
    for(i=0;i<n;++i)
        if(s[i]=='L'){
            t-=tmp;
            tmp<<=1;
        }else{
            t-=tmp+1;
            tmp<<=1;
            ++tmp;
        }
    cout<<t;
}
