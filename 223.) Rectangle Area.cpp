class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1)*(ay2 - ay1);
        int area2 = (bx2 - bx1)*(by2 - by1);
        
        int right, left, up, down;
        
        if(ax2 > bx2)
            right = bx2;
        else
            right = ax2;
        
        if(ax1 > bx1)
            left = ax1;
        else
            left = bx1;
        
        if(ay2 > by2)
            up = by2;
        else
            up = ay2;
        
        if(ay1 > by1)
            down = ay1;
        else
            down = by1;
        
        int x = right - left;
        int y = up - down;
    
        if(x>0 && y>0)
            return area1 + area2 - x*y;
        return area1 + area2;
    }
};