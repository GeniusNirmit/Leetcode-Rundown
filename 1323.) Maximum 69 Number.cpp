class Solution {
public:
    int maximum69Number (int num) {
        string temp;
        while(num)
        {
            temp.push_back('0'+(num%10));
            num/=10;
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='6')
            {
                temp[i]='9';
                break;
            }
        }
        return stoi(temp);
    }
};