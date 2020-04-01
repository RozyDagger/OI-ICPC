#include <bits/stdc++.h>
using namespace std;
inline void readint(int &x){
    char c=getchar_unlocked();
    x=0;
    for(;c<48||c>57;c=getchar_unlocked());
    for(;c>47&&c<58;c=getchar_unlocked()) x=(x<<3)+(x<<1)+c-48;
}
inline void readstr(char *x){
    char c=getchar_unlocked(), i=0;
    for(;!(c>='a'&&c<='z')&&!(c>='A'&&c<='Z');c=getchar_unlocked());
    for(;c!=' ';c=getchar_unlocked()) x[i++]=c;
}
inline void writeint(int x){
    if(!x){
        putchar_unlocked('0');
        return;
    }
    int n=x, t=n, cnt=0;
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=(t<<3)+(t<<1)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'0');
    for(;cnt--;putchar_unlocked('0'));
}
int main(){
    unordered_map<string, vector<int>> mp;
    int n, y;
    char s[20];
    readint(n);
    for(int i=0;i<n;++i){
        memset(s, 0, sizeof s);
        readstr(s);
        readint(y);
        mp[string(s)].push_back(y);
    }
    for(unordered_map<string, vector<int>>::iterator itr=mp.begin();itr!=mp.end();++itr) sort((*itr).second.begin(), (*itr).second.end());
    readint(n);
    for(int i=0;i<n;++i){
        memset(s, 0, sizeof s);
        readstr(s);
        readint(y);
        writeint(mp[string(s)][y-1]);
        putchar_unlocked('\n');
    }
}
