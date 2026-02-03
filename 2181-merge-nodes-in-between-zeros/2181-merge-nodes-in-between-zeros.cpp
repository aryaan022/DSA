class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;  
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        int sum = 0;

        while (curr != nullptr) {
            if (curr->val == 0) {
                
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
