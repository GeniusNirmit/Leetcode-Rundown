class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string number = to_string(n);
        int size = number.size();
        int ind = size - 1;

        for (int i = size - 1; i > 0; i--)
        {
            if (number[i] < number[i - 1])
            {
                number[i] = '9';
                number[i - 1]--;
                ind = i;
            }
        }

        for (int i = ind + 1; i < size; i++)
            number[i] = '9';
        return stoi(number);
    }
};