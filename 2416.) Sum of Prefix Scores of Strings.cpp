class Node
{
private:
    Node *links[26];
    int flag = 0;
    int counter = 0;

public:
    bool containsKey(char ch)
    {
        if (!links[ch - 'a'])
            return 0;
        return links[ch - 'a'];
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void increaseCounter()
    {
        counter++;
    }

    void decreaseCounter()
    {
        counter--;
    }

    int getCounter()
    {
        return counter;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        int n = word.length();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
            node->increaseCounter();
        }
    }

    int getCounter(string word)
    {
        int n = word.length();
        Node *node = root;
        int counter = 0;

        for (int i = 0; i < n; i++)
        {
            node = node->get(word[i]);
            counter += node->getCounter();
        }

        return counter;
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();
        vector<int> scores;
        Trie t;

        for (int i = 0; i < n; i++)
            t.insert(words[i]);

        for (int i = 0; i < n; i++)
            scores.push_back(t.getCounter(words[i]));
        return scores;
    }
};