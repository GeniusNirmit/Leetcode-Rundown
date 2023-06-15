class Solution {
public:
    unordered_map<string, int> map;
    vector<vector<string>> ladders;
    string begin;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        begin = beginWord;
        q.push(beginWord);
        map[beginWord] = 1;
        wordSet.erase(beginWord);
        while(!q.empty())
        {
            string currentWord = q.front();
            int steps = map[currentWord];
            q.pop();

            if(currentWord == endWord)
                break;

            for(int i=0; i<currentWord.size(); i++)
            {
                char origin = currentWord[i];
                for(char j='a'; j<='z'; j++)
                {
                    currentWord[i] = j;
                    if(wordSet.count(currentWord))
                    {
                        q.push(currentWord);
                        wordSet.erase(currentWord);
                        map[currentWord] = steps + 1;
                    }
                }
                currentWord[i] = origin;
            }
        }
        if(map.find(endWord) != map.end())
        {
            vector<string> ladder;
            ladder.push_back(endWord);
            dfs(endWord, ladder);
        }

        return ladders;
    }
    void dfs(string word, vector<string>& ladder) {
        if(word == begin)
        {
            reverse(ladder.begin(), ladder.end());
            ladders.push_back(ladder);
            reverse(ladder.begin(), ladder.end());
            return;
        }

        int steps = map[word];
        for(int i=0; i<word.length(); i++)
        {
            char origin = word[i];
            for(char j='a'; j<='z'; j++)
            {
                word[i] = j;
                if(map.find(word) != map.end() && map[word] + 1 == steps)
                {
                    ladder.push_back(word);
                    dfs(word, ladder);
                    ladder.pop_back();
                }
            }
            word[i] = origin;
        }
    }
};