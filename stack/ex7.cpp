// Vietnamese version:

// Bài toán stock span là một bài toán về chủ đề kinh tế tài chính, trong đó ta có thông tin về giá của một cổ phiếu qua từng ngày. Mục tiêu của bài toán là tính span của giá cổ phiếu ở từng ngày.

// Span của giá cổ phiếu tại ngày thứ i (ký hiệu là Si) được định nghĩa là số ngày liên tục nhiều nhất liền trước ngày thứ i có giá cổ phiếu thấp hơn, cộng cho 1 (cho chính nó).

// Ví dụ, với chuỗi giá cổ phiếu là [100, 80, 60, 70, 60, 75, 85].

// Stock span example

// Ngày thứ 0 không có ngày liền trước nên S0 bằng 1.
// Ngày thứ 1 có giá nhỏ hơn giá ngày thứ 0 nên S1 bằng 1.
// Ngày thứ 2 có giá nhỏ hơn giá ngày thứ 1 nên S2 bằng 1.
// Ngày thứ 3 có giá lớn hơn giá ngày thứ 2 nên S3 bằng 2.
// Ngày thứ 4 có giá nhỏ hơn giá ngày thứ 3 nên S4 bằng 1.
// Ngày thứ 5 có giá lớn hơn giá ngày thứ 4, 3, 2 nên S5 bằng 4.
// Ngày thứ 6 có giá lớn hơn giá ngày thứ 5, 4, 3, 2, 1 nên S6 bằng 6.
// Kết quả sẽ là [1, 1, 1, 2, 1, 4, 6].



// Yêu cầu. Viết chương trình tính toán chuỗi span từ chuỗi giá cổ phiếu từ đầu vào.

// Input. Các giá trị giá cổ phiếu, cách nhau bởi các ký tự khoảng trắng, được đưa vào standard input.

// Output. Các giá trị span, cách nhau bởi một khoảng cách, được xuất ra standard ouput.



// (Nguồn: Geeks For Geeks)
#include<bits/stdc++.h>
using namespace std;

vector<int> stock_span(const vector<int>& ns) {
    vector<int> result;
    result.push_back(1);
    for (unsigned int i = 1; i < ns.size(); i++){
        int tmp = 0;
        int j = i -1;
        while (j >= 0){
            if (ns[j] >= ns[i]) break;
            else {
                tmp++;
            }
            j--;
        }
        tmp++;
        result.push_back(tmp);
    }
    return result;
}
