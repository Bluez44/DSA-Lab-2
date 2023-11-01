// Given an array of integers.
// Your task is to implement a function with following prototype:
// int sumOfMaxSubarray(vector<int>& nums, int k);
// The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

#include<bits/stdc++.h>
using namespace std;

int sumOfMaxSubarray(std::vector<int>& nums, int k) {
    int sum = 0;
    int maxVal = 0;
    int n = nums.size();
    if(n < k) return -1;
    
    for (int i = 0; i < n - k + 1; i++) {
        maxVal = nums[i];
        
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] > maxVal) {
                maxVal = nums[j];
            }
        }
        
        sum += maxVal;
    }
    
    return sum;
}