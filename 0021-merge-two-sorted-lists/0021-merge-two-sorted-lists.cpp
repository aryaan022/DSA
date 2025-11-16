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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1 !=NULL && p2 !=NULL){
            if(p1->val >p2->val){
                tail->next=p2;
                p2=p2->next;
            }else{
                tail->next=p1;
                p1=p1->next;
            }
            tail = tail->next;
        }
        if(p1==NULL){
            tail->next =p2;
        }if(p2==NULL){
            tail->next=p1;
        }
        return ans->next;
    }
};