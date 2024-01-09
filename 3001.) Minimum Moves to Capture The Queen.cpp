class Solution
{
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        int rooksMoves = 2, bishopMoves = 2;

        if (a == e || b == f)
        {
            if (a == e && c == a)
            {
                if (b < d && d < f)
                    return 2;
                if (b > d && d > f)
                    return 2;
            }
            if (b == f && d == b)
            {
                if (a < c && c < e)
                    return 2;
                if (a > c && c > e)
                    return 2;
            }
            rooksMoves = 1;
        }

        if (abs(c - e) == abs(d - f))
        {
            if (abs(a - c) == abs(b - d))
            {
                if (c < a && a < e)
                {
                    if (d < b && b < f)
                        return 2;
                    if (d > b && b > f)
                        return 2;
                }
                if (c > a && a > e)
                {
                    if (d < b && b < f)
                        return 2;
                    if (d > b && b > f)
                        return 2;
                }
            }
            bishopMoves = 1;
        }

        return min(bishopMoves, rooksMoves);
    }
};