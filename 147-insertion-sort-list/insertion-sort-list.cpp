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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* newHead = new ListNode(0);

        while(temp) {
            ListNode* prev = newHead;
            ListNode* nextNode = temp->next;
            while(prev->next && prev->next->val < temp->val) {
                prev = prev->next;
            }
            temp->next = prev->next;
            prev->next = temp;
            temp = nextNode;
        }
        return newHead->next;
    }
};