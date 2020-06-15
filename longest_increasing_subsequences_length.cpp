#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
// read input from console
	int n; cin >> n;
	int v[n];
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int b[n]; // array for saving longest increasing subsequence's length, uses DP
	for(int i = 0; i < n; i++)
	{
	    b[i] = 1; // at least ith number
		for(int j = 0; j < i; j++)
        {
		    if(v[i] > v[j])
		        b[i] = max(b[i], b[j]+1);
        }
	}

	int result = 0;
	for(int i = 0; i < n; i++)
    {
	    result = max(result, b[i]);
    }

	cout << result << endl;

	return EXIT_SUCCESS;
}
