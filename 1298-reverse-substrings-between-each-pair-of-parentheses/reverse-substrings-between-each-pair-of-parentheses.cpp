class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                // Push '(' and alphabets
                st.push(s[i]);
            } else {
                // Pop all characters till '(' into a temp string (reverses order)
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                
                // Pop the opening '('
                if (!st.empty()) {
                    st.pop();
                }
                
                // Push the reversed characters back into the stack
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
        
        // Extract the final string from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Since popping from stack gives reverse order, reverse it once at the end
        reverse(ans.begin(), ans.end());
        return ans;
    }
};