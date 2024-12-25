// steps to convert infix to post fix 

// 1. determine the operator precendence order

// order =>  '()' > '^' > '*' > '+' > '-'

// scan the infix from left to right
// if s[i] is an operand add it to ans
// if s[i] is operator
// {

//    if  stack is empty then add it to stack
//    else if the precedence of the stack's top is greater than s[i] then
//    pop the stack untill the precedence of stacks top is strictly smaller than s[i]
//    and add the poped elements in ans

// }











// steps to convert infix to prefix is very simple by using the infix to postfix conversion
// 
// step1 : reverse the expression 
// step2: convert all the opening brackets in closing brackets
// step3: now apply infix to postfix conversion on it and keep in mind that
// here dont pop elements of stacks thathave same precedence as that of s[i]
// at the end reverse the result again  its our required answer



#include <bits/stdc++.h>
using namespace std;

// Function to reverse the input string and swap '(' and ')'
string reverseAndSwapBrackets(string s) 
{
    reverse(s.begin(), s.end());
    for (char &ch : s) 
    {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return s;
}

int main() 
{
    string s = "(A-B/C)*(A/K-L)";  // The infix expression
    string ans = "";
    int n = s.size();

    // Reverse the infix expression and swap brackets
    s = reverseAndSwapBrackets(s);

    stack<char> st;
    map<char, int> mp;

    // Operator precedence
    mp['^'] = 3;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['+'] = 1;
    mp['-'] = 1;

    // Traverse the reversed infix expression
    for (int i = 0; i < n; i++) 
    {
        char ch = s[i];

        // If the character is an operand, add it to the result
        if (isalnum(ch)) 
        {
            ans += ch;
        }

        // If the character is '(', push it onto the stack
        else if (ch == '(') 
        {
            st.push(ch);
        }

        // If the character is ')', pop and append until '(' is encountered
        else if (ch == ')') 
        {
            while (!st.empty() && st.top() != '(') 
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();  // Pop the '('
        }

        // If the character is an operator
        else 
        {
            while (!st.empty() && st.top() != '(' && mp[st.top()] > mp[ch]) 
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators in the stack
    while (!st.empty()) 
    {
        ans += st.top();
        st.pop();
    }

    // Reverse the postfix result to get the prefix expression
    reverse(ans.begin(), ans.end());

    cout << ans << endl;  // Output the prefix expression
    return 0;
}
