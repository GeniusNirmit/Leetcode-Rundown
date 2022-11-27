// Approach-1

class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulb(n+1,false);
        int counter = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j+=i)
                bulb[j] = !bulb[j];
        }
        for(int i=1;i<bulb.size();i++)
        {
            if(bulb[i])
                counter++;
        }
        return counter;
    }
};

// Approach-2

class Solution {
public:
    int bulbSwitch(int n) {
        int counter=0,i=1;
        while(i*i<= n) 
        {
            counter++;
            i++;
        }
        return counter;
    }
};