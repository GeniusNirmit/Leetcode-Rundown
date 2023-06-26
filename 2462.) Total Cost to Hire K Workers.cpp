class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long finalCost = 0;
        multiset<int> left(costs.begin(), costs.begin()+candidates);
        multiset<int> right(costs.rbegin(), costs.rbegin()+candidates);
        multiset<int> remains(costs.begin(), costs.end());
        int leftInd = candidates, rightInd = costs.size() - candidates - 1;
        while(k--)
        {
            if(*left.begin() <= *right.begin())
            {
                auto beginIt = remains.find(*left.begin());
                finalCost += *left.begin();
                left.erase(left.begin());
                left.insert(costs[leftInd++]);
                remains.erase(beginIt);
                if(leftInd > rightInd)
                    break;
            }
            else
            {
                auto beginIt = remains.find(*right.begin());
                finalCost += *right.begin();
                right.erase(right.begin());
                right.insert(costs[rightInd--]);
                remains.erase(beginIt);
                if(leftInd > rightInd)
                    break;
            }
        }

        while(k--)
        {
            finalCost += *remains.begin();
            remains.erase(remains.begin());
        }
        return finalCost;
    }
};