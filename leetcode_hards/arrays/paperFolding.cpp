#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int foldsReq(int curr, int target)
    {
        int folds = 0;
        while (curr > target)
        {
            curr = (curr + 1) / 2;
            folds++;
        }
        return folds;
    }

public:
    int minFolds(int h, int w, int h1, int w1)
    {
        return foldsReq(h, h1) + foldsReq(w, w1);
    }
};