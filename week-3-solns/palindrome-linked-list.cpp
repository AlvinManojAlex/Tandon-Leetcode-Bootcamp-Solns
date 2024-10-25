/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        bool ans = true;

        while(head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }

        int n = vec.size();

        for(int i = 0 ; i < n/2 ; i++){
            if (vec[i] != vec[n - 1 - i]){
                ans = false;
            }
        }

        return ans;
    }
};