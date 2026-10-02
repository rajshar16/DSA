class Solution {
public:
    void backtrack(vector<string>& result, string current_string, int open_count, int close_count, int n) {
        // Base case: The string is fully formed when its length is 2 * n
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }
        
        // Rule 1: We can add an open parenthesis if we haven't reached 'n' yet
        if (open_count < n) {
            backtrack(result, current_string + "(", open_count + 1, close_count, n);
        }
        
        // Rule 2: We can add a close parenthesis if there are unmatched open ones
        if (close_count < open_count) {
            backtrack(result, current_string + ")", open_count, close_count + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start the recursion with an empty string and 0 counts
        backtrack(result, "", 0, 0, n);
        return result;
    }
};