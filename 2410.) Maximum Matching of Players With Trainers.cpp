class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int counter = 0, i = 0, j = 0;
        while(i < players.size() && j < trainers.size())
        {
            if(players[i] <= trainers[j])
            {
                counter++;
                i++;
            }
            j++;
        }
        return counter;
    }
};