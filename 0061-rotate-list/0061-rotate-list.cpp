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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy=head;
        int n=1;
        if(head==NULL ||k==0 ||head->next==NULL){
            return head;
        }
        while(dummy->next!=NULL){
            dummy=dummy->next;
            n++;
        }
        dummy=head;
        k=k%n;
        if(k==0){
            return head;
        }
        int pos=n-k;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(pos--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        ListNode* last=curr;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=head;
        return curr;
    }
};