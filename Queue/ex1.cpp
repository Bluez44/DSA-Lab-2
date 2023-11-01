// [Vie] Cho 1 hàng đợi có số lượng phần tử là số chẵn, sắp xếp lại các phần tử theo quy tắc xen kẽ phần tử ở nửa đầu và nửa sau của hàng đợi.

// Sinh viên cần hiện thực hàm interleaveQueue.

// Thư viện stack và queue đã được thêm vào.
#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int>& q){
    queue<int> first_half;
    queue<int> last_half;
    int n = q.size();
    for(int i = 0; i < n; i++) {
        if(i < n/2) first_half.push(q.front());
        else last_half.push(q.front());
        q.pop();
    }
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            q.push(first_half.front());
            first_half.pop();
        }
        else {
            q.push(last_half.front());
            last_half.pop();
        }
    }
}