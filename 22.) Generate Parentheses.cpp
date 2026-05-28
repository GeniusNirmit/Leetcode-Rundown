class Solution {
public:
    void generate(int n, int openCount, int closeCount, string current, vector<string> &parentheses) {
        if(current.length() == 2 * n) {
            parentheses.push_back(current);
            return;
        }

        if(openCount < n) {
            generate(n, openCount + 1, closeCount, current + "(", parentheses);
        }

        if(closeCount < openCount) {
            generate(n, openCount, closeCount + 1, current + ")", parentheses);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> parentheses;

        generate(n, 0, 0, "", parentheses);
        
        return parentheses;
    }
};