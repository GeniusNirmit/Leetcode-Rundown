class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int n = commands.size();
        int m = obstacles.size();
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirInd = 0;
        int x = 0;
        int y = 0;
        int maxDist = 0;

        unordered_set<string> st;

        for (int i = 0; i < m; i++)
            st.insert(to_string(obstacles[i][0]) + "," + to_string(obstacles[i][1]));

        for (int i = 0; i < n; i++)
        {
            cout << dirInd << endl;
            if (commands[i] == -1)
                dirInd = (dirInd + 1) % 4;
            else if (commands[i] == -2)
                dirInd = (dirInd + 3) % 4;
            else
            {
                for (int j = 0; j < commands[i]; j++)
                {
                    int nextX = x + dir[dirInd].first;
                    int nextY = y + dir[dirInd].second;
                    string strCoordinates = to_string(nextX) + "," + to_string(nextY);

                    if (st.find(strCoordinates) != st.end())
                    {
                        cout << "Hey";
                        maxDist = max(maxDist, x * x + y * y);
                        break;
                    }

                    cout << x << " " << y << " " << nextX << " " << nextY << " " << dirInd << endl;
                    x = nextX;
                    y = nextY;
                }

                maxDist = max(maxDist, x * x + y * y);
            }
        }

        return maxDist;
    }
};