/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        int row = 0, col = 0, dirInd = 0;
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> mat(m, vector<int>(n, -1));

        while (head)
        {
            mat[row][col] = head->val;
            head = head->next;

            int newRow = row + dir[dirInd].first;
            int newCol = col + dir[dirInd].second;

            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n || mat[newRow][newCol] != -1)
            {
                dirInd++;
                dirInd %= 4;
            }

            row += dir[dirInd].first;
            col += dir[dirInd].second;
        }
        return mat;
    }
};