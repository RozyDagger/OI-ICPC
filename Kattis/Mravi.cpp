#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int main(){
    int n, a, b, x, t, cur, p[MAXN]={0}, perc[MAXN]={0};
    double rst=0, buf;
    bool flag[MAXN];
    scanf("%d", &n);
    vector<double> tV({0});
    for(int i=0;i<n-1;++i){
        scanf("%d %d %d %d", &a, &b, &x, &t);
        p[b]=a;
        perc[b]=x;
        flag[b]=t;
    }
    for(;~scanf("%lf", &buf);tV.push_back(buf));
    for(int z=1;z<n+1;++z){
        int i=z;
        if(tV[i]>=0){
            buf=tV[i];
            while(i>1){
                if(flag[i]) buf=sqrt(buf);
                buf=buf*100.0/perc[i];
                i=p[i];
            }
            rst=max(rst, buf);
        }
    }
    printf("%.4lf", rst);
}
