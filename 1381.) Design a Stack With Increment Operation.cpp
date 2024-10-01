class CustomStack
{
private:
    vector<int> st;
    vector<int> incrArr;
    int ind;

public:
    CustomStack(int maxSize)
    {
        st.resize(maxSize);
        incrArr.resize(maxSize);
        ind = -1;
    }

    void push(int x)
    {
        if (ind < (int)(st.size()) - 1)
            st[++ind] = x;
    }

    int pop()
    {
        if (ind < 0)
            return -1;

        int result = st[ind] + incrArr[ind];
        if (ind > 0)
            incrArr[ind - 1] += incrArr[ind];

        incrArr[ind] = 0;
        ind--;
        return result;
    }

    void increment(int k, int val)
    {
        if (ind >= 0)
        {
            int incrementIndex = min(ind, k - 1);
            incrArr[incrementIndex] += val;
        }
    }
};