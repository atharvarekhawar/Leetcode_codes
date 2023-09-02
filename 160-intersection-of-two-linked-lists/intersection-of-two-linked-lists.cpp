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
    int length(ListNode *temp1, ListNode *temp2){
        int len1=0;
        int len2=0;

        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL){
                len1++;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                len2++;
                temp2=temp2->next;
            }
        }

        return len1-len2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = length(headA,headB);
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        if(diff<0){
            diff=abs(diff);
            while(diff>0){
                temp2=temp2->next;
                diff--;
            }
        }
        else{
            diff=abs(diff);
            while(diff>0){
                temp1=temp1->next;
                diff--;
            }
        }

        ListNode* ans=NULL;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                ans=temp1;
                break;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return ans;
    }
};