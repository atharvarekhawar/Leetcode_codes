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
        Node* temp = head;

        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;

        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp=temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;

        temp=head;

        while(temp!=NULL){
            res->next = temp->next;
            Node* nextNode = temp->next->next;
            temp->next->next = NULL;
            temp->next = nextNode;
            temp=temp->next;
            res=res->next;
        }

        return dummy->next;
    }
};