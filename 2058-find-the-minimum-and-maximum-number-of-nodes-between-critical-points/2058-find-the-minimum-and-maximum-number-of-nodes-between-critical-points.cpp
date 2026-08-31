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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nodes;
        ListNode* curr = head;
        while(curr){
            nodes.push_back(curr->val);
            curr = curr->next;
        }

        int n = nodes.size();

        vector<int>criticalPoint;

        for(int i = 1 ; i < n-1 ; i++){
            if((nodes[i] > nodes[i-1] && nodes[i] > nodes[i+1]) ||
                (nodes[i] < nodes[i-1] && nodes[i] < nodes[i+1])){
                    criticalPoint.push_back(i);

            }
        }

        


        if(criticalPoint.size() < 2)
            return {-1, -1};
        
        int minDistance = INT_MAX;

        for(int i = 1; i < criticalPoint.size(); i++){
            minDistance = min(minDistance,
                              criticalPoint[i] - criticalPoint[i-1]);
        }

        int maxDistance =
            criticalPoint.back() - criticalPoint.front();

        return {minDistance, maxDistance};



       




        

    }
};