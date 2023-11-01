// A nice number is a positive integer that contains only 2's and 5's.
// Some nice numbers are: 2, 5, 22, 25, 52, 55, ...
// Number 2 is the first nice number.
// Given an integer N, return the Nth nice number.
// Note: iostream, vector, queue are already included for you.

// Constraint:
// 1 <= n <= 10^6

// Example 1:
// Input:
// n = 5
// Output:
// 52

// Explanation:
// The sequence of nice numbers is 2, 5, 22, 25, 52, 55, ...
// The 5th number in this sequence is 52

// Example 2:
// Input:
// n = 10000
// Output:
// 2255522252225

// iostream, vector and queue are included
// You can write helper methods

#include<queue>
using namespace std;

long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);
    while(true) {
        long long current = q.front();
        q.pop();
        n--;
        if(n == 0) {
            return current;
        }
        q.push(current * 10 + 2);
        q.push(current * 10 + 5);
    }
}