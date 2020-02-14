#include <stdio.h>
#include <bitset>
#define M10(a) (((a)<<3)+((a)<<1))
inline void readint(int &x){
    int c=getchar_unlocked();
    x=0;
    for(;c>47&&c<58;c=getchar_unlocked()) x=M10(x)+c-48;
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
    int n=x, t=x, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
int main() {
    int n, m, rst=0, t, cnt, i, j, k, l;
    std::bitset<1001> vs, mp[1001];
    readint(n);
    readint(m);
    for(i=0;i<n;++i){
        vs.set(i);
        readint(k);
        for(j=0;j<k;++j){
            readint(l);
            mp[i].set(l);
        }
    }
    for(i=0;i<m;++i){
        readint(t);
        cnt=0;
        for(j=0;j<n;++j){
            if(!mp[j].test(t)) vs.reset(j);
            if(!vs.test(j)) continue;
            ++cnt;
        }
        if(!cnt){
            ++rst;
            for(j=0;j<n;++j) if(mp[j].test(t)) vs.set(j);
        }
    }
    writeint(rst);
}
