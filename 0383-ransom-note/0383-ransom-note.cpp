class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> f1;
        for (char x : ransomNote) {
            f1[x]++;
        }

        unordered_map<char, int> f2;
        for (char x : magazine) {
            f2[x]++;
        }

        
        for(auto x : f1){
            char ch = x.first;
            int needed = x.second;

            if(needed > f2[ch]) return false;
        }

        return true;
    }
};