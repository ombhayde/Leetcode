/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;
        Node* it=head;
        while(it){
            Node* cloned=new Node(it->val);
            cloned->next=it->next;
            it->next=cloned;
            it=it->next->next;
        }
        it=head;
        while(it){
            Node* clonedNode=it->next;
            clonedNode->random=it->random?it->random->next:NULL;
            it=it->next->next;
        }
        it=head;
        Node* clonedHead=it->next;
        while(it){
            Node* clonedNode=it->next;
            it->next=it->next->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            it=it->next;
        }
        return clonedHead;
    }
};