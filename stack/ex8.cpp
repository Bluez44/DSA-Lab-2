// Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// For example:

// String "[]()" is a valid string, also "[()]".
// String "[])" is not a valid string.
#include <bits/stdc++.h>

using namespace std;
bool isValidParentheses (string s){
    /*TODO*/
    stack<char> st;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]); 
        }
        if(s[i] == ']' || s[i] == '}') {
            if(st.empty() == true) return false;
            if(s[i]-2 == st.top()) {
                st.pop();
            }
            else st.push(s[i]);
        }
        if(s[i] == ')') {
            if(st.empty() == true) return false;
            if(s[i]-1 == st.top()) {
                st.pop();
            }
            else st.push(s[i]);
        }
    }
    // cout << boolalpha << st.empty() << endl;
    return st.empty();
}


int main() {
cout << boolalpha <<isValidParentheses("))))(())");
    return 0;
}