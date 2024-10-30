#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int k = 0;
    int s = 0;

    while (n--) {
        m--;

        int a;
        cin >> a;

        if (m == 0) {
            k = a;
        }

        if (a < k || a < 1) {
            break;
        }

        else {s++;}
    }

    cout << s;

    return 0;
}