/*********************************************
Given a mathematical expression, determine if it is fully parenthesized or not.

Input Format

A string with the expression

Constraints

String length <= INT_MAX

The type of brackets used in the input string: (), [], {}, <>

Output Format

Output string should be "True" or "False"

Sample Input 0

(2 + (3 - 5))
Sample Output 0

True
Explanation 0

The given input is a valid exxpression where all the closing brackets matches the opening brackets

Sample Input 1

{6 * 5]
Sample Output 1

False
Explanation 1

The given expression is not valid as the closing brackets doesn't match the opening bracket type.
*********************************************/
#include <bits/stdc++.h>
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> stk;
    size_t n=s.size();
    for(int i=0;i<n;++i)
        if(s[i]=='('||s[i]=='{'||s[i]=='['||s[i]=='<') stk.push(s[i]);
        else if(stk.empty()||abs(stk.top()-s[i])>2) return "False";
        else stk.pop();
    return st.empty()?"True":"False";
}

int main()
{
    string s;
    getline(cin, s);
    string result = isBalanced(s);
    cout << result;
    return 0;
}
