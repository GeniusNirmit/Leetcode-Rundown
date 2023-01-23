class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> firstPerson;
        unordered_map<int,int> secondPerson;
        for(int i=0;i<trust.size();i++)
        {
            firstPerson[trust[i][0]]++;
            secondPerson[trust[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(firstPerson.find(firstPerson[i+1])==firstPerson.end() && secondPerson[i+1] == (n-1))
                return i+1;
        }
        return -1;
    }
};