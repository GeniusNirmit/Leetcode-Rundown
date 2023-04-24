class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& a, int k, int x) {
        map<int, int> window;
        vector<int> beauties;
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] < 0)
                window[a[i]]++;

            if(i+1 >= k)
            {
                int counter = x;
                auto it = window.begin();
                while(it != window.end() && counter > 0)
                {
                    counter -= it->second;
                    it++;
                }
                if(counter > 0)
                    beauties.push_back(0);
                else
                {
                    it--;
                    beauties.push_back(it->first);
                }

                if(a[i-k+1] < 0)
                {
                    window[a[i-k+1]]--;
                    if(window[a[i-k+1]] == 0)
                        window.erase(a[i-k+1]);
                }
            }
        }
        return beauties;
    }
};