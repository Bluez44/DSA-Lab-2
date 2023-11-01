// Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

// We repeatedly make duplicate removals on S until we no longer can.

// Return the final string after all such duplicate removals have been made.

// Included libraries: vector, list, stack

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> st;
    string str = "";
    string RES = "";
    for(int i = 0; i < (int)S.length(); i++) {
        if(st.empty() == true || st.top() != S[i]) st.push(S[i]);
        else if(st.top() == S[i]) st.pop();
    }
    while(!st.empty()) {
        str += st.top() ;
        st.pop();
    }
    for(int i = str.length()-1; i >= 0; i--) RES += str[i];
    return RES;
}