// You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

// At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:

// A non-negative integer x (from 0 to 9) - record a new score of x
// '+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
// 'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
// 'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
// Finally, return the sum of all scores in the record.
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int baseballScore(string ops){
/*TODO*/
    stack<int> st;
    for(int i = 0; i < (int)ops.length(); i++) {
        if(ops[i] == 'C') st.pop();
        if(ops[i] == 'D') {
            st.push(st.top()*2);
        }
        if(ops[i] == '+') {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.push(val1);
            st.push(val1 + val2);
        }
        if( (ops[i]) >= '0' && ops[i] <= '9' ) {
            st.push(ops[i]-'0');
        }
    }
    int sum = 0;
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}


int main() {
     cout << baseballScore("52CD+");
 
    return 0;
}
