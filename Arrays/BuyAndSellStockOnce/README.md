This problem is concerned with optimally buying and selling a stock once to make
maximum profit. As an example, consider the following sequence of strock prices 
[310, 315, 275, 295, 260, 270, 290, 230, 255, 250]. The maximum profit that can
be made with one buy and one sell is 30 i.e., buy at 260 and sell at 290.

Approach to solution:
1. Identifying the minimum and maximum is not enough since the minimum may appear
after the maximum.
2. The maximum profit that can be made by selling on each specific day is the
difference of the current price and the minimum seen so far.

Algorithm Complexity:
Time complexity is O(n)
Space complexity is O(1)
where n is the length of the array.
