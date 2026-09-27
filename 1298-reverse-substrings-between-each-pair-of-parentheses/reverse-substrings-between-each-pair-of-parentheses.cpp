class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // Store index of '('
            } else if (s[i] == ')') {
                int start = st.top();
                st.pop();
                // Reverse everything strictly inside the current '(' and ')'
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        // Filter out '(' and ')' to build the final string
        string ans = "";
        for (char c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }
        
        return ans;
    }
};