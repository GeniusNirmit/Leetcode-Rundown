class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentGas = 0;
        int start = 0;
        int totalGas = 0;
        for(int i=0;i<gas.size();i++)
        {
            currentGas += (gas[i] - cost[i]);
            if(currentGas < 0)
            {
                totalGas += currentGas;
                currentGas = 0;
                start = i+1;
            }
        }
        if(totalGas + currentGas < 0)
            return -1;
        return start;
    }
};