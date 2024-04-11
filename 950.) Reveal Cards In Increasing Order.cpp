class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        vector<int> increasingDeck(n);
        queue<int> q;

        sort(deck.begin(), deck.end());

        for (int i = 0; i < n; i++)
            q.push(i);

        int ind = 0;
        bool flag = true;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            if (flag)
                increasingDeck[top] = deck[ind++];
            else
                q.push(top);
            flag = !flag;
        }

        return increasingDeck;
    }
};