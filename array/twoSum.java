/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

difficulty: medium

time: O(n^2)
space: O(1)

 */


class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] answer = new int [2]; //create an answer array
        for (int i=0; i<nums.length; i++) { //loop through the nums array
            for (int j=i+1; j<nums.length; j++) { //loop through the nums array
                if (nums[i] + nums[j] == target) { //if the sum of the two numbers is equal to target
                    answer[0] = i; //set the first index to i
                    answer[1] = j; //set the second index to j
                    return answer; //return the answer array
                }
            }
        }
        return answer; //return the answer array
    }
}

//test
public class twoSum {
    public static void main(String[] args) { 
        Solution s = new Solution(); //create a Solution object
        int[] nums = {2, 7, 11, 15}; //create a nums array
        int target = 9; //create a target
        int[] answer = s.twoSum(nums, target); //get the answer
        System.out.println(answer[0]); //print the first answer
        System.out.println(answer[1]); //print the second answer
    }
}