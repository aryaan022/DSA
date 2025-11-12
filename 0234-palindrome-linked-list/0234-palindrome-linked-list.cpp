class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* current = slow;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    ListNode* firstHalf = head;
    ListNode* secondHalf = prev;

    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
};