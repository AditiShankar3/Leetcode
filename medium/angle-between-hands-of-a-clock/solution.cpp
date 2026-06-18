/*
[Description]
Angle Between Hands of a Clock
https://leetcode.com/problems/angle-between-hands-of-a-clock/submissions/2037729640/

Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 
Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 2:

Input: hour = 3, minutes = 30
Output: 75

Example 3:

Input: hour = 3, minutes = 15
Output: 7.5

 
Constraints:

  1 <= hour <= 12
  0 <= minutes <= 59

[Metadata]
- Difficulty: Medium
- Topics: Math
- Slug: angle-between-hands-of-a-clock
*/

// [Solution]
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