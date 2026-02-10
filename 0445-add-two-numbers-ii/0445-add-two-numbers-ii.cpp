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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        stack<int>s1;
        stack<int>s2;

        while(l1!=nullptr){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2=l2->next;
        }

        ListNode* ans= new ListNode();
        int ts=0;

        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                ts=ts+s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                ts=ts+s2.top();
                s2.pop();
            }
            ans->val=ts%10;
            carry=ts/10;
            ListNode* newnode = new ListNode(carry);
            newnode->next=ans;
            ans = newnode;
            ts=carry;
        }
        if(carry==0){

        return ans->next;
        }
        return ans;


    }
};