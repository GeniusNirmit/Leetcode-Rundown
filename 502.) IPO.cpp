class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multiset<int> queue;
        vector<pair<int,int>> projects;
        int currentCapital = w;
        for(int i=0;i<profits.size();i++)
            projects.push_back(make_pair(capital[i],profits[i]));
        
        sort(projects.begin(),projects.end());

        int i = 0;
        while(i<projects.size() && k)
        {
            if(currentCapital < projects[i].first)
            {
                if(!queue.size())
                    return currentCapital;
                currentCapital += *queue.rbegin();
                queue.erase(queue.find(*queue.rbegin()));
                k--;
            }
            else
            {
                queue.insert(projects[i].second);
                i++;
            }
        }
        while(k-- && !queue.empty())
        {        
            currentCapital += *queue.rbegin();
            queue.erase(queue.find(*queue.rbegin()));
        }
        return currentCapital;
    }
};