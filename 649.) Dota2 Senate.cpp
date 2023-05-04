class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> voteQ;
        int rCounter = 0, dCounter = 0, rBanned = 0, dBanned = 0;
        for(int i=0; i<senate.size(); i++)
        {
            voteQ.push(senate[i]);
            if(senate[i] == 'D')
                dCounter++;
            else
                rCounter++;
        }

        while(rCounter && dCounter)
        {
            char current = voteQ.front();
            voteQ.pop();
            if(current == 'R')
            {
                if(rBanned)
                {
                    rBanned--;
                    rCounter--;
                }
                else
                {
                    dBanned++;
                    voteQ.push('R');
                }
            }
            else
            {
                if(dBanned)
                {
                    dBanned--;
                    dCounter--;
                }
                else
                {
                    rBanned++;
                    voteQ.push('D');
                }
            }
        }

        if(dCounter)
            return "Dire";
        return "Radiant";
    }
};