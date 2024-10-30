#include <iostream>
#include <vector>
using namespace std;

// int binaryExponentaion(int base, int pow)
// {
//     int ans = 1;

//     while (pow > 0)
//     {
//         if (pow%2 == 1) 
//         {
//             ans *= base;
//         }

//         base *= base;
//         pow /= 2;
//     }

//     return ans;
// }


// int bestDayToBuyStock(vector<int> x)
// {
//     int bestBuy = x[0];
//     int bestSell = 0;
//     bool isBestBuy = false;

//     for (int i = 0; i < x.size(); i++)
//     {
//         bestBuy = min(bestBuy, x[i]);
//     }

//     for (int i = 0; i < x.size(); i++)
//     {
//         if (x[i] == bestBuy)
//         {
//             isBestBuy = true;
//         }

//         if (isBestBuy == true)
//         {
//             bestSell = max(bestSell, x[i]);
//         }
//     }

//     return bestSell-bestBuy;
// }


int main()
{
    // cout << binaryExponentaion(2,12);

    // vector<int> x{7, 1, 5, 3, 6, 4};
    // cout << bestDayToBuyStock(x);

    return 0;
}