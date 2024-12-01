class Solution {
public:

    int solve(vector<vector<int>> &dp, vector<int> &nums, int i, int sum) {
        if (sum == 0) {
            return true;
        }

        if (sum < 0 || i >= nums.size()) {
            return false;
        }

        bool ans = false;

        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        return dp[i][sum] = solve(dp, nums, i + 1, sum - nums[i]) || solve(dp, nums, i + 1, sum);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
        }
        
        vector<vector<int>> dp(nums.size(), vector<int> (sum + 1, -1));

        if (sum % 2 != 0) {
            return false;
        }

        else {
            return solve(dp, nums, 0, sum / 2);
        }
    }
};