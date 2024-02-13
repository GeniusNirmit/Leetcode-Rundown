class Solution
{
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        int n = nums.size();
        int m = pattern.size();
        int counter = 0;

        for (int i = 0; i < n - m; i++)
        {
            bool isMatch = true;
            for (int j = 0; j < m; j++)
            {
                if ((pattern[j] == 1 && nums[i + j] >= nums[i + j + 1]) || (pattern[j] == 0 && nums[i + j] != nums[i + j + 1]) || (pattern[j] == -1 && nums[i + j] <= nums[i + j + 1]))
                {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch)
                counter++;
        }

        return counter;
    }
};