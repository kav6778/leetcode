
// https://leetcode.com/problems/search-a-2d-matrix/description/
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;  // Empty matrix
        
        int m = matrix[0].size();
        int l = 0;
        int r = n * m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;  // Target found
            } else if (matrix[row][col] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return false;  // Target not found
    }
};
