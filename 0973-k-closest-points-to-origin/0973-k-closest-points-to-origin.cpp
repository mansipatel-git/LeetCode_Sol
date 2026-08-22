class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int n = points.size();

        for(auto &e : points){
            int x = e[0];
            int y = e[1];

            int dist = x * x + y * y;

            if(pq.size() < k){
                pq.push({dist,{x,y}});
            }else if(pq.top().first > dist){
                pq.pop();
                pq.push({dist,{x,y}});
            }
        }


        vector<vector<int>>ans;

        for(int i = 0; i < k ; i++){
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second;

            ans.push_back({x,y});


        }

        return ans;
    
    }
};