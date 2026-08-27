class TaskManager {
    priority_queue<pair<int, int>> pq;
    unordered_map<int, pair<int, int>> mp;
public:
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i = 0; i < n; i++) {
            pq.push({tasks[i][2], tasks[i][1]});
            mp[tasks[i][1]] = {tasks[i][0], tasks[i][2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        int userId = mp[taskId].first;
        mp[taskId] = {userId, newPriority};
        pq.push({newPriority    , taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()) {
            int priority = pq.top().first;
            int taskId = pq.top().second;
            pq.pop();

            if(mp.find(taskId) == mp.end()) {
                continue;
            }

            if(mp[taskId].second != priority) {
                continue;
            }

            int userId = mp[taskId].first;
            mp.erase(taskId);

            return userId;
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */