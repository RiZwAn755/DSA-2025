// steps
// 1. determine the operator precendence order

// order =>  '()' > '^' > '*' > '+' > '-'

// scan the infix from left to right
// if s[i] is an operand add it to ans
// if s[i] is operator
// {

//    if  stack is empty then add it to stack
//    else if the precedence of the stack's top is greater than s[i] then
//    pop the stack untill the precedence of stacks top is strictly smaller than s[i]
//    and add the poped elements in ans.
//    if s[i] == '(' push it in stack
//    if s[i] == ')' pop the stack untill the stack is empty or the '(' is found.

// }

#include<bits/stdc++.h>
using namespace std;

int main() {
	string s = "a+b*c+d";  // the infix expression
	string ans = "";
	int n = s.size();

	stack<char> st;
	map<char, int> mp;

	// Operator precedence
	mp['^'] = 5;
	mp['*'] = 4;
	mp['+'] = 3;
	mp['-'] = 2;

	for (int i = 0; i < n; i++) 
	{
		char ch = s[i];
		if (mp.find(ch) == mp.end() && ch != '(' && ch != ')')  // if current element is not a operator and not a bracket
		{
			ans += ch; // add directly into ans.
		}
	
		else if (ch == '(') 
		{
			st.push(ch);
		}
	
		else if (ch == ')') 
		{
			while (!st.empty() && st.top() != '(') 
			{
				ans += st.top();
				st.pop();
			}
			
			if (!st.empty()) st.pop();  
		}
	
		else 
		{
			while (!st.empty() && st.top() != '(' && mp[st.top()] >= mp[ch]) 
			{
				ans += st.top();
				st.pop();
			}
			
			st.push(ch);
		}
	}


	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << endl; 
	return 0;
}
