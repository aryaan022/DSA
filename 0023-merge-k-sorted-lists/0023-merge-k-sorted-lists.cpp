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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummyHead =new  ListNode(-1);
        ListNode* dummyTail =dummyHead;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        //pushing every first node and whole node in the prieority quueu
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        //step 2
        while(!pq.empty()){
            ListNode* minnode=pq.top().second; //yha pr hum node ka addressstore krre hai
            pq.pop();
            if(minnode->next!=NULL){
                pq.push({minnode->next->val,minnode->next});
            }
            dummyTail->next=minnode;
            dummyTail=dummyTail->next;
        }
        return dummyHead->next;

    }
};