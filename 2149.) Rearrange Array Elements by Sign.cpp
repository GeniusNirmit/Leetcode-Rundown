// Approach-1

class Solution {
public:
	vector<int> rearrangeArray(vector<int>& a) {
		vector<int> v(a.size(),0);
        int x=0,y=1;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>0)
            {
                v[x]=a[i];
                x += 2;
            }
            else
            {
                v[y]=a[i];
                y += 2;
            }
        }
        return v;
	}
};

// Approach-2

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int> positive;
        vector<int> negative;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>=0)
                positive.push_back(a[i]);
            else
                negative.push_back(a[i]);
        }
        a.clear();
        for(int i=0;i<positive.size();i++)
        {
            a.push_back(positive[i]);
            a.push_back(negative[i]);
        }
        return a;
    }
};