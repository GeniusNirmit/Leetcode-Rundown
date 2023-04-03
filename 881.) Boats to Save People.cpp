class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int counter = 0;

        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
                i++;
            counter++;
            j--;
        }

        return counter;
    }
};