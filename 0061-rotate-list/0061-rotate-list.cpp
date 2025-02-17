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
    int getLen(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        int len=getLen(head);
        int actual=k%len;
        if(actual==0) return head;
        int newpos=len-actual-1;
        ListNode* newLastNode=head;
        for(int i=0;i<newpos;i++){
            newLastNode=newLastNode->next;
        }
        ListNode* newHead=newLastNode->next;
        newLastNode->next=NULL;
        ListNode* it=newHead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};