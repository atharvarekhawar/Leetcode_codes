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
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i < k; i++) {
            if (temp == NULL) {
                return NULL;
            }
            temp = temp->next;
        }

        return temp;
    }
    int getSize(ListNode* head) {
        ListNode* temp = head;
        int size = 0;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int size = getSize(head);
        k = k % size;

        if (k == 0) {
            return head;
        }

        ListNode* KthNode = getKthNode(head, size - k);
        ListNode* start = head;

        head = KthNode->next;
        KthNode->next = NULL;

        ListNode*temp = head;

        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=start;
       
        return head;
    }
};