class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        set<int> s(a.begin(),a.end());
        if(!a.size())
            return 0;
        int counter = 0 , max_counter = 0;
        auto i = s.begin();
        int temp = *s.begin();
        for(i = s.begin();i!=s.end();++i)
        {
            if(i!=s.begin() && temp+1 == (*i))
                counter++;
            else
            {
                if(counter > max_counter)
                    max_counter = counter;
                counter=0;
            }
            temp = *i;
        }
        if(counter > max_counter)
            max_counter = counter;
        return max_counter+1;
    }
};