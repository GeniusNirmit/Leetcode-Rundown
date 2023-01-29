class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> participants;
        for(int i=0;i<n;i++)
            participants.push(i+1);
        while(participants.size()>1)
        {
            int counter = k-1;
            while(counter--)
            {
                participants.push(participants.front());
                participants.pop();
            }
            participants.pop();
        }
        return participants.front();
    }
};