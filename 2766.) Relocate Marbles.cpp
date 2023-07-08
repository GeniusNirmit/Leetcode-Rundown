class Solution {
public:
    vector<int> relocateMarbles(vector<int>& a, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> occupied;
        set<int> st(a.begin(), a.end());

        for(int i=0; i<moveFrom.size(); i++)
        {
            st.erase(st.find(moveFrom[i]));
            st.insert(moveTo[i]);
        }

        for(auto i: st)
            occupied.push_back(i);
        return occupied;
    }
};