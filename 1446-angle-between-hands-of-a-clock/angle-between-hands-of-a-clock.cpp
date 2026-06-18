class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_hand=(double)(minutes*6);
        double hour_hand=(double)((float)(30*hour)+(0.5*(float)minutes));
        double angle1=abs(hour_hand-minute_hand);
        double angle2=abs(360-angle1);
        if(angle1>angle2)
            return angle2;
        else
            return angle1;

    }
};