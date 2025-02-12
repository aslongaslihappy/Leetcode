#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//直接法
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i != n; ++i) {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

int m, n;

int main() {
    cin >> m >> n;
    vector<int> nums1, nums2;
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    merge(nums1, m, nums2, n);
    for (int i = 0; i <nums1.size(); i++) {
        cout << nums1[i];
    }
    return 0;
}

