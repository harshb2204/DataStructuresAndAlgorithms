#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lengthOfLIS(const vector<int>& nums) {
    vector<int> piles;
    
    for (const int& num : nums) {
        auto it = lower_bound(piles.begin(), piles.end(), num);
        
    
        if (it == piles.end()) {
            piles.push_back(num);
        } else {
            
            *it = num;
        }
    }
    
    
    return piles.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}
