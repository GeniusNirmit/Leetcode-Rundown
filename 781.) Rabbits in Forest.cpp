class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> uniqueRabbits;
        int totalRabbits = 0;
        for(int i=0;i<answers.size();i++)
            uniqueRabbits[answers[i]]++;
        for(auto i:uniqueRabbits)
            totalRabbits += ((i.second+i.first)/(i.first+1))*(i.first+1);
        return totalRabbits;
    }
};