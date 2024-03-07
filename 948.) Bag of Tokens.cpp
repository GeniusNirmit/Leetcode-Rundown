class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());

        int start = 0, end = n - 1;
        int score = 0, maxScore = 0;
        while (start <= end)
        {
            if (tokens[start] <= power)
            {
                power -= tokens[start];
                score++;
                start++;
            }
            else
            {
                power += tokens[end];
                score--;
                end--;
            }
            if (score < 0)
                return 0;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};