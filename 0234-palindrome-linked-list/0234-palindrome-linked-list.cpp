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
    ListNode* reverse(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=curr->next;
        while(curr!=NULL){
            forward = curr->next; // Save the next node
            curr->next = prev;    // Reverse the current node
            prev = curr;          // Move `prev` forward
            curr = forward; 
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode* reverseKaHead=reverse(slow->next);
        ListNode* t1=head;
        ListNode* t2=reverseKaHead;
        while(t2!=NULL){
            if(t1->val!=t2->val){
                return false;
            }else{
                t1=t1->next;
                t2=t2->next;
            }
        }
        return true;
        
    }
};