This file is a write-up explaining the solution to
[this problem on LeetCode](https://leetcode.com/problems/greatest-sum-divisible-by-three/).

In this problem, we are given a multiset `S` of positive integers as input, represented as a list or array.
Our task is to find a subset maximizing the sum `P` of its elements such that `P` is divisible by `3`.

We first make a simple observation: If the sum _K_ of all elements in `P` is divisible by 3, then _K_ is our answer.
Now, we have two remaining cases: either `P mod 3 == 1` or `P mod 3 == 2`.

If `P` is not divisible by `0`, then we want to remove elements to get a new value `P'` such that `P' mod 3 == 0`.
In particular, we want to maximize `P'`, which is equivalent to minimizing
the sum `R` of the removed elements `T`.
We have defined `P'+R=P`, so it also holds that `((P' mod 3) + (R mod 3)) mod 3 == P mod 3`.
Therefore, we must have `R mod 3 == P mod 3`.

Now, we have reduced to a much easier problem:
Find a subset `T` of `S` minimizing its sum `R`, such that `R mod 3 == P mod 3`,
where `P mod 3` is an input value that is either `1` or `2`. 
Why is this an easier problem?
Since we are minimizing the sum, we can assume that there is no subset of `T` with sum divisible by `3`,
otherwise we could remove it.
Furthermore, this implies that every element of `T` is equal modulo `3` (and of course that none are divisible by `3`),
since otherwise we could pair up an element that is `1` modulo `3` and one that is `2` modulo `3`
to create a set with sum divisible by `3`.
Lastly, we can finally see that `|T|<3`, since if we have `3` elements that are all `1` modulo `3` or all `2` modulo `3`,
their sum is divisible by `3`.  
This gives us a very efficient algorithm!
We only need to check `4` cases:
- `T` is the set of the smallest element that is `1` modulo `3`.
- `T` is the set of the two smallest elements that are `1` modulo `3`.
- `T` is the set of the smallest element that is `2` modulo `3`.
- `T` is the set of the two smallest elements that are `2` modulo `3`.
Of these `4` cases, find which ones exist (for example, `S` may not include any elements that are `1` modulo `3`),
and which have the correct sum modulo `3`.
To implement this, we can sort all the elements, and filter out the
subsets of elements that are all `1` modulo `3` and the elements that are all `2` modulo `3` to create the sets.

Finally, let's analyze the complexity of this solution:  
Let _n_ denote the number of elements in `S`.
We can compute `K` with a simple iteration through the elements, taking `O(n)` time and `O(1)` space to store the running sum.
Sorting the elements then takes `O(n log(n))` time, using a built-in sorting algorithm (such as `std::sort` in `C++`).
The sorting could be done in-place to save memory, but this isn't necessary for the problem.
Filtering the elements of `P` into the lists of elements that are uniform modulo `3` takes `O(n)` time and memory,
since we iterate through each element.

Overall, this solution runs in `O(n log(n))` time and `O(n)` memory.

The corresponding implementation can be found
[here](https://github.com/jacketsj/algorithms_solutions/blob/master/leetcode/greatest_sum_divisible_by_three.cpp).
