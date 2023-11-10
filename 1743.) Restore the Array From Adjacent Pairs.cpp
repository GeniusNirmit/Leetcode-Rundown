class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int n = adjacentPairs.size();
        vector<int> originalArray;
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            indegree[adjacentPairs[i][0]]++;
            indegree[adjacentPairs[i][1]]++;
            adj[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adj[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int start;
        for (auto i : indegree)
        {
            if (i.second == 1)
            {
                start = i.first;
                break;
            }
        }

        originalArray.push_back(start);
        traversal(start, originalArray, indegree, adj);
        return originalArray;
    }
    void traversal(int current, vector<int> &originalArray, unordered_map<int, int> &indegree, unordered_map<int, vector<int>> &adj)
    {
        if (indegree[current] == 0)
            return;

        int next;
        for (auto i : adj[current])
        {
            if (indegree[i] != 0)
            {
                next = i;
                break;
            }
        }
        indegree[current]--;
        indegree[next]--;
        originalArray.push_back(next);
        traversal(next, originalArray, indegree, adj);
    }
};