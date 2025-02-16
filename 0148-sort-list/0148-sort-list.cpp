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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1==0) return list2;
        if(list2==0) return list1;

        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }else{
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }
        if(list1!=NULL){
            mptr->next=list1;
        }
        if(list2!=NULL){
            mptr->next=list2;
        }
        return ans->next;
        
    }
    ListNode* findMid(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==0||head->next==0){
            return head;
        }
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=0;

        left=sortList(left);
        right=sortList(right);

        ListNode* mergedLL=merge(left,right);
        return mergedLL;
    }
};