/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool>store;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        

        while(temp1!=NULL){
            store[temp1]=true;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            if(store[temp2]==true){
                return temp2;
            }
            store[temp1]=true;
            temp2=temp2->next;
        }

        return NULL;

    }
};