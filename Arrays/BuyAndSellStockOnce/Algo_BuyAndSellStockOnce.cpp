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

 /** The function calculates the maximum profit that can be made by buying and then selling the stock once.
	 @Params : StockPrice (IN) - input vector containing the stock price
	 @Return : double          - The max profit that can be made.
 */
double Algo_BuyAndSellStockOnce(std::vector<double>& StockPrice)
{
	double lMinPriceSoFar;
	double lMaxProfit;

	/*Initialize the min price seen so far to a max value*/
	lMinPriceSoFar = std::numeric_limits<double>::max();

	/*Iterate through all the elements of the stock price vector*/
	for (double price : StockPrice)
	{
		/*The main idea behind this algorithm is to try to maximise the profit by keeping track of minimum price everytime. */
		lMaxProfit = std::max(lMaxProfit, price - lMinPriceSoFar);
		lMinPriceSoFar = std::min(lMinPriceSoFar, price);
	}

	/*Return the maximum profit made*/
	return lMaxProfit;
}

int main()
{
	double lMaxProfit;

	lMaxProfit = 0;
	/*Array containing the stock price.*/
	std::vector<double> StockPrice {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

	lMaxProfit = Algo_BuyAndSellStockOnce(StockPrice);

	std::cout << "The maximum profit that can be made by buying and selling stock once is : " << lMaxProfit << std::endl;

	return 0;
}