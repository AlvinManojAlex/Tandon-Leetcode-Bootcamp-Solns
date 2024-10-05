class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // Define vectors with initial value 1
        vector<int> ans(nums.size(), 1);
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        // Computing prefix values
        for (int i = 1; i<nums.size() ; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Computing suffix values
        for (int i = nums.size() - 2 ; i >= 0 ; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Computing answer by multiplying suffix and prefix (will contain product values except self element)
        for (int i = 0 ; i < nums.size() ; i++){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};