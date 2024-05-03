class Solution
{
    vector<string> generatePermutations(string lockState)
    {
        vector<string> permutations;

        for (int i = 0; i < 8; i++)
        {
            string current = lockState;
            if (i % 2 == 0)
            {
                if (current[i / 2] == '9')
                    current[i / 2] = '0';
                else
                    current[i / 2]++;
            }
            else
            {
                if (current[i / 2] == '0')
                    current[i / 2] = '9';
                else
                    current[i / 2]--;
            }
            permutations.push_back(current);
        }

        return permutations;
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        int counter = 0;

        queue<string> q;
        unordered_set<string> visited(deadends.begin(), deadends.end());
        unordered_set<string> deadend(deadends.begin(), deadends.end());

        if (visited.find("0000") != visited.end())
            return -1;

        q.push("0000");
        visited.insert("0000");

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string current = q.front();
                q.pop();

                if (current == target)
                    return counter;

                vector<string> permutations = generatePermutations(current);

                for (int i = 0; i < permutations.size(); i++)
                {
                    if (visited.find(permutations[i]) == visited.end() && deadend.find(permutations[i]) == deadend.end())
                    {
                        q.push(permutations[i]);
                        visited.insert(permutations[i]);
                    }
                }
            }
            counter++;
        }
        return -1;
    }
};