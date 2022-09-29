class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int n=ops.size();
        int num,temp;
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="+")
            {
                num=s.top();
                s.pop();
                temp=num+s.top();
                s.push(num);
                s.push(temp);
            }
            else if(ops[i]=="D")
                s.push(s.top()*2);
            else if(ops[i]=="C")
                s.pop();
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};