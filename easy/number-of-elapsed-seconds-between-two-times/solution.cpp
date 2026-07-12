/*
[Description]
Number of Elapsed Seconds Between Two Times
https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/submissions/2064579380/

You are given two valid times startTime and endTime, each represented as a string in the format "HH:MM:SS".

Return the number of seconds that have elapsed from startTime to endTime, inclusive of both endpoints.

 
Example 1:

Input: startTime = "01:00:00", endTime = "01:00:25"

Output: 25

Explanation:
endTime is 25 seconds ahead of startTime.

Example 2:

Input: startTime = "12:34:56", endTime = "13:00:00"

Output: 1504

Explanation:

endTime is 25 minutes and 4 seconds ahead of startTime, which equals 1504 seconds.

 
Constraints:

  startTime.length == 8
  endTime.length == 8
  startTime and endTime are valid times in the format "HH:MM:SS"
  00 <= HH <= 23
  00 <= MM <= 59
  00 <= SS <= 59
  endTime is not earlier than startTime

[Metadata]
- Difficulty: Easy
- Topics: 
- Slug: number-of-elapsed-seconds-between-two-times
*/

// [Solution]
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr1=stoi(startTime.substr(0,2));
        int min1=stoi(startTime.substr(3,2));
        int sec1=stoi(startTime.substr(6,2));
        int first=hr1*3600+min1*60+sec1;
        int hr2=stoi(endTime.substr(0,2));
        int min2=stoi(endTime.substr(3,2));
        int sec2=stoi(endTime.substr(6,2));
        int second=hr2*3600+min2*60+sec2;
        return second-first;
        
    }
};