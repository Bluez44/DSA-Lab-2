// Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

// Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

// Constraint:
// 1 <= list.length <= 10^5
// 0 <= node.val <= 5000
// 1 <= left <= right <= list.length

// Example 1:
// Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
// Output: 3 6 5 4 7

// Example 2:
// Input: list = {8, 9, 10}, a = 1, b = 3
// Output: 10 9 8


ListNode* reverse(ListNode* head, int a, int b) {
    ListNode* stackHead = NULL, * stackTail = NULL, *ptr = head;
    for(int i = 1; i < a; i++){
        ptr = ptr->right;
    }
    ListNode *front = ptr->left;
    stackTail = ptr;
    for(int i = a; i <= b; i++){
        ListNode *tmp = ptr;
        ptr = ptr->right;
        tmp->left = NULL;
        tmp->right = stackHead;
        stackHead = tmp;
        stackHead->left = ptr;
    }
    if(front){
        front->right = stackHead;
        stackHead->left = front;
        stackTail->right = ptr;
        if(ptr) ptr->left = stackTail;
    }
    else{
        stackTail->right = ptr;
        if(ptr) ptr->left = stackTail;
        head = stackHead;
        stackHead->left = NULL;
    }
    return head;
}