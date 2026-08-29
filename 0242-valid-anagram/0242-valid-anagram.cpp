class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : t) {

            freq[ch]--;

            if (freq[ch] < 0) {
                return false;
            }
        }

        return true;
    }
};