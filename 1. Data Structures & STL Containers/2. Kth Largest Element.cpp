#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    
    return nums[k-1];
}