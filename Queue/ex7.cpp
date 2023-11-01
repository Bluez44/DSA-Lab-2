// Given an array of integers.
// Your task is to implement a function with following prototype:
// int sumOfMaxSubarray(vector<int>& nums, int k);
// The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

#include<bits/stdc++.h>
using namespace std;

int sumOfMaxSubarray(vector<int>& nums,int k) {
    deque<int> dq;
    long long sum = 0;
    for (int i = 0 ; i < (int) nums.size(); i++){
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        
        dq.push_back(i);
        
        if (i >= k-1) sum+=nums[dq.front()];
        
    }
    return sum;
}

int main() {
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k);
    return 0;
}