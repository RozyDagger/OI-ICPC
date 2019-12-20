#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T, a, b;
bool val(ll x, ll l, ll r){
    if(x<l||x>r) return 0;
    ll t=0;
    for(ll i=x;i;i/=10) t=t*10+i%10;
    return t==x;
}
int ppp(ll x, ll m=-1){
    ll rst=x;
    if(m!=-1) rst=rst*10+m;
    for(;x;x/=10) rst=rst*10+x%10;
    return rst;
}
int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        int rst=(a<=1&&1<=b)+(a<=4&&4<=b)+(a<=9&&9<=b);
        for(ll i=1;i<100000000000000;++i){
            ll x=ppp(i);
            if(x*x>b) break;
            for(int m=-1;m<10;++m){
                x=ppp(i, m);
                if(val(x*x, a, b)) ++rst;
            }
        }
        cout<<rst<<endl;
    }
}
