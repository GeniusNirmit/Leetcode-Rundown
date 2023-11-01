class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> modes;
        int currentStreak = 0, maxStreak = 0, currentVal = 0;

        dfs(root, modes, currentStreak, maxStreak, currentVal);
        return modes;
    }
    void dfs(TreeNode *root, vector<int> &modes, int &currentStreak, int &maxStreak, int &currentVal)
    {
        if (!root)
            return;

        dfs(root->left, modes, currentStreak, maxStreak, currentVal);

        if (root->val == currentVal)
            currentStreak++;
        else
        {
            currentStreak = 1;
            currentVal = root->val;
        }

        if (currentStreak > maxStreak)
        {
            modes.clear();
            maxStreak = currentStreak;
        }

        if (currentStreak == maxStreak)
            modes.push_back(currentVal);

        dfs(root->right, modes, currentStreak, maxStreak, currentVal);
    }
};