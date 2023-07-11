class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distances(n, vector<int> (n, INT_MAX));
        int city = -1;
        int adjCityCounter = n;

        for(int i=0; i<edges.size(); i++)
        {
            distances[edges[i][0]][edges[i][1]] = edges[i][2];
            distances[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int i=0; i<n; i++)
            distances[i][i] = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    if(distances[j][i] == INT_MAX || distances[i][k] == INT_MAX)
                        continue;
                    distances[j][k] = min(distances[j][k], distances[j][i] + distances[i][k]);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            int counter = 0;
            for(int j=0; j<n; j++)
            {
                if(distances[i][j] <= distanceThreshold)
                    counter++;
            }

            if(counter <= adjCityCounter)
            {
                city = i;
                adjCityCounter = counter;
            }
        }

        return city;
    }
};