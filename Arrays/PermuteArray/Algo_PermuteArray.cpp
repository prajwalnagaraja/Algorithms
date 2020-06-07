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
#include <limits>
#include <algorithm>

/** This function permutes the array as expected in per array.
	@Params : array   (IN) - The array to be permuted.
	          per     (IN) - The format in which the array to be permuted.
	@Return : void
*/
void Algo_PermuteArray( std::vector<int>& array, std::vector<int>& per)
{
	/*Iterate through all the elements of the array*/
	for (int ArrIter = 0; ArrIter < array.size(); ArrIter++)
	{
		/*Swap the current element of the array and the index pointed by the 
		permute array till iterator is not same as the value in permute array.*/
		while (per[ArrIter] != ArrIter)
		{
			std::swap(array[ArrIter], array[per[ArrIter]]);
			std::swap(per[ArrIter], per[per[ArrIter]]);
		}
	}
}

/** Function to print the elements of the passed array.
	@Params : array (IN) - vector to be printed.
	@Return : void
*/
void PrintArray(std::vector<int>& array)
{
	/*Print all the elements of the array.*/
	for (auto iter : array)
	{
		std::cout << iter << std::endl;
	}
}

int main()
{
	/*vector containing the values to be permuted.*/
	std::vector<int> arr {5, 6, 0, 1};
	/*vector containing the values that specify the format in which the 
	array to be permuted.*/
	std::vector<int> per {2, 0, 1, 3};

	std::cout << "The value of array before permuting" << std::endl;
	PrintArray(arr);
	/*call the function to permute the array as desired.*/
	Algo_PermuteArray(arr, per);
	std::cout << "The value of array after permuting" << std::endl;
	PrintArray(arr);

	std::cin.get();
	return 0;
}