class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> taskMap;
        int counter = 0;
        for(int i=0;ai<tasks.size();i++)
            taskMap[tasks[i]]++;
        for(auto i:taskMap)
        {
            if(i.second < 2)
                return -1;
            else
            {
                if(i.second%3==0)
                    counter += i.second/3;
                else
                    counter += i.second/3+1;
            }
        }
        return counter;
    }
};