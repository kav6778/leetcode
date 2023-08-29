/* Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique. */

class Solution {
public:
vector<vector<int>>ans;
    void rec(int index, vector<int>& nums, vector<int>& taken){
        //base case
        if(index == nums.size()){
            ans.push_back(taken);
            return;
        }

        // don't take
        rec(index+1, nums, taken);

        //take these elements
        taken.push_back(nums[index]);
        rec(index +1, nums, taken);
        taken.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>taken;
        rec(0,nums,taken);
        for(auto vec : ans){
            for(auto ele : vec){
                cout<< ele << " ";
            }
            cout<<endl;
        }
        return ans;
    }
};
