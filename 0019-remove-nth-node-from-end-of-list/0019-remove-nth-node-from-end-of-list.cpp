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
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if(!head) return head;
        if(n  == len){
            ListNode* temp = head;
            temp = head->next;
            delete head;
            return temp;

        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i = 0; i < len - n ; i++){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
       // delete(curr);
        return head;
    }
};