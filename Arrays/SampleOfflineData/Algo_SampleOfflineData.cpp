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
#include <random>

/** This function generates the random subset of data of size k from the database.
	@Params : array   (IN) - The database array.
	          k       (IN) - The size of subset that shall be generated at random.
	@Return : void
*/
void RandomSampling(std::vector<int>& array, int k)
{
	int lRandNum = 0;
	/*Random number generator.*/
	std::default_random_engine seed((std::random_device())());

	/* 1. From 0 till size of the required subset select an index in random.
	   2. Swap the value of current index and the value in the index pointed by generated random number.
	   3. The subset starts to get accumulated from the index 0 till index k.*/
	for (int iter = 0; iter < k; iter++)
	{
		lRandNum = std::uniform_int_distribution<int>{ iter, static_cast<int>(array.size() - 1) } (seed);
		std::swap(array[iter], array[lRandNum]);
	}
}

/** Function to print the elements of the passed array till a particular index.
	@Params : array (IN) 	  - vector to be printed.
			  validIndex (IN) - Index till which the array has to be printed.
	@Return : void.
*/
void PrintArray_Sampling(std::vector<int>& array, int validIndex)
{
	/*Print elements of the array till the validIndex.*/
	for (int iter = 0; iter < validIndex; iter++)
	{
		std::cout << array[iter] << std::endl;
	}
}

int main()
{
	/*Database. Here int is considered for simplicity but it could be a collection of user data of a webpage.*/
	std::vector<int> arr{ 5, 7, 3, 11 };
	/*Size of subset that shall be generated from the database.*/
	int k = 3;
	/*Function that generates the sub array in a random manner.*/
	RandomSampling(k, arr);
	/*Print the generated sub array.*/
	PrintArray_Sampling(k, arr);
	
	return 0;
}