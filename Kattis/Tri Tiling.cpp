#include <stdlib.h>
#include <stdio.h>
#define MAXN 31
int dfs(int n, int *V){
    if(!V[n]) V[n]=(dfs(n-1, V)<<2)-dfs(n-2, V);
    return V[n];
}
int main(){
    int n, *V=(int*)calloc(MAXN, sizeof(int));
    for(V[0]=V[1]=1;scanf("%d", &n)==1;putchar_unlocked('\n'))
        if(!(1+(n>>31)-(-n>>31))) break;
        else if(n&1) putchar_unlocked('0');
        else printf("%d", dfs((n>>1)+1, V));
}
