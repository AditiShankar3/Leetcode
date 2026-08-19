/*
[Description]
Cinema Seat Allocation
https://leetcode.com/problems/cinema-seat-allocation/description/

A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

  seats 2, 3, 4, 5
  seats 4, 5, 6, 7
  seats 6, 7, 8, 9

A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

Return an integer denoting the maximum number of four-person groups that can be assigned.

 
Example 1:

Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows an optimal allocation of four groups. Seats marked in blue are already reserved, and each set of four contiguous seats marked in orange is assigned to one group.

Example 2:

Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

Example 3:

Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4

 
Constraints:

  1 <= n <= 109
  1 <= reservedSeats.length <= min(10 * n, 104)
  reservedSeats[i] == [rowi, seati]
  1 <= rowi <= n
  1 <= seati <= 10
  All reservedSeats[i] are distinct.

[Metadata]
- Difficulty: Medium
- Topics: Array, Hash Table, Greedy, Bit Manipulation
- Slug: cinema-seat-allocation
*/

// [Solution]
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> map;
        for(int i = 0; i < reservedSeats.size(); i++)
        {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            map[row].push_back(seat);
        }
        int m=map.size();
        int count=(n-m)*2;
        for(auto &it : map)
        {
            int row = it.first;
            vector<int> seats = it.second;
            unordered_set<int> reserved(seats.begin(), seats.end());
            if(reserved.count(2)==0 && reserved.count(3)==0 && reserved.count(4)==0 && reserved.count(5)==0)
                count++;
            if(reserved.count(6)==0 && reserved.count(7)==0 && reserved.count(8)==0 && reserved.count(9)==0)
                count++;
            else if(reserved.count(4)==0 && reserved.count(5)==0 && reserved.count(6)==0 && reserved.count(7)==0 && (reserved.count(2)==1 || reserved.count(3)==1))
                count++;
        }
        return count;
    }
};