class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        while(!q.empty())
        {
            string currentWord = q.front().first;
            int counter = q.front().second;
            q.pop();

            for(int i=0; i<currentWord.size(); i++)
            {
                char origin = currentWord[i];
                for(char j='a'; j<='z'; j++)
                {
                    currentWord[i] = j;
                    if(wordSet.find(currentWord) != wordSet.end())
                    {
                        wordSet.erase(currentWord);
                        q.push({ currentWord, counter + 1});
                    }
                }
                currentWord[i] = origin;
            }

            if(currentWord == endWord)
                return counter;
        }
        return 0;
    }
};