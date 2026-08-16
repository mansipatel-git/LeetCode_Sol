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
    void LLToArr(ListNode* head , vector<int>&a){
        if(!head) return ;

        while(head){
            a.push_back(head->val);
            head = head->next;
        }
        
    }

    ListNode* ArrToLL(vector<int>& arr) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i = 0; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        vector<int>a;
        LLToArr(head, a);
        sort(a.begin() , a.end());
        return ArrToLL(a);
    }
};