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

/** This function takes an element as key and removes all the instances of this element from the  array.
	@Params : array (IN) - Pointer to the array.
			  size  (IN) - Size of the array.
			  key   (IN) - The element whose instances to be removed.
	@Return : int	     - The index till which the elements are valid in the array. 
*/
int Algo_RemoveKey(int* array, int size, int key)
{
	int lWriteIndex = 0;

	for (int iter = 0; iter < size; iter++)
	{
		/*If the current element is not equal to the key, copy the value of current index to the lWriteIndex position. */
		if (array[iter] != key)
		{
			array[lWriteIndex++] = array[iter];
		}
	}

	return lWriteIndex - 1;
}

/** Function to print the elements of the passed array.
	@Params : array (IN) - The pointer to the array.
			  size  (IN) - Size of the array.
	@Return : void

*/
void PrintArray(int* array, int size)
{
	/*Print the elements of the array*/
	for (int iter = 0; iter < size; iter++)
	{
		std::cout << array[iter] << std::endl;
	}
}

int main()
{
	int lIndex;

	lIndex = 0;
	int lArray[] = {3, 3, 1, 0, 2, 0, 1};
	int lSize = sizeof(lArray) / sizeof(lArray[0]);

	std::cout << "Array elements before removing the elements with specific key : " << std::endl;
	/*Function to print the array*/
	PrintArray(lArray, lSize);

	/*Function call to remove the instances of given element. */
	lIndex = Algo_RemoveKey(lArray, lSize, 0);

	std::cout << "The index till which the array is valid : " << lIndex << std::endl;
	std::cout << "Array elements after removing the elements with specific key : " << std::endl;
	PrintArray(lArray, lSize);

	std::cin.get();

	return 0;
}