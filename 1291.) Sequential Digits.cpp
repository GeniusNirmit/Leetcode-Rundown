class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> digitSequence;
        string number = "123456789";

        string lowString = to_string(low);
        string highString = to_string(high);

        int lowSize = lowString.length();
        int highSize = highString.length();

        for (int i = lowSize; i <= highSize; i++)
        {
            for (int j = 0; j <= 9 - i; j++)
            {
                string currentNumber = "";
                for (int k = 0; k < i; k++)
                    currentNumber += number[j + k];
                int currentDigit = stoi(currentNumber);
                if (low <= currentDigit && high >= currentDigit)
                    digitSequence.push_back(currentDigit);
            }
        }

        return digitSequence;
    }
};