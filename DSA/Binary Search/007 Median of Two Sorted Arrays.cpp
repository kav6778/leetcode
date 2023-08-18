/* https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. */


/* Complexity
    Time complexity: O(log(min(m,n)) Binary Search on Shortest array.

    Space complexity: O(1) */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float median;
        int n = nums1.size();
        int m = nums2.size();

        if(m<n)
        return findMedianSortedArrays(nums2, nums1); //Shortest array finding

        int lo = 0; // low of shortest array
        int hi = n; // high of shortest array
        int mid = (n+m+1)/2; // median pos in merged array
        while(lo <=hi){
            int cut1 = (lo+hi)/2; // L1 array ---   0 to cut1, R1 array --- cut1 to n
            int cut2 = mid - cut1; // L2 array --- 0 to cut2, R2 array --- cut2 to m

            int l1 = cut1 ==0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 ==0 ? INT_MIN : nums2[cut2- 1];
            int r1 = cut1 == n? INT_MAX : nums1[cut1];
            int r2 = cut2 == m? INT_MAX : nums2[cut2];
            //Above are boundary values of L1,L2,R1,R2
            // ----- l1 r1----
            // ----- l2 r2----

            if( l1 <=r2 && l2 <=r1){// validity of Partition
                if((n+m)%2 == 0)// Even no merged array
                    return(max(l1,l2) + min(r1,r2))/ 2.0;
                else // odd no merged array
                    return max(l1,l2);
            } 
            else if (l1 > r2) // Invalid case
                hi = cut1-1;
            
            else 
                lo = cut1 +1;
        }
        return 0.0;
    }   
};
