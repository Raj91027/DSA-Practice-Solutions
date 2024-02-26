/*
 * Given an array of integers where each element represents the max number of steps 
 * that can be made forward from that element. Write a function to return the minimum 
 * number of jumps to reach the end of the array (starting from the first element). 
 * If an element is 0, then we cannot move through that element. If we can’t reach the end, return -1.
 * 
 * 
 * Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
    Output: 3 (1-> 3 -> 8 -> 9)
    Explanation: Jump from 1st element to 2nd element as there is only 1 step, now there are three options 5, 8 or 9. If 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

    Input : arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    Output: 10 Explanation: In every step a jump is needed so the count of jumps is 10.

  Link: https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

 */

 // Java program to count Minimum number
// of jumps to reach end

class Test {
	static int minJumps(int arr[])
	{
		if (arr.length <= 1)
			return 0;
	
		//If value of first index guarantees 
		//only 1 jump is needed, return 1
		if (arr[0] >= arr.length-1)
			return 1;

		// Return -1 if not possible to jump
		if (arr[0] == 0)
			return -1;

		// initialization
		int maxReach = arr[0];
		int step = arr[0];
		int jump = 1;

		// Start traversing array
		for (int i = 1; i < arr.length; i++) {
			// Check if we have reached 
// the end of the array
			if (i == arr.length - 1)
				return jump;
		
		//Check if value at current index guarantees jump to end
			if (arr[i] >= (arr.length-1) - i)
				return jump + 1;

			// updating maxReach
			maxReach = Math.max(maxReach, i + arr[i]);

			// we use a step to get to the current index
			step--;

			// If no further steps left
			if (step == 0) {
				// we must have used a jump
				jump++;

				// Check if the current 
// index/position or lesser index
				// is the maximum reach point 
// from the previous indexes
				if (i >= maxReach)
					return -1;

				// re-initialize the steps to the amount
				// of steps to reach maxReach from position i.
				step = maxReach - i;
			}
		}

		return -1;
	}

	// Driver method to test the above function
	public static void main(String[] args)
	{
		int arr[] = new int[] { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };

		// calling minJumps method
		System.out.println(minJumps(arr));
	}
}
