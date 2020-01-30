#include <bits/stdc++.h>
using namespace std;
#define INTABS(a) (((a)+((a)>>31))^((a)>>31))
int main(){
    vector<int> V={99, 9, 88, 89, 80, 8, 77, 78, 79, 70, 7, 66, 69, 6, 56, 58, 59, 50, 136, 139, 144, 145, 146, 147, 148, 155, 156, 159, 1, 150, 15, 166, 18, 149, 188, 19, 110, 100, 12, 179, 14, 199, 120, 158, 177, 10, 13, 180, 189, 22, 17, 133, 20, 140, 16, 178, 11, 129, 128, 49, 126, 47, 125, 46, 123, 44, 122, 119, 40, 118, 39, 117, 116, 115, 36, 114, 113, 112, 111, 169, 2, 33, 200, 29, 28, 26, 25, 23, 220, 55, 222, 170, 3, 4, 48, 45, 5, 0};
    set<int> st(V.begin(), V.end());
    int n, t, l, r;
    for(scanf("%d", &n);n--;printf("%d\n", INTABS(t-l)<INTABS(t-r)?l:r)){
        scanf("%d", &t);
        set<int>::iterator itr=st.lower_bound(t);
        r=*itr;
        set<int>::iterator ttr=itr==st.begin()?itr:--itr;
        l=*ttr;
    }
}
