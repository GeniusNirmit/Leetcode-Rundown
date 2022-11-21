class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int counter = 0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++)
        {            
            int l = 0, h = arr2.size()-1, mid;
            while(l<=h)
            {
                mid = (l+h)/2;
                if(abs(arr1[i]-arr2[mid]) <= d)
                {
                    counter++;
                    l = h+1;
                }
                else if(arr2[mid] > arr1[i])
                    h = mid - 1;
                else       
                    l = mid + 1;
            }
        }
        return arr1.size()-counter;
    }
};