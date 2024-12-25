// Read the Prefix expression in reverse order (from right to left)
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack 
// Create a string by concatenating the two operands and the operator between them. 
// string = "(" + operand1 + operator + operand2 + ")" 
// And push the resultant string back to Stack
// Repeat the above steps until the end of Prefix expression.
// At the end stack will have only 1 string i.e resultant string


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "+ab"; 
    int n = s.size();

    // Reverse the string to process it from right to left
    reverse(s.begin(), s.end());
    
    // Stack to store operands (intermediate expressions)
    stack<string> st;
    
    // Iterate over the reversed string
    for (int i = 0; i < n; i++)
    {
        // If the character is an operand, push it onto the stack
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            // If the character is an operator, pop two operands from the stack
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            
            // Form the new infix expression
            string temp = "(" + operand2 + string(1, s[i]) + operand1 + ")";
            
            // Push the new infix expression back onto the stack
            st.push(temp);
        }
    }

    // The final result will be at the top of the stack
    cout << st.top() << endl;
}
