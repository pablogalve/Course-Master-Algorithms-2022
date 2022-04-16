#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
    std::priority_queue<int, vector<int>, greater<int>> priority_queue;
    for(int i = 0; i < nums.size(); ++i) // O(n)
    {
        priority_queue.push(nums[i]);
    }

    int ans = 0;
    while(priority_queue.size() > 1) // O(n) because it will only do nums.size()-1 operations
    {
        int n0 = priority_queue.top();
        priority_queue.pop();
        int n1 = priority_queue.top();
        priority_queue.pop();

        int sum = n0 + n1;
        priority_queue.push(sum);
        
        ans += sum;
    }

	return ans;
}
