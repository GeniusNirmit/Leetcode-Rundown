class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string col = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            char temp = 'A' + columnNumber % 26;
            col += temp;
            columnNumber /= 26;
        }
        reverse(col.begin(), col.end());
        return col;
    }
};