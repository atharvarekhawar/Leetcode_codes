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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;

        while(curr!=NULL){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
    ListNode* getKthNode(ListNode* head,int k){
        ListNode* temp = head;
        for(int i=1;i<k;i++){
            if(temp==NULL){
                return NULL;
            }
            temp=temp->next;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while(temp!=NULL){
            ListNode* KthNode = getKthNode(temp,k);
            if(KthNode==NULL){
                if(nextNode){
                    prevNode->next = temp;
                }
                break;
            }

            nextNode = KthNode->next;
            KthNode->next=NULL;
            reverse(temp);

            if(temp==head){
                head = KthNode;
            }else{
                prevNode->next=KthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;

    }
};