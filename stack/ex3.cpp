// Given an array nums[] of size N having distinct elements, the task is to find the next greater element for each element of the array
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist a next greater of a element, the next greater element for it is -1

// Note: iostream, stack and vector are already included

// Constraints:
// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^9

// Example 1:
// Input:
// nums = {15, 2, 4, 10}
// Output:
// {-1, 4, 10, -1}

// Example 2:
// Input:
// nums = {1, 4, 6, 9, 6}
// Output:
// {4, 6, 9, -1, -1}

// iostream, stack and vector are included
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> Greater(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            Greater[i] = st.top();
        }
        st.push(arr[i]);
    }
    return Greater;
}