#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long run(long long n){
    long long t=0;
    for(long long i=1, j;i<=n;i=j+1){
        j=n/(n/i);
        t+=(i+j)*(j-i+1)/2*(n/i);
    }
    return t;
}
int main(){
    cin>>a>>b;
    cout<<run(b)-run(a-1);
}
