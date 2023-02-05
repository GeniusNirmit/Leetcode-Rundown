class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int> gift(gifts.begin(),gifts.end());
        long long sum = 0;
        while(k--)
        {
            auto maxGift = gift.rbegin();
            gift.insert(sqrt(*maxGift));
            gift.erase(gift.find(*maxGift));
        }
        for(auto i:gift)
            sum += i;
        return sum;
    }
};