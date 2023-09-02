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
        unordered_map<ListNode*,bool>m;

        ListNode* ans=NULL;
        ListNode* temp1=headA;
        ListNode* temp2=headB;


        while(temp1!=NULL && temp2!=NULL){
            if(m[temp1]==true){
                ans=temp1;
                break;
            }
            m[temp1]=true;
            if(m[temp2]==true){
                ans=temp2;
                break;
            }
            m[temp2]=true;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        while(temp1!=NULL){
            if(m[temp1]==true){
                ans=temp1;
                break;
            }
            temp1=temp1->next;
        }
         while(temp2!=NULL){
            if(m[temp2]==true){
                ans=temp2;
                break;
            }
            temp2=temp2->next;
        }

        return ans;
    }
};