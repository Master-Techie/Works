#include <iostream>
using namespace std;

int main(){
    int initial, money, bananas;
    cin >> initial >> money >> bananas;

    int total = bananas*(bananas+1)*initial/2;

    if (total > money) {cout << total-money;}
    else {cout << 0;}

    return 0;
}