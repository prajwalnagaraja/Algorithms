/**
 * @section License
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017, Prajwal Nagaraja
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <iostream>
#include <algorithm>

/** This function calculates the maximum sum of a sub array of given size.
	@Params : arr          (IN)  - Pointer to array.
			  arrSize      (IN)  - Size of the passed array.
			  subArraySize (IN)  - Size of sub array.
	@Return : int				 - Maximum sum of a sub array.
*/
int Algo_MaxSumOfSubArray(int *arr, int arrSize, int subArraySize)
{
	/*Local variable declaration.*/
	int lResultSum;
	int lWindowSum;
	int lRetVal;

	/*Local variable initialization.*/
	lResultSum = 0;
	lWindowSum = 0;
	lRetVal = 0;

	/*Assign -1 to return variable if the length of array is less than the length of sub array.*/
	if (arrSize < subArraySize)
	{
		lRetVal = -1;
	}
	else
	{
		/*Calculate the sum of first window. Window size is 0 to subArraySize.*/
		for (int lWinIter = 0; lWinIter < subArraySize; lWinIter++)
		{
			lResultSum += arr[lWinIter];
		}

		lWindowSum = lResultSum;

		/*Slide the window one step at a time starting from second window index i.e., 0 + subArraySize.*/
		for (int lWinIter = subArraySize; lWinIter < arrSize; lWinIter++)
		{
			/*The sum can be calculated in O(1) using the sum of previous sub array.
			  From the previous sum subtract the value at first index of previous window and add the value at current index.*/
			lWindowSum += arr[lWinIter];
			lWindowSum -= arr[lWinIter - subArraySize];
			lResultSum = std::max(lResultSum, lWindowSum);
		}

		lRetVal = lResultSum;
	}

	/*Return the result.*/
	return lRetVal;
}

int main()
{
	/*Local variable declaration*/
	int larr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int  lSubArraySize;
	int larrSize;
	int lSubArrayMaxSum;

	/*Local variable initialization*/
	lSubArrayMaxSum = 0;
	lSubArraySize = 4;
	larrSize = sizeof(larr) / sizeof(larr[0]);

	/*Function call to calculate the max of sub array.*/
	lSubArrayMaxSum = Algo_MaxSumOfSubArray(larr, larrSize, lSubArraySize);

	std::cout << "The maximum sum of a subarray of size " << lSubArraySize << " is " << lSubArrayMaxSum  << std::endl;

	return 0;
}