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
#include <deque>

/** This function enumerates all the prime numbers till n
	@Params : n       (IN) - Number till which prime numbers are to be generated.
	          Primes  (OUT) - Vector to store the prime numbers.
	@Return : void
*/
void Algo_EnumeratePrimes(int n, std::vector<int>& Primes)
{
	std::deque<bool> lIsPrime(n + 1, true);

	/*Check from 2 till n*/
	for (int iter = 2; iter <= n; ++iter)
	{
		/*Create an array and store true in all locations*/
		if (lIsPrime[iter])
		{
			/*If the array element is true insert the elements Primes*/
			Primes.emplace_back(iter);

			/*Set the multiples of prime numbers to false*/
			for (int itRemoveMult = 2 * iter; itRemoveMult <= n; itRemoveMult+=iter)
			{
				lIsPrime[itRemoveMult] = false;
			}
		}
	}
}

/** Function to print the elements of the passed array.
	@Params : array (IN) - vector to be printed.
	@Return : void
*/
void printArray(std::vector<int>& array)
{
	for (auto iter : array)
	{
		std::cout << iter << std::endl;
	}
}

int main()
{
	std::vector<int> lPrimes;
	/*Function to enumerate prime numbers till a given value*/
	Algo_EnumeratePrimes(10, lPrimes);
	std::cout << "The values in the array are : " << std::endl;
	/*Helper to print the array*/
	printArray(lPrimes);
	std::cin.get();

	return 0;
}