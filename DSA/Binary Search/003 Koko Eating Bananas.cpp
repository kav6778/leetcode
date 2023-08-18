// https://leetcode.com/problems/koko-eating-bananas/description/
/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
  */

class Solution {
public:
    int eating(vector<int>& piles, int k){
        int sum=0;
        for(int p: piles)
            sum+=(p+(k-1))/k; // Calculate the number of hours needed to eat each pile, rounding up using the ceiling function
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=h-1; // Initialize the left pointer as h-1
        left=accumulate(piles.begin(), piles.end(), left)/h; // Calculate the average eating speed required, rounding up using the ceiling function
        int right=*max_element(piles.begin(),piles.end()); // Initialize the right pointer as the maximum element in the piles vector
        
        while(left<right) // Perform binary search until left and right pointers meet
        {
            int&& mid=(left+right)/2; // Calculate the middle pointer
            
            if (eating(piles, mid)<=h) // If eating at the middle speed allows us to finish within h hours
                right=mid; // Update the right pointer to mid
            else
                left=mid+1; // Update the left pointer to mid+1
        }
        
        return right; // Return the minimum eating speed
    }
};
