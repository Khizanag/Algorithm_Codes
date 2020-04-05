/*
 * Maximum_sum_of_a_subarray
 * -------------------------
 * Given an integer array v, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 */

int maxSubArray(vector<int>& v) {
	int max_sum = INT_MIN;
	int curr_sum = 0;
	int l = 0, r = 0;

	while(r < v.size())
	{
		if(r == l)
		{
			curr_sum += v[r++];
		}
		else if(curr_sum < 0 || v[l] < 0)
		{
			max_sum = max(max_sum, curr_sum);
			curr_sum -= v[l++];
		}
		else
		{
			max_sum = max(max_sum, curr_sum);
			curr_sum += v[r++];
		}
	}

	while(l < r)
	{
		max_sum = max(max_sum, curr_sum);
		curr_sum -= v[l++];
	}

	return max_sum;
}
