#include <iostream>
using namespace std;

int main(){
    int k,l;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            cin >> a;

            if (a == 1) {
                k = i;
                l = j;
            }
        }
    }

    cout << abs(k-2)+abs(l-2);

    return 0;
}