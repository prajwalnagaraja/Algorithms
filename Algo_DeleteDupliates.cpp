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
#include <stdlib.h>
#include <vector>

/** The function removes the duplicates from the array.
	The size of array remains the same. The index till
	which the array elements are valid is returned.
	@Params : array (IN) - input vector
	@Return : int        - Index of array till which
						   the array elements are valid.

*/
int Algo_DeleteDuplicates(std::vector<int>& array)
{
    int lWriteIndex = 1;

	/*Return 0 if the size of vector is zero. */
	if (array.size() == 0)
	{
		return 0;
	}
	else
	{
		/*Iterate through the array. */
		for (int iter = 1; iter < array.size(); iter++)
		{
			/*If the current element is not equal to the element pointer by (lWriteIndex - 1), copy the value of current index to the 				  lWriteIndex position. */
			if (array[iter] != array[lWriteIndex - 1])
			{
				array[lWriteIndex++] = array[iter];
			}
		}
	}

	return (lWriteIndex - 1);
}

/** Helper to print the array.
	@Params : array (IN) - The array to be printed
	@Return : void.
*/
void PrintArray(std::vector<int>& array)
{
	/*Print all the elements of the vector. */
	for (auto iter : array)
	{
		std::cout << iter << std::endl;
	}
}

int main()
{
	int lIndex;
	
	lIndex = 0;
	std::vector<int> lArray{2, 3, 4, 4, 5, 5, 5, 6};

	std::cout << "The elements in the array before removing duplicates" << std::endl;
	PrintArray(lArray);

	lIndex = Algo_DeleteDuplicates(lArray);
	
	std::cout << "The index till which the array elements are valid is : " << lIndex << std::endl;
	std::cout << "The elements in the array after removing duplicates" << std::endl;
	PrintArray(lArray);

	return 0;
}
