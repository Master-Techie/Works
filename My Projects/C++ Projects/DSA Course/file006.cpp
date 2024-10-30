#include <iostream>
#include <vector>
using namespace std;


int maxWaterInContainer(vector<int> x)
{
    // int maxArea = 0;
    // int currArea = 0;

    // for (int i = 0; i < x.size()-1; i++)
    // {
    //     for (int j = i+1; j < x.size(); j++)
    //     {
    //         currArea = min(x[i],x[j]) * (j-i);

    //         if (currArea > maxArea)
    //         {
    //             maxArea = currArea;
    //         }
    //     }
    // }

    // return maxArea;


    // int n = x.size();
    // int lhs = 0;
    // int rhs = n-1;
    // int currArea = 0;
    // int maxArea = 0;

    // while (lhs < rhs)
    // {
    //     currArea = (rhs - lhs) * min(x[rhs], x[lhs]);
    //     maxArea = max(maxArea, currArea);

    //     (x[rhs] > x[lhs]) ? lhs++ : rhs--;
    // }

    // return maxArea;
}


int main()
{
    vector<int> x = {1, 1, 1, 9, 9, 1, 1, 1};
    cout << maxWaterInContainer(x);

    return 0;
}