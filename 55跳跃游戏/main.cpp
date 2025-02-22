#include <iostream>
#include <vector>
using namespace std;

// 贪心算法
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1) {
                return true;
            }
        }
    }
    return false;
}

int n;
int main() {
    cin >> n;
    vector<int> nums(n);
    for (int i = 0 ; i < n; i++) {
        cin >> nums[i];
    }
    cout << canJump(nums);
    return 0;
}