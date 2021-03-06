/*******************************************
Totient is good at Math but bad at series. 

Given a positive integer, N, find the length of the sequence of all fractions a/b with (0 <= a <= b), (1 <= b <= N) and a and b are relatively prime.

For example, given N=6, the sequence listed in increasing order is 

0/1, 1/6, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 5/6, 1/1 
The length is 13. 

Can you please help him?

Input Format

The first line of the input contains a single integer P, which is the number of data sets that follow. Each data set should be processed identically and independently.

Each data set consists of a single line of input. It contains the data set number, K, followed by N,

Constraints

2 <= P <= 10000
2 <= N <= 1000
Output Format

Got each data set there is a single line of output of the data set number K and the length of the sequence.

Sample Input 0

4
1 6
2 15
3 57
4 999
Sample Output 0

1 13
2 73
3 1001
4 303793

*******************************************/
#include <bits/stdc++.h>
using namespace std;
int n, t, p;
int phi(int x){
    int rst=x;
    for(int p=2;p*p<=x;++p)
        if(!x%p){
            for(;!x%p;x/=p); 
            rst-=rst/p; 
        } 
    if(x>1) rst-=rst/x; 
    return rst; 
}
int run(int x){
    int rst=1;
    for(int i=1;i<=x;++i) rst+=phi(i);
    return rst;
}
int main(){
    for(cin>>n;n--;cout<<t<<" "<<run(p)<<endl) cin>>t>>p;
    return 0;
}
