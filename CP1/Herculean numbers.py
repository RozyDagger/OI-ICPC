#https://www.hackerrank.com/contests/cp1-fall-2019-contest-3/challenges/herculean-numbers/copy-from/1317270336
from bisect import *
MAXN=999999999999999999+1
V=[]
st=set()
for i in range(1, 40):
    tmp=i**12
    if(tmp>MAXN):
        break
    if(tmp not in st):
        V.append(tmp)
        st.add(tmp)
for i in range(1, 1500):
    for j in range(1, 1500):
        if(i==j):
            continue
        tmp=i**6+j**6
        if(tmp>MAXN):
            break
        if(tmp not in st):
            V.append(tmp)
            st.add(tmp)
V.sort()
s=input()
N=int(s)
def bs(x, fl):
    if(x<V[0]):
        return 1
    if(x>V[-1]):
        return len(V)
    l=0
    r=len(V)-1
    while(l<=r):
        m=int(l+(r-l)/2)
        if(V[m]==x):
            return m-1
        if(V[m]<x):
            l=m+1
        else:
            r=m-1
    return r
for i in range(N):
    s=input()
    a=int(s.split(" ")[0])
    b=int(s.split(" ")[1])
    rst=bisect_right(V, b)-bisect_left(V, a)
    print(rst)
