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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Return the head itself for empty or single-node lists
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move `fast` two steps and `slow` one step until `fast` reaches the end
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // When `fast` reaches the end, `slow` will be at the middle node
        return slow;
    }
};
