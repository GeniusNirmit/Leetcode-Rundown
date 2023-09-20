class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int n = tickets.size();
        unordered_map<string, multiset<string>> adj;
        vector<string> path;
        for (int i = 0; i < n; i++)
            adj[tickets[i][0]].insert(tickets[i][1]);

        visit("JFK", adj, path);
        reverse(path.begin(), path.end());
        return path;
    }
    void visit(string current, unordered_map<string, multiset<string>> &adj, vector<string> &path)
    {
        while (adj[current].size())
        {
            string next = *adj[current].begin();
            adj[current].erase(adj[current].begin());
            visit(next, adj, path);
        }
        path.push_back(current);
    }
};