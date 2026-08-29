class Solution {
    vector<int> isPossible(int n, vector<int> &currentPos, char dir) {
        int xInd = currentPos[0];
        int yInd = currentPos[1];

        if(dir == 'D' && xInd + 1 <= n - 1) {
            return {xInd + 1, yInd};
        }

        if(dir == 'U' && xInd - 1 >= 0) {
            return {xInd - 1, yInd};
        }

        if(dir == 'L' && yInd - 1 >= 0) {
            return {xInd, yInd - 1};
        }

        if(dir == 'R' && yInd + 1 <= n - 1) {
            return {xInd, yInd + 1};
        }

        return {-1, -1};
    }
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.length();
        vector<int> instructions(m, 0);

        for(int i = 0; i < m; i++) {
            vector<int> currentPos = startPos;

            instructions[i] = m - i;
            
            for(int j = i; j < m; j++) {
                currentPos = isPossible(n, currentPos, s[j]);
                
                if(currentPos[0] == -1) {
                    instructions[i] = j - i;
                    break;
                }
            }
        }

        return instructions;
    }
};