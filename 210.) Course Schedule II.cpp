class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> topoSort;

        for(int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for(int i=0; i<numCourses; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            topoSort.push_back(current);

            for(int i=0; i<adj[current].size(); i++)
            {
                indegree[adj[current][i]]--;
                if(indegree[adj[current][i]] == 0)
                    q.push(adj[current][i]);
            }
        }

        if(topoSort.size() == numCourses)
            return topoSort;
        return {};
    }
};