#include <stdio.h>
inline int readint(){
    int c=getchar_unlocked(), x=0;
    for(;c<48||c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
    return x;
}
int main() {
    int t, w, h, n, v[2], s, y, x, i, j, k;
    char G[30][30][2], ch;
    bool flag, ab;
    for(t=readint();t--;putchar_unlocked('\n')){
        w=readint();
        h=readint();
        n=readint();
        v[0]=v[1]=0;
        for(i=0;i<2;++i)
            for(j=h-1;j>=0;--j)
                for(k=0;k<w;++k){
                    ch=getchar_unlocked();
                    if(ch!='_'&&ch!='#') ch=getchar_unlocked();
                    G[k][j][i]=ch;
                    if(ch=='#') ++v[i];
                }
        for(flag=ab=0;n--;){
            i=readint();
            j=readint();
            if(flag) continue;
            if(G[i][j][!ab]=='#'){
                G[i][j][!ab]='_';
                if(!--v[!ab]) flag=!(ab=!ab);
            }else flag=!(ab=!ab)&&!(v[0]*v[1]);
        }
        printf("%s", v[0]&&!v[1]?"player one wins":!*v&&v[1]?"player two wins":"draw");
    }
}
