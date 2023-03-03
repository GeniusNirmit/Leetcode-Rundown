class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, counter = 0;
        while(i < chars.size())
        {
            int j = 1;
            while(i + j < chars.size() && chars[i + j] == chars[i])
                j++;
            chars[counter] = chars[i];
            counter++;
            if(j > 1)
            {
                string temp = to_string(j);
                for(int i=0;i<temp.size();i++)
                {
                    chars[counter] = temp[i];
                    counter++;
                }
            }
            i += j;
        }
        return counter;
    }
};