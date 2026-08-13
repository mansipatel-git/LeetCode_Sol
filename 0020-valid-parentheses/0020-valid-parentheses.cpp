class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s){
            if(ch == '{' || ch == '(' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty()) return false;

                char tp  = st.top();
                st.pop();
                if((ch == ')'  && tp != '(') || (ch == '}' && tp != '{') || (ch == ']' && tp != '['))return false;
            }
            

        }
        return st.empty();
    }
};