// TC: O(1)
// SC: O(1)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minDeg=minutes*6;
        double percentage=double(minutes)/60.00000;
        double hourDeg=(hour*30)+(percentage*30);
        double diff=abs(minDeg-hourDeg);
        if(diff>180) diff=360-diff;
        return diff;
    }
};