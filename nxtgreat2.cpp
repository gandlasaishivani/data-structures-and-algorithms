class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize the result vector with -1
        stack<int> s;

        // We iterate twice over the array to simulate the circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Use modulo to wrap around the array
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i % n] = s.top();
            }
            s.push(nums[i % n]);
        }

        return ans;
    }
};
