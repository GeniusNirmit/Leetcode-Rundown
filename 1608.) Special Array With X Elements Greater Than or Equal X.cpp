class Solution {
public:
    int specialArray(vector<int>& a) {
        int l = 1, h = a.size(), mid;
        int counter = 0;
		while(l <= h)
        {
			counter = 0;
            mid = (l+h)/2;
			for(int k=0; k<a.size(); k++)
            {
				if(a[k] >= mid)
                    counter++;
			}
			if(counter == mid) 
                return mid;
			else if(counter < mid) 
                h = mid - 1;
			else
                l = mid + 1;
		}
		return -1;
    }
};