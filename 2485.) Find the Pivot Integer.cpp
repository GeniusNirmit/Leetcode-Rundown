class Solution
{
public:
    int pivotInteger(int n)
    {
        int forward = 1, backward = n;
        int sumForward = forward, sumBackward = backward;

        if (n == 1)
            return n;

        while (forward < backward)
        {
            if (sumForward < sumBackward)
            {
                forward++;
                sumForward += forward;
            }
            else
            {
                backward--;
                sumBackward += backward;
            }

            if (sumForward == sumBackward && forward + 1 == backward - 1)
                return forward + 1;
        }
        return -1;
    }
};