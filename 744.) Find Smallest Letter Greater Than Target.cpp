class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, h = letters.size()-1, mid;
        char letter = letters[0];
        while(l <= h)
        {
            mid = (l+h)/2;
            if(letters[mid] <= target)
                l = mid + 1;
            else
            {
                letter = letters[mid];
                h = mid - 1;
            }
        }
        return letter;
    }
};