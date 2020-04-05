/* Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum. 
 */

int maxSubArray(vector<int>& nums) {
	int max_sum = INT_MIN;
	int curr_sum = 0;
	int l = 0, r = 0;

	while(r < nums.size())
	{
		if(r == l)
		{
			curr_sum += nums[r++];
		}
		else if(curr_sum < 0 || nums[l] < 0)
		{
			max_sum = max(max_sum, curr_sum);
			curr_sum -= nums[l++];
		}
		else
		{
			max_sum = max(max_sum, curr_sum);
			curr_sum += nums[r++];
		}

	}

	while(l < r)
	{
		max_sum = max(max_sum, curr_sum);
		curr_sum -= nums[l++];
	}

	return max_sum;
}
