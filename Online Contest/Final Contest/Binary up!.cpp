/****************************************
[Defination] 
"Bianry up" is a type of sequence consisting of increasing numbers which can be written as 2^x, 2^(x+1), 2^(x+2), 2^(x+3).... (x>=0) 

[Example]
1,2,4,8 and 4,8 are binary up sequences, while 2,6,12,24 is not. 

[Task]
Given a sequence, find the lengnth of the longest binary up subsequence in it.

Input Format

The first line contains one interger n representing the length of given sequence.
The second line contains n integers representing the given sequence.

Constraints

(1 <= n <= 10^7)

(0 <= elements in given sequence <= 5x10^18)

Output Format

Output the lengnth of the longest binary up subsequence

Sample Input 0

6
1 2 3 4 5 6
Sample Output 0

3
Explanation 0

Binary up sequence: 1 2 4
****************************************/
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
ULL n;
int main() {
    cin>>n;
    ULL s;
    float x;
    int cnt=0, V[4000003]={0};
    for(int i=0;i<n;++i){
        cin>>s;
        x=log2(s);
        if((!(ceil(x)-floor(x))&&s%2==0)||(s==1)) V[cnt++]=x;
    }
    int dp[cnt]={0};
    for(int i=0;i<n;++i){
        int t=0;
        for(int j=0;j<i;++j) if(V[i]>V[j]) t=max(t, dp[j]);
        dp[i]=t+1;
    }
    cout<<dp[cnt-1]<<endl;
    return 0;
}
