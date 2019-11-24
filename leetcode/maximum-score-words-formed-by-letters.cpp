// solution to: https://leetcode.com/problems/maximum-score-words-formed-by-letters

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<vector<int>> letter_counts(n, vector<int>(26));
        for (int i = 0; i < n; ++i)
            for (char c : words[i])
                ++letter_counts[i][c-'a'];
        vector<int> total_letters(26);
        for (char c : letters)
            ++total_letters[c-'a'];
        vector<int> cur_letters;
        //for every set of words
        int best = 0;
        for (int word_set = 0; word_set < (1<<n); ++word_set)
        {
            cur_letters = total_letters;
            int cur = 0;
            // for each word
            bool ok = true;
            for (int i = 0; i < n; ++i)
            {
                // if it is in word_set
                if ((1 << i) & word_set)
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        cur += letter_counts[i][k]*score[k];
                        cur_letters[k] -= letter_counts[i][k];
                        ok = ok && (cur_letters[k] >= 0);
                    }
                }
            }
            if (ok)
                best = max(best, cur);
        }
        return best;
    }
};
