// Solution to: https://leetcode.com/problems/greatest-sum-divisible-by-three/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // Let's first compute the sum of all elements
        int sum_all = 0;
        for (int i : nums)
            sum_all += i;
        // Since all input values are positive, this sum being divisible by 3 implies it is the largest sum
        if (sum_all % 3 == 0)
            return sum_all;
        // Otherwise, we need to not include some of the numbers in the sum
        // There are two remaining cases: either sum_all mod 3 = 1 or 2. Call this value k.
        // Since the empty sum is 0 (which is 0 mod 3), there must exist either a number v in nums with v mod 3 = k,
        //  or two numbers x and y with (x + y) mod 3 = k. In particular, since we never want to remove a number that
        //  is divisble by 3, the latter case holds only if x mod 3 = y mod 3 = 3-k.
        
        // Let's find the smallest numbers of each modulo value.
        sort(nums.begin(),nums.end());
        // now find the smallest numbers with mod 1 and mod 2
        vector<int> mod1, mod2;
        for (int i : nums)
        {
            if (i % 3 == 1)
                mod1.push_back(i);
            if (i % 3 == 2)
                mod2.push_back(i);
        }
        // second case:
        if (sum_all % 3 == 1)
        {
            //we either need to remove 2 mod2s or 1 mod1
            int best = 0;
            if (mod2.size() >= 2)
                best = sum_all - mod2[0] - mod2[1];
            if (mod1.size() > 0)
                best = max(best,sum_all - mod1[0]);
            return best;
        }
        // last case: if (sum_all % 3 == 2)
        //we either need to remove 2 mod1s or 1 mod2
        int best = 0;
        if (mod1.size() >= 2)
            best = sum_all - mod1[0] - mod1[1];
        if (mod2.size() > 0)
            best = max(best,sum_all - mod2[0]);
        return best;
    }
};
