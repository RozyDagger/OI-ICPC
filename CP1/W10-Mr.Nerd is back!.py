'''
Mr.Nerd has been travelling since last time he failed to unplug all the trees that Purdue Pete planted in front of WALC. As soon as Mr.Nerd heard the registration for 2019 Spring is opening, he came back in a hurry by bike from Las Vegas (Yes, I double checked with him. He said he came back from Las Vegas by bike). At this time, Mr. Nerd stays at WALC and doesn't let students use ITAP computers to register classes unless they can solve a problem from him. With a number N which may have up to 150 (since this year is "150 YEARS OF GIANTLEAPS") digits given by Mr. Nerd, you need to figure out the last 4 digits of 2019^N in order to get the access to ITAP computers and finish your 2019 registration.

Input Format

First line contains one integer T indicating the number of testcases.

Each of the following T lines contains one integer N representing the number given by Mr. Nerd.

Constraints

1<= T <= 150

0<= N <= 10^149

Output Format

The last four digits of 2019^N (leading zeros should be ignored)

e.g. If the last four digits are 0233, the output should be 233.

Sample Input 0

4
2
4
1067
517
Sample Output 0

6361
2321
939
9939
Explanation 0

Hint: find minimum b (b>0) as in a^b%c==1 ---- it is the key to the new world :)
'''
T=input()
for i in range(int(T)):
    N=input()
    N=str(N)
    if len(N)>4:
        n=N[len(N)-5:len(N)]
    else:
        n=N
    n=int(n)
    n=n%500
    x=(2019**n)%10000
    print(x)
