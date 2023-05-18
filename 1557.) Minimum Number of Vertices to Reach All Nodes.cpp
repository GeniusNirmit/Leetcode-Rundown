class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> vertices(n, true);
        vector<int> smallestVerticesSet;

        for(int i=0; i<edges.size(); i++)
        {
            for(int j=0; j<edges[0].size(); j++)
            {
                vertices[edges[i][1]] = false;
            }
        }

        for(int i=0; i<vertices.size(); i++)
        {
            if(vertices[i])
                smallestVerticesSet.push_back(i);
        }

        return smallestVerticesSet;
    }
};