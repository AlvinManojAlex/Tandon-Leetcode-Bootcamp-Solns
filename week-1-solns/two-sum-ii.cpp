class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        // Using two pointer approach; Pointers at the end of arrays
        int left = 0;
        int right = numbers.size() - 1;

        vector<int> ans(2);

        // Iterating through loop until left == right
        while (left < right) {

            // If sum is less, means next big number at left + 1
            if (numbers[left] + numbers[right] < target) {
                left += 1;
            }

            // If sum is more, means next smallest number at right - 1
            else if (numbers[left] + numbers[right] > target) {
                right -= 1;
            }

            // If equal, then store answer and break
            else {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            }
        }

        return ans;
    }
};