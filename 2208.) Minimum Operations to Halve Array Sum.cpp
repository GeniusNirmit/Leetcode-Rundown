class Solution {
public:
    int halveArray(vector<int>& a) {
        double initialSum = 0;
        double currentSum = 0;
        int counter = 0;
        multiset<double> operationElements(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
            initialSum += a[i];
        currentSum = initialSum;
        while(currentSum > initialSum/2.0)
        {
            double endElement = *operationElements.rbegin();
            currentSum -= endElement/2.0;
            operationElements.erase(operationElements.lower_bound(endElement));
            operationElements.insert(endElement/2.0);
            counter++;
        }
        return counter;
    }
};