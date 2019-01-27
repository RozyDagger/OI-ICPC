#include <bits/stdc++.h>
using namespace std;
#define forn(a, b, c) for(int i=a;i<b;i+=c)
#define fore(a, b, c) for(int i=a;i<=b;i+=c)
int N, vr[200], vm[15][5][200][7000];
int Sc(int *v, int c) {
    int vc[7]={0}, rst=0;
    forn(0, 5, 1) rst+=v[i], ++vc[v[i]];
    if(c<6) return (c+1)*vc[c+1];
    if(c==6){
        fore(1, 6, 1) if(vc[i]>=3) return rst;
        return 0;
    }else if(c==7){
        fore(1, 6, 1) if(vc[i]>=4) return rst;
        return 0;
    }else if(c==8){
        fore(1, 6, 1) for(int j=1;j<=6;++j) if(i!=j&&vc[i]==3&&vc[j]==2) return 25;
        return 0;
    }else if(c==9) return (vc[1]>0&&vc[2]>0&&vc[3]>0&&vc[4]>0)||(vc[2]>0&&vc[3]>0&&vc[4]>0&&vc[5]>0)||(vc[3]>0&&vc[4]>0&&vc[5]>0&&vc[6]>0)?30:0;
    else if(c==10) return (vc[1]==1&&vc[2]==1&&vc[3]==1&&vc[4]==1&&vc[5]==1)||(vc[2]==1&&vc[3]==1&&vc[4]==1&&vc[5]==1&&vc[6]==1)?40:0;
    else if(c==11) return rst;
    else if(c==12) fore(0, 6, 1) if(vc[i]==5) return 50;
    return 0;
}
int L(int *v, int a){
    int rst=0;
    sort(v, v+5);
    for(int i=16, j=4;i>0;--j, i/=2) if(a>i) a-=i, rst=rst*10+v[j];
    return rst;
}
int run(int c, int re, int nt, int lc){
    if(c>=13) return 0;
    if(nt>=N) return -2;
    if(vm[c][re][nt][lc]+1) return vm[c][re][nt][lc];
    int t=nt, v[5]={0};
    if(!re){
        if(nt+4>=N) return -2;
        forn(0, 5, 1) v[i]=vr[nt+i];
        t=nt+5;
    }else{
        int i=0;
        for(int tt=lc;tt>0;tt/=10) v[i++]=tt%10;
        for(;i<5;++i){
            if(t>=N) return -2;
            v[i]=vr[t++];
        }
    }
    int ss=Sc(v, c), rs=run(c+1, 0, t, 0), rst;
    rst=rs<0?-2:ss+rs;
    if(re<2)
        forn(0, 32, 1){
            int tl=L(v, i), ts=run(c, re+1, t, tl);
            if(ts>0&&ts>rst) rst=ts;
        }
    vm[c][re][nt][lc]=rst;
    return rst;
}
int main() {
    cin>>N;
    forn(0, N, 1) cin>>vr[i];
    forn(0, 13, 1) for(int j=0;j<3;++j) for(int k=0;k<200;++k) for(int z=0;z<7000;vm[i][j][k][z++]=-1);
    cout<<run(0, 0, 0, 0);
}
