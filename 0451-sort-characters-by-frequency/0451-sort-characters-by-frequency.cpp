class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        priority_queue<pair<int ,char>>pq;
        for(auto it : mp){
            pq.push({it.second, it.first});

        }

        string str = "" ;

        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for(int i = 0; i < freq ; i++){
                str += ch;
            }
        }

        return str;



    }
};