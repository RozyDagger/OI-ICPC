#include <stdio.h>
inline void readint(int &x){
    int c=getchar_unlocked();
    x=0;
    for(;c<48||c>57;c=getchar_unlocked());
    for(;(c>47)&(c<58);c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
}
inline void writeint(int x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    if(x<0){
        putchar_unlocked('-');
        x=~x+1;
    }
    int n=x, t=n, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
inline int F(int *P, int a){
    for(;a!=P[a];a=P[a]);
    return a;
}
inline void U(int *P, int *R, int a, int b){
    a=F(P, a), b=F(P, b);
    if(a==b) return;
    if(R[a]<R[b]){
        ++R[b];
        P[a]=P[b];
        return;
    }
    ++R[a];
    P[b]=P[a];
}
int main(){
    char t;
    int i, j, n, r, c, r1, c1, r2, c2;
    readint(r), readint(c);
    int P[r*c], R[r*c]={0};
    bool bs[r][c];
    for(i=0;i<r;++i)
        for(j=0;j<c;++j){
            P[i*c+j]=i*c+j;
            t=getchar_unlocked();
            if(t<'0'||t>'1') t=getchar_unlocked();
            bs[i][j]=t=='1';
        }
    for(i=0;i<r;++i)
        for(j=0;j<c;++j){
            if((j<c-1)&(bs[i][j]==bs[i][j+1])) U(P, R, i*c+j, i*c+j+1);
            if((i<r-1)&(bs[i][j]==bs[i+1][j])) U(P, R, i*c+j, (i+1)*c+j);
        }
    for(readint(n);n--;putchar_unlocked('\n')){
        readint(r1), readint(c1), readint(r2), readint(c2);
        --r1, --r2, --c1, --c2;
        if(F(P, r1*c+c1)==F(P, r2*c+c2))
            if(bs[r1][c1]){
                putchar_unlocked('d');
                putchar_unlocked('e');
                putchar_unlocked('c');
                putchar_unlocked('i');
                putchar_unlocked('m');
                putchar_unlocked('a');
                putchar_unlocked('l');
            }
            else{
                putchar_unlocked('b');
                putchar_unlocked('i');
                putchar_unlocked('n');
                putchar_unlocked('a');
                putchar_unlocked('r');
                putchar_unlocked('y');
            }
        else{
            putchar_unlocked('n');
            putchar_unlocked('e');
            putchar_unlocked('i');
            putchar_unlocked('t');
            putchar_unlocked('h');
            putchar_unlocked('e');
            putchar_unlocked('r');
        }
    }
}
