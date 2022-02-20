#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int checkLexicon(string word)
    {
        vector<int> count(26, 0);
        for (char c : word)
        {
            count.at(c - 'a')++;
        }
        sort(count.begin(), count.end());
        return count.back();
    }

    int getF(string &s)
    {
        int a[26] = {
            0,
        };
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 0)
                return a[i];
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        int n = queries.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int nums = 0;
            for (int j = 0; j < words.size(); j++)
            {
                int query = getF(queries[i]);
                int word = getF(words[j]);

                cout << i << " : query " << query << " : word " << word << endl;
                if (query < word)
                {
                    nums++;
                }
            }
            result[i] = nums;
        }
        return result;
    }
};

void test()
{
    Solution solution;
    vector<string> queries{"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab", "bbabbaabb"};
    vector<string> words{"aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa"};
    vector<int> result;

    result = solution.numSmallerByFrequency(queries, words);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}