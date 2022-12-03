class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(abs(((60*hour)-(11*minutes))/2.0) > 180)
            return 360 - abs(((60*hour)-(11*minutes))/2.0);
        return abs(((60*hour)-(11*minutes))/2.0);
    }
};