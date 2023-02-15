class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int carry = 0;
        int size = a.size()-1;
        vector<int> newArray = a;
        while(size>=0)
        {
            int sum = a[size] + k%10 + carry;
            k /= 10;
            newArray[size--] = sum % 10;
            carry = sum / 10;
        }
        while(k>0)
        {
            int sum = k % 10 + carry;
            k /= 10;
            newArray.insert(newArray.begin(), sum%10);
            carry = sum/10;
        }
        if(carry > 0)
            newArray.insert(newArray.begin(), carry);
        return newArray;
    }
};