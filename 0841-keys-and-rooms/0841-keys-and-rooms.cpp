class Solution {
public:
    void bfs(vector<vector<int>>& rooms, vector<int>&vis){
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int n : rooms[x]){
                if(!vis[n]){
                    vis[n] = 1;
                    q.push(n);
                }
            }
        }


    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n , 0);
        bfs(rooms,vis);

        for(int x : vis){
            if(x == 0) return false;
        }

        return true;
    }
};