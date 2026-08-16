class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string> arr;
        string str = "";

        for (char ch : s) {
            if (ch != ' ') {
                str += ch;
            }
            else {
                if (!str.empty()) {
                    arr.push_back(str);
                    str = "";
                }
            }
        }

        // Don't forget the last word
        if (!str.empty()) {
            arr.push_back(str);
        }
        if(pattern.length() != arr.size()) return false;
        for(int i = 0; i < pattern.length() ; i++){
            char a = pattern[i];
            string st = arr[i];

            if(mp1.count(a)){
                if(mp1[a] != st) return false;
            }
            if(mp2.count(st)){
                if(mp2[st] != a) return false;
            }

            mp1[a] = st;
            mp2[st] = a;
        }

        return true;
    }
};