/*
[Description]
Task Scheduler
https://leetcode.com/problems/task-scheduler/submissions/2079015448/

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 
Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 
Constraints:

  1 <= tasks.length <= 104
  tasks[i] is an uppercase English letter.
  0 <= n <= 100

[Metadata]
- Difficulty: Medium
- Topics: Array, Hash Table, Greedy, Sorting, Heap (Priority Queue), Counting
- Slug: task-scheduler
*/

// [Solution]
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26,0);
        for(char c:tasks)
            mp[c-'A']++;
        for(int i=0;i<26;i++)
        {
            if(mp[i])
                pq.push(mp[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int> remain;
            int cycle=n+1;
            while(cycle && !pq.empty()){
                int maxi=pq.top();
                pq.pop();
                if(maxi>1)
                    remain.push_back(maxi-1);
                time++;
                cycle--;
            }
            for(int j:remain)
                pq.push(j);
            if(pq.empty())
                break;
            time+=cycle;
        }
        return time;
    }
};