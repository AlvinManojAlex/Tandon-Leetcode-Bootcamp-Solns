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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count = 1;
        while(temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }

        n = count-n+1;
        count=1;
        temp = head;

        if(n == 1)
        {
            temp = temp->next;
            return temp;
        }
        else
        {
            while(temp->next != NULL)
            {
                if(count + 1 == n)
                {
                    temp->next = temp->next->next;
                    break;
                }
                count++;
                temp = temp->next;
            }
            return head;
        }
        
    }
};