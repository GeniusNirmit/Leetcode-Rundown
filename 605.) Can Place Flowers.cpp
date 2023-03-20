class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int counter = 0;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i] == 0)
            {
                bool leftOne = false, rightOne = false;
                if((i==0) || (flowerbed[i-1]==0))
                    leftOne = true;
                if((i==flowerbed.size()-1) || (flowerbed[i+1]==0))
                    rightOne = true;
                
                if(leftOne && rightOne)
                {
                    flowerbed[i] = 1;
                    counter++;
                    if(counter >= n)
                        return true;
                }
            }
        }
        if(counter >= n)
            return true;
        return false;
    }
};