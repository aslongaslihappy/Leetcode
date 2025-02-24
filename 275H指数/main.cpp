#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int i = citations.size()-1;
    int h = 0;
    while (i >= 0 && citations[i] > h) {
        h++;
        i--;
    }
    return h;
    
}

int n;
int main() {
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << hIndex(nums) << endl;
    return 0;
}