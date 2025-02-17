#include <iostream>
#include <vector>
using namespace std;

// 贪心算法

/*
    我们依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。
    对于当前遍历到的位置 x，如果它在 最远可以到达的位置 的范围内，
    那么我们就可以从起点通过若干次跳跃到达该位置，
    因此我们可以用 x+nums[x] 更新 最远可以到达的位置。
    在遍历的过程中，如果 最远可以到达的位置 大于等于数组中的最后一个位置，
    那就说明最后一个位置可达，我们就可以直接返回 True 作为答案。反之，如果在遍历结束后，最后一个位置仍然不可达，我们就返回 False 作为答案。。
 */
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
    bool res = false;
    res = canJump(nums);
    cout << res;
    return 0;
}