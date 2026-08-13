class Solution {
public:
    string removeSpace(string s){
        string ans = "";
        for(char c : s){
            if (isalnum(c)) {
                ans += tolower(c);
            }

        }
        return ans;
    }
    bool isPalindrome(string s) {
        string str = removeSpace(s);

        int l = 0;
        int r = str.length() -1;
        while( l < r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;

    }
};