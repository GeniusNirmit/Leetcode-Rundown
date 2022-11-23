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