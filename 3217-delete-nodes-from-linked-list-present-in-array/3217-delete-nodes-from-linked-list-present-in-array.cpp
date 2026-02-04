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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (binary_search(nums.begin(), nums.end(), curr->val)) {
                if (prev == nullptr) {
                    head = curr->next;
                    //delete curr;
                    curr = head;
                }
                else {
                    prev->next = curr->next;
                    //delete curr;
                    curr = prev->next;
                }
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
