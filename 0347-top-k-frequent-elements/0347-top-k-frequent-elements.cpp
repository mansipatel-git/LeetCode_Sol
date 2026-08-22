class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        unordered_map<int,int>mp;

        for(int x : nums){
            mp[x]++;
        }

        for (auto it : mp) {

            if (pq.size() < k) {
                pq.push({it.second, it.first});
            }
            else if (it.second > pq.top().first) {
                pq.pop();
                pq.push({it.second, it.first});
            }

        }


        vector<int>ans;

        for(int i  =0; i < k ; i++){
            int tp = pq.top().second;
            pq.pop();

            ans.push_back(tp);
        }

        return ans;


    }
};