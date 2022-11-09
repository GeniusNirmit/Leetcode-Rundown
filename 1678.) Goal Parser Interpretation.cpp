class Solution {
public:
    string interpret(string command) {
        string s;
        for(int i=0;i<command.size();i++)
        {
            if(i<command.size() && command[i]=='(' && command[i+1]=='a')
            {
                i+=3;
                s+="al";
            }
            else if(command[i]=='G')
                s+="G";
            else if(i<command.size())
            {
                i++;
                s+="o";
            }
        }
        return s;
    }
};