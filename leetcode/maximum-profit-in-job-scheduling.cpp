// solution to: https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Solution {
public:
    int dp_res(map<int,int> &dp, int q)
    {
        auto iter = dp.lower_bound(q);
        if (iter == dp.end())
            return 0;
        return iter->second;
    }
    typedef tuple<int,int,int> job; //start,end,profit
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<job> jobs;
        for (int i = 0; i < n; ++i)
            jobs.emplace_back(startTime[i],endTime[i],profit[i]);
        sort(jobs.rbegin(),jobs.rend()); // look through jobs in reverse start date order
        map<int,int> dp; //most profit starting here (current start date)
        for (job &j : jobs)
        {
            int s, e, p;
            tie(s,e,p) = j;
            // either use this one or skip it
            dp[s] = max(dp_res(dp,e) + p, dp_res(dp,s));
        }
        return dp_res(dp,0);
    }
};
