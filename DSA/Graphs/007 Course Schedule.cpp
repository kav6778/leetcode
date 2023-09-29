/* https://leetcode.com/problems/course-schedule/solutions/3756938/beat-s-100-topo-c-java-python-beginner-friendly/
    Courses & prerequisites, return true if can finish all courses
    Ex. numCourses = 2, prerequisites = [[1,0]] -> true

    All courses can be completed if there's no cycle (visit already visited)

    Time: O(V + E)
    Space: O(V + E)
*/

class Solution {
public:
    int c = 0;  // Initialize a count to check if all courses can be finished

    void bfs(int numCourses, vector<vector<int>>& prerequisites,vector<vector<int>>& g,vector<int>& indegree){
        // Initialize a queue to perform a breadth-first search
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            c++;

            // Reduce the indegree of each course that depends on the current course
            for (auto& it : g[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list representation of the courses and their prerequisites
        vector<vector<int>> g(numCourses);
        for (auto& it : prerequisites) {
            g[it[1]].push_back(it[0]);
        }

        // Calculate the indegree (number of prerequisites) for each course
        vector<int> indegree(g.size(), 0);
        for (auto& it : g) {
            for (auto& itt : it) {
                indegree[itt]++;
            }
        }
        bfs(numCourses, prerequisites, g, indegree);

         // If the count equals the total number of courses, return true (all courses can be finished)
        if (c == numCourses) {
            return true;
        }

        // Otherwise, return false (not all courses can be finished)
        return false;
    }
};
