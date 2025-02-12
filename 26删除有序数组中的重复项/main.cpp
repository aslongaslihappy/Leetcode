#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int fast = 1, slow = 1;
    while (fast < n) {
        if (nums[fast] != nums[fast - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}

int n;
int main() {
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << removeDuplicates(nums) << endl;
    return 0;
}