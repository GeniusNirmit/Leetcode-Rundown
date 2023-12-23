class Solution
{
public:
    bool isPathCrossing(string path)
    {
        int n = path.size();
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1};
        moves['S'] = {0, -1};
        moves['W'] = {-1, 0};
        moves['E'] = {1, 0};

        unordered_set<string> visited;
        visited.insert("0,0");

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++)
        {
            pair<int, int> current = moves[path[i]];
            int dx = current.first;
            int dy = current.second;
            x += dx;
            y += dy;

            string hash = to_string(x) + "," + to_string(y);
            if (visited.find(hash) != visited.end())
                return true;
            visited.insert(hash);
        }

        return false;
    }
};