class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = false;
        bool isHeavy = false;
        if(length>=1e4 || height>=1e4 || width>=1e4)
            isBulky = true;
        long long vol = length*height*width;
        if(vol>=1e9)
            isBulky = true;
        if(mass>=100)
            isHeavy = true;
        if(isBulky && isHeavy)
            return "Both";
        else if(!isBulky && isHeavy)
            return "Heavy";
        else if(isBulky && !isHeavy)
            return "Bulky";
        else if(!isBulky && !isHeavy)
            return "Neither";
        return "";
    }
};