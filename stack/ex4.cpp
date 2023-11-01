// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

// Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.

// For example: Given string S is  "2 3 1 * + 9 -". If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

// Requirement: Write the function to evaluate the value of postfix expression.
#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expr){
    /*TODO*/
    stack<int> st;
    for(int i = 0; i < (int)expr.length(); i++) {
        if(expr[i] == ' ') continue;
        if(expr[i] >= '0' && expr[i] <= '9') {
            string num = "";
            while(expr[i] != ' ') {
                num += expr[i];
                i++;
            }
            st.push( stoi(num) );
        }
        if(expr[i] == '+') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            st.push(val1 + val2);
        }
        if(expr[i] == '-') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            st.push(val2 - val1);
        }
        if(expr[i] == '*') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            st.push(val1 * val2);
        }
        if(expr[i] == '/') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            // cout << val2 << " " << val1 << endl;
            int res = val2/val1;
            st.pop();
            st.push(res);
        }
        // cout << st.top() << endl;
    }
    return st.top();
}