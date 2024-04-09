class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();

        int circleCounter = 0, squareCounter = 0;

        for (int i = 0; i < n; i++)
        {
            if (students[i] == 0)
                circleCounter++;
            else
                squareCounter++;
        }

        for (int i = 0; i < n; i++)
        {
            if (sandwiches[i] == 0)
            {
                if (circleCounter == 0)
                    return squareCounter;
                else
                    circleCounter--;
            }
            else
            {
                if (squareCounter == 0)
                    return circleCounter;
                else
                    squareCounter--;
            }
        }

        return 0;
    }
};