//next_permutation solution
/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INTMAX(a, b) ((b)&(((a)-(b))>>31)|(a)&~(((a)-(b))>>31))
int main(){
    char *letters=strdup("abcdefghij");
    int n, k;
    scanf("%d %d",&n, &k);
    k>>=1;
    n=INTMAX(n, k)-1;
    for(int i=0;i<n;++i){
        printf("%s ", letters);
        std::next_permutation(letters, letters+9);
    }
    printf("%s\n", letters);
}
*/
//Self written writer
#include <stdlib.h>
#include <stdio.h>
#define M10(a) (((a)<<3)+((a)<<1))
#define INTMAX(a, b) ((b)&(((a)-(b))>>31)|(a)&~(((a)-(b))>>31))
inline void write(int x){
    int n=x, t=n, cnt=0;
    if(!n){
        putchar_unlocked('a');
        return;
    }
    for(;!(t%10);t/=10) ++cnt;
    for(t=0;n;n/=10) t=M10(t)+n%10;
    for(;t;t/=10) putchar_unlocked(t%10+'a');
    for(;cnt--;putchar_unlocked('a'));
}
int main(){
    int n, k, i;
    scanf("%d %d",&n, &k);
    k>>=1;
    n=INTMAX(n, k)-1;
    for(i=0;i<n;++i){
        write(i);
        putchar_unlocked(' ');
    }
    write(i);
    putchar_unlocked('\n');
}
