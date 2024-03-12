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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> sumMap;
        int sum = 0;
        sumMap[0] = dummy;
        
        while (head) {
            sum += head->val;
            sumMap[sum] = head;
            head = head->next;
        }
        
        sum = 0;
        head = dummy;
        while (head) {
            sum += head->val;
            if (sumMap.find(sum) != sumMap.end()) {
                ListNode* start = sumMap[sum]->next;
                if (start != head) {
                    sumMap.erase(sum);
                    head->next = start;
                }
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};