class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> uglyNumbers,possibleNumbers;
        possibleNumbers.insert(1);
        while(uglyNumbers.size() != n)
        {
            uglyNumbers.insert(*possibleNumbers.begin());
            possibleNumbers.insert(*possibleNumbers.begin()*2);
            possibleNumbers.insert(*possibleNumbers.begin()*3);
            possibleNumbers.insert(*possibleNumbers.begin()*5);
            possibleNumbers.erase(possibleNumbers.begin());
        }
        return *uglyNumbers.rbegin();
    }
};  