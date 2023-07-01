class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        
        dfs(0, rooms, visited);
        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
                return false;
        }
        return true;
    }
    void dfs(int current, vector<vector<int>>& rooms, vector<bool>& visited) {
        visited[current] = true;

        for(int i=0; i<rooms[current].size(); i++)
        {
            if(!visited[rooms[current][i]])
                dfs(rooms[current][i], rooms, visited);
        }
    }
};