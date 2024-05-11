class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.length();
        string organizedString = "";
        priority_queue<pair<int, char>> pq;
        vector<int> mp(26, 0);

        for (int i = 0; i < n; i++)
            mp[s[i] - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            if (mp[i] > 0)
                pq.push({mp[i], i + 'a'});
        }

        while (pq.size() > 1)
        {
            pair<int, char> first = pq.top();
            pq.pop();
            pair<int, char> second = pq.top();
            pq.pop();

            first.first--;
            second.first--;
            organizedString += first.second;
            organizedString += second.second;

            if (first.first > 0)
                pq.push(first);
            if (second.first > 0)
                pq.push(second);
        }

        if (!pq.empty())
        {
            if (pq.top().first > 1)
                return "";
            else
                organizedString += pq.top().second;
        }

        return organizedString;
    }
};