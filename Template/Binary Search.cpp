//Some BS
#include <bits/stdc++.h>
using namespace std;
int bs_find_sth(vector<int> V, int n, int k){   //find index of any number==k
    int l=0, r=n-1, m;
    while(l<=r){
        m=l+(r-l>>1);
        if(V[m]==k) return m;
        else if(V[m]>k) r=m-1;
        else l=m+1;
    }
    return -1;
}
int bs_find_fste(vector<int> V, int n, int k){    //find index of first number==k
    int l=0, r=n-1, m;
    while(l<=r){    //if k is in V, when l==r, it's the answer
        m=l+(r-l>>1);
        if(V[m]>=k) r=m-1;
        else l=m+1;
    }
    return l<n&&V[l]==k?l:-1;
}
int bs_find_lste(vector<int> V, int n, int k){    //find index of last number==k
    int l=0, r=n-1, m;
    while(l<=r){    //if k is in V, when l==r, it's the answer
        m=l+(r-l>>1);
        if(V[m]<k) r=m-1;
        else l=m+1;
    }
    return r>0&&V[r]==k?r:-1;
}
int bs_find_me(vector<int> V, int n, int k){    //find index of first number>=k
    int l=0, r=n-1, m;
    while(l<=r){
        m=l+(r-l>>1);
        if(V[m]>=k) r=m-1;
        else l=m+1;
    }
    return l<n?l:-1;
}
int bs_find_m(vector<int> V, int n, int k){    //find index of first number>k
    int l=0, r=n-1, m;
    while(l<=r){
        m=l+(r-l>>1);
        if(V[m]>k) r=m-1;
        else l=m+1;
    }
    return l<n?l:-1;
}
int bs_find_le(vector<int> V, int n, int k){    //find index of first number<=k
    int l=0, r=n-1, m;
    while(l<=r){
        m=l+(r-l>>1);
        if(V[m]>=k) r=m-1;
        else l=m+1;
    }
    return l<n?l-1;
}
int bs_find_l(vector<int> V, int n, int k){    //find index of first number<k
    int l=0, r=n-1, m;
    while(l<=r){
        m=l+(r-l>>1);
        if(V[m]>=k) r=m-1;
        else l=m+1;
    }
    return l-1>=0?l-1;
}
int main(){
    
}
